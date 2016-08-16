# Makefile for project 3
# 
# DO NOT modify this file 

FILES := procline.c userin.c runcommand.c proj4.c proj4.h  
CC		= gcc
CFLAGS := -g -Og -std=gnu99 

all: proj4 test_run test_run_loop

proj4: $(FILES)
	cc -o proj4   $(FILES) 
    

	
test_run: test_run.c 
	cc -o test_run test_run.c 	
	
test_run_loop: test_run_loop.c 
	cc -o test_run_loop test_run_loop.c 
	
test_run_sleep: test_run_sleep.c 
	cc -o test_run_sleep test_run_sleep.c 
	
test_run_pause: test_run_pause.c 
	cc -o test_run_pause test_run_pause.c 

clean: 
	rm -f *~ proj4 proj4.o *.o a.out test_run test_run_loop test_run_pause test_run_sleep core
