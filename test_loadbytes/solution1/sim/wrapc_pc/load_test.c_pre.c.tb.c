// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.c"
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.c" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.h" 1



# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/types.h" 1
# 4 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.h" 2

# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/constants.h" 1
# 5 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.h" 2

# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/ascon.h" 1





typedef unsigned long long int state_t[5];
# 6 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.h" 2


void load_test_c(volatile unsigned char k[16], volatile unsigned char n[16], volatile unsigned long long int st[5]);
void load_test_h(volatile unsigned char k[16], volatile unsigned char n[16], volatile unsigned long long int st[5]);
# 2 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.c" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/word.h" 1








static inline unsigned long long int LOADBYTES(volatile unsigned char* bytes, unsigned long long int n) {
  unsigned long long int x = 0;
  for (unsigned long long int i = 0; i < n; ++i) x |= ((unsigned long long int)(bytes[i]) << (56 - 8 * (i)));
  return x;
}
# 3 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.c" 2




void load_test(volatile unsigned char k[16], volatile unsigned char n[16], volatile unsigned long long int st[5]);



void copyState(state_t a, state_t b){
    for(unsigned long long int i=0; i<5; i++){
        b[i] = a[i];
    }
}

void load_test_c(volatile unsigned char k[16], volatile unsigned char n[16], volatile unsigned long long int st[5]){
 load_test(k,n,st);
}
void load_test_h(volatile unsigned char k[16], volatile unsigned char n[16], volatile unsigned long long int st[5]){
 load_test(k,n,st);
}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_load_test_h_ir(volatile unsigned char *, volatile unsigned char *, volatile unsigned long long *);
#ifdef __cplusplus
extern "C"
#endif
void load_test_h_hw_stub(volatile unsigned char *k, volatile unsigned char *n, volatile unsigned long long *st){
load_test_h(k, n, st);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void apatb_load_test_h_sw(volatile unsigned char *k, volatile unsigned char *n, volatile unsigned long long *st){
apatb_load_test_h_ir(k, n, st);
return ;
}
#endif
# 22 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-base_func/load_test.c"


void load_test(volatile unsigned char k[16], volatile unsigned char n[16], volatile unsigned long long int st[5]){
    st[0] = (((unsigned long long int)(16 * 8) << 56) | ((unsigned long long int)(8 * 8) << 48) | ((unsigned long long int)(12) << 40) | ((unsigned long long int)(6) << 32));
    st[1] = LOADBYTES(k, 8);
    st[2] = LOADBYTES(&k[8], 8);
    st[3] = LOADBYTES(n, 8);
    st[4] = LOADBYTES(&n[8], 8);
}
