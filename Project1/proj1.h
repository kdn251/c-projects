/*
 * This is the header file for project 1.
 * It contains declarations of functions
 * that are defined in proj1.c file.
 * 
 * If you define any additional functions, 
 * you should add their declarations to this file.  
 * 
 */ 

#ifndef _PROJ1_H_
#define _PROJ1_H_



char *convert_to_string(int text[], int size); //REMINDER: comment this function

/*
 * Computes and returns a c-string containting
 * the binary vector representation of the parameter n. 
 */
char * get_bits_int ( int n );

/*
 * Computes and returns a c-string containting
 * the binary vector representation of the parameter f. 
 */
char * get_bits_float ( float f );

/*
 * Converts the next size-many integers from the text array
 * to a null terminated character array that is returned.
 * The function allocates memory for the string.   
 */
char * convert_to_string ( int text[] , int size );

/*
 * Extracts and returns the value of the most significant 
 * byte of num.  
 */
int get_most_significant_byte ( int num );

/*
 * Extracts and returns the value of the most significant 
 * byte of num.  
 */
int get_least_significant_byte ( int num );

/*
 * Return the bits corresponding to exp field of 
 * IEEE single precission floating point. All other bits
 * are set to zero.
 * Assumption sizeof(int) = sizeof(float).
 */
unsigned int * get_exp ( float f );

/*
 * Return the bits corresponding to frac field of 
 * IEEE single precission floating point. All other bits
 * are set to zero.
 * Assumption sizeof(int) = sizeof(float).
 */
unsigned int * get_frac ( float f );

/*
 * Return the bits corresponding to sign field of 
 * IEEE single precission floating point. All other bits
 * are set to zero.
 * Assumption sizeof(int) = sizeof(float).
 */
unsigned int * get_sign ( float f ) ;

/*
 * Determines if the parameter f represented using
 * IEEE single precission floating point is using normalized 
 * encoding. Returns zero to indicate false, and any non-zero 
 * value to indicate true.
 * Assumption sizeof(int) = sizeof(float).
 */
int is_normalized ( float f ) ;

/*
 * Determines if the parameter f represented using
 * IEEE single precission floating point is using denormalized 
 * encoding. Returns zero to indicate false, and any non-zero 
 * value to indicate true.
 * Assumption sizeof(int) = sizeof(float).
 */
int is_denormalized ( float f );

/*
 * Determines if the parameter f represented using
 * IEEE single precission floating point is using special value 
 * encoding. Returns zero to indicate false, and any non-zero 
 * value to indicate true.
 * Assumption sizeof(int) = sizeof(float).
 */
int is_special ( float f ) ;

/*
 * Computes and return the value of M (fractional part) of   
 * IEEE single precission floating point number. 
 * Assumption sizeof(int) = sizeof(float).
 */
char * get_M ( float f ) ;

/*
 * Computes and return the value of s (sign) of   
 * IEEE single precission floating point number. 
 * Assumption sizeof(int) = sizeof(float).
 */
int get_s ( float f );

/*
 * Computes and return the value of E (exponent) of   
 * IEEE single precission floating point number. 
 * Assumption sizeof(int) = sizeof(float).
 */
int get_E ( float f ) ;


#endif
