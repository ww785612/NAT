# NAT
# Description
This program reads NAT translation rules from file "NAT" and performs Network Address Translation on addresses from file "FLOW" and outputs the result to "RESULT.txt".

# Usage
Put file "NAT" and "FLOW" in the same folder, compile the program with the Makefile and run the executable "main".

# Algorithm
Each address in file "FLOW" is compared to entries in the NAT lookup table (a vector) to find a match. The lookup result is put into "RESULT.txt".
Since the NAT table entries are patterns, a special matching algorithm is used to check whether a given address matches to a pattern from the NAT table. Given a pattern string and a network address, the matching algorithm ustilizes a 2D array to store matching results of the two strings at different character positions. The last cell (with largest row index and column index) in the array represents the final matching result of the two strings.
