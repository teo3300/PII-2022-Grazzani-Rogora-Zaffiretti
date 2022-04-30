#include "api.h"
#include "ascon.h"
#include "types.h"

int crypto_aead_encrypt(
        u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES], volatile u64* clen,
        u8 m[MAX_MESSAGE_LENGTH], u64 mlen,
        u8 ad[MAX_ASSOCIATED_DATA_LENGTH], u64 adlen, u8 npub[CRYPTO_NPUBBYTES],
        u8 k[CRYPTO_KEYBYTES]);

int crypto_aead_decrypt(
        u8 m[MAX_MESSAGE_LENGTH], volatile u64* mlen, u8 c[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES],
        u64 clen, u8 ad[MAX_ASSOCIATED_DATA_LENGTH],
        u64 adlen, u8 npub[CRYPTO_NPUBBYTES],
        u8 k[CRYPTO_KEYBYTES]);
