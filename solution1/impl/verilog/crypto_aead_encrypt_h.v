// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="crypto_aead_encrypt_h_crypto_aead_encrypt_h,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7k160t-fbv484-2,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=3.858400,HLS_SYN_LAT=22,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=464,HLS_SYN_LUT=1521,HLS_VERSION=2021_2}" *)

module crypto_aead_encrypt_h (
        ap_local_block,
        ap_local_deadlock,
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        c,
        clen,
        clen_ap_vld,
        m,
        mlen,
        ad,
        adlen,
        nsec,
        npub,
        k,
        st_address0,
        st_ce0,
        st_we0,
        st_d0,
        ap_return
);

parameter    ap_ST_fsm_state1 = 6'd1;
parameter    ap_ST_fsm_state2 = 6'd2;
parameter    ap_ST_fsm_state3 = 6'd4;
parameter    ap_ST_fsm_state4 = 6'd8;
parameter    ap_ST_fsm_state5 = 6'd16;
parameter    ap_ST_fsm_state6 = 6'd32;

output   ap_local_block;
output   ap_local_deadlock;
input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [7:0] c;
output  [63:0] clen;
output   clen_ap_vld;
input  [7:0] m;
input  [63:0] mlen;
input  [7:0] ad;
input  [63:0] adlen;
input  [7:0] nsec;
input  [7:0] npub;
input  [7:0] k;
output  [2:0] st_address0;
output   st_ce0;
output   st_we0;
output  [63:0] st_d0;
output  [31:0] ap_return;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg clen_ap_vld;

(* fsm_encoding = "none" *) reg   [5:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg   [2:0] s_address0;
reg    s_ce0;
reg    s_we0;
reg   [63:0] s_d0;
wire   [63:0] s_q0;
reg   [2:0] s_address1;
reg    s_ce1;
reg    s_we1;
reg   [63:0] s_d1;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_done;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_idle;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_ready;
wire   [63:0] grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_x_out;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_x_out_ap_vld;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_done;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_idle;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_ready;
wire   [63:0] grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_x_2_out;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_x_2_out_ap_vld;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_done;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_idle;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_ready;
wire   [63:0] grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_x_4_out;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_x_4_out_ap_vld;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_done;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_idle;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_ready;
wire   [63:0] grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_x_6_out;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_x_6_out_ap_vld;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_done;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_idle;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_ready;
wire   [2:0] grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_s_address0;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_s_ce0;
wire   [2:0] grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_address0;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_ce0;
wire    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_we0;
wire   [63:0] grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_d0;
reg    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start_reg;
wire    ap_CS_fsm_state2;
reg    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start_reg;
reg    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start_reg;
reg    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start_reg;
reg    grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start_reg;
wire    ap_CS_fsm_state5;
wire    ap_CS_fsm_state6;
wire    ap_CS_fsm_state3;
wire    ap_CS_fsm_state4;
reg    ap_block_state2_on_subcall_done;
reg   [5:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
reg    ap_ST_fsm_state2_blk;
wire    ap_ST_fsm_state3_blk;
wire    ap_ST_fsm_state4_blk;
wire    ap_ST_fsm_state5_blk;
reg    ap_ST_fsm_state6_blk;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 6'd1;
#0 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start_reg = 1'b0;
#0 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start_reg = 1'b0;
#0 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start_reg = 1'b0;
#0 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start_reg = 1'b0;
#0 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start_reg = 1'b0;
end

crypto_aead_encrypt_h_s_RAM_AUTO_1R1W #(
    .DataWidth( 64 ),
    .AddressRange( 5 ),
    .AddressWidth( 3 ))
s_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(s_address0),
    .ce0(s_ce0),
    .we0(s_we0),
    .d0(s_d0),
    .q0(s_q0),
    .address1(s_address1),
    .ce1(s_ce1),
    .we1(s_we1),
    .d1(s_d1)
);

crypto_aead_encrypt_h_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start),
    .ap_done(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_done),
    .ap_idle(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_idle),
    .ap_ready(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_ready),
    .zext_ln21(k),
    .x_out(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_x_out),
    .x_out_ap_vld(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_x_out_ap_vld)
);

crypto_aead_encrypt_h_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start),
    .ap_done(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_done),
    .ap_idle(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_idle),
    .ap_ready(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_ready),
    .zext_ln21(k),
    .x_2_out(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_x_2_out),
    .x_2_out_ap_vld(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_x_2_out_ap_vld)
);

