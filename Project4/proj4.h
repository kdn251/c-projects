/*
 * @author: Kevin Naughton Jr. & Joanna Klukowska
 */
  
#ifndef PROJECT4_H
#define PROJECT4_H


#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

#define EOL       1   /*end of line*/
#define ARG       2   /* normal arguments */
#define AMPERSAND 3
#define SEMICOLON 4
#define PONDKEY   5   /*for pondkey*/
#define PIPE      6   /*for pipe*/

#define MAXARG 512   /* max. no. command args*/
#define MAXBUF 512   /* max. length input line */

#define FOREGROUND  0
#define BACKGROUND  1

#define PROMPT  "sh201>  "
#define SHELL_NAME  "sh201"

int procline(void);

int userinput( ) ;

int gettok(char **outptr) ;

int runcommand(char **cline, int where) ;

//declare function that will handle SIGINT signal
void sigint_handler();

#endif // PROJECT4_H
