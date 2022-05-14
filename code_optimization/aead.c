#include "api.h"
#include "ascon.h"
#include "crypto_aead.h"
#include "permutations.h"
#include "printstate.h"
#include "word.h"
#include "types.h"

u8 crypto_aead_encrypt(
        u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES], 	volatile u8* clen,
		u8 m[MAX_MESSAGE_LENGTH], 				   	u8  mlen,
		u8 ad[MAX_ASSOCIATED_DATA_LENGTH], 	   	u8  adlen,
		u32 npub[CRYPTO_NPUBBYTES/4],
		u32 k[CRYPTO_KEYBYTES/4]){

    /* set ciphertext size */
    *clen = mlen + CRYPTO_ABYTES;

    /* load key and nonce */
    const u64 K0 = FASTFLOAD(k);
    const u64 K1 = FASTFLOAD(&k[2]);
    const u64 N0 = FASTFLOAD(npub);
    const u64 N1 = FASTFLOAD(&npub[2]);

    /* initialize */
    u64 s[5];
    s[0] = ASCON_128_IV;
    s[1] = K0;
    s[2] = K1;
    s[3] = N0;
    s[4] = N1;

    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;


    if (adlen) {
        /* full associated data blocks */
        ad_full_block_load: while (adlen >= ASCON_128_RATE) {
        s[0] ^= LOADBYTES(ad, 8);

        P6(s);
        ad += ASCON_128_RATE;
        adlen -= ASCON_128_RATE;
        }
        /* final associated data block */
        s[0] ^= LOADBYTES(ad, adlen);
        s[0] ^= PAD(adlen);

        P6(s);
    }
    /* domain separation */
    s[4] ^= 1;


    /* full plaintext blocks */
      msg_full_block_load: while (mlen >= ASCON_128_RATE) {
        s[0] ^= LOADBYTES(m, 8);
        STOREBYTES(c, s[0], 8);

        P6(s);
        m += ASCON_128_RATE;
        c += ASCON_128_RATE;
        mlen -= ASCON_128_RATE;
    }
    /* final plaintext block */
    s[0] ^= LOADBYTES(m, mlen);
    STOREBYTES(c, s[0], mlen);
    s[0] ^= PAD(mlen);
    c += mlen;


    /* finalize */
    s[1] ^= K0;
    s[2] ^= K1;

    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;


    /* set tag */
    STOREBYTES(c, s[3], 8);
    STOREBYTES(c + 8, s[4], 8);

    return 0;
}

u8 crypto_aead_decrypt(
        u8 m[MAX_MESSAGE_LENGTH], volatile u8* mlen,
		u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES],
        u8 clen, u8 ad[MAX_ASSOCIATED_DATA_LENGTH],
        u8 adlen, u8 npub[CRYPTO_NPUBBYTES],
        u8 k[CRYPTO_KEYBYTES]){

    if (clen < CRYPTO_ABYTES) return -1;

    /* set plaintext size */
    *mlen = clen - CRYPTO_ABYTES;

    /* load key and nonce */
    const u64 K0 = LOADBYTES(k, 8);
    const u64 K1 = LOADBYTES(&k[8], 8);
    const u64 N0 = LOADBYTES(npub, 8);
    const u64 N1 = LOADBYTES(&k[8], 8);

    /* initialize */
    u64 s[5];
    s[0] = ASCON_128_IV;
    s[1] = K0;
    s[2] = K1;
    s[3] = N0;
    s[4] = N1;

    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;


    if (adlen) {
        /* full associated data blocks */
    	ad_full_block_load: while (adlen >= ASCON_128_RATE) {
        s[0] ^= LOADBYTES(ad, 8);

        P6(s);
        ad += ASCON_128_RATE;
        adlen -= ASCON_128_RATE;
        }
        /* final associated data block */
        s[0] ^= LOADBYTES(ad, adlen);
        s[0] ^= PAD(adlen);

        P6(s);
    }
    /* domain separation */
    s[4] ^= 1;


    /* full ciphertext blocks */
    clen -= CRYPTO_ABYTES;
    msg_full_block_load: while (clen >= ASCON_128_RATE) {
        u64 c0 = LOADBYTES(c, 8);
        STOREBYTES(m, s[0] ^ c0, 8);
        s[0] = c0;

        P6(s);
        m += ASCON_128_RATE;
        c += ASCON_128_RATE;
        clen -= ASCON_128_RATE;
    }
    /* final ciphertext block */
    u64 c0 = LOADBYTES(c, clen);
    STOREBYTES(m, s[0] ^ c0, clen);
    s[0] = CLEARBYTES(s[0], clen);
    s[0] |= c0;
    s[0] ^= PAD(clen);
    c += clen;


    /* finalize */
    s[1] ^= K0;
    s[2] ^= K1;

    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;


    /* set tag */
    u8 t[16];
    STOREBYTES(t, s[3], 8);
    STOREBYTES(t + 8, s[4], 8);

    /* verify tag (should be constant time, check compiler output) -- Ritorna errore in cosim*/
    u32 result = 0;
    for (u8 i = 0; i < CRYPTO_ABYTES; ++i) result |= c[i] ^ t[i];
    result = (((result - 1) >> 8) & 1) - 1;

    u8 compact = 0;
    for(u8 a = 0; a<4; a++) compact |= (u8)result >> 8*a;

    return compact;
}
