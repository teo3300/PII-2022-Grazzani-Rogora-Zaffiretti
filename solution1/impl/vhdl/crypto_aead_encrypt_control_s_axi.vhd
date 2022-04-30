-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

entity crypto_aead_encrypt_control_s_axi is
generic (
    C_S_AXI_ADDR_WIDTH    : INTEGER := 8;
    C_S_AXI_DATA_WIDTH    : INTEGER := 32);
port (
    ACLK                  :in   STD_LOGIC;
    ARESET                :in   STD_LOGIC;
    ACLK_EN               :in   STD_LOGIC;
    AWADDR                :in   STD_LOGIC_VECTOR(C_S_AXI_ADDR_WIDTH-1 downto 0);
    AWVALID               :in   STD_LOGIC;
    AWREADY               :out  STD_LOGIC;
    WDATA                 :in   STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH-1 downto 0);
    WSTRB                 :in   STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH/8-1 downto 0);
    WVALID                :in   STD_LOGIC;
    WREADY                :out  STD_LOGIC;
    BRESP                 :out  STD_LOGIC_VECTOR(1 downto 0);
    BVALID                :out  STD_LOGIC;
    BREADY                :in   STD_LOGIC;
    ARADDR                :in   STD_LOGIC_VECTOR(C_S_AXI_ADDR_WIDTH-1 downto 0);
    ARVALID               :in   STD_LOGIC;
    ARREADY               :out  STD_LOGIC;
    RDATA                 :out  STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH-1 downto 0);
    RRESP                 :out  STD_LOGIC_VECTOR(1 downto 0);
    RVALID                :out  STD_LOGIC;
    RREADY                :in   STD_LOGIC;
    interrupt             :out  STD_LOGIC;
    ap_start              :out  STD_LOGIC;
    ap_done               :in   STD_LOGIC;
    ap_ready              :in   STD_LOGIC;
    ap_continue           :out  STD_LOGIC;
    ap_idle               :in   STD_LOGIC;
    ap_return             :in   STD_LOGIC_VECTOR(31 downto 0);
    c                     :out  STD_LOGIC_VECTOR(63 downto 0);
    clen                  :out  STD_LOGIC_VECTOR(63 downto 0);
    m                     :out  STD_LOGIC_VECTOR(63 downto 0);
    mlen                  :out  STD_LOGIC_VECTOR(63 downto 0);
    ad                    :out  STD_LOGIC_VECTOR(63 downto 0);
    adlen                 :out  STD_LOGIC_VECTOR(63 downto 0);
    nsec                  :out  STD_LOGIC_VECTOR(63 downto 0);
    npub                  :out  STD_LOGIC_VECTOR(63 downto 0);
    k                     :out  STD_LOGIC_VECTOR(63 downto 0);
    ap_local_deadlock     :in   STD_LOGIC_VECTOR(0 downto 0)
);
end entity crypto_aead_encrypt_control_s_axi;

