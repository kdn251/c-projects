/*
 * TODO: implement your solution to problem 5 in this file.
 */
 
#include "proj1.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

 
int main (int argc, char *argv[] )  {
	//prompt user for input
	printf("Please enter a floating point number: ");
	
	//declare variable to store user input
	float userFloat;
	
	//store user input in userFloat
	scanf("%e", &userFloat);
	
	//VALUE - print first line of sample output ***MAKE SURE TO CHANGE TO SCIENTIFIC NOTATION***
	printf("value\t%e\n", userFloat);
	
	//STORE VARIABLE FOR ALL BITS
	char *allBits = get_bits_float(userFloat);

	//ALL BITS - print second line of sample output ***MAKE SURE TO FIX BY SHIFTING LEFT BY 1***
	printf("all bits\t    %32s\n", allBits);
	
	//FREE ALLBITS
	free(allBits);
	
	//STORE VARIABLEs FOR EXP
	unsigned int *expValue = get_exp(userFloat);
	char *expBinary = get_bits_int(expValue);
	
	//EXP - print third line of sample output
	printf("exp\t%10u  %32s\n", expValue, expBinary);	
	
	//FREE VARIABLE FOR EXP
	free(expBinary);
	
	//STORE VARIABLE FOR FRAC
	char *fracBits = get_bits_int(get_frac(userFloat));
	
	//FRAC - print fourth line of sample output
	printf("frac\t%10u  %32s\n", get_frac(userFloat), fracBits);
	
	//FREE VARIABLE FOR FRAC
	free(fracBits);
	
	char *signBits = get_bits_int(get_sign(userFloat));

	//SIGN - print fifth line of sample output
	printf("sign\t%10u  %32s\n", get_sign(userFloat), signBits);
	
	//FREE VARIABLE FOR SIGN
	free(signBits);
	
	//NORMALIZED/DENORMALIZED/SPECIAL - print sixth line of sample output
	if(is_normalized(userFloat)) {
		printf("%e is normalized\n", userFloat); //userFloat is normalized
	}
	else if(is_denormalized(userFloat)) {
		printf("%e is denormalized\n", userFloat); //userFloat is denormalized
	}
	else {
		printf("%e is special\n", userFloat); //userFloat is a special case
	}
	
	//E - print seventh line of sample output
	printf("E = %i\n", get_E(userFloat));
	
	//STORE VARIABLES FOR M
	char *getM = get_M(userFloat);
	
	//M - print eigth line of sample output
	printf("M = %s\n", getM);
	
	//FREE VARIABLE FOR M
	free(getM);
	
	//s - print ninth line of sample output
	printf("s = %i\n", get_s(userFloat));
	
	//exit gracefully
	return 0;
}

