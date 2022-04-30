create_clock -period 20.000 -name clk -waveform {0.000 5.000} [get_ports ap_clk]

set_property IOSTANDARD HSLVDCI_15 [get_ports ap_rst]
