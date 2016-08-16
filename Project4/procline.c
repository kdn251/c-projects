/*
 * @author: Kevin Naughton Jr. & Joanna Klukowska
 */ 
 
#include "proj4.h"


/* shell input line */
int procline(void)
{

    
    char *arg[MAXARG + 1];  //pointer array for runcommand
    
    //initialize toktype to 0
    int toktype = 0;        // type of token in command
    
    //Bug 1 Fix - set narg to zero
    //initialize narg to 0
    int narg = 0;          // number of arguments so far
    
    //initialize type to 0
    int type = 0;           //type =  FOREGROUND or BACKGROUND


    while ( 1 ) // loop forever
    {
        // take action according to token type
        switch(toktype = gettok(&arg[narg]))

        {

        case ARG:
            if(narg<MAXARG)
                narg++;
            break;

        case EOL:
        case SEMICOLON:
        case AMPERSAND:
            if(toktype == AMPERSAND)
                type = BACKGROUND;
            else
                type = FOREGROUND;

            if(narg != 0)
            {
                arg[narg] = 0;
                runcommand(arg,type);
            }
            
            //Ensure that program name does not print twice
            narg = 0;
            
            if( toktype == EOL ) {
				return;
			}
			
            break;
        }
    }
}