-- ------------------------Address Info-------------------
-- 0x00 : Control signals
--        bit 0  - ap_start (Read/Write/COH)
--        bit 1  - ap_done (Read)
--        bit 2  - ap_idle (Read)
--        bit 3  - ap_ready (Read/COR)
--        bit 4  - ap_continue (Read/Write/SC)
--        bit 7  - auto_restart (Read/Write)
--        others - reserved
-- 0x04 : Global Interrupt Enable Register
--        bit 0  - Global Interrupt Enable (Read/Write)
--        others - reserved
-- 0x08 : IP Interrupt Enable Register (Read/Write)
--        bit 0 - enable ap_done interrupt (Read/Write)
--        bit 1 - enable ap_ready interrupt (Read/Write)
--        bit 5 - enable ap_local_deadlock interrupt (Read/Write)
--        others - reserved
-- 0x0c : IP Interrupt Status Register (Read/TOW)
--        bit 0 - ap_done (COR/TOW)
--        bit 1 - ap_ready (COR/TOW)
--        bit 5 - ap_local_deadlock (COR/TOW)
--        others - reserved
-- 0x10 : Data signal of ap_return
--        bit 31~0 - ap_return[31:0] (Read)
-- 0x18 : Data signal of c
--        bit 31~0 - c[31:0] (Read/Write)
-- 0x1c : Data signal of c
--        bit 31~0 - c[63:32] (Read/Write)
-- 0x20 : reserved
-- 0x24 : Data signal of clen
--        bit 31~0 - clen[31:0] (Read/Write)
-- 0x28 : Data signal of clen
--        bit 31~0 - clen[63:32] (Read/Write)
-- 0x2c : reserved
-- 0x30 : Data signal of m
--        bit 31~0 - m[31:0] (Read/Write)
-- 0x34 : Data signal of m
--        bit 31~0 - m[63:32] (Read/Write)
-- 0x38 : reserved
-- 0x3c : Data signal of mlen
--        bit 31~0 - mlen[31:0] (Read/Write)
-- 0x40 : Data signal of mlen
--        bit 31~0 - mlen[63:32] (Read/Write)
-- 0x44 : reserved
-- 0x48 : Data signal of ad
--        bit 31~0 - ad[31:0] (Read/Write)
-- 0x4c : Data signal of ad
--        bit 31~0 - ad[63:32] (Read/Write)
-- 0x50 : reserved
-- 0x54 : Data signal of adlen
--        bit 31~0 - adlen[31:0] (Read/Write)
-- 0x58 : Data signal of adlen
--        bit 31~0 - adlen[63:32] (Read/Write)
-- 0x5c : reserved
-- 0x60 : Data signal of nsec
--        bit 31~0 - nsec[31:0] (Read/Write)
-- 0x64 : Data signal of nsec
--        bit 31~0 - nsec[63:32] (Read/Write)
-- 0x68 : reserved
-- 0x6c : Data signal of npub
--        bit 31~0 - npub[31:0] (Read/Write)
-- 0x70 : Data signal of npub
--        bit 31~0 - npub[63:32] (Read/Write)
-- 0x74 : reserved
-- 0x78 : Data signal of k
--        bit 31~0 - k[31:0] (Read/Write)
-- 0x7c : Data signal of k
--        bit 31~0 - k[63:32] (Read/Write)
-- 0x80 : reserved
-- (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

architecture behave of crypto_aead_encrypt_control_s_axi is
    type states is (wridle, wrdata, wrresp, wrreset, rdidle, rddata, rdreset);  -- read and write fsm states
    signal wstate  : states := wrreset;
    signal rstate  : states := rdreset;
    signal wnext, rnext: states;
    constant ADDR_AP_CTRL      : INTEGER := 16#00#;
    constant ADDR_GIE          : INTEGER := 16#04#;
    constant ADDR_IER          : INTEGER := 16#08#;
    constant ADDR_ISR          : INTEGER := 16#0c#;
    constant ADDR_AP_RETURN_0  : INTEGER := 16#10#;
    constant ADDR_C_DATA_0     : INTEGER := 16#18#;
    constant ADDR_C_DATA_1     : INTEGER := 16#1c#;
    constant ADDR_C_CTRL       : INTEGER := 16#20#;
    constant ADDR_CLEN_DATA_0  : INTEGER := 16#24#;
    constant ADDR_CLEN_DATA_1  : INTEGER := 16#28#;
    constant ADDR_CLEN_CTRL    : INTEGER := 16#2c#;
    constant ADDR_M_DATA_0     : INTEGER := 16#30#;
    constant ADDR_M_DATA_1     : INTEGER := 16#34#;
    constant ADDR_M_CTRL       : INTEGER := 16#38#;
    constant ADDR_MLEN_DATA_0  : INTEGER := 16#3c#;
    constant ADDR_MLEN_DATA_1  : INTEGER := 16#40#;
    constant ADDR_MLEN_CTRL    : INTEGER := 16#44#;
    constant ADDR_AD_DATA_0    : INTEGER := 16#48#;
    constant ADDR_AD_DATA_1    : INTEGER := 16#4c#;
    constant ADDR_AD_CTRL      : INTEGER := 16#50#;
    constant ADDR_ADLEN_DATA_0 : INTEGER := 16#54#;
    constant ADDR_ADLEN_DATA_1 : INTEGER := 16#58#;
    constant ADDR_ADLEN_CTRL   : INTEGER := 16#5c#;
    constant ADDR_NSEC_DATA_0  : INTEGER := 16#60#;
    constant ADDR_NSEC_DATA_1  : INTEGER := 16#64#;
    constant ADDR_NSEC_CTRL    : INTEGER := 16#68#;
    constant ADDR_NPUB_DATA_0  : INTEGER := 16#6c#;
    constant ADDR_NPUB_DATA_1  : INTEGER := 16#70#;
    constant ADDR_NPUB_CTRL    : INTEGER := 16#74#;
    constant ADDR_K_DATA_0     : INTEGER := 16#78#;
    constant ADDR_K_DATA_1     : INTEGER := 16#7c#;
    constant ADDR_K_CTRL       : INTEGER := 16#80#;
    constant ADDR_BITS         : INTEGER := 8;

    signal waddr               : UNSIGNED(ADDR_BITS-1 downto 0);
    signal wmask               : UNSIGNED(C_S_AXI_DATA_WIDTH-1 downto 0);
    signal aw_hs               : STD_LOGIC;
    signal w_hs                : STD_LOGIC;
    signal rdata_data          : UNSIGNED(C_S_AXI_DATA_WIDTH-1 downto 0);
    signal ar_hs               : STD_LOGIC;
    signal raddr               : UNSIGNED(ADDR_BITS-1 downto 0);
    signal AWREADY_t           : STD_LOGIC;
    signal WREADY_t            : STD_LOGIC;
    signal ARREADY_t           : STD_LOGIC;
    signal RVALID_t            : STD_LOGIC;
    -- internal registers
    signal int_ap_idle         : STD_LOGIC := '0';
    signal int_ap_continue     : STD_LOGIC;
    signal int_ap_ready        : STD_LOGIC := '0';
    signal task_ap_ready       : STD_LOGIC;
    signal int_ap_done         : STD_LOGIC := '0';
    signal task_ap_done        : STD_LOGIC;
    signal int_task_ap_done    : STD_LOGIC := '0';
    signal int_ap_start        : STD_LOGIC := '0';
    signal int_auto_restart    : STD_LOGIC := '0';
    signal auto_restart_status : STD_LOGIC := '0';
    signal auto_restart_done   : STD_LOGIC := '0';
    signal int_gie             : STD_LOGIC := '0';
    signal int_ier             : UNSIGNED(5 downto 0) := (others => '0');
    signal int_isr             : UNSIGNED(5 downto 0) := (others => '0');
    signal int_ap_return       : UNSIGNED(31 downto 0);
    signal int_c               : UNSIGNED(63 downto 0) := (others => '0');
    signal int_clen            : UNSIGNED(63 downto 0) := (others => '0');
    signal int_m               : UNSIGNED(63 downto 0) := (others => '0');
    signal int_mlen            : UNSIGNED(63 downto 0) := (others => '0');
    signal int_ad              : UNSIGNED(63 downto 0) := (others => '0');
    signal int_adlen           : UNSIGNED(63 downto 0) := (others => '0');
    signal int_nsec            : UNSIGNED(63 downto 0) := (others => '0');
    signal int_npub            : UNSIGNED(63 downto 0) := (others => '0');
    signal int_k               : UNSIGNED(63 downto 0) := (others => '0');


begin
-- ----------------------- Instantiation------------------


-- ----------------------- AXI WRITE ---------------------
    AWREADY_t <=  '1' when wstate = wridle else '0';
    AWREADY   <=  AWREADY_t;
    WREADY_t  <=  '1' when wstate = wrdata else '0';
    WREADY    <=  WREADY_t;
    BRESP     <=  "00";  -- OKAY
    BVALID    <=  '1' when wstate = wrresp else '0';
    wmask     <=  (31 downto 24 => WSTRB(3), 23 downto 16 => WSTRB(2), 15 downto 8 => WSTRB(1), 7 downto 0 => WSTRB(0));
    aw_hs     <=  AWVALID and AWREADY_t;
    w_hs      <=  WVALID and WREADY_t;

    -- write FSM
    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                wstate <= wrreset;
            elsif (ACLK_EN = '1') then
                wstate <= wnext;
            end if;
        end if;
    end process;

    process (wstate, AWVALID, WVALID, BREADY)
    begin
        case (wstate) is
        when wridle =>
            if (AWVALID = '1') then
                wnext <= wrdata;
            else
                wnext <= wridle;
            end if;
        when wrdata =>
            if (WVALID = '1') then
                wnext <= wrresp;
            else
                wnext <= wrdata;
            end if;
        when wrresp =>
            if (BREADY = '1') then
                wnext <= wridle;
            else
                wnext <= wrresp;
            end if;
        when others =>
            wnext <= wridle;
        end case;
    end process;

    waddr_proc : process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (aw_hs = '1') then
                    waddr <= UNSIGNED(AWADDR(ADDR_BITS-1 downto 0));
                end if;
            end if;
        end if;
    end process;

-- ----------------------- AXI READ ----------------------
    ARREADY_t <= '1' when (rstate = rdidle) else '0';
    ARREADY <= ARREADY_t;
    RDATA   <= STD_LOGIC_VECTOR(rdata_data);
    RRESP   <= "00";  -- OKAY
    RVALID_t  <= '1' when (rstate = rddata) else '0';
    RVALID    <= RVALID_t;
    ar_hs   <= ARVALID and ARREADY_t;
    raddr   <= UNSIGNED(ARADDR(ADDR_BITS-1 downto 0));

    -- read FSM
    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                rstate <= rdreset;
            elsif (ACLK_EN = '1') then
                rstate <= rnext;
            end if;
        end if;
    end process;

    process (rstate, ARVALID, RREADY, RVALID_t)
    begin
        case (rstate) is
        when rdidle =>
            if (ARVALID = '1') then
                rnext <= rddata;
            else
                rnext <= rdidle;
            end if;
        when rddata =>
            if (RREADY = '1' and RVALID_t = '1') then
                rnext <= rdidle;
            else
                rnext <= rddata;
            end if;
        when others =>
            rnext <= rdidle;
        end case;
    end process;

    rdata_proc : process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (ar_hs = '1') then
                    rdata_data <= (others => '0');
                    case (TO_INTEGER(raddr)) is
                    when ADDR_AP_CTRL =>
                        rdata_data(7) <= int_auto_restart;
                        rdata_data(4) <= int_ap_continue;
                        rdata_data(3) <= int_ap_ready;
                        rdata_data(2) <= int_ap_idle;
                        rdata_data(1) <= int_task_ap_done;
                        rdata_data(0) <= int_ap_start;
                    when ADDR_GIE =>
                        rdata_data(0) <= int_gie;
                    when ADDR_IER =>
                        rdata_data(5 downto 0) <= int_ier;
                    when ADDR_ISR =>
                        rdata_data(5 downto 0) <= int_isr;
                    when ADDR_AP_RETURN_0 =>
                        rdata_data <= RESIZE(int_ap_return(31 downto 0), 32);
                    when ADDR_C_DATA_0 =>
                        rdata_data <= RESIZE(int_c(31 downto 0), 32);
                    when ADDR_C_DATA_1 =>
                        rdata_data <= RESIZE(int_c(63 downto 32), 32);
                    when ADDR_CLEN_DATA_0 =>
                        rdata_data <= RESIZE(int_clen(31 downto 0), 32);
                    when ADDR_CLEN_DATA_1 =>
                        rdata_data <= RESIZE(int_clen(63 downto 32), 32);
                    when ADDR_M_DATA_0 =>
                        rdata_data <= RESIZE(int_m(31 downto 0), 32);
                    when ADDR_M_DATA_1 =>
                        rdata_data <= RESIZE(int_m(63 downto 32), 32);
                    when ADDR_MLEN_DATA_0 =>
                        rdata_data <= RESIZE(int_mlen(31 downto 0), 32);
                    when ADDR_MLEN_DATA_1 =>
                        rdata_data <= RESIZE(int_mlen(63 downto 32), 32);
                    when ADDR_AD_DATA_0 =>
                        rdata_data <= RESIZE(int_ad(31 downto 0), 32);
                    when ADDR_AD_DATA_1 =>
                        rdata_data <= RESIZE(int_ad(63 downto 32), 32);
                    when ADDR_ADLEN_DATA_0 =>
                        rdata_data <= RESIZE(int_adlen(31 downto 0), 32);
                    when ADDR_ADLEN_DATA_1 =>
                        rdata_data <= RESIZE(int_adlen(63 downto 32), 32);
                    when ADDR_NSEC_DATA_0 =>
                        rdata_data <= RESIZE(int_nsec(31 downto 0), 32);
                    when ADDR_NSEC_DATA_1 =>
                        rdata_data <= RESIZE(int_nsec(63 downto 32), 32);
                    when ADDR_NPUB_DATA_0 =>
                        rdata_data <= RESIZE(int_npub(31 downto 0), 32);
                    when ADDR_NPUB_DATA_1 =>
                        rdata_data <= RESIZE(int_npub(63 downto 32), 32);
                    when ADDR_K_DATA_0 =>
                        rdata_data <= RESIZE(int_k(31 downto 0), 32);
                    when ADDR_K_DATA_1 =>
                        rdata_data <= RESIZE(int_k(63 downto 32), 32);
                    when others =>
                        NULL;
                    end case;
                end if;
            end if;
        end if;
    end process;

-- ----------------------- Register logic ----------------
    interrupt            <= int_gie and (int_isr(0) or int_isr(1) or int_isr(5));
    ap_start             <= int_ap_start;
    task_ap_done         <= (ap_done and not auto_restart_status) or auto_restart_done;
    task_ap_ready        <= ap_ready and not int_auto_restart;
    ap_continue          <= int_ap_continue or auto_restart_status;
    c                    <= STD_LOGIC_VECTOR(int_c);
    clen                 <= STD_LOGIC_VECTOR(int_clen);
    m                    <= STD_LOGIC_VECTOR(int_m);
    mlen                 <= STD_LOGIC_VECTOR(int_mlen);
    ad                   <= STD_LOGIC_VECTOR(int_ad);
    adlen                <= STD_LOGIC_VECTOR(int_adlen);
    nsec                 <= STD_LOGIC_VECTOR(int_nsec);
    npub                 <= STD_LOGIC_VECTOR(int_npub);
    k                    <= STD_LOGIC_VECTOR(int_k);

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_start <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1' and WDATA(0) = '1') then
                    int_ap_start <= '1';
                elsif (ap_ready = '1') then
                    int_ap_start <= int_auto_restart; -- clear on handshake/auto restart
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_done <= '0';
            elsif (ACLK_EN = '1') then
                if (true) then
                    int_ap_done <= ap_done;
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_task_ap_done <= '0';
            elsif (ACLK_EN = '1') then
                if (true) then
                    int_task_ap_done <= task_ap_done;
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_idle <= '0';
            elsif (ACLK_EN = '1') then
                if (true) then
                    int_ap_idle <= ap_idle;
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_ready <= '0';
            elsif (ACLK_EN = '1') then
                if (task_ap_ready = '1') then
                    int_ap_ready <= '1';
                elsif (ar_hs = '1' and raddr = ADDR_AP_CTRL) then
                    int_ap_ready <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_continue <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1' and WDATA(4) = '1') then
                    int_ap_continue <= '1';
                else
                    int_ap_continue <= '0'; -- self clear
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_auto_restart <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1') then
                    int_auto_restart <= WDATA(7);
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                auto_restart_status <= '0';
            elsif (ACLK_EN = '1') then
                if (int_auto_restart = '1') then
                    auto_restart_status <= '1';
                elsif (ap_idle = '1') then
                    auto_restart_status <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                auto_restart_done <= '0';
            elsif (ACLK_EN = '1') then
                if (auto_restart_status = '1' and (ap_idle = '1' and int_ap_idle = '0')) then
                    auto_restart_done <= '1';
                elsif (int_ap_continue = '1') then
                    auto_restart_done <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_gie <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_GIE and WSTRB(0) = '1') then
                    int_gie <= WDATA(0);
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ier <= (others=>'0');
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_IER and WSTRB(0) = '1') then
                    int_ier <= UNSIGNED(WDATA(5 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_isr(0) <= '0';
            elsif (ACLK_EN = '1') then
                if (int_ier(0) = '1' and ap_done = '1') then
                    int_isr(0) <= '1';
                elsif (w_hs = '1' and waddr = ADDR_ISR and WSTRB(0) = '1') then
                    int_isr(0) <= int_isr(0) xor WDATA(0); -- toggle on write
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_isr(1) <= '0';
            elsif (ACLK_EN = '1') then
                if (int_ier(1) = '1' and ap_ready = '1') then
                    int_isr(1) <= '1';
                elsif (w_hs = '1' and waddr = ADDR_ISR and WSTRB(0) = '1') then
                    int_isr(1) <= int_isr(1) xor WDATA(1); -- toggle on write
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_isr(5) <= '0';
            elsif (ACLK_EN = '1') then
                if (int_ier(5) = '1' and ap_local_deadlock(0) = '1') then
                    int_isr(5) <= '1';
                elsif (w_hs = '1' and waddr = ADDR_ISR and WSTRB(0) = '1') then
                    int_isr(5) <= int_isr(5) xor WDATA(5); -- toggle on write
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_return <= (others => '0');
            elsif (ACLK_EN = '1') then
                if (ap_done = '1') then
                    int_ap_return <= UNSIGNED(ap_return);
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_C_DATA_0) then
                    int_c(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_c(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_C_DATA_1) then
                    int_c(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_c(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_CLEN_DATA_0) then
                    int_clen(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_clen(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_CLEN_DATA_1) then
                    int_clen(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_clen(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_M_DATA_0) then
                    int_m(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_m(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_M_DATA_1) then
                    int_m(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_m(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_MLEN_DATA_0) then
                    int_mlen(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_mlen(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_MLEN_DATA_1) then
                    int_mlen(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_mlen(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AD_DATA_0) then
                    int_ad(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_ad(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AD_DATA_1) then
                    int_ad(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_ad(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_ADLEN_DATA_0) then
                    int_adlen(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_adlen(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_ADLEN_DATA_1) then
                    int_adlen(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_adlen(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_NSEC_DATA_0) then
                    int_nsec(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_nsec(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_NSEC_DATA_1) then
                    int_nsec(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_nsec(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_NPUB_DATA_0) then
                    int_npub(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_npub(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_NPUB_DATA_1) then
                    int_npub(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_npub(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_K_DATA_0) then
                    int_k(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_k(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_K_DATA_1) then
                    int_k(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_k(63 downto 32));
                end if;
            end if;
        end if;
    end process;


-- ----------------------- Memory logic ------------------

end architecture behave;
