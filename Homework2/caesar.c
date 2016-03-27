/* IMPLEMENT YOUR CODE IN THIS FILE */

/* 
 *  Name: Kevin Naughton Jr.
 *  
 */ 


//COMMENT ENTIRE FILE INCLUDING FUNCTIONS! 


#include "inputlib.h"
//add other include statements below 
#include <stdio.h>
#include <ctype.h>

//declare encrypt and decrypt functions
char *encrypt(char *userMessage, int userKey);
char *decrypt(char *userMessage, int userKey);


int main ( ) {
	
	//print the application banner
	printf("=====================\n");
	printf("Encrypt/Decrypt Tool\n");
	printf("=====================\n\n");
	
	//user chooses encrypt or decrypt	
	printf("What would you like to do? (E)ncrypyt or (D)ecrypyt?  ");
	char userChoice = getChar(); //store character
	
	
	
	//validate 1st user input
	if((userChoice != 'E') && (userChoice != 'e') && (userChoice != 'D') && (userChoice != 'd')) {
		printf("ERROR:  invalid choice.\n");
		return(-1); //exit program
	}
	
	//user enters value key (automatically validated by function)
	printf("Enter your encryption key:  ");
	int userKey = getInt(); //store key value
		
	//user enters message to encrypt or decrypt
	printf("Enter your message:  ");
	char *userMessage = getString(); //store user message

	//call either encrypt or decrypt function depending on user input
	if((userChoice == 'E') || (userChoice == 'e')) {
		encrypt(userMessage, userKey); //call encrypt function
		printf("Your encrypted message is:  %s\n", userMessage); //display user's encrypted message
	}
	else {
		decrypt(userMessage,userKey); //call decrypt function
		printf("Your decrypted message is:  %s\n", userMessage); //display user's decrypted message
	}
		
	
	return 0; //program has terminated "successfully"
}

/*
 * encrypts a user's message based on a user provided shift value
 * @param *userMessage - pointer to the message that will be encrypted
 * @param userKey - user provided shift value
 * @return userMessage - pointer to the encrypted user message
*/
char *encrypt(char *userMessage, int userKey) {
	//ensure alphabet characters do not surpass 'Z'
	int totalShift = userKey % 26;
	
	//loop until end of user message
	int count = 0;
	while(userMessage[count] != '\0') {
		//if current character is an alphabetical character
		if(isalpha(userMessage[count])) {
			//if current letter is an uppercase letter
			if(isupper(userMessage[count])) {
				//if userKey is a positive number shift right
				if(totalShift >= 0) {
					//loop until correct shift has been applied
					int i;
					for(i = totalShift; i > 0; i--) {
						(userMessage[count])++; //increment letter
						if(userMessage[count] > 90) { //wrap back to 'A'
							userMessage[count] = 65;
						}
					}
				}
				//if userKey is a negative number shift left
				if(totalShift < 0) {
					//loop until correct shift has been applied
					int j;
					for(j = totalShift; j < 0; j++) {
						(userMessage[count])--; //decrement letter
						if(userMessage[count] < 65) { //wrap back to 'Z'
							userMessage[count] = 90;
						}
					}
				}
			}
			//if current letter is a lowercase letter
			else if(islower(userMessage[count])) {
				if(totalShift >= 0) {
					//loop until correct shift has been applied
					int i;
					for(i = totalShift; i > 0; i--) {
						(userMessage[count])++; //increment letter
						if(userMessage[count] > 122) { //wrap back to 'a'
							userMessage[count] = 97;
						}
					}
				}
				//if userKey is a negative number shift left
				if(totalShift < 0) {
					//loop until correct shift has been applied
					int j;
					for(j = totalShift; j < 0; j++) {
						(userMessage[count])--; //decrement letter
						if(userMessage[count] < 97) { //wrap back to 'z'
							userMessage[count] = 122;
						}
					}
				}
			}
		}
		count++; //move to next character in user message
	}
	return userMessage; //return encrypted user message
}

/*
 *decrypts a user's message based on a user provided shift value
 * @param *userMessage - pointer to the message that will be decrypted
 * @param userKey - user provided shift value
 * @return userMessage - pointer to the decrypted user message
*/ 
char *decrypt(char *userMessage, int userKey) {
	//ensure alphabet characters do not surpass 'Z'
	int totalShift = userKey % 26;
	
	//loop until end of user message
	int count = 0;
	while(userMessage[count] != '\0') {
		//if current character is an alphabetical character
		if(isalpha(userMessage[count])) {
			//if current letter is an uppercase letter
			if(isupper(userMessage[count])) {
				//if userKey is a positive number shift left
				if(totalShift >= 0) {
					//loop until correct shift has been applied
					int i;
					for(i = totalShift; i > 0; i--) {
						(userMessage[count])--; //decrement letter
						if(userMessage[count] < 65) { //wrap back to 'Z'
							userMessage[count] = 90;
						}
					}
				}
				//if userKey is a negative number shift right
				if(totalShift < 0) {
					//loop until correct shift has been applied
					int j;
					for(j = totalShift; j < 0; j++) {
						(userMessage[count])++; //increment letter
						if(userMessage[count] > 90) { //wrap back to 'A'
							userMessage[count] = 65;
						}
					}
				}
			}
			//if current letter is a lowercase letter
			else if(islower(userMessage[count])) {
				if(totalShift >= 0) {
					//loop until correct shift has been applied
					int i;
					for(i = totalShift; i > 0; i--) {
						(userMessage[count])--; //decrement letter
						if(userMessage[count] < 97) { //wrap back to 'z'
							userMessage[count] = 122;
						}
					}
				}
				//if userKey is a negative number shift right
				if(totalShift < 0) {
					//loop until correct shift has been applied
					int j;
					for(j = totalShift; j < 0; j++) {
						(userMessage[count])++; //increment letter
						if(userMessage[count] > 122) { //wrap back to 'a'
							userMessage[count] = 97;
						}
					}
				}
			}
		}
		count++; //move to next character in user message
	}
	return userMessage; //return decrypted user message
}

