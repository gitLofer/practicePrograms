library IEEE;
use IEEE.std_logic_1164.all;

-- entity
entity timer is
port ( 
	CLR,CLK	: in std_logic;
	TIME_MS	: out std_logic);
end timer;
-- entity end

--architecture
architecture arch of timer is
	
signal Ticks : unsigned integer := 0;
signal MiliSeconds : unsigned integer range 0 to 255 := 0;
	
begin
	
    process(CLK) is
    begin
        if rising_edge(CLK) then
 
            -- If the reset signal is active
            if CLR = '1' then
                Ticks   <= 0;
            else
                -- True every 1000th rising edge
                if Ticks = 999 then
                    Ticks <= 0;
					if (MiliSeconds = 250) then 
						TIME_MS <= 1;
						MiliSeconds <= 0;
					else 
						MiliSeconds <= MiliSeconds + 1; 
					end if;
                else
                    Ticks <= Ticks + 1;
                end if;
 
            end if;
        end if;
		
    end process;
	
end arch;

-----------------------

library IEEE;
use IEEE.std_logic_1164.all;


entity tetris_logic is
port ( 	INPUT	 	: in std_logic_vector(3 downto 0) 
		M_CLK,RST	: in std_logic);
entity end;

architecture arch_tetris of tetris_logic is

type bit_matrix is array(0 to 9, 0 to 23) of std_logic;
type block_shape is (I, L, J, O, T, Z, S);
type state_type is (ST0, ST1, ST2, ST3, ST4, ST5, ST6, ST7);		

signal tetris_map : bit_matrix := (others => (others = > 0));

type tetris_block is 
	record
		signal blockType : block_shape;
		signal currentRotation : std_logic_vector (0 to 1) := "00";
		--Position of the block - First two numbers are the height, last number is width
		signal a1 : integer range 0 to 239;
		signal a2 : integer range 0 to 239;
		signal a3 : integer range 0 to 239;
		signal a4 : integer range 0 to 239;
	end record;

--NS: Next state, PS: Present state
signal PS, NS : state_type;
signal timer_passed : std_logic := 0;
--signal miliseconds_passed : unsigned integer := 0;


	
component timer is
	Port (	CLR,CLK	: in std_logic;
			TIME_MS	: out std_logic);
end component;
	
begin
	
	x1 : timer port map (	CLR => RST,
							CLK => M_CLK,
							TIME_MS => timer_passed);
							
	--Changes Next state (NS)
	sync_process: process (timer_passed, NS, M_CLK, RST)
	begin
		if (RST = 1) then 
			PS <= ST0;
		elsif (rising_edge(M_CLK))
		--Input
			if (
			elsif (timer_passed = 1) then
				PS <= ST3;
				NS <= ST0;
				timer_passed <= 0;
			else 
				PS <= NS;
			end if;
		end if;
		
end arch_tetris
