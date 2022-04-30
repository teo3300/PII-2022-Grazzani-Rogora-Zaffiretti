// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module crypto_aead_encrypt_crypto_aead_encrypt_Pipeline_VITIS_LOOP_27_1 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        n_assign,
        xor_ln69,
        m_addr_0_lcssa_idx,
        c_address0,
        c_ce0,
        c_we0,
        c_d0
);

parameter    ap_ST_fsm_state1 = 1'd1;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [31:0] n_assign;
input  [63:0] xor_ln69;
input  [5:0] m_addr_0_lcssa_idx;
output  [5:0] c_address0;
output   c_ce0;
output   c_we0;
output  [7:0] c_d0;

reg ap_idle;
reg c_ce0;
reg c_we0;

(* fsm_encoding = "none" *) reg   [0:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    ap_block_state1_pp0_stage0_iter0;
wire   [0:0] icmp_ln27_fu_83_p2;
reg    ap_condition_exit_pp0_iter0_stage0;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
wire   [63:0] zext_ln27_fu_132_p1;
reg   [31:0] i_1_fu_40;
wire   [31:0] add_ln27_3_fu_89_p2;
wire    ap_loop_init;
reg   [31:0] ap_sig_allocacmp_i;
wire   [31:0] shl_ln27_fu_99_p2;
wire   [31:0] sub_ln27_fu_105_p2;
wire   [63:0] zext_ln27_1_fu_111_p1;
wire   [63:0] lshr_ln27_fu_115_p2;
wire   [5:0] empty_fu_95_p1;
wire   [5:0] add_ln27_2_fu_126_p2;
reg    ap_done_reg;
wire    ap_continue_int;
reg    ap_done_int;
reg   [0:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
wire    ap_start_int;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 1'd1;
#0 ap_done_reg = 1'b0;
end

crypto_aead_encrypt_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_start_int(ap_start_int),
    .ap_loop_init(ap_loop_init),
    .ap_ready_int(ap_ready_int),
    .ap_loop_exit_ready(ap_condition_exit_pp0_iter0_stage0),
    .ap_loop_exit_done(ap_done_int),
    .ap_continue_int(ap_continue_int),
    .ap_done_int(ap_done_int)
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
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue_int == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((ap_loop_exit_ready == 1'b1) & (1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        if ((icmp_ln27_fu_83_p2 == 1'd0)) begin
            i_1_fu_40 <= add_ln27_3_fu_89_p2;
        end else if ((ap_loop_init == 1'b1)) begin
            i_1_fu_40 <= 32'd0;
        end
    end
end

always @ (*) begin
    if ((ap_start_int == 1'b0)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln27_fu_83_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        ap_condition_exit_pp0_iter0_stage0 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter0_stage0 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_loop_exit_ready == 1'b1) & (1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        ap_done_int = 1'b1;
    end else begin
        ap_done_int = ap_done_reg;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        ap_ready_int = 1'b1;
    end else begin
        ap_ready_int = 1'b0;
    end
end

always @ (*) begin
    if (((ap_loop_init == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_sig_allocacmp_i = 32'd0;
    end else begin
        ap_sig_allocacmp_i = i_1_fu_40;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        c_ce0 = 1'b1;
    end else begin
        c_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln27_fu_83_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        c_we0 = 1'b1;
    end else begin
        c_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln27_2_fu_126_p2 = (empty_fu_95_p1 + m_addr_0_lcssa_idx);

assign add_ln27_3_fu_89_p2 = (ap_sig_allocacmp_i + 32'd1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

always @ (*) begin
    ap_block_state1_pp0_stage0_iter0 = (ap_start_int == 1'b0);
end

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter0_stage0;

assign c_address0 = zext_ln27_fu_132_p1;

assign c_d0 = lshr_ln27_fu_115_p2[7:0];

assign empty_fu_95_p1 = ap_sig_allocacmp_i[5:0];

assign icmp_ln27_fu_83_p2 = ((ap_sig_allocacmp_i == n_assign) ? 1'b1 : 1'b0);

assign lshr_ln27_fu_115_p2 = xor_ln69 >> zext_ln27_1_fu_111_p1;

assign shl_ln27_fu_99_p2 = ap_sig_allocacmp_i << 32'd3;

assign sub_ln27_fu_105_p2 = (32'd56 - shl_ln27_fu_99_p2);

assign zext_ln27_1_fu_111_p1 = sub_ln27_fu_105_p2;

assign zext_ln27_fu_132_p1 = add_ln27_2_fu_126_p2;

endmodule //crypto_aead_encrypt_crypto_aead_encrypt_Pipeline_VITIS_LOOP_27_1
