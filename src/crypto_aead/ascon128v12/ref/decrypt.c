#define CRYPTO_VERSION "1.2.5"
#define CRYPTO_KEYBYTES 16
#define CRYPTO_NSECBYTES 0
#define CRYPTO_NPUBBYTES 16
#define CRYPTO_ABYTES 16
#define CRYPTO_NOOVERLAP 1
#define ASCON_AEAD_RATE 8

#ifndef ASCON_H_
#define ASCON_H_

#include <stdint.h>

typedef struct {
  uint64_t x0, x1, x2, x3, x4;
} state_t;

#endif /* ASCON_H */

int crypto_aead_encrypt(unsigned char *c, unsigned long long *clen,
                        const unsigned char *m, unsigned long long mlen,
                        const unsigned char *ad, unsigned long long adlen,
                        const unsigned char *nsec, const unsigned char *npub,
                        const unsigned char *k);

int crypto_aead_decrypt(unsigned char *m, unsigned long long *mlen,
                        unsigned char *nsec, const unsigned char *c,
                        unsigned long long clen, const unsigned char *ad,
                        unsigned long long adlen, const unsigned char *npub,
                        const unsigned char *k);

#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include <stdint.h>

#ifndef ROUND_H_
#define ROUND_H_

static inline uint64_t ROR(uint64_t x, int n) {
  return (x << (64 - n)) | (x >> n);
}

static inline void ROUND(state_t* s, uint8_t C) {
  state_t t;
  /* addition of round constant */
  s->x2 ^= C;
  /* // printstate(" round constant", s); */
  /* substitution layer */
  s->x0 ^= s->x4;
  s->x4 ^= s->x3;
  s->x2 ^= s->x1;
  /* start of keccak s-box */
  t.x0 = s->x0 ^ (~s->x1 & s->x2);
  t.x1 = s->x1 ^ (~s->x2 & s->x3);
  t.x2 = s->x2 ^ (~s->x3 & s->x4);
  t.x3 = s->x3 ^ (~s->x4 & s->x0);
  t.x4 = s->x4 ^ (~s->x0 & s->x1);
  /* end of keccak s-box */
  t.x1 ^= t.x0;
  t.x0 ^= t.x4;
  t.x3 ^= t.x2;
  t.x2 = ~t.x2;
  /* // printstate(" substitution layer", &t); */
  /* linear diffusion layer */
  s->x0 = t.x0 ^ ROR(t.x0, 19) ^ ROR(t.x0, 28);
  s->x1 = t.x1 ^ ROR(t.x1, 61) ^ ROR(t.x1, 39);
  s->x2 = t.x2 ^ ROR(t.x2, 1) ^ ROR(t.x2, 6);
  s->x3 = t.x3 ^ ROR(t.x3, 10) ^ ROR(t.x3, 17);
  s->x4 = t.x4 ^ ROR(t.x4, 7) ^ ROR(t.x4, 41);
  // printstate(" round output", s);
}

#endif /* ROUND_H_ */


#define ASCON_128_KEYBYTES 16
#define ASCON_128A_KEYBYTES 16
#define ASCON_80PQ_KEYBYTES 20

#define ASCON_128_RATE 8
#define ASCON_128A_RATE 16
#define ASCON_HASH_RATE 8

#define ASCON_128_PA_ROUNDS 12
#define ASCON_128_PB_ROUNDS 6

#define ASCON_128A_PA_ROUNDS 12
#define ASCON_128A_PB_ROUNDS 8

#define ASCON_HASH_PA_ROUNDS 12
#define ASCON_HASH_PB_ROUNDS 12

#define ASCON_HASHA_PA_ROUNDS 12
#define ASCON_HASHA_PB_ROUNDS 8

#define ASCON_HASH_BYTES 32

