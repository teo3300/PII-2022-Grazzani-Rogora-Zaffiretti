#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include <stdint.h>

#include "ascon.h"
#include "constants.h"
#include "printstate.h"
#include "round.h"

static inline void P6(u64 s[5]) {
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}

static inline void P8(u64 s[5]) {
  ROUND(s, 0xb4);
  ROUND(s, 0xa5);
  P6(s);
}

static inline void P12(u64 s[5]) {
  ROUND(s, 0xf0);
  ROUND(s, 0xe1);
  ROUND(s, 0xd2);
  ROUND(s, 0xc3);
  P8(s);
}

#endif /* PERMUTATIONS_H_ */