crypto_aead_encrypt_h_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start),
    .ap_done(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_done),
    .ap_idle(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_idle),
    .ap_ready(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_ready),
    .zext_ln21_1(npub),
    .x_4_out(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_x_4_out),
    .x_4_out_ap_vld(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_x_4_out_ap_vld)
);

crypto_aead_encrypt_h_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start),
    .ap_done(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_done),
    .ap_idle(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_idle),
    .ap_ready(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_ready),
    .zext_ln21_1(npub),
    .x_6_out(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_x_6_out),
    .x_6_out_ap_vld(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_x_6_out_ap_vld)
);

crypto_aead_encrypt_h_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1 grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start),
    .ap_done(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_done),
    .ap_idle(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_idle),
    .ap_ready(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_ready),
    .s_address0(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_s_address0),
    .s_ce0(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_s_ce0),
    .s_q0(s_q0),
    .st_address0(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_address0),
    .st_ce0(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_ce0),
    .st_we0(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_we0),
    .st_d0(grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_d0)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state5)) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start_reg <= 1'b1;
        end else if ((grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_ready == 1'b1)) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start_reg <= 1'b1;
        end else if ((grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_ready == 1'b1)) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start_reg <= 1'b1;
        end else if ((grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_ready == 1'b1)) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start_reg <= 1'b1;
        end else if ((grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_ready == 1'b1)) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start_reg <= 1'b1;
        end else if ((grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_ready == 1'b1)) begin
            grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start_reg <= 1'b0;
        end
    end
end

always @ (*) begin
    if ((ap_start == 1'b0)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_block_state2_on_subcall_done)) begin
        ap_ST_fsm_state2_blk = 1'b1;
    end else begin
        ap_ST_fsm_state2_blk = 1'b0;
    end
end

assign ap_ST_fsm_state3_blk = 1'b0;

assign ap_ST_fsm_state4_blk = 1'b0;

assign ap_ST_fsm_state5_blk = 1'b0;

always @ (*) begin
    if ((grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_done == 1'b0)) begin
        ap_ST_fsm_state6_blk = 1'b1;
    end else begin
        ap_ST_fsm_state6_blk = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) & (grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_done == 1'b1))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) & (grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_done == 1'b1))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) & (grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_done == 1'b1))) begin
        clen_ap_vld = 1'b1;
    end else begin
        clen_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        s_address0 = 64'd3;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        s_address0 = 64'd2;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        s_address0 = 64'd0;
    end else if ((1'b1 == ap_CS_fsm_state6)) begin
        s_address0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_s_address0;
    end else begin
        s_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        s_address1 = 64'd4;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        s_address1 = 64'd1;
    end else begin
        s_address1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3) | ((1'b1 == ap_CS_fsm_state2) & (1'b0 == ap_block_state2_on_subcall_done)))) begin
        s_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state6)) begin
        s_ce0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_s_ce0;
    end else begin
        s_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3))) begin
        s_ce1 = 1'b1;
    end else begin
        s_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        s_d0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_x_4_out;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        s_d0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_x_2_out;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        s_d0 = 64'd9241399655273594880;
    end else begin
        s_d0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        s_d1 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_x_6_out;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        s_d1 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_x_out;
    end else begin
        s_d1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3) | ((1'b1 == ap_CS_fsm_state2) & (1'b0 == ap_block_state2_on_subcall_done)))) begin
        s_we0 = 1'b1;
    end else begin
        s_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3))) begin
        s_we1 = 1'b1;
    end else begin
        s_we1 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((1'b1 == ap_CS_fsm_state2) & (1'b0 == ap_block_state2_on_subcall_done))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state6 : begin
            if (((1'b1 == ap_CS_fsm_state6) & (grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_done == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

always @ (*) begin
    ap_block_state2_on_subcall_done = ((grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_done == 1'b0) | (grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_done == 1'b0) | (grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_done == 1'b0) | (grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_done == 1'b0));
end

assign ap_local_block = 1'b0;

assign ap_local_deadlock = 1'b0;

assign ap_return = 32'd0;

assign clen = (mlen + 64'd16);

assign grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_ap_start_reg;

assign grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_12_fu_170_ap_start_reg;

assign grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_13_fu_177_ap_start_reg;

assign grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_14_fu_184_ap_start_reg;

assign grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_21_1_fu_163_ap_start_reg;

assign st_address0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_address0;

assign st_ce0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_ce0;

assign st_d0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_d0;

assign st_we0 = grp_crypto_aead_encrypt_h_Pipeline_VITIS_LOOP_13_1_fu_191_st_we0;

endmodule //crypto_aead_encrypt_h
