## 
# Makefile of tic_tac_toe
# 
# Written by Gustavo Bacagine in April 2024
# 

tic_tac_toe: tic_tac_toe.o
	gcc -o tic_tac_toe tic_tac_toe.o -Wall -Wextra
tic_tac_toe.c:
	gcc -c tic_tac_toe.c -o tic_tac_toe.o

clean:
	rm tic_tac_toe.o
distclean: clean
	rm tic_tac_toe

.PHONY: clean distclean

