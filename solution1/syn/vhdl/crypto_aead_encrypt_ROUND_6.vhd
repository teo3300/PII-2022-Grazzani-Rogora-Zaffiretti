-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Version: 2021.2
-- Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity crypto_aead_encrypt_ROUND_6 is
port (
    ap_ready : OUT STD_LOGIC;
    s_x0_read : IN STD_LOGIC_VECTOR (63 downto 0);
    s_x1_read : IN STD_LOGIC_VECTOR (63 downto 0);
    s_x2_read : IN STD_LOGIC_VECTOR (63 downto 0);
    s_x3_read : IN STD_LOGIC_VECTOR (63 downto 0);
    s_x4_read : IN STD_LOGIC_VECTOR (63 downto 0);
    C : IN STD_LOGIC_VECTOR (7 downto 0);
    ap_return_0 : OUT STD_LOGIC_VECTOR (63 downto 0);
    ap_return_1 : OUT STD_LOGIC_VECTOR (63 downto 0);
    ap_return_2 : OUT STD_LOGIC_VECTOR (63 downto 0);
    ap_return_3 : OUT STD_LOGIC_VECTOR (63 downto 0);
    ap_return_4 : OUT STD_LOGIC_VECTOR (63 downto 0) );
end;


architecture behav of crypto_aead_encrypt_ROUND_6 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv64_FFFFFFFFFFFFFFFF : STD_LOGIC_VECTOR (63 downto 0) := "1111111111111111111111111111111111111111111111111111111111111111";
    constant ap_const_lv32_13 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000010011";
    constant ap_const_lv32_3F : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000111111";
    constant ap_const_lv32_1C : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000011100";
    constant ap_const_lv32_3D : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000111101";
    constant ap_const_lv32_27 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000100111";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_A : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001010";
    constant ap_const_lv32_11 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000010001";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv32_29 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000101001";
    constant ap_const_logic_0 : STD_LOGIC := '0';

attribute shreg_extract : string;
    signal zext_ln47_fu_118_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln47_fu_122_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln54_fu_146_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal and_ln54_fu_152_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln50_fu_128_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln52_fu_140_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln55_fu_164_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln56_fu_176_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal and_ln56_fu_182_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln51_fu_134_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln57_fu_194_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln58_fu_206_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal and_ln58_fu_212_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal t_fu_158_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln60_fu_224_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal and_ln55_fu_170_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal t_2_fu_218_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal t_1_fu_188_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln62_fu_242_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal and_ln57_fu_200_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal t_4_fu_236_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal trunc_ln41_fu_260_p1 : STD_LOGIC_VECTOR (18 downto 0);
    signal lshr_ln_fu_264_p4 : STD_LOGIC_VECTOR (44 downto 0);
    signal trunc_ln41_1_fu_282_p1 : STD_LOGIC_VECTOR (27 downto 0);
    signal lshr_ln41_1_fu_286_p4 : STD_LOGIC_VECTOR (35 downto 0);
    signal or_ln41_1_fu_296_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln66_fu_304_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal or_ln_fu_274_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal t_3_fu_230_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal trunc_ln41_2_fu_316_p1 : STD_LOGIC_VECTOR (60 downto 0);
    signal lshr_ln41_2_fu_320_p4 : STD_LOGIC_VECTOR (2 downto 0);
    signal trunc_ln41_3_fu_338_p1 : STD_LOGIC_VECTOR (38 downto 0);
    signal lshr_ln41_3_fu_342_p4 : STD_LOGIC_VECTOR (24 downto 0);
    signal or_ln41_3_fu_352_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln67_fu_360_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal or_ln41_2_fu_330_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal t_6_fu_254_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal trunc_ln41_4_fu_372_p1 : STD_LOGIC_VECTOR (0 downto 0);
    signal lshr_ln41_4_fu_376_p4 : STD_LOGIC_VECTOR (62 downto 0);
    signal trunc_ln41_5_fu_394_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal lshr_ln41_5_fu_398_p4 : STD_LOGIC_VECTOR (57 downto 0);
    signal or_ln41_5_fu_408_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln68_fu_416_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal or_ln41_4_fu_386_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal t_5_fu_248_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal trunc_ln41_6_fu_428_p1 : STD_LOGIC_VECTOR (9 downto 0);
    signal lshr_ln41_6_fu_432_p4 : STD_LOGIC_VECTOR (53 downto 0);
    signal trunc_ln41_7_fu_450_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal lshr_ln41_7_fu_454_p4 : STD_LOGIC_VECTOR (46 downto 0);
    signal or_ln41_7_fu_464_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln69_fu_472_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal or_ln41_6_fu_442_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal trunc_ln41_8_fu_484_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal lshr_ln41_8_fu_488_p4 : STD_LOGIC_VECTOR (56 downto 0);
    signal trunc_ln41_9_fu_506_p1 : STD_LOGIC_VECTOR (40 downto 0);
    signal lshr_ln41_9_fu_510_p4 : STD_LOGIC_VECTOR (22 downto 0);
    signal or_ln41_9_fu_520_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln70_fu_528_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal or_ln41_8_fu_498_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln66_1_fu_310_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln67_1_fu_366_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln68_1_fu_422_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln69_1_fu_478_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln70_1_fu_534_p2 : STD_LOGIC_VECTOR (63 downto 0);


