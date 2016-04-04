/*
 * TODO: implement your solution to problem 1 in this file.
 * @author Kevin Naughton Jr.
 */

#include "proj1.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[] )  {
	
	//create array of integers to store numbers
	int *numbers = malloc(sizeof(int) * 1000);
	
	//check if memory was properly allocated
	if(numbers == NULL) {
		printf("Could not allocate memory\n");
		return -1;
	}
	
	//create file
	FILE *userFile;
	
	//open and read file from command line
	userFile = fopen(argv[1], "r");
	
	//check if the file exists
	if(userFile == NULL) {
		printf("File does not exist\n");
		return -1;
	}
	
	//read integers until the end of the file has been reached
	int current;
	int i = 0; //store the number of lines in the file
	while(fscanf(userFile, "%d", &current) == 1) {
		numbers[i] = current;
		i++;
	}

	
	fclose(userFile); //close file
	
	//call function
	char *messageInWords = convert_to_string(numbers, i);
	

	printf("%s\n", messageInWords);
	
	//free variables
	//free(messageInWords);
	//free(numbers);

	
	return 0;
}