#define ASCON_128_IV                            \
  (((uint64_t)(ASCON_128_KEYBYTES * 8) << 56) | \
   ((uint64_t)(ASCON_128_RATE * 8) << 48) |     \
   ((uint64_t)(ASCON_128_PA_ROUNDS) << 40) |    \
   ((uint64_t)(ASCON_128_PB_ROUNDS) << 32))

#define ASCON_128A_IV                            \
  (((uint64_t)(ASCON_128A_KEYBYTES * 8) << 56) | \
   ((uint64_t)(ASCON_128A_RATE * 8) << 48) |     \
   ((uint64_t)(ASCON_128A_PA_ROUNDS) << 40) |    \
   ((uint64_t)(ASCON_128A_PB_ROUNDS) << 32))

#define ASCON_80PQ_IV                            \
  (((uint64_t)(ASCON_80PQ_KEYBYTES * 8) << 56) | \
   ((uint64_t)(ASCON_128_RATE * 8) << 48) |      \
   ((uint64_t)(ASCON_128_PA_ROUNDS) << 40) |     \
   ((uint64_t)(ASCON_128_PB_ROUNDS) << 32))

#define ASCON_HASH_IV                                                \
  (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |                         \
   ((uint64_t)(ASCON_HASH_PA_ROUNDS) << 40) |                        \
   ((uint64_t)(ASCON_HASH_PA_ROUNDS - ASCON_HASH_PB_ROUNDS) << 32) | \
   ((uint64_t)(ASCON_HASH_BYTES * 8) << 0))

#define ASCON_HASHA_IV                                                 \
  (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |                           \
   ((uint64_t)(ASCON_HASHA_PA_ROUNDS) << 40) |                         \
   ((uint64_t)(ASCON_HASHA_PA_ROUNDS - ASCON_HASHA_PB_ROUNDS) << 32) | \
   ((uint64_t)(ASCON_HASH_BYTES * 8) << 0))

#define ASCON_XOF_IV                          \
  (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |  \
   ((uint64_t)(ASCON_HASH_PA_ROUNDS) << 40) | \
   ((uint64_t)(ASCON_HASH_PA_ROUNDS - ASCON_HASH_PB_ROUNDS) << 32))

#define ASCON_XOFA_IV                          \
  (((uint64_t)(ASCON_HASH_RATE * 8) << 48) |   \
   ((uint64_t)(ASCON_HASHA_PA_ROUNDS) << 40) | \
   ((uint64_t)(ASCON_HASHA_PA_ROUNDS - ASCON_HASHA_PB_ROUNDS) << 32))

static inline void P12(state_t* s) {
  // printstate(" permutation input", s);
  ROUND(s, 0xf0);
  ROUND(s, 0xe1);
  ROUND(s, 0xd2);
  ROUND(s, 0xc3);
  ROUND(s, 0xb4);
  ROUND(s, 0xa5);
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}

static inline void P8(state_t* s) {
  // printstate(" permutation input", s);
  ROUND(s, 0xb4);
  ROUND(s, 0xa5);
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}

static inline void P6(state_t* s) {
  // printstate(" permutation input", s);
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}

#endif /* PERMUTATIONS_H_ */

#ifndef PRINTSTATE_H_
#define PRINTSTATE_H_

#ifdef ASCON_PRINTSTATE


void printword(const char* text, const word_t x);
void printstate(const char* text, const state_t* s);

#else

#define printword(text, w) \
  do {                     \
  } while (0)

#define printstate(text, s) \
  do {                      \
  } while (0)

#endif

#endif /* PRINTSTATE_H_ */

#ifndef WORD_H_
#define WORD_H_

#include <stdint.h>

#define WORDTOU64
#define U64TOWORD

typedef uint64_t word_t;

/* get byte from 64-bit Ascon word */
#define GETBYTE(x, i) ((uint8_t)((uint64_t)(x) >> (56 - 8 * (i))))

/* set byte in 64-bit Ascon word */
#define SETBYTE(b, i) ((uint64_t)(b) << (56 - 8 * (i)))

