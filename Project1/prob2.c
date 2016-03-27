/*
 * TODO: implement your solution to problem 2 in this file.
 */
 
#include "proj1.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[] )  {
	
	//create array of characters to store letters
	char *letters = malloc(sizeof(int));
	
	//check the number of command line arguments
	if(argc < 3) {
		printf("3 arguments are required");
		return 1;
	}
	
	//declare files
	FILE *inputFile;
	FILE *outputFile;
	
	//open input file
	inputFile = fopen(argv[1], "r");
	
	//open output file
	outputFile = fopen(argv[2], "w");
	
	//check if the file exists
	if(inputFile == NULL) {
		printf("Input file does not exist");
		return -1;
	}
	
	//check if output file exists
	if(outputFile == NULL) {
		printf("output file does not exist");
		return -1;
	}
	
	
	//read characters until the end of the file has been reached
	char current;
	int i = 0;
	int count = -1;
	while(fscanf(inputFile, "%c", &current) == 1) {
		letters[i] = current; //set ith index of letters equal to current character
		i++;
		count++;
		//check if letters is full
		if(i % 4 == 0) {
			int numberEquivalentOfCurrentLine = convert_to_int(letters);
			fprintf(outputFile, "%d\n", numberEquivalentOfCurrentLine); //write number to output file
			i = 0; //set i back to first index location of letters
		}
			
	}
	
	//if number of characters is not divisible by 4 write last 1, 2, or 3 characters to the output
	if(count % 4 != 0) {
		//set current index to null character
		letters[i] = '\0';
	
		//pass last 1-3 characters to function
		int lastNumber = convert_to_int(letters);
	
		//write last integer to output file
		fprintf(outputFile, "%d\n", lastNumber);
	
	}
	
	//free variables
	free(letters);
	
	return 0;
}
