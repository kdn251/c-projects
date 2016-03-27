#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

/*
 * TODO: add your funcitons in this file. 
 * Make sure that you document the code.
 */ 


/*
 *Given an array of integers and its  length, computes a message based on the integers ASCII values
*/
char *convert_to_string(int text[], int size) {
	//allocate memory
	char *message = (char *) malloc(size * sizeof(int));
	
	//check if memory was properly allocated
	if(message == NULL) {
		return NULL;
	}
	
	//cast text from an integer to a character
	message = (char *)text;
	
	//return pointer to decrypted message
	return message;
	
}

/*
 *Given a character array, creates an encrypted message using each character's ASCII value
*/
int convert_to_int(char *text) {
	//allocate memory
	int *numberEquivalent = malloc(sizeof(int));
	
	//check if memory was properly allocated
	if(numberEquivalent == NULL) {
		return -1;
	}
	
	//cast text from a character to an integer
	numberEquivalent = (int *)text;
	
	//set returnNumber to numberEquivalent
	int returnNumber = *numberEquivalent;
	
	//return integer
	return returnNumber;

}

/*
 *Given an integer x, returns the most significant byte
*/
int get_most_significant_byte(int x) {
	//shift bytes to get the most significant byte
	int shift = (x >> sizeof(x) * 6) & 0xff;
	
	//return the most significant byte
	return shift;
	
}
/*
 *Given an integer x, returns the least significant byte
*/
int get_least_significant_byte(int x) {
	//shift bytes to get the least significant byte
	int shift = (x >> sizeof(x) * 0) & 0xff;
	
	//return the most significant byte
	return shift;
	
}


char* get_bits_float ( float f ) {
	//allocate memory to store the string
	int num_of_bits =  sizeof(float) * 8;  //*8 since there are 8 bits per byte 
	char * bits_of_numbers = (char*) malloc( num_of_bits + 1);
	
	//interpret the bits as int (this is not equivalent to casting to int) 
	int  p = *((int*) (&f) );
	short bit; 
	
	int i;
	//convert value of n to bits 
	for ( i = 0; i < sizeof(float)*8; i++ ) {
		bit = p & 1;  //grab the last bit
		bits_of_numbers[num_of_bits-i-1] = '0' + bit;
		p = p>>1;    //remove the last bit
	}
	
	bits_of_numbers[num_of_bits] = '\0'; //end with a null character
	return bits_of_numbers; 
	
}


unsigned int *get_exp(float f) {
	//store binary representation of f
	char *bits = get_bits_float(f);
	
	//store the 8 exp bits of f
	char expBits[9];
	
	//copy exp of f to expBits
	int i;
	for(i = 0; i < 8; i++) {
		expBits[i] = bits[i+1];
	}
	
	//set last index to null character
	expBits[8] = '\0';
	
	//calculate decimal representation of exp bits
	int j;
	int total = 0;
	int bitPos = 7;
	for(j = 0; j < 8; j++) {
		if(expBits[j] == '1') {
			total += pow(2, bitPos - j); //add current bits value to total
		}
		else {
			continue; //continue if current bit is a 0
		}
	}
	
	//shift to proper position
	int expShifted = (total << 23);
	
	//cast to unsigned int
	unsigned int unsignedExp = (unsigned int)expShifted;
	
	//free variable
	free(bits);
	
	//return pointer to exp bits of f
	return unsignedExp;

}


unsigned int *get_frac(float f) {
	//store binary representation of f
	char *bits = get_bits_float(f);

	//store the 23 frac bits of f
	char fracBits[23];
	
	//copy frac of f to fracBits
	int i;
	int k = 0;
	for(i = 9; i < 32; i++) {
		fracBits[k] = bits[i];
		k++; //move to next index
	}
	
	//set last index to null character
	fracBits[24] = '\0';
	
	//calculate decimal representation of frac bits
	int j;
	int total = 0;
	int bitPos = 22;
	for(j = 0; j < 23; j++) {
		if(fracBits[j] == '1') {
			total += pow(2, bitPos - j); //add current bits value to total
		}
		else {
			continue; //continue if current bit is a 0
		}
	}

	
	//cast to unsigned int
	unsigned int *unsignedFrac = (unsigned int)total;
	
	//free variable
	free(bits);
	
	//return pointer to frac bits of f
	return unsignedFrac;

}

/*
 *Given a floating point number, returns its sign bit 
*/
unsigned int *get_sign(float f) {
	//store binary representation of f
	char *bits = get_bits_float(f);
	
	//convert most significant bit to int
	unsigned int signBit = (unsigned int) (bits[0] - '0');
	
	//shift to correct location
	unsigned int signBitShifted = (signBit << 31);
	
	//free variable
	free(bits);
	
	//return signed bit
	return signBitShifted;
	
}





