/*
 * author: Kevin Naughton Jr.
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_2_opt. It should perform the same 
// task as the implemented level_2 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 

// Note: you may observe that this function performs "useless" looping
// over an array of structures that are all filled with zero bits. 
// Your task is not to remove that "useless" code, but modify it 
// so that it is more cache friendly. 
// You also should not be removing any parts of the structures.
//
// (In an actual application, the structures would be populated with
// real data and the loop would be computing some real results.) 


char * level_2()
{
    data_2 * B = (data_2 * ) calloc( LARGER, sizeof(data_2) ) ;
	if (!B) return 0; 
	double sum_f = 0.0;
	double sum_n = 0; 
	char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) );	
	sum_c[2*LARGER] = '\0'; 
	
    int i; 

	for(i = 0; i < LARGER; i++){
		sum_f += B[i].f1 + B[i].f2; 
		sum_n += B[i].n1 + B[i].n2; 
		sum_c[2*i] = B[i].c1;
		sum_c[2*i+1] = B[i].c2;
	}
	
	
    free(B); 
    return sum_c;
}


/*
 * performs the same task as level_2 with fewer cache misses
 * as a results of reorganizing the data_2 struct to minimize
 * padding
 */
char * level_2_opt()
{	
	// create the array of structures (same or equivalent to the one
	// in the function above: 
	data_OPT *B = (data_OPT *) calloc(LARGER, sizeof(data_OPT));
	if(!B) return 0;


	// DO NOT modify the following declarations 
	double sum_f = 0.0; //initialize sum_f
	double sum_n = 0;  //initialize sum_n
	char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) ); //intitalize sum_c
	sum_c[2*LARGER] = '\0'; //set last index of sum_c to NULL character
	
	// enter your code here (make sure to free the array B once 
	// before returning) 
	
	//declare i
	int i;
	
	//iterate through array B of data_OPT structs
	for(i = 0; i < LARGER; i++) {
		//add current data_OPT struct's f1 and f2 to sum_f
		sum_f += B[i].f1 + B[i].f2;
		
		//add current data_OPT struct's n1 and n2 to sum_n
		sum_n += B[i].n1 + B[i].n2;
		
		//set current data_OPT struct's c1 to the 2 * i index of sum_c
		sum_c[2 * i] = B[i].c1;
		
		//set current data_OPT struct's c2 to the 2 * i + 1 index of sum_c
		sum_c[2 * i + 1] = B[i].c2;
	}
	
	//free B
	free(B);
	
	//return
	return sum_c;
    
    
	//DO NOT modify the rest of this function 
    return sum_c;
}

