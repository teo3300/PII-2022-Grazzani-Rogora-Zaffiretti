// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
 `timescale 1ns/1ps


`define AUTOTB_DUT      crypto_aead_decrypt_c
`define AUTOTB_DUT_INST AESL_inst_crypto_aead_decrypt_c
`define AUTOTB_TOP      apatb_crypto_aead_decrypt_c_top
`define AUTOTB_LAT_RESULT_FILE "crypto_aead_decrypt_c.result.lat.rb"
`define AUTOTB_PER_RESULT_TRANS_FILE "crypto_aead_decrypt_c.performance.result.transaction.xml"
`define AUTOTB_TOP_INST AESL_inst_apatb_crypto_aead_decrypt_c_top
`define AUTOTB_MAX_ALLOW_LATENCY  15000000
`define AUTOTB_CLOCK_PERIOD_DIV2 5.00

`define AESL_MEM_m AESL_automem_m
`define AESL_MEM_INST_m mem_inst_m
`define AESL_DEPTH_mlen 1
`define AESL_DEPTH_nsec 1
`define AESL_MEM_c AESL_automem_c
`define AESL_MEM_INST_c mem_inst_c
`define AESL_DEPTH_clen 1
`define AESL_MEM_ad AESL_automem_ad
`define AESL_MEM_INST_ad mem_inst_ad
`define AESL_DEPTH_adlen 1
`define AESL_MEM_npub AESL_automem_npub
`define AESL_MEM_INST_npub mem_inst_npub
`define AESL_MEM_k AESL_automem_k
`define AESL_MEM_INST_k mem_inst_k
`define AUTOTB_TVIN_m  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvin_m.dat"
`define AUTOTB_TVIN_c  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvin_c.dat"
`define AUTOTB_TVIN_clen  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvin_clen.dat"
`define AUTOTB_TVIN_ad  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvin_ad.dat"
`define AUTOTB_TVIN_adlen  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvin_adlen.dat"
`define AUTOTB_TVIN_npub  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvin_npub.dat"
`define AUTOTB_TVIN_k  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvin_k.dat"
`define AUTOTB_TVIN_m_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvin_m.dat"
`define AUTOTB_TVIN_c_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvin_c.dat"
`define AUTOTB_TVIN_clen_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvin_clen.dat"
`define AUTOTB_TVIN_ad_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvin_ad.dat"
`define AUTOTB_TVIN_adlen_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvin_adlen.dat"
`define AUTOTB_TVIN_npub_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvin_npub.dat"
`define AUTOTB_TVIN_k_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvin_k.dat"
`define AUTOTB_TVOUT_m  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvout_m.dat"
`define AUTOTB_TVOUT_mlen  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvout_mlen.dat"
`define AUTOTB_TVOUT_ap_return  "../tv/cdatafile/c.crypto_aead_decrypt_c.autotvout_ap_return.dat"
`define AUTOTB_TVOUT_m_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvout_m.dat"
`define AUTOTB_TVOUT_mlen_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvout_mlen.dat"
`define AUTOTB_TVOUT_ap_return_out_wrapc  "../tv/rtldatafile/rtl.crypto_aead_decrypt_c.autotvout_ap_return.dat"
module `AUTOTB_TOP;

parameter AUTOTB_TRANSACTION_NUM = 1089;
parameter PROGRESS_TIMEOUT = 10000000;
parameter LATENCY_ESTIMATION = -1;
parameter LENGTH_m = 32;
parameter LENGTH_mlen = 1;
parameter LENGTH_nsec = 1;
parameter LENGTH_c = 48;
parameter LENGTH_clen = 1;
parameter LENGTH_ad = 32;
parameter LENGTH_adlen = 1;
parameter LENGTH_npub = 16;
parameter LENGTH_k = 16;
parameter LENGTH_ap_return = 1;

task read_token;
    input integer fp;
    output reg [159 : 0] token;
    integer ret;
    begin
        token = "";
        ret = 0;
        ret = $fscanf(fp,"%s",token);
    end
endtask

