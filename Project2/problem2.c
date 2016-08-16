#include "project2.h"  

/* @author Kevin Naughton Jr.
 * Sets return value to three times the value of the first parameter.
 * Multiplies the return value by 16.
 * Sets variable z to y + 31
 * Reassigns variable z to second parameter if y is >= 0
 * Multiplies the corresponding z by 32
 * Reassigns the return value by performing a bitwise and (&) operation
 * on the return value and variable z
 * Returns the result of all the aforementioned computations
 */
long problem2(long x, long y) {
	//initialize return value to 3x
	long returnValue = 3 * x;
	
	//multiply return value by 16
	returnValue = (returnValue << 4);
	
	//initialize z
	long z = y + 31;
	
	//check if y is greater than or equal to zero
	if(y >= 0) {
		z = y;
	}
	
	//multiply z by 32
	z = (z >> 5);
	
	//perform bitwise and operation on the return value and z
	returnValue = returnValue & z;
	
	//return return value
	return returnValue;
	
	
}
