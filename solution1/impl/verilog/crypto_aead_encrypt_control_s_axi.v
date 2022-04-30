// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1ns/1ps
module crypto_aead_encrypt_control_s_axi
#(parameter
    C_S_AXI_ADDR_WIDTH = 8,
    C_S_AXI_DATA_WIDTH = 32
)(
    input  wire                          ACLK,
    input  wire                          ARESET,
    input  wire                          ACLK_EN,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] AWADDR,
    input  wire                          AWVALID,
    output wire                          AWREADY,
    input  wire [C_S_AXI_DATA_WIDTH-1:0] WDATA,
    input  wire [C_S_AXI_DATA_WIDTH/8-1:0] WSTRB,
    input  wire                          WVALID,
    output wire                          WREADY,
    output wire [1:0]                    BRESP,
    output wire                          BVALID,
    input  wire                          BREADY,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] ARADDR,
    input  wire                          ARVALID,
    output wire                          ARREADY,
    output wire [C_S_AXI_DATA_WIDTH-1:0] RDATA,
    output wire [1:0]                    RRESP,
    output wire                          RVALID,
    input  wire                          RREADY,
    output wire                          interrupt,
    output wire                          ap_start,
    input  wire                          ap_done,
    input  wire                          ap_ready,
    output wire                          ap_continue,
    input  wire                          ap_idle,
    input  wire [31:0]                   ap_return,
    output wire [63:0]                   c,
    output wire [63:0]                   clen,
    output wire [63:0]                   m,
    output wire [63:0]                   mlen,
    output wire [63:0]                   ad,
    output wire [63:0]                   adlen,
    output wire [63:0]                   nsec,
    output wire [63:0]                   npub,
    output wire [63:0]                   k,
    input  wire [0:0]                    ap_local_deadlock
);
//------------------------Address Info-------------------
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 4  - ap_continue (Read/Write/SC)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        bit 5 - enable ap_local_deadlock interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (COR/TOW)
//        bit 1 - ap_ready (COR/TOW)
//        bit 5 - ap_local_deadlock (COR/TOW)
//        others - reserved
// 0x10 : Data signal of ap_return
//        bit 31~0 - ap_return[31:0] (Read)
// 0x18 : Data signal of c
//        bit 31~0 - c[31:0] (Read/Write)
// 0x1c : Data signal of c
//        bit 31~0 - c[63:32] (Read/Write)
// 0x20 : reserved
// 0x24 : Data signal of clen
//        bit 31~0 - clen[31:0] (Read/Write)
// 0x28 : Data signal of clen
//        bit 31~0 - clen[63:32] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of m
//        bit 31~0 - m[31:0] (Read/Write)
// 0x34 : Data signal of m
//        bit 31~0 - m[63:32] (Read/Write)
// 0x38 : reserved
// 0x3c : Data signal of mlen
//        bit 31~0 - mlen[31:0] (Read/Write)
// 0x40 : Data signal of mlen
//        bit 31~0 - mlen[63:32] (Read/Write)
// 0x44 : reserved
// 0x48 : Data signal of ad
//        bit 31~0 - ad[31:0] (Read/Write)
// 0x4c : Data signal of ad
//        bit 31~0 - ad[63:32] (Read/Write)
// 0x50 : reserved
// 0x54 : Data signal of adlen
//        bit 31~0 - adlen[31:0] (Read/Write)
// 0x58 : Data signal of adlen
//        bit 31~0 - adlen[63:32] (Read/Write)
// 0x5c : reserved
// 0x60 : Data signal of nsec
//        bit 31~0 - nsec[31:0] (Read/Write)
// 0x64 : Data signal of nsec
//        bit 31~0 - nsec[63:32] (Read/Write)
// 0x68 : reserved
// 0x6c : Data signal of npub
//        bit 31~0 - npub[31:0] (Read/Write)
// 0x70 : Data signal of npub
//        bit 31~0 - npub[63:32] (Read/Write)
// 0x74 : reserved
// 0x78 : Data signal of k
//        bit 31~0 - k[31:0] (Read/Write)
// 0x7c : Data signal of k
//        bit 31~0 - k[63:32] (Read/Write)
// 0x80 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