reg AESL_clock;
reg rst;
reg dut_rst;
reg start;
reg ce;
reg tb_continue;
wire AESL_start;
wire AESL_reset;
wire AESL_ce;
wire AESL_ready;
wire AESL_idle;
wire AESL_continue;
wire AESL_done;
reg AESL_done_delay = 0;
reg AESL_done_delay2 = 0;
reg AESL_ready_delay = 0;
wire ready;
wire ready_wire;
wire  ap_local_block;
wire  ap_local_deadlock;
wire ap_start;
wire ap_done;
wire ap_idle;
wire ap_ready;
wire [4 : 0] m_address0;
wire  m_ce0;
wire  m_we0;
wire [7 : 0] m_d0;
wire [63 : 0] mlen;
wire  mlen_ap_vld;
wire [7 : 0] nsec;
wire [5 : 0] c_address0;
wire  c_ce0;
wire [7 : 0] c_q0;
wire [63 : 0] clen;
wire [4 : 0] ad_address0;
wire  ad_ce0;
wire [7 : 0] ad_q0;
wire [63 : 0] adlen;
wire [3 : 0] npub_address0;
wire  npub_ce0;
wire [7 : 0] npub_q0;
wire [3 : 0] k_address0;
wire  k_ce0;
wire [7 : 0] k_q0;
wire [31 : 0] ap_return;
integer done_cnt = 0;
integer AESL_ready_cnt = 0;
integer ready_cnt = 0;
reg ready_initial;
reg ready_initial_n;
reg ready_last_n;
reg ready_delay_last_n;
reg done_delay_last_n;
reg interface_done = 0;


wire ap_clk;
wire ap_rst;
wire ap_rst_n;

`AUTOTB_DUT `AUTOTB_DUT_INST(
    .ap_local_block(ap_local_block),
    .ap_local_deadlock(ap_local_deadlock),
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .ap_ready(ap_ready),
    .m_address0(m_address0),
    .m_ce0(m_ce0),
    .m_we0(m_we0),
    .m_d0(m_d0),
    .mlen(mlen),
    .mlen_ap_vld(mlen_ap_vld),
    .nsec(nsec),
    .c_address0(c_address0),
    .c_ce0(c_ce0),
    .c_q0(c_q0),
    .clen(clen),
    .ad_address0(ad_address0),
    .ad_ce0(ad_ce0),
    .ad_q0(ad_q0),
    .adlen(adlen),
    .npub_address0(npub_address0),
    .npub_ce0(npub_ce0),
    .npub_q0(npub_q0),
    .k_address0(k_address0),
    .k_ce0(k_ce0),
    .k_q0(k_q0),
    .ap_return(ap_return));

// Assignment for control signal
assign ap_clk = AESL_clock;
assign ap_rst = dut_rst;
assign ap_rst_n = ~dut_rst;
assign AESL_reset = rst;
assign ap_start = AESL_start;
assign AESL_start = start;
assign AESL_done = ap_done;
assign AESL_idle = ap_idle;
assign AESL_ready = ap_ready;
assign AESL_ce = ce;
assign AESL_continue = tb_continue;
    always @(posedge AESL_clock) begin
        if (AESL_reset) begin
        end else begin
            if (AESL_done !== 1 && AESL_done !== 0) begin
                $display("ERROR: Control signal AESL_done is invalid!");
                $finish;
            end
        end
    end
    always @(posedge AESL_clock) begin
        if (AESL_reset) begin
        end else begin
            if (AESL_ready !== 1 && AESL_ready !== 0) begin
                $display("ERROR: Control signal AESL_ready is invalid!");
                $finish;
            end
        end
    end
//------------------------arraym Instantiation--------------

// The input and output of arraym
wire    arraym_ce0, arraym_ce1;
wire [1 - 1 : 0]    arraym_we0, arraym_we1;
wire    [4 : 0]    arraym_address0, arraym_address1;
wire    [7 : 0]    arraym_din0, arraym_din1;
wire    [7 : 0]    arraym_dout0, arraym_dout1;
wire    arraym_ready;
wire    arraym_done;

`AESL_MEM_m `AESL_MEM_INST_m(
    .clk        (AESL_clock),
    .rst        (AESL_reset),
    .ce0        (arraym_ce0),
    .we0        (arraym_we0),
    .address0   (arraym_address0),
    .din0       (arraym_din0),
    .dout0      (arraym_dout0),
    .ce1        (arraym_ce1),
    .we1        (arraym_we1),
    .address1   (arraym_address1),
    .din1       (arraym_din1),
    .dout1      (arraym_dout1),
    .ready      (arraym_ready),
    .done    (arraym_done)
);

// Assignment between dut and arraym
assign arraym_address0 = m_address0;
assign arraym_ce0 = m_ce0;
assign arraym_we0[0] = m_we0;
assign arraym_din0 = m_d0;
assign arraym_we1 = 0;
assign arraym_din1 = 0;
assign arraym_ready= ready_initial | arraym_done;
assign arraym_done =    AESL_done_delay;