begin



    and_ln54_fu_152_p2 <= (xor_ln54_fu_146_p2 and xor_ln47_fu_122_p2);
    and_ln55_fu_170_p2 <= (xor_ln55_fu_164_p2 and s_x3_read);
    and_ln56_fu_182_p2 <= (xor_ln56_fu_176_p2 and s_x4_read);
    and_ln57_fu_200_p2 <= (xor_ln57_fu_194_p2 and xor_ln50_fu_128_p2);
    and_ln58_fu_212_p2 <= (xor_ln58_fu_206_p2 and s_x1_read);
    ap_ready <= ap_const_logic_1;
    ap_return_0 <= xor_ln66_1_fu_310_p2;
    ap_return_1 <= xor_ln67_1_fu_366_p2;
    ap_return_2 <= xor_ln68_1_fu_422_p2;
    ap_return_3 <= xor_ln69_1_fu_478_p2;
    ap_return_4 <= xor_ln70_1_fu_534_p2;
    lshr_ln41_1_fu_286_p4 <= t_4_fu_236_p2(63 downto 28);
    lshr_ln41_2_fu_320_p4 <= t_3_fu_230_p2(63 downto 61);
    lshr_ln41_3_fu_342_p4 <= t_3_fu_230_p2(63 downto 39);
    lshr_ln41_4_fu_376_p4 <= t_6_fu_254_p2(63 downto 1);
    lshr_ln41_5_fu_398_p4 <= t_6_fu_254_p2(63 downto 6);
    lshr_ln41_6_fu_432_p4 <= t_5_fu_248_p2(63 downto 10);
    lshr_ln41_7_fu_454_p4 <= t_5_fu_248_p2(63 downto 17);
    lshr_ln41_8_fu_488_p4 <= t_2_fu_218_p2(63 downto 7);
    lshr_ln41_9_fu_510_p4 <= t_2_fu_218_p2(63 downto 41);
    lshr_ln_fu_264_p4 <= t_4_fu_236_p2(63 downto 19);
    or_ln41_1_fu_296_p3 <= (trunc_ln41_1_fu_282_p1 & lshr_ln41_1_fu_286_p4);
    or_ln41_2_fu_330_p3 <= (trunc_ln41_2_fu_316_p1 & lshr_ln41_2_fu_320_p4);
    or_ln41_3_fu_352_p3 <= (trunc_ln41_3_fu_338_p1 & lshr_ln41_3_fu_342_p4);
    or_ln41_4_fu_386_p3 <= (trunc_ln41_4_fu_372_p1 & lshr_ln41_4_fu_376_p4);
    or_ln41_5_fu_408_p3 <= (trunc_ln41_5_fu_394_p1 & lshr_ln41_5_fu_398_p4);
    or_ln41_6_fu_442_p3 <= (trunc_ln41_6_fu_428_p1 & lshr_ln41_6_fu_432_p4);
    or_ln41_7_fu_464_p3 <= (trunc_ln41_7_fu_450_p1 & lshr_ln41_7_fu_454_p4);
    or_ln41_8_fu_498_p3 <= (trunc_ln41_8_fu_484_p1 & lshr_ln41_8_fu_488_p4);
    or_ln41_9_fu_520_p3 <= (trunc_ln41_9_fu_506_p1 & lshr_ln41_9_fu_510_p4);
    or_ln_fu_274_p3 <= (trunc_ln41_fu_260_p1 & lshr_ln_fu_264_p4);
    t_1_fu_188_p2 <= (xor_ln52_fu_140_p2 xor and_ln56_fu_182_p2);
    t_2_fu_218_p2 <= (xor_ln51_fu_134_p2 xor and_ln58_fu_212_p2);
    t_3_fu_230_p2 <= (xor_ln60_fu_224_p2 xor and_ln55_fu_170_p2);
    t_4_fu_236_p2 <= (t_fu_158_p2 xor t_2_fu_218_p2);
    t_5_fu_248_p2 <= (xor_ln62_fu_242_p2 xor and_ln57_fu_200_p2);
    t_6_fu_254_p2 <= (t_1_fu_188_p2 xor ap_const_lv64_FFFFFFFFFFFFFFFF);
    t_fu_158_p2 <= (xor_ln50_fu_128_p2 xor and_ln54_fu_152_p2);
    trunc_ln41_1_fu_282_p1 <= t_4_fu_236_p2(28 - 1 downto 0);
    trunc_ln41_2_fu_316_p1 <= t_3_fu_230_p2(61 - 1 downto 0);
    trunc_ln41_3_fu_338_p1 <= t_3_fu_230_p2(39 - 1 downto 0);
    trunc_ln41_4_fu_372_p1 <= t_6_fu_254_p2(1 - 1 downto 0);
    trunc_ln41_5_fu_394_p1 <= t_6_fu_254_p2(6 - 1 downto 0);
    trunc_ln41_6_fu_428_p1 <= t_5_fu_248_p2(10 - 1 downto 0);
    trunc_ln41_7_fu_450_p1 <= t_5_fu_248_p2(17 - 1 downto 0);
    trunc_ln41_8_fu_484_p1 <= t_2_fu_218_p2(7 - 1 downto 0);
    trunc_ln41_9_fu_506_p1 <= t_2_fu_218_p2(41 - 1 downto 0);
    trunc_ln41_fu_260_p1 <= t_4_fu_236_p2(19 - 1 downto 0);
    xor_ln47_fu_122_p2 <= (zext_ln47_fu_118_p1 xor s_x2_read);
    xor_ln50_fu_128_p2 <= (s_x4_read xor s_x0_read);
    xor_ln51_fu_134_p2 <= (s_x4_read xor s_x3_read);
    xor_ln52_fu_140_p2 <= (xor_ln47_fu_122_p2 xor s_x1_read);
    xor_ln54_fu_146_p2 <= (s_x1_read xor ap_const_lv64_FFFFFFFFFFFFFFFF);
    xor_ln55_fu_164_p2 <= (xor_ln52_fu_140_p2 xor ap_const_lv64_FFFFFFFFFFFFFFFF);
    xor_ln56_fu_176_p2 <= (s_x3_read xor ap_const_lv64_FFFFFFFFFFFFFFFF);
    xor_ln57_fu_194_p2 <= (xor_ln51_fu_134_p2 xor ap_const_lv64_FFFFFFFFFFFFFFFF);
    xor_ln58_fu_206_p2 <= (xor_ln50_fu_128_p2 xor ap_const_lv64_FFFFFFFFFFFFFFFF);
    xor_ln60_fu_224_p2 <= (t_fu_158_p2 xor s_x1_read);
    xor_ln62_fu_242_p2 <= (t_1_fu_188_p2 xor s_x3_read);
    xor_ln66_1_fu_310_p2 <= (xor_ln66_fu_304_p2 xor or_ln_fu_274_p3);
    xor_ln66_fu_304_p2 <= (t_4_fu_236_p2 xor or_ln41_1_fu_296_p3);
    xor_ln67_1_fu_366_p2 <= (xor_ln67_fu_360_p2 xor or_ln41_2_fu_330_p3);
    xor_ln67_fu_360_p2 <= (t_3_fu_230_p2 xor or_ln41_3_fu_352_p3);
    xor_ln68_1_fu_422_p2 <= (xor_ln68_fu_416_p2 xor or_ln41_4_fu_386_p3);
    xor_ln68_fu_416_p2 <= (t_6_fu_254_p2 xor or_ln41_5_fu_408_p3);
    xor_ln69_1_fu_478_p2 <= (xor_ln69_fu_472_p2 xor or_ln41_6_fu_442_p3);
    xor_ln69_fu_472_p2 <= (t_5_fu_248_p2 xor or_ln41_7_fu_464_p3);
    xor_ln70_1_fu_534_p2 <= (xor_ln70_fu_528_p2 xor or_ln41_8_fu_498_p3);
    xor_ln70_fu_528_p2 <= (t_2_fu_218_p2 xor or_ln41_9_fu_520_p3);
    zext_ln47_fu_118_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(C),64));
end behav;
