LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY ANDgate_Garima IS
	PORT (
	   A : IN STD_LOGIC;
	   B : IN STD_LOGIC;
	   Y : OUT STD_LOGIC
	);
END ANDgate_Garima;

ARCHITECTURE Behaviour OF ANDgate_Garima IS
BEGIN
    Y <= A AND B;
END Behaviour;