reg AESL_REG_mlen_ap_vld = 0;
// The signal of port mlen
reg [63: 0] AESL_REG_mlen = 0;
always @(posedge AESL_clock)
begin
    if(AESL_reset)
        AESL_REG_mlen = 0; 
    else if(mlen_ap_vld) begin
        AESL_REG_mlen <= mlen;
        AESL_REG_mlen_ap_vld <= 1;
    end
end 

initial begin : write_file_process_mlen
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer mlen_count;
    reg [159:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_mlen_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_mlen_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        # 0.4;
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
        if(AESL_REG_mlen_ap_vld)  begin
          $fdisplay(fp,"0x%x", AESL_REG_mlen);
        AESL_REG_mlen_ap_vld = 0;
        end
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end


// The signal of port nsec
reg [7: 0] AESL_REG_nsec = 0;
assign nsec = AESL_REG_nsec;

//------------------------arrayc Instantiation--------------

// The input and output of arrayc
wire    arrayc_ce0, arrayc_ce1;
wire [1 - 1 : 0]    arrayc_we0, arrayc_we1;
wire    [5 : 0]    arrayc_address0, arrayc_address1;
wire    [7 : 0]    arrayc_din0, arrayc_din1;
wire    [7 : 0]    arrayc_dout0, arrayc_dout1;
wire    arrayc_ready;
wire    arrayc_done;

`AESL_MEM_c `AESL_MEM_INST_c(
    .clk        (AESL_clock),
    .rst        (AESL_reset),
    .ce0        (arrayc_ce0),
    .we0        (arrayc_we0),
    .address0   (arrayc_address0),
    .din0       (arrayc_din0),
    .dout0      (arrayc_dout0),
    .ce1        (arrayc_ce1),
    .we1        (arrayc_we1),
    .address1   (arrayc_address1),
    .din1       (arrayc_din1),
    .dout1      (arrayc_dout1),
    .ready      (arrayc_ready),
    .done    (arrayc_done)
);

// Assignment between dut and arrayc
assign arrayc_address0 = c_address0;
assign arrayc_ce0 = c_ce0;
assign c_q0 = arrayc_dout0;
assign arrayc_we0 = 0;
assign arrayc_din0 = 0;
assign arrayc_we1 = 0;
assign arrayc_din1 = 0;
assign arrayc_ready=    ready;
assign arrayc_done = 0;


// The signal of port clen
reg [63: 0] AESL_REG_clen = 0;
assign clen = AESL_REG_clen;
initial begin : read_file_process_clen
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [159  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_clen,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_clen);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_clen);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


//------------------------arrayad Instantiation--------------

// The input and output of arrayad
wire    arrayad_ce0, arrayad_ce1;
wire [1 - 1 : 0]    arrayad_we0, arrayad_we1;
wire    [4 : 0]    arrayad_address0, arrayad_address1;
wire    [7 : 0]    arrayad_din0, arrayad_din1;
wire    [7 : 0]    arrayad_dout0, arrayad_dout1;
wire    arrayad_ready;
wire    arrayad_done;

`AESL_MEM_ad `AESL_MEM_INST_ad(
    .clk        (AESL_clock),
    .rst        (AESL_reset),
    .ce0        (arrayad_ce0),
    .we0        (arrayad_we0),
    .address0   (arrayad_address0),
    .din0       (arrayad_din0),
    .dout0      (arrayad_dout0),
    .ce1        (arrayad_ce1),
    .we1        (arrayad_we1),
    .address1   (arrayad_address1),
    .din1       (arrayad_din1),
    .dout1      (arrayad_dout1),
    .ready      (arrayad_ready),
    .done    (arrayad_done)
);

// Assignment between dut and arrayad
assign arrayad_address0 = ad_address0;
assign arrayad_ce0 = ad_ce0;
assign ad_q0 = arrayad_dout0;
assign arrayad_we0 = 0;
assign arrayad_din0 = 0;
assign arrayad_we1 = 0;
assign arrayad_din1 = 0;
assign arrayad_ready=    ready;
assign arrayad_done = 0;


