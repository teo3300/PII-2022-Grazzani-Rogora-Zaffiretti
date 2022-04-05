############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project PII-2022-Grazzani-Rogora-Zaffiretti
set_top crypto_aead_encrypt_h
add_files PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/printstate.c -cflags "-DNDEBUG" -csimflags "-DNDEBUG"
add_files PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c -cflags "-DNDEBUG" -csimflags "-DNDEBUG"
add_files -tb PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/genkat_aead.c -cflags "-DNDEBUG -Wno-unknown-pragmas" -csimflags "-DNDEBUG -Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7k160t-fbv484-2}
create_clock -period 10 -name default
source "./PII-2022-Grazzani-Rogora-Zaffiretti/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