//------------------------Parameter----------------------
localparam
    ADDR_AP_CTRL      = 8'h00,
    ADDR_GIE          = 8'h04,
    ADDR_IER          = 8'h08,
    ADDR_ISR          = 8'h0c,
    ADDR_AP_RETURN_0  = 8'h10,
    ADDR_C_DATA_0     = 8'h18,
    ADDR_C_DATA_1     = 8'h1c,
    ADDR_C_CTRL       = 8'h20,
    ADDR_CLEN_DATA_0  = 8'h24,
    ADDR_CLEN_DATA_1  = 8'h28,
    ADDR_CLEN_CTRL    = 8'h2c,
    ADDR_M_DATA_0     = 8'h30,
    ADDR_M_DATA_1     = 8'h34,
    ADDR_M_CTRL       = 8'h38,
    ADDR_MLEN_DATA_0  = 8'h3c,
    ADDR_MLEN_DATA_1  = 8'h40,
    ADDR_MLEN_CTRL    = 8'h44,
    ADDR_AD_DATA_0    = 8'h48,
    ADDR_AD_DATA_1    = 8'h4c,
    ADDR_AD_CTRL      = 8'h50,
    ADDR_ADLEN_DATA_0 = 8'h54,
    ADDR_ADLEN_DATA_1 = 8'h58,
    ADDR_ADLEN_CTRL   = 8'h5c,
    ADDR_NSEC_DATA_0  = 8'h60,
    ADDR_NSEC_DATA_1  = 8'h64,
    ADDR_NSEC_CTRL    = 8'h68,
    ADDR_NPUB_DATA_0  = 8'h6c,
    ADDR_NPUB_DATA_1  = 8'h70,
    ADDR_NPUB_CTRL    = 8'h74,
    ADDR_K_DATA_0     = 8'h78,
    ADDR_K_DATA_1     = 8'h7c,
    ADDR_K_CTRL       = 8'h80,
    WRIDLE            = 2'd0,
    WRDATA            = 2'd1,
    WRRESP            = 2'd2,
    WRRESET           = 2'd3,
    RDIDLE            = 2'd0,
    RDDATA            = 2'd1,
    RDRESET           = 2'd2,
    ADDR_BITS                = 8;

//------------------------Local signal-------------------
    reg  [1:0]                    wstate = WRRESET;
    reg  [1:0]                    wnext;
    reg  [ADDR_BITS-1:0]          waddr;
    wire [C_S_AXI_DATA_WIDTH-1:0] wmask;
    wire                          aw_hs;
    wire                          w_hs;
    reg  [1:0]                    rstate = RDRESET;
    reg  [1:0]                    rnext;
    reg  [C_S_AXI_DATA_WIDTH-1:0] rdata;
    wire                          ar_hs;
    wire [ADDR_BITS-1:0]          raddr;
    // internal registers
    reg                           int_ap_idle;
    reg                           int_ap_continue;
    reg                           int_ap_ready = 1'b0;
    wire                          task_ap_ready;
    reg                           int_ap_done = 1'b0;
    wire                          task_ap_done;
    reg                           int_task_ap_done = 1'b0;
    reg                           int_ap_start = 1'b0;
    reg                           int_auto_restart = 1'b0;
    reg                           auto_restart_status = 1'b0;
    reg                           auto_restart_done = 1'b0;
    reg                           int_gie = 1'b0;
    reg  [5:0]                    int_ier = 6'b0;
    reg  [5:0]                    int_isr = 6'b0;
    reg  [31:0]                   int_ap_return;
    reg  [63:0]                   int_c = 'b0;
    reg  [63:0]                   int_clen = 'b0;
    reg  [63:0]                   int_m = 'b0;
    reg  [63:0]                   int_mlen = 'b0;
    reg  [63:0]                   int_ad = 'b0;
    reg  [63:0]                   int_adlen = 'b0;
    reg  [63:0]                   int_nsec = 'b0;
    reg  [63:0]                   int_npub = 'b0;
    reg  [63:0]                   int_k = 'b0;