// The signal of port adlen
reg [63: 0] AESL_REG_adlen = 0;
assign adlen = AESL_REG_adlen;
initial begin : read_file_process_adlen
    integer fp;
    integer err;
    integer ret;
    integer proc_rand;
    reg [159  : 0] token;
    integer i;
    reg transaction_finish;
    integer transaction_idx;
    transaction_idx = 0;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVIN_adlen,"r");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVIN_adlen);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    if (token != "[[[runtime]]]") begin
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    read_token(fp, token);
    while (token != "[[[/runtime]]]") begin
        if (token != "[[transaction]]") begin
            $display("ERROR: Simulation using HLS TB failed.");
              $finish;
        end
        read_token(fp, token);  // skip transaction number
          read_token(fp, token);
            # 0.2;
            while(ready_wire !== 1) begin
                @(posedge AESL_clock);
                # 0.2;
            end
        if(token != "[[/transaction]]") begin
            ret = $sscanf(token, "0x%x", AESL_REG_adlen);
              if (ret != 1) begin
                  $display("Failed to parse token!");
                $display("ERROR: Simulation using HLS TB failed.");
                  $finish;
              end
            @(posedge AESL_clock);
              read_token(fp, token);
        end
          read_token(fp, token);
    end
    $fclose(fp);
end


//------------------------arraynpub Instantiation--------------

// The input and output of arraynpub
wire    arraynpub_ce0, arraynpub_ce1;
wire [1 - 1 : 0]    arraynpub_we0, arraynpub_we1;
wire    [3 : 0]    arraynpub_address0, arraynpub_address1;
wire    [7 : 0]    arraynpub_din0, arraynpub_din1;
wire    [7 : 0]    arraynpub_dout0, arraynpub_dout1;
wire    arraynpub_ready;
wire    arraynpub_done;

`AESL_MEM_npub `AESL_MEM_INST_npub(
    .clk        (AESL_clock),
    .rst        (AESL_reset),
    .ce0        (arraynpub_ce0),
    .we0        (arraynpub_we0),
    .address0   (arraynpub_address0),
    .din0       (arraynpub_din0),
    .dout0      (arraynpub_dout0),
    .ce1        (arraynpub_ce1),
    .we1        (arraynpub_we1),
    .address1   (arraynpub_address1),
    .din1       (arraynpub_din1),
    .dout1      (arraynpub_dout1),
    .ready      (arraynpub_ready),
    .done    (arraynpub_done)
);

// Assignment between dut and arraynpub
assign arraynpub_address0 = npub_address0;
assign arraynpub_ce0 = npub_ce0;
assign npub_q0 = arraynpub_dout0;
assign arraynpub_we0 = 0;
assign arraynpub_din0 = 0;
assign arraynpub_we1 = 0;
assign arraynpub_din1 = 0;
assign arraynpub_ready=    ready;
assign arraynpub_done = 0;


//------------------------arrayk Instantiation--------------

// The input and output of arrayk
wire    arrayk_ce0, arrayk_ce1;
wire [1 - 1 : 0]    arrayk_we0, arrayk_we1;
wire    [3 : 0]    arrayk_address0, arrayk_address1;
wire    [7 : 0]    arrayk_din0, arrayk_din1;
wire    [7 : 0]    arrayk_dout0, arrayk_dout1;
wire    arrayk_ready;
wire    arrayk_done;

`AESL_MEM_k `AESL_MEM_INST_k(
    .clk        (AESL_clock),
    .rst        (AESL_reset),
    .ce0        (arrayk_ce0),
    .we0        (arrayk_we0),
    .address0   (arrayk_address0),
    .din0       (arrayk_din0),
    .dout0      (arrayk_dout0),
    .ce1        (arrayk_ce1),
    .we1        (arrayk_we1),
    .address1   (arrayk_address1),
    .din1       (arrayk_din1),
    .dout1      (arrayk_dout1),
    .ready      (arrayk_ready),
    .done    (arrayk_done)
);

// Assignment between dut and arrayk
assign arrayk_address0 = k_address0;
assign arrayk_ce0 = k_ce0;
assign k_q0 = arrayk_dout0;
assign arrayk_we0 = 0;
assign arrayk_din0 = 0;
assign arrayk_we1 = 0;
assign arrayk_din1 = 0;
assign arrayk_ready=    ready;
assign arrayk_done = 0;


