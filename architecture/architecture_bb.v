
module architecture (
	clk_clk,
	reset_reset_n,
	btn_export,
	led_export,
	rw_writeresponsevalid_n,
	en_writeresponsevalid_n,
	rs_writeresponsevalid_n,
	db_readdata);	

	input		clk_clk;
	input		reset_reset_n;
	input	[3:0]	btn_export;
	output	[3:0]	led_export;
	output		rw_writeresponsevalid_n;
	output		en_writeresponsevalid_n;
	output		rs_writeresponsevalid_n;
	output	[7:0]	db_readdata;
endmodule
