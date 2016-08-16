/*
 * @author: Kevin Naughton Jr. & Joanna Klukowska
 */ 

#include "proj4.h"
#include <string.h>


// execute a command with optional wait
int runcommand(char **cline, int where) {
    pid_t pid;
    int status;
	
	//Bug 2 Fix - implement change directory (cd) functionality
	//check if cd is typed in command line
    if(strcmp(*cline, "cd") == 0) {
		
		//store second argument of command line as pathname
		char * path = cline[1]; 
		
		//check if only cd is typed
		if(path == NULL || path == "") { 
			//change directory to home directory
			chdir(getenv("HOME"));
		}
		
		//check if a second argument is entered on command line
		else if(path != NULL) { 
			//check if user entered a forward slash as start of path name
			if(path[0] == '/') { 
					
				//change directory to user specified path
				int chdirValue = chdir(path);

				//check if directory was accessed successfully
				if(chdirValue != 0) {
					//print error message to user
					printf("The specified directory does not exist.\n");
				}
			}
		
			
			//check if user entered ".." as second command line argument
			else if(strcmp(path, "..") == 0) {
				//change directory to parent directory
				chdir(path);
			}
			
			//add forward slash to path entered by user
			else {
								
				//declare character array to store backslash
				char pathWithBackslash[1024];
				
				//clear current content of pathWithBackslash
				memset(&pathWithBackslash[0], 0, sizeof(pathWithBackslash));
				
				//set first index to backslash character
				pathWithBackslash[0] = '/';
				
				//concatenate user specified path with backslash character
				strcat(pathWithBackslash, path);
				
				//declare character array to store current directory
				char currentDirectory[1024];
				
				//clear current content of currentDirectory
				memset(&currentDirectory[0], 0, sizeof(currentDirectory));
								
				//check if current directory has been stored in currentDirectory properly
				if(getcwd(currentDirectory, sizeof(currentDirectory)) != NULL) {
					//concatenate user specified path containing a backslash with current directory
					strcat(currentDirectory, pathWithBackslash);
										
					//change directory to user specified path
					int chdirValue = chdir(currentDirectory);
										
					//check if directory was accessed successfully
					if(chdirValue != 0) {
						//print error message to user
						printf("The specified directory does not exist.\n");
					}
				}	
			}
		}
		
		//empty else block
		else {
			//continue
		}
	}
	//Bug 3 Fix - implement exit functionality
	//check if command line argument is exit
	else if(strcmp(*cline, "exit") == 0) {
		//gracefully exit the shell
		exit(0); 
		
	}
	
	
	else {
    
		switch(pid=fork()) {
			case -1:
				perror(SHELL_NAME);
				return (-1); 
    
			case 0:
				execvp(*cline, cline);
				//we should never get to this code, sice execve does not return
				perror(*cline);
		 		exit(1);
		}
	}
    
    
    //BACKGROUND PROCESS
    // code for parent
    // if background process print pid and exit
    // program is running in the background
    if(where == BACKGROUND) {
        printf("[Process id %d]\n",pid);
        
        return(0);

    }
    
    //wait until child process terminates
    wait(NULL);
	
	//FOREGROUND PROCESS
    // wait until process pid exits
    if (waitpid(pid,&status,0) == -1) //Waits for child to terminate
        return (-1);
    else
        return (status);
}
