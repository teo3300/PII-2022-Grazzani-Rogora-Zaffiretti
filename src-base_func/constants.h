#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "types.h"

#define ASCON_128_KEYBYTES 16

#define ASCON_128_RATE 8

#define ASCON_128_PA_ROUNDS 12
#define ASCON_128_PB_ROUNDS 6

#define ASCON_128_IV                                \
    (((u64)(ASCON_128_KEYBYTES * 8) << 56) |   \
    ((u64)(ASCON_128_RATE * 8) << 48)      |   \
    ((u64)(ASCON_128_PA_ROUNDS) << 40)     |   \
    ((u64)(ASCON_128_PB_ROUNDS) << 32))

#define KAT_SUCCESS 0
#define KAT_FILE_OPEN_ERROR -1
#define KAT_DATA_ERROR -3
#define KAT_CRYPTO_FAILURE -4

#define MAX_MESSAGE_LENGTH 32
#define MAX_ASSOCIATED_DATA_LENGTH 32

#define CRYPTO_KEYBYTES 16
#define CRYPTO_NSECBYTES 0
#define CRYPTO_NPUBBYTES 16
#define CRYPTO_ABYTES 16
#define CRYPTO_NOOVERLAP 1
#define ASCON_AEAD_RATE 8

#endif//CONSTANTS_H
