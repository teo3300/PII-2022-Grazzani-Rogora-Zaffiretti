# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
# Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__SIM_MATHHLS__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = ../../../src/tests/genkat_aead.c ../../../src/crypto_aead/ascon128v12/ref/printstate.c ../../../src/crypto_aead/ascon128v12/ref/encrypt.c ../../../src/crypto_aead/ascon128v12/ref/decrypt.c

override TARGET := csim.exe

AUTOPILOT_ROOT := C:/Xilinx/Vitis_HLS/2021.2
AUTOPILOT_MACH := win64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
ifndef AP_GCC_PATH
  AP_GCC_PATH := C:/Xilinx/Vitis_HLS/2021.2/tps/win64/msys64/mingw64/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_ROOT}/tps/win64/msys64/mingw64/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -D__VITIS_HLS__

IFLAG += -D__SIM_FPO__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E1__
IFLAG += -I../../src/tests -I../../src/crypto_aead/ascon128v12/ref -o -Wno-unknown-pragmas 
IFLAG += -g
IFLAG += -DNT
LFLAG += -Wl,--enable-auto-import 
DFLAG += -DAUTOCC
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += -Werror=return-type
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



AUTOCC := cmd //c apcc.bat  

$(ObjDir)/genkat_aead.o: ../../../src/tests/genkat_aead.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/tests/genkat_aead.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -I../../../../src/tests -I../../../../src/crypto_aead/ascon128v12/ref -I../../../../src/tests -I../../../../src/crypto_aead/ascon128v12/ref -DNDEBUG -o genkat -Wno-unknown-pragmas -DNDEBUG -o genkat -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/genkat_aead.d

$(ObjDir)/printstate.o: ../../../src/crypto_aead/ascon128v12/ref/printstate.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/crypto_aead/ascon128v12/ref/printstate.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/printstate.d

$(ObjDir)/encrypt.o: ../../../src/crypto_aead/ascon128v12/ref/encrypt.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/crypto_aead/ascon128v12/ref/encrypt.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/encrypt.d

$(ObjDir)/decrypt.o: ../../../src/crypto_aead/ascon128v12/ref/decrypt.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/crypto_aead/ascon128v12/ref/decrypt.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/decrypt.d
