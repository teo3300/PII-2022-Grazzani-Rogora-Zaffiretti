############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project PII-2022-Grazzani-Rogora-Zaffiretti
set_top crypto_aead_encrypt
add_files PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c
add_files PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/encrypt.c
add_files PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/printstate.c
add_files -tb PII-2022-Grazzani-Rogora-Zaffiretti/src/tests/genkat_aead.c -cflags "-DNDEBUG" -csimflags "-DNDEBUG"
open_solution "solution1" -flow_target vivado
set_part {xcvu35p-fsvh2104-1-e}
create_clock -period 100 -name default
set_clock_uncertainty 0.5
#source "./PII-2022-Grazzani-Rogora-Zaffiretti/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -setup -rtl vhdl
export_design -format ip_catalog
