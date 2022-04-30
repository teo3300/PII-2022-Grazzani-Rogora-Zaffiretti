############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project PII-2022-Grazzani-Rogora-Zaffiretti
set_top crypto_aead_encrypt
add_files PII-2022-Grazzani-Rogora-Zaffiretti/code_optimization/aead.c -cflags "-DNDEBUG -O3" -csimflags "-DNDEBUG -O3"
add_files -tb PII-2022-Grazzani-Rogora-Zaffiretti/code_optimization/genkat_aead.c -cflags "-DNDEBUG -O3 -Wno-unknown-pragmas" -csimflags "-DNDEBUG -O3 -Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7k160t-fbv484-2}
create_clock -period 30 -name default
config_export -format ip_catalog -output H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/code_optimization/vivado_IP -rtl verilog -vivado_clock 30 -vivado_phys_opt all
source "./PII-2022-Grazzani-Rogora-Zaffiretti/solution1/directives.tcl"
csim_design -clean -O
csynth_design
cosim_design -O
export_design -rtl verilog -format ip_catalog -output H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/code_optimization/vivado_IP
