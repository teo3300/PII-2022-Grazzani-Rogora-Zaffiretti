#include "load_test.h"
#include "word.h"
#include "constants.h"

#include "types.h"

void load_test(volatile u8 k[CRYPTO_KEYBYTES], volatile u8 n[CRYPTO_NPUBBYTES], volatile u64 st[5]);

#define F_QUIT do{ /*copyState(s,st);*/ return; }while(0);

void copyState(state_t a, state_t b){
    for(u64 i=0; i<5; i++){
        b[i] = a[i];
    }
}

void load_test_c(volatile u8 k[CRYPTO_KEYBYTES], volatile u8 n[CRYPTO_NPUBBYTES], volatile u64 st[5]){
	load_test(k,n,st);
}
void load_test_h(volatile u8 k[CRYPTO_KEYBYTES], volatile u8 n[CRYPTO_NPUBBYTES], volatile u64 st[5]){
	load_test(k,n,st);
}

void load_test(volatile u8 k[CRYPTO_KEYBYTES], volatile u8 n[CRYPTO_NPUBBYTES], volatile u64 st[5]){
    st[0] = ASCON_128_IV;
    st[1] = LOADBYTES(k, 8);
    st[2] = LOADBYTES(&k[8], 8);
    st[3] = LOADBYTES(n, 8);
    st[4] = LOADBYTES(&n[8], 8);
}