//------------------------Instantiation------------------


//------------------------AXI write fsm------------------
assign AWREADY = (wstate == WRIDLE);
assign WREADY  = (wstate == WRDATA);
assign BRESP   = 2'b00;  // OKAY
assign BVALID  = (wstate == WRRESP);
assign wmask   = { {8{WSTRB[3]}}, {8{WSTRB[2]}}, {8{WSTRB[1]}}, {8{WSTRB[0]}} };
assign aw_hs   = AWVALID & AWREADY;
assign w_hs    = WVALID & WREADY;

// wstate
always @(posedge ACLK) begin
    if (ARESET)
        wstate <= WRRESET;
    else if (ACLK_EN)
        wstate <= wnext;
end

// wnext
always @(*) begin
    case (wstate)
        WRIDLE:
            if (AWVALID)
                wnext = WRDATA;
            else
                wnext = WRIDLE;
        WRDATA:
            if (WVALID)
                wnext = WRRESP;
            else
                wnext = WRDATA;
        WRRESP:
            if (BREADY)
                wnext = WRIDLE;
            else
                wnext = WRRESP;
        default:
            wnext = WRIDLE;
    endcase
end

// waddr
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (aw_hs)
            waddr <= AWADDR[ADDR_BITS-1:0];
    end
end

//------------------------AXI read fsm-------------------
assign ARREADY = (rstate == RDIDLE);
assign RDATA   = rdata;
assign RRESP   = 2'b00;  // OKAY
assign RVALID  = (rstate == RDDATA);
assign ar_hs   = ARVALID & ARREADY;
assign raddr   = ARADDR[ADDR_BITS-1:0];

// rstate
always @(posedge ACLK) begin
    if (ARESET)
        rstate <= RDRESET;
    else if (ACLK_EN)
        rstate <= rnext;
end

// rnext
always @(*) begin
    case (rstate)
        RDIDLE:
            if (ARVALID)
                rnext = RDDATA;
            else
                rnext = RDIDLE;
        RDDATA:
            if (RREADY & RVALID)
                rnext = RDIDLE;
            else
                rnext = RDDATA;
        default:
            rnext = RDIDLE;
    endcase
end

// rdata
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ar_hs) begin
            rdata <= 'b0;
            case (raddr)
                ADDR_AP_CTRL: begin
                    rdata[0] <= int_ap_start;
                    rdata[1] <= int_task_ap_done;
                    rdata[2] <= int_ap_idle;
                    rdata[3] <= int_ap_ready;
                    rdata[4] <= int_ap_continue;
                    rdata[7] <= int_auto_restart;
                end
                ADDR_GIE: begin
                    rdata <= int_gie;
                end
                ADDR_IER: begin
                    rdata <= int_ier;
                end
                ADDR_ISR: begin
                    rdata <= int_isr;
                end
                ADDR_AP_RETURN_0: begin
                    rdata <= int_ap_return[31:0];
                end
                ADDR_C_DATA_0: begin
                    rdata <= int_c[31:0];
                end
                ADDR_C_DATA_1: begin
                    rdata <= int_c[63:32];
                end
                ADDR_CLEN_DATA_0: begin
                    rdata <= int_clen[31:0];
                end
                ADDR_CLEN_DATA_1: begin
                    rdata <= int_clen[63:32];
                end
                ADDR_M_DATA_0: begin
                    rdata <= int_m[31:0];
                end
                ADDR_M_DATA_1: begin
                    rdata <= int_m[63:32];
                end
                ADDR_MLEN_DATA_0: begin
                    rdata <= int_mlen[31:0];
                end
                ADDR_MLEN_DATA_1: begin
                    rdata <= int_mlen[63:32];
                end
                ADDR_AD_DATA_0: begin
                    rdata <= int_ad[31:0];
                end
                ADDR_AD_DATA_1: begin
                    rdata <= int_ad[63:32];
                end
                ADDR_ADLEN_DATA_0: begin
                    rdata <= int_adlen[31:0];
                end
                ADDR_ADLEN_DATA_1: begin
                    rdata <= int_adlen[63:32];
                end
                ADDR_NSEC_DATA_0: begin
                    rdata <= int_nsec[31:0];
                end
                ADDR_NSEC_DATA_1: begin
                    rdata <= int_nsec[63:32];
                end
                ADDR_NPUB_DATA_0: begin
                    rdata <= int_npub[31:0];
                end
                ADDR_NPUB_DATA_1: begin
                    rdata <= int_npub[63:32];
                end
                ADDR_K_DATA_0: begin
                    rdata <= int_k[31:0];
                end
                ADDR_K_DATA_1: begin
                    rdata <= int_k[63:32];
                end
            endcase
        end
    end
