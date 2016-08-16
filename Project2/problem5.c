#include "project2.h"
#include <stdlib.h> 
#include <stdio.h>

/*
 * @author Kevin Naughton Jr.
 * returns the product of all elements
 * with array excluding the last index     
 */
long comp5(long * array, int size) {
	//declare return value
	long returnValue;
	
	//intialize count
	int count = 0;
	
	returnValue = 1;
	
	int totalValue = 0;
	
	//decrement size
	size = size - 1;
	
	while(size > count) {
		
		//store current iteration of while loop
		int currentIteration = count;
		
		//store value of current index of the array
		long currentValue = array[currentIteration];
		
		//update array's total value
		totalValue = totalValue + currentValue;
		
		//update return value
		returnValue = returnValue * currentValue;
		
		//increment fourthArg
		count = count + 1;
	
	}
	
	//divide return value by total value of the array
	returnValue = returnValue / totalValue;
	
	//return result
	return returnValue;
}
/*
 * @author Kevin Naughton Jr.
 * creates an array of size 10 and initializes
 * each value of the array to a random number
 * modulus 201. It then returns the product
 * of all elements of the array excluding the
 * last index (computed by comp5)
 */
long problem5() {
	//declare return value
	int returnValue;
	
	//initalize 
	int size = 10;
	
	//declare array
	long array[size];
	
	//initialize count
	int count = 0;
			
	//set index of array to a random number % 201
	while(count <= 9){
		//intialize random number
		int randomNumber = (rand()) % 201;
		
		//set current index of array equal to random number
		array[count] = randomNumber;
		
		//increment count
		count++;
	
	}
	
	//store return value of helper function
	long comp5ReturnValue = comp5(array, size);
	
	//return
	return comp5ReturnValue;
	
}
