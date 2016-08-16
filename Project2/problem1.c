#include "project2.h"
  
/*
 * @author Kevin Naughton Jr.
 * Compares parameters x and y and
 * returns the greater of the two.
 */
long problem1(long x, long y) {
	//create return value
	long returnValue;
	
	//check if x is greater than y
	if(x > y) {
		returnValue = x; //set return value to x
		return returnValue;
	}
	
	//y is greater than x
	returnValue = y; //set return value to y
	return returnValue;
}