initial begin : write_file_process_ap_return
    integer fp;
    integer fp_size;
    integer err;
    integer ret;
    integer i;
    integer hls_stream_size;
    integer proc_rand;
    integer ap_return_count;
    reg [159:0] token;
    integer transaction_idx;
    reg [8 * 5:1] str;
    wait(AESL_reset === 0);
    fp = $fopen(`AUTOTB_TVOUT_ap_return_out_wrapc,"w");
    if(fp == 0) begin       // Failed to open file
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_ap_return_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fdisplay(fp,"[[[runtime]]]");
    transaction_idx = 0;
    while (transaction_idx != AUTOTB_TRANSACTION_NUM) begin
        @(posedge AESL_clock);
          while(AESL_done !== 1) begin
              @(posedge AESL_clock);
          end
        $fdisplay(fp,"[[transaction]] %d", transaction_idx);
          $fdisplay(fp,"0x%x", ap_return);
    transaction_idx = transaction_idx + 1;
      $fdisplay(fp,"[[/transaction]]");
    end
    $fdisplay(fp,"[[[/runtime]]]");
    $fclose(fp);
end

initial begin : generate_AESL_ready_cnt_proc
    AESL_ready_cnt = 0;
    wait(AESL_reset === 0);
    while(AESL_ready_cnt != AUTOTB_TRANSACTION_NUM) begin
        while(AESL_ready !== 1) begin
            @(posedge AESL_clock);
            # 0.4;
        end
        @(negedge AESL_clock);
        AESL_ready_cnt = AESL_ready_cnt + 1;
        @(posedge AESL_clock);
        # 0.4;
    end
end

    event next_trigger_ready_cnt;
    
    initial begin : gen_ready_cnt
        ready_cnt = 0;
        wait (AESL_reset === 0);
        forever begin
            @ (posedge AESL_clock);
            if (ready == 1) begin
                if (ready_cnt < AUTOTB_TRANSACTION_NUM) begin
                    ready_cnt = ready_cnt + 1;
                end
            end
            -> next_trigger_ready_cnt;
        end
    end
    
    wire all_finish = (done_cnt == AUTOTB_TRANSACTION_NUM);
    
    // done_cnt
    always @ (posedge AESL_clock) begin
        if (AESL_reset) begin
            done_cnt <= 0;
        end else begin
            if (AESL_done == 1) begin
                if (done_cnt < AUTOTB_TRANSACTION_NUM) begin
                    done_cnt <= done_cnt + 1;
                end
            end
        end
    end
    
    initial begin : finish_simulation
        wait (all_finish == 1);
        // last transaction is saved at negedge right after last done
        repeat(6) @ (posedge AESL_clock);
        $finish;
    end
    
initial begin
    AESL_clock = 0;
    forever #`AUTOTB_CLOCK_PERIOD_DIV2 AESL_clock = ~AESL_clock;
end


reg end_m;
reg [31:0] size_m;
reg [31:0] size_m_backup;
reg end_c;
reg [31:0] size_c;
reg [31:0] size_c_backup;
reg end_clen;
reg [31:0] size_clen;
reg [31:0] size_clen_backup;
reg end_ad;
reg [31:0] size_ad;
reg [31:0] size_ad_backup;
reg end_adlen;
reg [31:0] size_adlen;
reg [31:0] size_adlen_backup;
reg end_npub;
reg [31:0] size_npub;
reg [31:0] size_npub_backup;
reg end_k;
reg [31:0] size_k;
reg [31:0] size_k_backup;
reg end_mlen;
reg [31:0] size_mlen;
reg [31:0] size_mlen_backup;
reg end_ap_return;
reg [31:0] size_ap_return;
reg [31:0] size_ap_return_backup;

initial begin : initial_process
    integer proc_rand;
    rst = 1;
    # 100;
    repeat(0+3) @ (posedge AESL_clock);
    rst = 0;
end
initial begin : initial_process_for_dut_rst
    integer proc_rand;
    dut_rst = 1;
    # 100;
    repeat(3) @ (posedge AESL_clock);
    dut_rst = 0;
end
initial begin : start_process
    integer proc_rand;
    reg [31:0] start_cnt;
    ce = 1;
    start = 0;
    start_cnt = 0;
    wait (AESL_reset === 0);
    @ (posedge AESL_clock);
    #0 start = 1;
    start_cnt = start_cnt + 1;
    forever begin
        if (start_cnt >= AUTOTB_TRANSACTION_NUM + 1) begin
            #0 start = 0;
        end
        @ (posedge AESL_clock);
        if (AESL_ready) begin
            start_cnt = start_cnt + 1;
        end
    end
end

always @(AESL_done)
begin
    tb_continue = AESL_done;
end

initial begin : ready_initial_process
    ready_initial = 0;
    wait (AESL_start === 1);
    ready_initial = 1;
    @(posedge AESL_clock);
    ready_initial = 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
      AESL_ready_delay = 0;
  else
      AESL_ready_delay = AESL_ready;
end
initial begin : ready_last_n_process
  ready_last_n = 1;
  wait(ready_cnt == AUTOTB_TRANSACTION_NUM)
  @(posedge AESL_clock);
  ready_last_n <= 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
      ready_delay_last_n = 0;
  else
      ready_delay_last_n <= ready_last_n;
end
assign ready = (ready_initial | AESL_ready_delay);
assign ready_wire = ready_initial | AESL_ready_delay;
initial begin : done_delay_last_n_process
  done_delay_last_n = 1;
  while(done_cnt < AUTOTB_TRANSACTION_NUM)
      @(posedge AESL_clock);
  # 0.1;
  done_delay_last_n = 0;
end

always @(posedge AESL_clock)
begin
    if(AESL_reset)
  begin
      AESL_done_delay <= 0;
      AESL_done_delay2 <= 0;
  end
  else begin
      AESL_done_delay <= AESL_done & done_delay_last_n;
      AESL_done_delay2 <= AESL_done_delay;
  end
end
always @(posedge AESL_clock)
begin
    if(AESL_reset)
      interface_done = 0;
  else begin
      # 0.01;
      if(ready === 1 && ready_cnt > 0 && ready_cnt < AUTOTB_TRANSACTION_NUM)
          interface_done = 1;
      else if(AESL_done_delay === 1 && done_cnt == AUTOTB_TRANSACTION_NUM)
          interface_done = 1;
      else
          interface_done = 0;
  end
end
task write_binary;
    input integer fp;
    input reg[64-1:0] in;
    input integer in_bw;
    reg [63:0] tmp_long;
    reg[64-1:0] local_in;
    integer char_num;
    integer long_num;
    integer i;
    integer j;
    begin
        long_num = (in_bw + 63) / 64;
        char_num = ((in_bw - 1) % 64 + 7) / 8;
        for(i=long_num;i>0;i=i-1) begin
             local_in = in;
             tmp_long = local_in >> ((i-1)*64);
             for(j=0;j<64;j=j+1)
                 if (tmp_long[j] === 1'bx)
                     tmp_long[j] = 1'b0;
             if (i == long_num) begin
                 case(char_num)
                     1: $fwrite(fp,"%c",tmp_long[7:0]);
                     2: $fwrite(fp,"%c%c",tmp_long[15:8],tmp_long[7:0]);
                     3: $fwrite(fp,"%c%c%c",tmp_long[23:16],tmp_long[15:8],tmp_long[7:0]);
                     4: $fwrite(fp,"%c%c%c%c",tmp_long[31:24],tmp_long[23:16],tmp_long[15:8],tmp_long[7:0]);
                     5: $fwrite(fp,"%c%c%c%c%c",tmp_long[39:32],tmp_long[31:24],tmp_long[23:16],tmp_long[15:8],tmp_long[7:0]);
                     6: $fwrite(fp,"%c%c%c%c%c%c",tmp_long[47:40],tmp_long[39:32],tmp_long[31:24],tmp_long[23:16],tmp_long[15:8],tmp_long[7:0]);
                     7: $fwrite(fp,"%c%c%c%c%c%c%c",tmp_long[55:48],tmp_long[47:40],tmp_long[39:32],tmp_long[31:24],tmp_long[23:16],tmp_long[15:8],tmp_long[7:0]);
                     8: $fwrite(fp,"%c%c%c%c%c%c%c%c",tmp_long[63:56],tmp_long[55:48],tmp_long[47:40],tmp_long[39:32],tmp_long[31:24],tmp_long[23:16],tmp_long[15:8],tmp_long[7:0]);
                     default: ;
                 endcase
             end
             else begin
                 $fwrite(fp,"%c%c%c%c%c%c%c%c",tmp_long[63:56],tmp_long[55:48],tmp_long[47:40],tmp_long[39:32],tmp_long[31:24],tmp_long[23:16],tmp_long[15:8],tmp_long[7:0]);
             end
        end
    end
endtask;

reg dump_tvout_finish_m;

initial begin : dump_tvout_runtime_sign_m
    integer fp;
    dump_tvout_finish_m = 0;
    fp = $fopen(`AUTOTB_TVOUT_m_out_wrapc, "wb");
    if (fp == 0) begin
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_m_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    $fclose(fp);
    wait (done_cnt == AUTOTB_TRANSACTION_NUM);
    repeat(5) @ (posedge AESL_clock);
    fp = $fopen(`AUTOTB_TVOUT_m_out_wrapc, "ab");
    if (fp == 0) begin
        $display("Failed to open file \"%s\"!", `AUTOTB_TVOUT_m_out_wrapc);
        $display("ERROR: Simulation using HLS TB failed.");
        $finish;
    end
    write_binary(fp,64'h5a5aa5a50f0ff0f0,64);
    $fclose(fp);
    repeat(5) @ (posedge AESL_clock);
    dump_tvout_finish_m = 1;
end


////////////////////////////////////////////
// progress and performance
////////////////////////////////////////////

task wait_start();
    while (~AESL_start) begin
        @ (posedge AESL_clock);
    end
endtask

reg [31:0] clk_cnt = 0;
reg AESL_ready_p1;
reg AESL_start_p1;

always @ (posedge AESL_clock) begin
    if (AESL_reset == 1) begin
        clk_cnt <= 32'h0;
        AESL_ready_p1 <= 1'b0;
        AESL_start_p1 <= 1'b0;
    end
    else begin
        clk_cnt <= clk_cnt + 1;
        AESL_ready_p1 <= AESL_ready;
        AESL_start_p1 <= AESL_start;
    end
end

reg [31:0] start_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] start_cnt;
reg [31:0] ready_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] ap_ready_cnt;
reg [31:0] finish_timestamp [0:AUTOTB_TRANSACTION_NUM - 1];
reg [31:0] finish_cnt;
reg [31:0] lat_total;
event report_progress;

always @(posedge AESL_clock)
begin
    if (finish_cnt == AUTOTB_TRANSACTION_NUM - 1 && AESL_done == 1'b1)
        lat_total = clk_cnt - start_timestamp[0];
end

initial begin
    start_cnt = 0;
    finish_cnt = 0;
    ap_ready_cnt = 0;
    wait (AESL_reset == 0);
    wait_start();
    start_timestamp[start_cnt] = clk_cnt;
    start_cnt = start_cnt + 1;
    if (AESL_done) begin
        finish_timestamp[finish_cnt] = clk_cnt;
        finish_cnt = finish_cnt + 1;
    end
    -> report_progress;
    forever begin
        @ (posedge AESL_clock);
        if (start_cnt < AUTOTB_TRANSACTION_NUM) begin
            if ((AESL_start && AESL_ready_p1)||(AESL_start && ~AESL_start_p1)) begin
                start_timestamp[start_cnt] = clk_cnt;
                start_cnt = start_cnt + 1;
            end
        end
        if (ap_ready_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_start_p1 && AESL_ready_p1) begin
                ready_timestamp[ap_ready_cnt] = clk_cnt;
                ap_ready_cnt = ap_ready_cnt + 1;
            end
        end
        if (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_done) begin
                finish_timestamp[finish_cnt] = clk_cnt;
                finish_cnt = finish_cnt + 1;
            end
        end
        -> report_progress;
    end
end

reg [31:0] progress_timeout;

initial begin : simulation_progress
    real intra_progress;
    wait (AESL_reset == 0);
    progress_timeout = PROGRESS_TIMEOUT;
    $display("////////////////////////////////////////////////////////////////////////////////////");
    $display("// Inter-Transaction Progress: Completed Transaction / Total Transaction");
    $display("// Intra-Transaction Progress: Measured Latency / Latency Estimation * 100%%");
    $display("//");
    $display("// RTL Simulation : \"Inter-Transaction Progress\" [\"Intra-Transaction Progress\"] @ \"Simulation Time\"");
    $display("////////////////////////////////////////////////////////////////////////////////////");
    print_progress();
    while (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
        @ (report_progress);
        if (finish_cnt < AUTOTB_TRANSACTION_NUM) begin
            if (AESL_done) begin
                print_progress();
                progress_timeout = PROGRESS_TIMEOUT;
            end else begin
                if (progress_timeout == 0) begin
                    print_progress();
                    progress_timeout = PROGRESS_TIMEOUT;
                end else begin
                    progress_timeout = progress_timeout - 1;
                end
            end
        end
    end
    print_progress();
    $display("////////////////////////////////////////////////////////////////////////////////////");
    calculate_performance();
end

task get_intra_progress(output real intra_progress);
    begin
        if (start_cnt > finish_cnt) begin
            intra_progress = clk_cnt - start_timestamp[finish_cnt];
        end else if(finish_cnt > 0) begin
            intra_progress = LATENCY_ESTIMATION;
        end else begin
            intra_progress = 0;
        end
        intra_progress = intra_progress / LATENCY_ESTIMATION;
    end
endtask

task print_progress();
    real intra_progress;
    begin
        if (LATENCY_ESTIMATION > 0) begin
            get_intra_progress(intra_progress);
            $display("// RTL Simulation : %0d / %0d [%2.2f%%] @ \"%0t\"", finish_cnt, AUTOTB_TRANSACTION_NUM, intra_progress * 100, $time);
        end else begin
            $display("// RTL Simulation : %0d / %0d [n/a] @ \"%0t\"", finish_cnt, AUTOTB_TRANSACTION_NUM, $time);
        end
    end
endtask

task calculate_performance();
    integer i;
    integer fp;
    reg [31:0] latency [0:AUTOTB_TRANSACTION_NUM - 1];
    reg [31:0] latency_min;
    reg [31:0] latency_max;
    reg [31:0] latency_total;
    reg [31:0] latency_average;
    reg [31:0] interval [0:AUTOTB_TRANSACTION_NUM - 2];
    reg [31:0] interval_min;
    reg [31:0] interval_max;
    reg [31:0] interval_total;
    reg [31:0] interval_average;
    reg [31:0] total_execute_time;
    begin
        latency_min = -1;
        latency_max = 0;
        latency_total = 0;
        interval_min = -1;
        interval_max = 0;
        interval_total = 0;
        total_execute_time = lat_total;

        for (i = 0; i < AUTOTB_TRANSACTION_NUM; i = i + 1) begin
            // calculate latency
            latency[i] = finish_timestamp[i] - start_timestamp[i];
            if (latency[i] > latency_max) latency_max = latency[i];
            if (latency[i] < latency_min) latency_min = latency[i];
            latency_total = latency_total + latency[i];
            // calculate interval
            if (AUTOTB_TRANSACTION_NUM == 1) begin
                interval[i] = 0;
                interval_max = 0;
                interval_min = 0;
                interval_total = 0;
            end else if (i < AUTOTB_TRANSACTION_NUM - 1) begin
                interval[i] = start_timestamp[i + 1] - start_timestamp[i];
                if (interval[i] > interval_max) interval_max = interval[i];
                if (interval[i] < interval_min) interval_min = interval[i];
                interval_total = interval_total + interval[i];
            end
        end

        latency_average = latency_total / AUTOTB_TRANSACTION_NUM;
        if (AUTOTB_TRANSACTION_NUM == 1) begin
            interval_average = 0;
        end else begin
            interval_average = interval_total / (AUTOTB_TRANSACTION_NUM - 1);
        end

        fp = $fopen(`AUTOTB_LAT_RESULT_FILE, "w");

        $fdisplay(fp, "$MAX_LATENCY = \"%0d\"", latency_max);
        $fdisplay(fp, "$MIN_LATENCY = \"%0d\"", latency_min);
        $fdisplay(fp, "$AVER_LATENCY = \"%0d\"", latency_average);
        $fdisplay(fp, "$MAX_THROUGHPUT = \"%0d\"", interval_max);
        $fdisplay(fp, "$MIN_THROUGHPUT = \"%0d\"", interval_min);
        $fdisplay(fp, "$AVER_THROUGHPUT = \"%0d\"", interval_average);
        $fdisplay(fp, "$TOTAL_EXECUTE_TIME = \"%0d\"", total_execute_time);

        $fclose(fp);

        fp = $fopen(`AUTOTB_PER_RESULT_TRANS_FILE, "w");

        $fdisplay(fp, "%20s%16s%16s", "", "latency", "interval");
        if (AUTOTB_TRANSACTION_NUM == 1) begin
            i = 0;
            $fdisplay(fp, "transaction%8d:%16d%16d", i, latency[i], interval[i]);
        end else begin
            for (i = 0; i < AUTOTB_TRANSACTION_NUM; i = i + 1) begin
                if (i < AUTOTB_TRANSACTION_NUM - 1) begin
                    $fdisplay(fp, "transaction%8d:%16d%16d", i, latency[i], interval[i]);
                end else begin
                    $fdisplay(fp, "transaction%8d:%16d               x", i, latency[i]);
                end
            end
        end

        $fclose(fp);
    end
endtask


////////////////////////////////////////////
// Dependence Check
////////////////////////////////////////////

`ifndef POST_SYN

`endif
///////////////////////////////////////////////////////
// dataflow status monitor
///////////////////////////////////////////////////////
dataflow_monitor U_dataflow_monitor(
    .clock(AESL_clock),
    .reset(rst),
    .finish(all_finish));

`include "fifo_para.vh"

endmodule
