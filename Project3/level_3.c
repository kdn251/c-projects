/*
 * author: Kevin Naughton Jr.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_3_opt. It should perform the same 
// task as the implemented level_3 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry. 

long level_3(long * B, long * A, int x)
{
	long * C = (long * ) calloc (N,sizeof(long) );
	if (!C) return 0; 
	
    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r ] = B[ r*N + c ] + A[ c*N + r ] ;
	
	long ret = C[x];
	free (C); C = 0; 
    return ret;
}


/*
 * performs the same task as level_3 with fewer cache misses
 * as a result of only computing and overwriting the index corresponding 
 * to the last iteration of the inner for loop for r = 0 to N
 */
long level_3_opt(long * B, long * A, int x)
{
	//allocate memory
	long * C = (long * ) calloc (N,sizeof(long) );
	
	//ensure that memory was allocated properly
	if (!C) return 0; 
	
	//declare c and r
	int c, r;
	
	//only compute last iteration because values are constantly overwritten
	for(r = 0; r < N; r++) {
		for(c = 0; c < N; c++) {
			//check if at last iteration of inner loop
			if(c == N - 1) {
				//assign C[r] by referencing indices of array A and array B
				C[r] = B[r * N + c] + A[c * N + r];
			}
		}
	}

	//DO NOT modify the rest of this function 
	long ret = C[x]; //store return value
	free (C); C = 0;  //free C
    return ret; //return
}



