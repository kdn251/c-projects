/*
 * author: Kevin Naughton Jr.
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>

#include "proj3.h"

// Implement a C function called level_1_opt. It should perform the same 
// task as the implemented level_1 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//
// Note: your function needs to compute the entire matrix A,
// not only its x+y entry. 


double level_1(double * B, double * A, int x, int y )
{	
    int i, j; 

    for(i = 0; i < LARGE; i++)
        for(j = 0; j < SMALL; j++){
            A[ i ] = A[i] + B[  j*LARGE + i ];
		}

    return A[x+y];
}
/*
 * performs the same task as level_1 with fewer cache misses
 * as a result of reducing our stride and therefore our spacial
 * locality by flipping the inner and outer loop
 */
double level_1_opt(double * B, double * A, int x, int y )
{	
	//declare i and j
	int i, j;
	
	//flip inner and outer loop to reduce stride
	for(i = 0; i < SMALL; i++) {
		for(j = 0; j < LARGE; j++) {
			//add specific index of B to current A[j] value
			A[j] = A[j] + B[i * LARGE + j];
		}
	}


	//DO NOT modify the rest of this function 
    return A[x+y]; //return x + y index of A
}
