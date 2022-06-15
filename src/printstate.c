#ifdef ASCON_PRINT_STATE

#include "printstate.h"

#include <stdio.h>
#include <string.h>

#ifndef WORDTOU64
#define WORDTOU64
#endif

#ifndef U64BIG
#define U64BIG
#endif

void printword(const char* text, const uint64_t x) {

  #ifndef __SYNTHESIS__
	printf("%s=%016" PRIx64, text, U64BIG(WORDTOU64(x)));
  #endif
}

void printstate(const char* text, const state_t* s) {
  #ifndef __SYNTHESIS__
	printf("%s:", text);
	for (int i = strlen(text); i < 17; ++i) printf(" ");
	printword(" x0", s[0]);
	printword(" x1", s[1]);
	printword(" x2", s[2]);
	printword(" x3", s[3]);
	printword(" x4", s[4]);
    printf("\n");
  #endif
}

#endif