end


//------------------------Register logic-----------------
assign interrupt     = int_gie & (|int_isr);
assign ap_start      = int_ap_start;
assign task_ap_done  = (ap_done && !auto_restart_status) || auto_restart_done;
assign task_ap_ready = ap_ready && !int_auto_restart;
assign ap_continue   = int_ap_continue || auto_restart_status;
assign c             = int_c;
assign clen          = int_clen;
assign m             = int_m;
assign mlen          = int_mlen;
assign ad            = int_ad;
assign adlen         = int_adlen;
assign nsec          = int_nsec;
assign npub          = int_npub;
assign k             = int_k;
// int_ap_start
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_start <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0] && WDATA[0])
            int_ap_start <= 1'b1;
        else if (ap_ready)
            int_ap_start <= int_auto_restart; // clear on handshake/auto restart
    end
end

// int_ap_done
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_done <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_done <= ap_done;
    end
end

// int_task_ap_done
always @(posedge ACLK) begin
    if (ARESET)
        int_task_ap_done <= 1'b0;
    else if (ACLK_EN) begin
            int_task_ap_done <= task_ap_done;
    end
end

// int_ap_idle
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_idle <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_idle <= ap_idle;
    end
end

// int_ap_ready
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_ready <= 1'b0;
    else if (ACLK_EN) begin
        if (task_ap_ready)
            int_ap_ready <= 1'b1;
        else if (ar_hs && raddr == ADDR_AP_CTRL)
            int_ap_ready <= 1'b0;
    end
end

// int_ap_continue
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_continue <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0] && WDATA[4])
            int_ap_continue <= 1'b1;
        else
            int_ap_continue <= 1'b0; // self clear
    end
end

// int_auto_restart
always @(posedge ACLK) begin
    if (ARESET)
        int_auto_restart <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0])
            int_auto_restart <=  WDATA[7];
    end
end

// auto_restart_status
always @(posedge ACLK) begin
    if (ARESET)
        auto_restart_status <= 1'b0;
    else if (ACLK_EN) begin
        if (int_auto_restart)
            auto_restart_status <= 1'b1;
        else if (ap_idle)
            auto_restart_status <= 1'b0;
    end
end

// auto_restart_done
always @(posedge ACLK) begin
    if (ARESET)
        auto_restart_done <= 1'b0;
    else if (ACLK_EN) begin
        if (auto_restart_status && (ap_idle && !int_ap_idle))
            auto_restart_done <= 1'b1;
        else if (int_ap_continue)
            auto_restart_done <= 1'b0;
    end
end

// int_gie
always @(posedge ACLK) begin
    if (ARESET)
        int_gie <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_GIE && WSTRB[0])
            int_gie <= WDATA[0];
    end
end

// int_ier
always @(posedge ACLK) begin
    if (ARESET)
        int_ier <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_IER && WSTRB[0])
            int_ier <= WDATA[5:0];
    end
end

// int_isr[0]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[0] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[0] & ap_done)
            int_isr[0] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[0] <= int_isr[0] ^ WDATA[0]; // toggle on write
    end
