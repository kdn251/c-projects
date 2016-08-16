# Makefile for project 2
#

OBJS := problem1.o problem2.o problem3.o problem4.o problem5.o
GIVEN := objs/problem1.o objs/problem2.o objs/problem3.o objs/problem4.o objs/problem5.o

CC		= gcc
CFLAGS := -Og -std=gnu99 

all: $(OBJS)

project2: objs/project2.o project2.h $(OBJS)
	$(CC) $(CFLAGS) -o project2 objs/project2.o $(OBJS)

project2_given: objs/project2.o $(GIVEN)
	$(CC) $(CFLAGS) -o project2_given objs/project2.o $(GIVEN)

problem1.o: problem1.c 
	$(CC) $(CFLAGS) -c problem1.c 
problem2.o: problem2.c 
	$(CC) $(CFLAGS) -c problem2.c 
problem3.o: problem3.c 
	$(CC) $(CFLAGS) -c problem3.c 
problem4.o: problem4.c 
	$(CC) $(CFLAGS) -c problem4.c 
problem5.o: problem5.c 
	$(CC) $(CFLAGS) -c problem5.c 


clean:		
	rm -f *~ project2 project2_given problem*.o a.out core