char* get_bits_int ( int n ) {
	//allocate memory to store the string 
	int num_of_bits =  sizeof(int) * 8;  //*8 since there are 8 bits per byte 
	char * bits_of_numbers = (char*) malloc( num_of_bits + 1);
	
	short bit ; 
	
	int i;
	//convert value of n to bits 
	for ( i = 0; i < num_of_bits; i++ ) {
		bit = n & 1; //grab the last bit
		bits_of_numbers[num_of_bits-i-1] = '0' + bit;
		n = n>>1;    //remove the last bit
	}
	
	bits_of_numbers[num_of_bits] = '\0'; //end with a null character
	return bits_of_numbers; 
}

int is_denormalized(float f) {
	//store exp bits of f
	unsigned int expBits = get_exp(f);
	
	//store binary representation of f
	char *expBinary = get_bits_int(expBits);
	
	//check if all exp bits are 0s
	int i;
	int count = 0; //set count for 0s
	for(i = 1; i < 9; i++) {
		if(expBinary[i] == '0') {
			count++; //increment 0 count
		}
		else {
			continue;
		}
	}
	//if exp bits are all 0s return true
	if(count == 8) {
		free(expBinary);
		return 1;
	}
	//return false
	else {
		free(expBinary);
		return 0;
	}	
	
}

int is_special(float f) {
	//store exp bits of f
	unsigned int expBits = get_exp(f);
	
	//store binary representation of f
	char *expBinary = get_bits_int(expBits);
	
	//check if all exp bits are 1s
	int i;
	int count = 0;
	for(i = 1; i < 9; i++) {
		if(expBinary[i] == '1') {
			count++;
		}
		else {
			continue;
		}
	}
	//if exp bits are all 1s return true
	if(count == 8) {
		free(expBinary);
		return 1;
	}
	//otherwise return false
	else {
		free(expBinary);
		return 0;
	}

}
int is_normalized(float f) {
	//return true if exp bits are all 1s or all 0s
	if((!is_denormalized(f)) && (!is_special(f))) {
		return 1;
	}
	//otherwise return false
	else {
		return 0;
	}	
	
}

int get_E(float f) {
	//declare value to return
	int E;
	//store exp value
	unsigned int exp = get_exp(f);
	
	//store shifted exp value
	unsigned int expShifted = (exp >> 23);
		
	//compute bias
	int bias = pow(2, (8-1)) - 1;
	
	//check if E is normalized
	if(is_normalized(f)) {
		E = expShifted - bias;
	}
	//check if f is denormalized
	else if(is_denormalized(f)) {
		E = 1 - bias;
	}
	//otherwise f is a special case
	else {
		//FIGURE OUT HOW TO CALCULATE E FOR SPECIAL CASES - CHECK THIS E = 255 MIGHT NOT APPLY TO ALL SPECIAL CASES
		E = 255;
	}
	
	//return correct value of E
	return E;
}

char *get_M(float f) {
	//store frac bits of f
	unsigned int *frac = get_frac(f);
		
	//store binary representation of frac bits of f
	char *fracBinary = get_bits_int(frac);
	
	//declare character array to store M
	char *fracBits = (char *) malloc(sizeof(char) * 26);
	
	//check if memory was properly allocated
	if(fracBits == NULL) {
		return NULL;	
	}
	
	//set second  index to decimal point
	fracBits[1] = '.';
	
	//check if f is normalized
	if(is_normalized(f)) {
		//set first index to 1
		fracBits[0] = '1';
		//declare i for loop
		int i;		
		//keep index of fracBits
		int j = 2;
		//keep index of fracBinary
		int k = 9;
		//assign last 23 bits of fracBinary to fracBits
		for(i = 0; i < 23; i++) {
			fracBits[j] = fracBinary[k];
			j++;
			k++;
		}
	}
	//check if f is denormalized
	else if(is_denormalized(f)) {
		//set first index to 1
		fracBits[0] = '0';
		//declare i for loop
		int i;		
		//keep index of fracBits
		int j = 2;
		//keep index of fracBinary
		int k = 9;
		//assign last 23 bits of fracBinary to fracBits
		for(i = 0; i < 23; i++) {
			fracBits[j] = fracBinary[k];
			j++;
			k++;
		}
	}
	//set M to empty string for special cases
	else {
		int i;
		for(i = 0; i < 23; i++) {
			fracBits[i] = ' ';
		}
	}
	
	//set last index to null character
	fracBits[25] = '\0';
	
	//free variable
	free(fracBinary);
		
	//return pointer to fracBits array	
	return fracBits;
	
}

int get_s(float f) {
	unsigned int sign = get_sign(f);
	int returnSign = sign >> 31;	
	
}
