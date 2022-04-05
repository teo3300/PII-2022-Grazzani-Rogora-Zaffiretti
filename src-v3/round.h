#ifndef ROUND_H_
#define ROUND_H_

#include "ascon.h"
#include "printstate.h"

static inline u64 ROR(u64 x, int n) {
  return x >> n | x << (-n & 63);
}

static inline void ROUND(u64 s[5], u8 C) {
  u64 t[5];
  /* addition of round constant */
  s[2] ^= C;
  /* printstate(" round constant", s); */
  /* substitution layer */
  s[0] ^= s[4];
  s[4] ^= s[3];
  s[2] ^= s[1];
  /* start of keccak s-box */
  t[0] = s[0] ^ (~s[1] & s[2]);
  t[1] = s[1] ^ (~s[2] & s[3]);
  t[2] = s[2] ^ (~s[3] & s[4]);
  t[3] = s[3] ^ (~s[4] & s[0]);
  t[4] = s[4] ^ (~s[0] & s[1]);
  /* end of keccak s-box */
  t[1] ^= t[0];
  t[0] ^= t[4];
  t[3] ^= t[2];
  t[2] = ~t[2];
  /* printstate(" substitution layer", &t); */
  /* linear diffusion layer */
  s[0] = t[0] ^ ROR(t[0], 19) ^ ROR(t[0], 28);
  s[1] = t[1] ^ ROR(t[1], 61) ^ ROR(t[1], 39);
  s[2] = t[2] ^ ROR(t[2], 1) ^ ROR(t[2], 6);
  s[3] = t[3] ^ ROR(t[3], 10) ^ ROR(t[3], 17);
  s[4] = t[4] ^ ROR(t[4], 7) ^ ROR(t[4], 41);
  printstate(" round output", s);
}

#endif /* ROUND_H_ */
