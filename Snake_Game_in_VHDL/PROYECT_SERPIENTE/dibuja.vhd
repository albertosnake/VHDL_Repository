----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:52:51 11/01/2016 
-- Design Name: 
-- Module Name:    dibuja - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity dibuja is
	Port ( 	eje_x : in STD_LOGIC_VECTOR (9 downto 0);
				eje_y : in STD_LOGIC_VECTOR (9 downto 0);
				--- ram---
				datab : in STD_LOGIC_VECTOR (4 downto 0);
				addrb: out STD_LOGIC_VECTOR (9 downto 0);
				------ rom -------
				addr_ROM : out STD_LOGIC_VECTOR (12 downto 0);
				data_rom : in STD_LOGIC_VECTOR (2 downto 0);
				-------------------
				RED : out STD_LOGIC;
				GRN : out STD_LOGIC;
				BLUE : out STD_LOGIC);
end dibuja;

architecture Behavioral of dibuja is

--------------- LIMITS ---------------
-- EJE X (0,639) ---- EJE Y (0,479)---
--------------------------------------
signal addrb1 : unsigned (9 downto 0);
signal uejex,uejey : unsigned (9 downto 0);
--signal ejexfor : unsigned (14 downto 0);
signal ejeyfor,ejeyforli : unsigned (14 downto 0);
constant limitx : unsigned :="10000000";
constant limity : unsigned :="000000001110111"; --119 
begin

uejex<=unsigned(eje_x);
uejey<=unsigned(eje_y);


------------ nota ------
-- no es lo mismo multiplicar por 40 que multiplicar por 160 y dividir por cuatro
-- las operaciones de bits no son iguales
-- hacer ejempplo a mano
 
 ------ 10 12 16 --------- proceso de rom----------------

centra : process (uejey,uejex)
begin
addrb1<= (uejey(7 downto 3)& uejex(7 downto 3))+ "1000000000"; --concatenamos deslpazando
--ejeyfor<=(uejex(9 downto 2)&"00" + uejex(9 downto 2))&"00000"; -- multiplicar por 160

  if (addrb1>"1111111111") then
		addrb<=std_logic_vector(addrb1-"10000000000");
  else
		addrb<=std_logic_vector(addrb1);
  end if;
  
	--- ROM -------------------------------------------------
  if (uejex<640 and uejey<480) then 
   addr_ROM<=std_logic_vector(uejey(8 downto 3)& uejex(9 downto 3));
  else
	addr_ROM<=((others=>'0'));
  end if;

end process;


dibuja: process(datab,uejex,uejey,data_rom)
begin
			if ((uejex > 512 or uejex < 256) or (uejey < 128 or uejey > (128+256))) then
			RED<=data_rom(2); 
			GRN<=data_rom(1);  
			BLUE<=data_rom(0);
			-- fondo background --
			else
				case datab is  	
				 --- el blanco y el negro va en negativo ----
				when ("00000") => RED<='1'; GRN<='1';  BLUE<='1';  -- hueco blanco 
				when ("00001") => RED<='0'; GRN<='1';  BLUE<='0'; -- cabeza
				when ("11110") => RED<='0'; GRN<='1';  BLUE<='1'; -- seta
				when ("11111") => RED<='0'; GRN<='0';  BLUE<='1'; --  muro azul
				when ("01010") => RED<='1'; GRN<='0';  BLUE<='0'; -- esquina
				when others => -- cuerpo
				RED<= '0'; 
				GRN<= '1'; -- provisional
				BLUE<= '0';	
				end case;
			end if;
end process;


end Behavioral;

