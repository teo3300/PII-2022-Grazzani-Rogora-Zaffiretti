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

HLS_SOURCES = ../../../code_optimization/genkat_aead.c ../../../code_optimization/aead.c

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
IFLAG += -O3 -Wno-unknown-pragmas 
AP_ENABLE_OPTIMIZED := 1
IFLAG += -DNT
LFLAG += -Wl,--enable-auto-import 
DFLAG += -DAUTOCC
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += -Werror=return-type
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



AUTOCC := cmd //c apcc.bat  

$(ObjDir)/genkat_aead.o: ../../../code_optimization/genkat_aead.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../code_optimization/genkat_aead.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -DNDEBUG -O3 -Wno-unknown-pragmas -DNDEBUG -O3 -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) -DNDEBUG $< -o $@ ; \

-include $(ObjDir)/genkat_aead.d

$(ObjDir)/aead.o: ../../../code_optimization/aead.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../code_optimization/aead.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -DNDEBUG -O3 -DNDEBUG -O3  $(IFLAG) $(DFLAG) -DNDEBUG $< -o $@ ; \

-include $(ObjDir)/aead.d
