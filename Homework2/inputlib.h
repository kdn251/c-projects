/****************************************************************************
 * inputlib.h
 *
 * M. Farbood
 *
 * Declarations for functions defined in inputlib.c.
 * Based on Eric Roberts' genlib.h and simpio.h and 
 * Glenn Holloway and David Malan's cs50 library.
 *
 ***************************************************************************/

#ifndef _INPUTLIB_H_
#define _INPUTLIB_H_

#include <float.h>
#include <limits.h>

/*
 * char getChar()
 *
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If line can't be read, returns CHAR_MAX.
 */

char getChar();


/*
 * double getDouble()
 *
 * Reads a line of text from standard input and returns the equivalent
 * double as precisely as possible; if text does not represent a
 * double, user is prompted to retry.  Leading and trailing whitespace 
 * is ignored.  For simplicity, overflow and underflow are not detected.  
 * If line can't be read, returns DBL_MAX.
 */

double getDouble();


/*
 * float getFloat()
 *
 * Reads a line of text from standard input and returns the equivalent
 * float as precisely as possible; if text does not represent a float,
 * user is prompted to retry.  Leading and trailing whitespace is ignored.
 * For simplicity, overflow and underflow are not detected.  If line can't 
 * be read, returns FLT_MAX.
 */

float getFloat();


/*
 * int getInt()
 *
 * Reads a line of text from standard input and returns it as an
 * int in the range of [-2^31 + 1, 2^31 - 2], if possible; if text
 * does not represent such an int, user is prompted to retry.  Leading 
 * and trailing whitespace is ignored.  For simplicity, overflow is not 
 * detected.  If line can't be read, returns INT_MAX.
 */

int getInt();


/*
 * long getLong()
 *
 * Reads a line of text from standard input and returns an equivalent
 * long int, if possible; if text  does not represent such a long, 
 * user is prompted to retry. 
 * Leading and trailing whitespace is ignored.  For simplicity, overflow 
 * is not detected.  If line can't be read, returns LONG_MAX.
 */

long getLong();


/*
 * string getString()
 *
 * Reads a line of text from standard input and returns it as a string,
 * sans trailing newline character.  Leading and trailing whitespace is not
 * ignored.  Returns NULL upon input error or upon EOF.
 */

char *getString();



#endif
