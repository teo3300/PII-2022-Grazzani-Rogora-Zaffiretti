############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project test_loadbytes
set_top load_test_h
add_files src-base_func/load_test.c
add_files -tb src-base_func/test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7k160t-fbv484-2}
create_clock -period 10 -name default
source "./test_loadbytes/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
