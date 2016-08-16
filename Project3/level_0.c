/*
 * author: Kevin Naughton Jr.
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>

#include "proj3.h"


// Implement a C function called level_0_opt. It should perform the same 
// task as the implemented level_0 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 

// Note: this is a warmup level. It will not be graded. 

int level_0( int * B, int x, int y )
{
	if (!B) return -1; 
	
    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            B[ r*N + c ] = 2*(B[ r*N + c ] + 2);

    
    return  B[ x*N + y ];
}


int level_0_opt( int * B, int x, int y )
{
	if (!B) return -1; 
	
    

    
    return  B[ x*N + y ];
}
