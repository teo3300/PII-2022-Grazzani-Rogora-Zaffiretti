#include "api.h"
#include "ascon.h"
#include "types.h"

u8 crypto_aead_encrypt(
        u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES], volatile u8* clen,
        u8 m[MAX_MESSAGE_LENGTH], u8 mlen,
        u8 ad[MAX_ASSOCIATED_DATA_LENGTH], u8 adlen, u8 npub[CRYPTO_NPUBBYTES],
        u8 k[CRYPTO_KEYBYTES]);

u8 crypto_aead_decrypt(
        u8 m[MAX_MESSAGE_LENGTH], volatile u8* mlen, u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES],
        u8 clen, u8 ad[MAX_ASSOCIATED_DATA_LENGTH],
        u8 adlen, u8 npub[CRYPTO_NPUBBYTES],
        u8 k[CRYPTO_KEYBYTES]);
