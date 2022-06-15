#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define ASCON_128_KEYBYTES 16
#define ASCON_128A_KEYBYTES 16
#define ASCON_80PQ_KEYBYTES 20

#define ASCON_128_RATE 8
#define ASCON_128A_RATE 16
#define ASCON_HASH_RATE 8
#define ASCON_PRF_IN_RATE 32
#define ASCON_PRF_OUT_RATE 16

#define ASCON_128_PA_ROUNDS 12
#define ASCON_128_PB_ROUNDS 6

#define ASCON_128A_PA_ROUNDS 12
#define ASCON_128A_PB_ROUNDS 8

#define ASCON_HASH_PA_ROUNDS 12
#define ASCON_HASH_PB_ROUNDS 12

#define ASCON_HASHA_PA_ROUNDS 12
#define ASCON_HASHA_PB_ROUNDS 8

#define ASCON_PRF_PA_ROUNDS 12
#define ASCON_PRF_PB_ROUNDS 12

#define ASCON_128_IV                            \
    (((u64)(ASCON_128_KEYBYTES * 8) << 56) | \
    ((u64)(ASCON_128_RATE * 8) << 48) |     \
    ((u64)(ASCON_128_PA_ROUNDS) << 40) |    \
    ((u64)(ASCON_128_PB_ROUNDS) << 32))

#define ASCON_128A_IV                            \
    (((u64)(ASCON_128A_KEYBYTES * 8) << 56) | \
    ((u64)(ASCON_128A_RATE * 8) << 48) |     \
    ((u64)(ASCON_128A_PA_ROUNDS) << 40) |    \
    ((u64)(ASCON_128A_PB_ROUNDS) << 32))

#define ASCON_80PQ_IV                            \
    (((u64)(ASCON_80PQ_KEYBYTES * 8) << 56) | \
    ((u64)(ASCON_128_RATE * 8) << 48) |      \
    ((u64)(ASCON_128_PA_ROUNDS) << 40) |     \
    ((u64)(ASCON_128_PB_ROUNDS) << 32))

#define ASCON_HASH_IV                                                \
    (((u64)(ASCON_HASH_RATE * 8) << 48) |                         \
    ((u64)(ASCON_HASH_PA_ROUNDS) << 40) |                        \
    ((u64)(ASCON_HASH_PA_ROUNDS - ASCON_HASH_PB_ROUNDS) << 32) | \
    ((u64)(ASCON_HASH_BYTES * 8) << 0))

#define ASCON_HASHA_IV                                                 \
    (((u64)(ASCON_HASH_RATE * 8) << 48) |                           \
    ((u64)(ASCON_HASHA_PA_ROUNDS) << 40) |                         \
    ((u64)(ASCON_HASHA_PA_ROUNDS - ASCON_HASHA_PB_ROUNDS) << 32) | \
    ((u64)(ASCON_HASH_BYTES * 8) << 0))

#define ASCON_XOF_IV                          \
    (((u64)(ASCON_HASH_RATE * 8) << 48) |  \
    ((u64)(ASCON_HASH_PA_ROUNDS) << 40) | \
    ((u64)(ASCON_HASH_PA_ROUNDS - ASCON_HASH_PB_ROUNDS) << 32))

#define ASCON_XOFA_IV                          \
    (((u64)(ASCON_HASH_RATE * 8) << 48) |   \
    ((u64)(ASCON_HASHA_PA_ROUNDS) << 40) | \
    ((u64)(ASCON_HASHA_PA_ROUNDS - ASCON_HASHA_PB_ROUNDS) << 32))

#define ASCON_PRF_IV                            \
    (((u64)(CRYPTO_KEYBYTES * 8) << 56) |    \
    ((u64)(ASCON_PRF_OUT_RATE * 8) << 48) | \
    ((u64)(0x80 | ASCON_PRF_PA_ROUNDS) << 40))

#define ASCON_MAC_IV                                \
    (((u64)(CRYPTO_KEYBYTES * 8) << 56) |        \
    ((u64)(ASCON_PRF_OUT_RATE * 8) << 48) |     \
    ((u64)(0x80 | ASCON_PRF_PA_ROUNDS) << 40) | \
    ((u64)(ASCON_PRF_BYTES * 8) << 0))

#define ASCON_PRFS_IV                               \
    (((u64)(CRYPTO_KEYBYTES * 8) << 56) |        \
    ((u64)(0x40 | ASCON_PRF_PA_ROUNDS) << 40) | \
    ((u64)(ASCON_PRF_BYTES * 8) << 32))

#endif /* CONSTANTS_H_ */
