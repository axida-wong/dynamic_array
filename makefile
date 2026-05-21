.PHONY=ALL 
FLAGS=-Wall -std=c17 -D_GNU_SOURCE -g 

ALL : dyarr_test.c dyarr.o
	gcc -g -o dyarr_test dyarr_test.c dyarr.o

dyarr.o: dyarr.c
	gcc -c -g dyarr.c

clean: 
	rm *.o dyarr_test