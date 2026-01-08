LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY NANDgate_Garima IS
	PORT (
	   A : IN STD_LOGIC;
	   B : IN STD_LOGIC;
	   Y : OUT STD_LOGIC
	);
END NANDgate_Garima;

ARCHITECTURE Behaviour OF NANDgate_Garima IS
BEGIN
    Y <= A NAND B;
END Behaviour;
