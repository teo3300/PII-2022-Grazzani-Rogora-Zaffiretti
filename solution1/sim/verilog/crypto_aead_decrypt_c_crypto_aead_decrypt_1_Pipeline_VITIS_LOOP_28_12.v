// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module crypto_aead_decrypt_c_crypto_aead_decrypt_1_Pipeline_VITIS_LOOP_28_12 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        s_4_45,
        t_address0,
        t_ce0,
        t_we0,
        t_d0
);

parameter    ap_ST_fsm_state1 = 1'd1;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [63:0] s_4_45;
output  [3:0] t_address0;
output   t_ce0;
output   t_we0;
output  [7:0] t_d0;

reg ap_idle;
reg t_ce0;
reg t_we0;

(* fsm_encoding = "none" *) reg   [0:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    ap_block_state1_pp0_stage0_iter0;
wire   [0:0] icmp_ln28_fu_69_p2;
reg    ap_condition_exit_pp0_iter0_stage0;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
wire   [63:0] zext_ln28_1_fu_120_p1;
reg   [3:0] i_fu_38;
wire   [3:0] add_ln28_fu_75_p2;
wire    ap_loop_init;
reg   [3:0] ap_sig_allocacmp_i_2;
wire   [2:0] trunc_ln28_fu_81_p1;
wire   [5:0] shl_ln28_3_fu_85_p3;
wire   [5:0] sub_ln28_fu_93_p2;
wire   [63:0] zext_ln28_fu_99_p1;
wire   [63:0] lshr_ln28_fu_103_p2;
wire   [3:0] xor_ln28_fu_114_p2;
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

crypto_aead_decrypt_c_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
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
        if ((icmp_ln28_fu_69_p2 == 1'd0)) begin
            i_fu_38 <= add_ln28_fu_75_p2;
        end else if ((ap_loop_init == 1'b1)) begin
            i_fu_38 <= 4'd0;
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
    if (((icmp_ln28_fu_69_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
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
        ap_sig_allocacmp_i_2 = 4'd0;
    end else begin
        ap_sig_allocacmp_i_2 = i_fu_38;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        t_ce0 = 1'b1;
    end else begin
        t_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln28_fu_69_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1) & (ap_start_int == 1'b1))) begin
        t_we0 = 1'b1;
    end else begin
        t_we0 = 1'b0;
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

assign add_ln28_fu_75_p2 = (ap_sig_allocacmp_i_2 + 4'd1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

always @ (*) begin
    ap_block_state1_pp0_stage0_iter0 = (ap_start_int == 1'b0);
end

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter0_stage0;

assign icmp_ln28_fu_69_p2 = ((ap_sig_allocacmp_i_2 == 4'd8) ? 1'b1 : 1'b0);

assign lshr_ln28_fu_103_p2 = s_4_45 >> zext_ln28_fu_99_p1;

assign shl_ln28_3_fu_85_p3 = {{trunc_ln28_fu_81_p1}, {3'd0}};

assign sub_ln28_fu_93_p2 = ($signed(6'd56) - $signed(shl_ln28_3_fu_85_p3));

assign t_address0 = zext_ln28_1_fu_120_p1;

assign t_d0 = lshr_ln28_fu_103_p2[7:0];

assign trunc_ln28_fu_81_p1 = ap_sig_allocacmp_i_2[2:0];

assign xor_ln28_fu_114_p2 = (ap_sig_allocacmp_i_2 ^ 4'd8);

assign zext_ln28_1_fu_120_p1 = xor_ln28_fu_114_p2;

assign zext_ln28_fu_99_p1 = sub_ln28_fu_93_p2;

endmodule //crypto_aead_decrypt_c_crypto_aead_decrypt_1_Pipeline_VITIS_LOOP_28_12
