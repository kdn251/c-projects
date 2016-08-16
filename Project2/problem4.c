#include "project2.h"

/*
 * @author Kevin Naughton Jr.
 * increments the value of the current index of the array by value 
 */
long comp4(long * index, long value) {
	
	//store current value
	long returnValue = *index;
	
	//update value
	value = value + returnValue;
	
	//reassign value to current index
	*index = value;
	
	//return
	return returnValue;
	
}
/* @author Kevin Naughton Jr.
 * returns the sum of all values within the array after incrementing
 * each index by the size of the array.
 */
long problem4(long * array, int size) {
	//declare return value
	long returnValue;
		
	//set pointer to first index of array
	long *arrayPointer = array;
	
	//store size of array
	int sizeOfArray = size;
	
	
	//set count to 0
	int count = 0;
	
	//set total to 0
	int total = 0;

	//loop through the array
	for(count; count < sizeOfArray; count++) {
		//set return value to count
		returnValue = count;
		
		//advance current inde
		array = returnValue + arrayPointer;
		
		//set size to 2
		size = 2;
		
		//add current iteration to total
		total = total + comp4(array, size);
		
	}
	
	//set return value to total
	returnValue = total;
	
	//return
	return returnValue;
	
}
		
		

