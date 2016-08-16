#include "project2.h"

/* @author Kevin Naughton Jr.
 * checks if the second parameter is >= 0 : condition 1
 * if condition 1 holds, checks if the second parameter is <= 7 : condition 2
 * if condition 2 holds, initializes z1 to 8 * y casted into a char, initializes
 * first parameter to the first parameter shifted by the value of z1 casted into a char,
 * sets return value to x and returns the return value casted into a char.
 * if only condition 1 holds, the return value is set to 0 and 0 is returned.
 * if neither condition holds, the  return value is set to 0 and 0 is returned.
 */
char problem3(long x, int y) {
	//declare return value
	int returnValue;
	
	//check if y is greater than or equal to 0
	if(y >= 0) {
		//check if y is less than or equal to 7
		if(y <= 7) {
			//intialize z1
			int z1 = (char)(8 * y);
			
			//shift x by z1 and cast to char
			x = (char)(x >> z1);
			
			//set return value to x
			returnValue = x;
			
			//cast return value to char and return
			return (char)returnValue;
		}
		//set return value to 0
		returnValue = 0;
		
		//return
		return returnValue;
	}
	//set return value to 0
	returnValue = 0;
	
	//return
	return returnValue;
	
}
