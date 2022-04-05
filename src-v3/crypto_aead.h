#include "api.h"
#include "ascon.h"
#include "types.h"

int crypto_aead_encrypt_c(
        u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES], volatile u64* clen,
        volatile u8 m[MAX_MESSAGE_LENGTH], u64 mlen,
        volatile u8 ad[MAX_ASSOCIATED_DATA_LENGTH], u64 adlen,
        volatile u8 nsec[CRYPTO_NSECBYTES], volatile u8 npub[CRYPTO_NPUBBYTES],
        volatile u8 k[CRYPTO_KEYBYTES]);//, u64 st[5]);
int crypto_aead_encrypt_h(
        u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES], volatile u64* clen,
        volatile u8 m[MAX_MESSAGE_LENGTH], u64 mlen,
        volatile u8 ad[MAX_ASSOCIATED_DATA_LENGTH], u64 adlen,
        volatile u8 nsec[CRYPTO_NSECBYTES], volatile u8 npub[CRYPTO_NPUBBYTES],
        volatile u8 k[CRYPTO_KEYBYTES]);//, u64 st[5]);

int crypto_aead_decrypt_c(
        u8 m[MAX_MESSAGE_LENGTH], volatile u64* mlen,
        volatile u8 nsec[CRYPTO_NSECBYTES], volatile u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES],
        u64 clen, volatile u8 ad[MAX_ASSOCIATED_DATA_LENGTH],
        u64 adlen, volatile u8 npub[CRYPTO_NPUBBYTES],
        volatile u8 k[CRYPTO_KEYBYTES]);//, u64 st[5]);
int crypto_aead_decrypt_h(
        u8 m[MAX_MESSAGE_LENGTH], volatile u64* mlen,
        volatile u8 nsec[CRYPTO_NSECBYTES], volatile u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES],
        u64 clen, volatile u8 ad[MAX_ASSOCIATED_DATA_LENGTH],
        u64 adlen, volatile u8 npub[CRYPTO_NPUBBYTES],
        volatile u8 k[CRYPTO_KEYBYTES]);//, u64 st[5]);