/* set padding byte in 64-bit Ascon word */
#define PAD(i) SETBYTE(0x80, i)

/* load bytes into 64-bit Ascon word */
static inline uint64_t LOADBYTES(const uint8_t* bytes, int n) {
  uint64_t x = 0;
  for (int i = 0; i < n; ++i) x |= SETBYTE(bytes[i], i);
  return x;
}

/* store bytes from 64-bit Ascon word */
static inline void STOREBYTES(uint8_t* bytes, uint64_t x, int n) {
  for (int i = 0; i < n; ++i) bytes[i] = GETBYTE(x, i);
}

/* clear bytes in 64-bit Ascon word */
static inline uint64_t CLEARBYTES(uint64_t x, int n) {
  for (int i = 0; i < n; ++i) x &= ~SETBYTE(0xff, i);
  return x;
}

#endif /* WORD_H_ */

int crypto_aead_decrypt(unsigned char* m, unsigned long long* mlen,
                        unsigned char* nsec, const unsigned char* c,
                        unsigned long long clen, const unsigned char* ad,
                        unsigned long long adlen, const unsigned char* npub,
                        const unsigned char* k) {
  (void)nsec;

  if (clen < CRYPTO_ABYTES) return -1;

  /* set plaintext size */
  *mlen = clen - CRYPTO_ABYTES;

  /* load key and nonce */
  const uint64_t K0 = LOADBYTES(k, 8);
  const uint64_t K1 = LOADBYTES(k + 8, 8);
  const uint64_t N0 = LOADBYTES(npub, 8);
  const uint64_t N1 = LOADBYTES(npub + 8, 8);

  /* initialize */
  state_t s;
  s.x0 = ASCON_128_IV;
  s.x1 = K0;
  s.x2 = K1;
  s.x3 = N0;
  s.x4 = N1;
  P12(&s);
  s.x3 ^= K0;
  s.x4 ^= K1;
  // printstate("initialization", &s);

  if (adlen) {
    /* full associated data blocks */
    while (adlen >= ASCON_128_RATE) {
      s.x0 ^= LOADBYTES(ad, 8);
      P6(&s);
      ad += ASCON_128_RATE;
      adlen -= ASCON_128_RATE;
    }
    /* final associated data block */
    s.x0 ^= LOADBYTES(ad, adlen);
    s.x0 ^= PAD(adlen);
    P6(&s);
  }
  /* domain separation */
  s.x4 ^= 1;
  // printstate("process associated data", &s);

  /* full ciphertext blocks */
  clen -= CRYPTO_ABYTES;
  while (clen >= ASCON_128_RATE) {
    uint64_t c0 = LOADBYTES(c, 8);
    STOREBYTES(m, s.x0 ^ c0, 8);
    s.x0 = c0;
    P6(&s);
    m += ASCON_128_RATE;
    c += ASCON_128_RATE;
    clen -= ASCON_128_RATE;
  }
  /* final ciphertext block */
  uint64_t c0 = LOADBYTES(c, clen);
  STOREBYTES(m, s.x0 ^ c0, clen);
  s.x0 = CLEARBYTES(s.x0, clen);
  s.x0 |= c0;
  s.x0 ^= PAD(clen);
  c += clen;
  // printstate("process ciphertext", &s);

  /* finalize */
  s.x1 ^= K0;
  s.x2 ^= K1;
  P12(&s);
  s.x3 ^= K0;
  s.x4 ^= K1;
  // printstate("finalization", &s);

  /* set tag */
  uint8_t t[16];
  STOREBYTES(t, s.x3, 8);
  STOREBYTES(t + 8, s.x4, 8);

  /* verify tag (should be constant time, check compiler output) */
  int result = 0;
  for (int i = 0; i < CRYPTO_ABYTES; ++i) result |= c[i] ^ t[i];
  result = (((result - 1) >> 8) & 1) - 1;

  return result;
}
