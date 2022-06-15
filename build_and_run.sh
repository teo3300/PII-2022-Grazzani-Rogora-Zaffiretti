#!/bin/sh

# The aim of this script is to compile the C code following the original compilation process (from ascon-c)
# 	and comparing the output of the two compilations, just to ensure both programs behave the same
# 	before and after any edit to the code
gcc -O3 src/*.c -o genkat && ./genkat && diff src/original_LWC_AEAD_KAT_128_128.txt LWC_AEAD_KAT_128_128.txt
