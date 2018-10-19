	component architecture is
		port (
			clk_clk                 : in  std_logic                    := 'X';             -- clk
			reset_reset_n           : in  std_logic                    := 'X';             -- reset_n
			btn_export              : in  std_logic_vector(3 downto 0) := (others => 'X'); -- export
			led_export              : out std_logic_vector(3 downto 0);                    -- export
			rw_writeresponsevalid_n : out std_logic;                                       -- writeresponsevalid_n
			en_writeresponsevalid_n : out std_logic;                                       -- writeresponsevalid_n
			rs_writeresponsevalid_n : out std_logic;                                       -- writeresponsevalid_n
			db_readdata             : out std_logic_vector(7 downto 0)                     -- readdata
		);
	end component architecture;

	u0 : component architecture
		port map (
			clk_clk                 => CONNECTED_TO_clk_clk,                 --   clk.clk
			reset_reset_n           => CONNECTED_TO_reset_reset_n,           -- reset.reset_n
			btn_export              => CONNECTED_TO_btn_export,              --   btn.export
			led_export              => CONNECTED_TO_led_export,              --   led.export
			rw_writeresponsevalid_n => CONNECTED_TO_rw_writeresponsevalid_n, --    rw.writeresponsevalid_n
			en_writeresponsevalid_n => CONNECTED_TO_en_writeresponsevalid_n, --    en.writeresponsevalid_n
			rs_writeresponsevalid_n => CONNECTED_TO_rs_writeresponsevalid_n, --    rs.writeresponsevalid_n
			db_readdata             => CONNECTED_TO_db_readdata              --    db.readdata
		);

