/*
 * author: Kevin Naughton Jr.
 */


#ifndef _PROJECT3_H_
#define _PROJECT3_H_

/* If you wish to use different definitions
 * of the following structures, provide new
 * definitions (do not remove the existing ones).
 */

typedef struct data_ { 
	double d;
	int n1; 
	int n2;
} data; 


typedef struct { 
	char c1;
	double f1;
	int n1; 
	char c2;
	int n2;
	double f2; 
} data_2; 

/* optimized organization of data_2 struct
 * reorganized attributes of the struct in decreasing
 * size in order to minimize padding
 */
typedef struct {
	double f1; //8 bytes
	double f2; //8 bytes
	int n1; //4 bytes
	int n2; //4 bytes
	char c1; //1 byte
	char c2; //1 byte
} data_OPT;


typedef struct node_ { 
	data value;
	struct node_ * next; 
} node; 




/* DO NOT modify anything below this line */

#define SMALL   64
#define N	    1024
#define DIM     512
#define DIM2    1024
#define LARGE   10000
#define LARGER  50000

int level_0( int * B, int x, int y );

int level_0_opt( int * B, int x, int y );


double level_1(double * B, double * A, int x, int y ); 

double level_1_opt(double * B, double * A, int x, int y );

char * level_2();

char * level_2_opt();

long  level_3(long * B, long * A, int x); 

long level_3_opt(long * B, long * A, int x);


void addBack(data * s,  node ** head); 

void addFront(data * s,  node ** head);

void level_4( node** head, int length); 

void level_4_opt(node** head, int length);



#endif 