end

// int_isr[1]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[1] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[1] & ap_ready)
            int_isr[1] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[1] <= int_isr[1] ^ WDATA[1]; // toggle on write
    end
end

// int_isr[5]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[5] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[5] & ap_local_deadlock)
            int_isr[5] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[5] <= int_isr[5] ^ WDATA[5]; // toggle on write
    end
end

// int_ap_return
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_return <= 0;
    else if (ACLK_EN) begin
        if (ap_done)
            int_ap_return <= ap_return;
    end
end

// int_c[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_c[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_C_DATA_0)
            int_c[31:0] <= (WDATA[31:0] & wmask) | (int_c[31:0] & ~wmask);
    end
end

// int_c[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_c[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_C_DATA_1)
            int_c[63:32] <= (WDATA[31:0] & wmask) | (int_c[63:32] & ~wmask);
    end
end

// int_clen[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_clen[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_CLEN_DATA_0)
            int_clen[31:0] <= (WDATA[31:0] & wmask) | (int_clen[31:0] & ~wmask);
    end
end

// int_clen[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_clen[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_CLEN_DATA_1)
            int_clen[63:32] <= (WDATA[31:0] & wmask) | (int_clen[63:32] & ~wmask);
    end
end

// int_m[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_m[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_M_DATA_0)
            int_m[31:0] <= (WDATA[31:0] & wmask) | (int_m[31:0] & ~wmask);
    end
end

// int_m[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_m[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_M_DATA_1)
            int_m[63:32] <= (WDATA[31:0] & wmask) | (int_m[63:32] & ~wmask);
    end
end

// int_mlen[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_mlen[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_MLEN_DATA_0)
            int_mlen[31:0] <= (WDATA[31:0] & wmask) | (int_mlen[31:0] & ~wmask);
    end
end

// int_mlen[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_mlen[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_MLEN_DATA_1)
            int_mlen[63:32] <= (WDATA[31:0] & wmask) | (int_mlen[63:32] & ~wmask);
    end
end

// int_ad[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_ad[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AD_DATA_0)
            int_ad[31:0] <= (WDATA[31:0] & wmask) | (int_ad[31:0] & ~wmask);
    end
end

// int_ad[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_ad[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AD_DATA_1)
            int_ad[63:32] <= (WDATA[31:0] & wmask) | (int_ad[63:32] & ~wmask);
    end
end

// int_adlen[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_adlen[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_ADLEN_DATA_0)
            int_adlen[31:0] <= (WDATA[31:0] & wmask) | (int_adlen[31:0] & ~wmask);
    end
end

// int_adlen[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_adlen[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_ADLEN_DATA_1)
            int_adlen[63:32] <= (WDATA[31:0] & wmask) | (int_adlen[63:32] & ~wmask);
    end
end

// int_nsec[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_nsec[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_NSEC_DATA_0)
            int_nsec[31:0] <= (WDATA[31:0] & wmask) | (int_nsec[31:0] & ~wmask);
    end
end

// int_nsec[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_nsec[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_NSEC_DATA_1)
            int_nsec[63:32] <= (WDATA[31:0] & wmask) | (int_nsec[63:32] & ~wmask);
    end
end

// int_npub[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_npub[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_NPUB_DATA_0)
            int_npub[31:0] <= (WDATA[31:0] & wmask) | (int_npub[31:0] & ~wmask);
    end
end

// int_npub[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_npub[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_NPUB_DATA_1)
            int_npub[63:32] <= (WDATA[31:0] & wmask) | (int_npub[63:32] & ~wmask);
    end
end

// int_k[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_k[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_K_DATA_0)
            int_k[31:0] <= (WDATA[31:0] & wmask) | (int_k[31:0] & ~wmask);
    end
end

// int_k[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_k[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_K_DATA_1)
            int_k[63:32] <= (WDATA[31:0] & wmask) | (int_k[63:32] & ~wmask);
    end
end


//------------------------Memory logic-------------------

endmodule
