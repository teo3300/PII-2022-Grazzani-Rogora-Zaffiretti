############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project PII-2022-Grazzani-Rogora-Zaffiretti
open_solution "solution1" -flow_target vivado
set_part {xc7k160tfbg484-2}
create_clock -period 100 -name default
set_clock_uncertainty 0.5
#source "./PII-2022-Grazzani-Rogora-Zaffiretti/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
