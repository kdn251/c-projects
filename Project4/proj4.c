/*
 * @author: Kevin Naughton Jr. & Joanna Klukowska
 */ 

#include "proj4.h"


int main()
{
	//Bug 4 Fix - handle SIGINT signal by killing child process while continuing shell execution	
	signal(SIGINT, sigint_handler); //call method to handle SIGINT
	
	
    //run the shell until EOF (keyboard Ctrl+D) is detected
    while (userinput(  ) != EOF	) {
		

        procline();
        
    }
    return 0;
}

//create function to catch and handle SIGINT signal - simply returns
void sigint_handler() {
	//return from function
	return;
}

/*Bug 1 Fix (procline.c lines 15-23)
 * Bug 1 was fixed by initializing the variable narg to zero. Each argument is 
 * assigned to an integer value corresponding to the type of argument it represents.
 * Based on a specific character, the ampersand, the executable is either run in the
 * foreground or background. Once all command line arguments have been assigned a value, 
 * the array containing the command line arguments and its location of where to run the
 * command is passed to runcommand. After returning, narg is reassigned to zero ensuring
 * that the next set of command line arguments passed can be correctly assessed. This occurs
 * as a result of procline being continuously called within the main function of proj4.c
 * 
 */
 
/*Bug 2 Fix (runcommand.c lines 14-91)
 * Bug 2 was fixed by implementing the functionality of a cd command.
 * To do this code was added to recognize when cd was passed to the command
 * line and based on the argument that follows different scenarios arise.
 * If no argument follows, the user is taken to the home directory.
 * If an argument does follow, the program attempts to take the user to the 
 * specified directory. If the specified directory exits, the user is successfully
 * taken there, otherwise, an error message is printed and the shell prompt returns.
 */
 
/*Bug 3 Fix (runcommand.c lines 92-98)
 * Bug 3 was fixed by implementing the functionality of an exit command.
 * To do this code was added to recognize when the word exit was passed to
 * the command line. If the word exit is passed, normal processs termination
 * of the shell occurs, and control returns to Bash.
 */
 
/*Bug 4 Fix (proj4.c lines 24-28, proj4.h lines 42-43)
 * Bug 4 was fixed by catching and handling any SIGINT signals passed to
 * the shell. By catching SIGINT signals, we are able to then determine
 * what should happen, possibly overwriting its default functionality.
 * In our case, we used a signal handler to catch SIGINT signals and
 * simply terminate the current process but not the shell itself.
 */
 
/*Bug 5 Fix (runcommand.c lines 128-129)
 * But 5 was fixed by adding one line of code to ensure that parent processes 
 * reap their respective child processes that are running in the background.
 * The line that was added was wait(NULL). wait(NULL) is a function that
 * requires parent processes to wait until their respective child processes
 * have terminated. Upon terminating, the code that follows wait(NULL)
 * properly reaps the terminated child processes.
 */ 
  
 
