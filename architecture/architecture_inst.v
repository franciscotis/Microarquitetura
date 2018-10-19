	architecture u0 (
		.clk_clk                 (<connected-to-clk_clk>),                 //   clk.clk
		.reset_reset_n           (<connected-to-reset_reset_n>),           // reset.reset_n
		.btn_export              (<connected-to-btn_export>),              //   btn.export
		.led_export              (<connected-to-led_export>),              //   led.export
		.rw_writeresponsevalid_n (<connected-to-rw_writeresponsevalid_n>), //    rw.writeresponsevalid_n
		.en_writeresponsevalid_n (<connected-to-en_writeresponsevalid_n>), //    en.writeresponsevalid_n
		.rs_writeresponsevalid_n (<connected-to-rs_writeresponsevalid_n>), //    rs.writeresponsevalid_n
		.db_readdata             (<connected-to-db_readdata>)              //    db.readdata
	);

