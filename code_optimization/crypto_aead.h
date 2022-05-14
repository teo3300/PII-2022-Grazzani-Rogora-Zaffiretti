#include "api.h"
#include "ascon.h"
#include "types.h"

u8 crypto_aead_encrypt(
        u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES], volatile u8* clen,
        u32 m[MAX_MESSAGE_LENGTH/4], u8 mlen,
        u32 ad[MAX_ASSOCIATED_DATA_LENGTH/4], u8 adlen, u32 npub[CRYPTO_NPUBBYTES/4],
        u32 k[CRYPTO_KEYBYTES/4]);

u8 crypto_aead_decrypt(
        u8 m[MAX_MESSAGE_LENGTH], volatile u8* mlen, u32 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES],
        u8 clen, u32 ad[MAX_ASSOCIATED_DATA_LENGTH],
        u8 adlen, u32 npub[CRYPTO_NPUBBYTES],
        u32 k[CRYPTO_KEYBYTES]);
