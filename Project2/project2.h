

#ifndef _PROJECT2_H_
#define _PROJECT2_H_

//@author Kevin Naughton Jr.

 /* Compares parameters x and y and
 * returns the greater of the two.
 */
long problem1(long x, long y);

 /* Sets return value to three times the value of the first parameter.
 * Multiplies the return value by 16.
 * Sets variable z to y + 31
 * Reassigns variable z to second parameter if y is >= 0
 * Multiplies the corresponding z by 32
 * Reassigns the return value by performing a bitwise and (&) operation
 * on the return value and variable z
 * Returns the result of all the aforementioned computations
 */
long problem2(long x, long y);

 /* checks if the second parameter is >= 0 : condition 1
 * if condition 1 holds, checks if the second parameter is <= 7 : condition 2
 * if condition 2 holds, initializes z1 to 8 * y casted into a char, initializes
 * first parameter to the first parameter shifted by the value of z1 casted into a char,
 * sets return value to x and returns the return value casted into a char.
 * if only condition 1 holds, the return value is set to 0 and 0 is returned.
 * if neither condition holds, the  return value is set to 0 and 0 is returned.
 */
char problem3(long x, int y);

 /* returns the sum of all values within the array after incrementing
 * each index by the size of the array.
 */
long problem4(long * array, int y);

 /* increments the value of the current index of the array by value 
 */
long comp4(long * pointer, long y);

 /* creates an array of size 10 and initializes
 * each value of the array to a random number
 * modulus 201. It then returns the product
 * of all elements of the array excluding the
 * last index (computed by comp5)
 */
long problem5();

 /* returns the product of all elements
 * with array excluding the last index     
 */
long comp5(long * array, int size);

#endif



