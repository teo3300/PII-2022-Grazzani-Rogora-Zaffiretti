#ifndef LOAD_TEST_H
#define LOAD_TEST_H

#include "types.h"
#include "constants.h"
#include "ascon.h"

void load_test_c(volatile u8 k[CRYPTO_KEYBYTES], volatile u8 n[CRYPTO_NPUBBYTES], volatile u64 st[5]);
void load_test_h(volatile u8 k[CRYPTO_KEYBYTES], volatile u8 n[CRYPTO_NPUBBYTES], volatile u64 st[5]);

#endif//LOAD_TEST_H
