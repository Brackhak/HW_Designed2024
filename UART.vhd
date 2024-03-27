----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:30:16 03/27/2024 
-- Design Name: 
-- Module Name:    UART - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;
use work.clockgen_package.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity UART is
	generic(
	pulses_bit : integer := 28);
	port(
	clk_i : in std_logic;
	reset : in std_logic;
	data_Rx : in std_logic;
	-- data_Tx: out std_logic;
	led_x : out std_logic_vector(7 downto 0);
	buttonn : in std_logic;
	clk_dd : out std_logic
	--detech_condition : out std_logic
	);
	
end UART;

architecture Behavioral of UART is
	ATTRIBUTE CHIP_PIN: STRING;
	ATTRIBUTE CHIP_PIN OF clk_i      : SIGNAL IS "123";
	ATTRIBUTE CHIP_PIN OF reset      : SIGNAL IS "45"; 	
	ATTRIBUTE CHIP_PIN OF data_Rx     : SIGNAL IS "97"; -- BROWN
	-- ATTRIBUTE CHIP_PIN OF data_Tx     : SIGNAL IS "98"; -- WHITE
	--ATTRIBUTE CHIP_PIN OF detect_sit       : SIGNAL IS "82"; 	
	
	
	
	type state_type is (IDLE, RX_START, RCV, RX_PARITY, RX_STOP);
	signal state : state_type := IDLE;

	signal dta_rcv,led   : std_logic_vector(7 downto 0) := (others => '0');
	signal count     : integer range 0 to pulses_bit-1 := 0;
	signal bit_dta   : integer range 0 to 7 := 0;		
	signal sig_Rx    : std_logic := '0';
	signal sig_C_Rx  : std_logic := '0';
	signal dat_fin   : std_logic := '0';
	signal clk_da    : std_logic;	 
	
begin
	-- Main clock: 50MHz -> 20ns
	-- Main clock: 20MHz -> 50ns
	
	-- To obtain 14 pulses of 8680ns -> 8680/28 = 310ns
	-- To obtain 50% duty and pulse width 310ns -> 310ns/50ns = 15.5 rounded up -> 16
	CLKDA: clockgen generic map(6) port map(clk_i, reset, clk_da);
	clk_dd <= clk_da;

Metastability:
	process (clk_i)
	begin
		if rising_edge(clk_i) then
			sig_C_Rx <= data_Rx;
			sig_Rx   <= sig_C_Rx;	
		end if;	
end process Metastability;

Takedata: process (clk_da)
	begin

	if rising_edge(clk_da) then

		case state is
			when IDLE =>
				count <= 0;
				if sig_Rx = '0' then
					state <= RX_START;
				else 
					state <= IDLE;
				end if;
			
			when RX_START =>
				dat_fin <= '0';
				if count = ((pulses_bit/2)-1) then
					if sig_Rx = '0' then
						count <= 0;
						state <=  RCV;
					end if;
				else 
					count <= count + 1;
					state <= RX_START;
					
				end if;

			when RCV =>
	
				if count < (pulses_bit-1) then
					count <= count + 1;
					state <= RCV;

				else 
					count <= 0;	
					dta_rcv(bit_dta) <= sig_Rx;
						
					if bit_dta < 7 then
						bit_dta <= bit_dta + 1;
						state <= RCV;

					else
						bit_dta <= 0;
						state <= RX_PARITY;
						
					end if;
					
				end if;

			when RX_PARITY =>

				state <= RX_STOP;
				
			when RX_STOP =>

				state <= IDLE;

		end case;
	end if;

end process Takedata;
	 
DataReceived:
	process (clk_i)
	begin
		if rising_edge(clk_i) then
			--detech_condition <= '1';
			if dta_rcv     = "01000001" then -- A
				led <= dta_rcv;
			elsif  dta_rcv = "01100001" then -- a
				led <= dta_rcv;
			end if;
		end if;	
 end process DataReceived;

led_x <= led;
end Behavioral;

