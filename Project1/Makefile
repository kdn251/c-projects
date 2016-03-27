# Makefile for project 1
#
# Modify this file if you need to add files to 
# compilation/builld. 

CC		= gcc

CFLAGS		= -g  -Wall

LDLIBS = -lm

all: prob1 prob2 prob5

prob1: prob1.c proj1.o proj1.h 
	$(CC) $(CFLAGS) -o prob1 prob1.c proj1.o $(LDLIBS)

prob2: prob2.c proj1.o proj1.h 
	$(CC) $(CFLAGS) -o prob2 prob2.c proj1.o $(LDLIBS)

prob5: prob5.c proj1.o proj1.h 
	$(CC) $(CFLAGS) -o prob5 prob5.c proj1.o $(LDLIBS)

#prob1.o: prob1.c proj1.h proj1.c
#prob2.o: prob2.c proj1.h proj1.c 
#prob3.o: prob3.c proj1.h proj1.c 
proj1.o: proj1.c proj1.h
	$(CC) $(CFLAGS) -c proj1.c $(LDLIBS)


clean:		
	rm -f *~ *.o a.out core prob1 prob2 prob5

