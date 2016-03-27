/****************************************************************************
 * inputlib.c
 *
 * M. Farbood
 *
 * Functions for simple input.
 * Based on Eric Roberts' genlib.h and simpio.h and 
 * Glenn Holloway and David Malan's cs50 library.
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "inputlib.h"

/*
 * Default buffer size for standard input.
 */

#define SIZE 128

/*
 * char getChar()
 *
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.  If line can't be read, 
 * returns CHAR_MAX.
 */

char getChar()
{
    char c1, c2;
    char *line;

    /* try to get a char from user */
    while (true)
    {
        /* get line of text, returning CHAR_MAX on failure */
        line = getString();
        if (line == NULL)
            return CHAR_MAX;

        /* return char equivalent to text if possible */
        if (sscanf(line, " %c %c", &c1, &c2) == 1)
        {
            free(line);
            return c1;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}


/*
 * double getDouble()
 *
 * Reads a line of text from standard input and returns the equivalent
 * double as precisely as possible; if text does not represent a
 * double, user is prompted to retry.  Leading and trailing whitespace 
 * is ignored.  For simplicity, overflow and underflow are not detected.  
 * If line can't be read, returns DBL_MAX.
 */

double getDouble()
{
    char c;
    double d;
    char *line;

    /* try to get a double from user */
    while (true)
    {
        /* get line of text, returning DBL_MAX on failure */
        line = getString();
        if (line == NULL)
            return DBL_MAX;

        /* return double equivalent to text if possible */
        if (sscanf(line, " %lf %c", &d, &c) == 1)
        {
            free(line);
            return d;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}


/*
 * float getFloat()
 *
 * Reads a line of text from standard input and returns the equivalent
 * float as precisely as possible; if text does not represent a float,
 * user is prompted to retry.  Leading and trailing whitespace is ignored.
 * For simplicity, overflow and underflow are not detected.  If line can't 
 * be read, returns FLT_MAX.
 */

float getFloat()
{
    char c;
    float f;
    char *line;

    /* try to get a float from user */
    while (true)
    {
        /* get line of text, returning FLT_MAX on failure */
        line = getString();
        if (line == NULL)
            return FLT_MAX;

        /* return float equivalent to text if possible */
        if (sscanf(line, " %f %c", &f, &c) == 1)
        {
            free(line);
            return f;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}


/*
 * int getInt()
 *
 * Reads a line of text from standard input and returns it as an
 * int in the range of [-2^31 + 1, 2^31 - 2], if possible; if text
 * does not represent such an int, user is prompted to retry.  Leading 
 * and trailing whitespace is ignored.  For simplicity, overflow is not 
 * detected.  If line can't be read, returns INT_MAX.
 */

int getInt()
{
    char c;
    int n;
    char *line;

    /* try to get an int from user */
    while (true)
    {
        /* get line of text, returning INT_MAX on failure */
        line = getString();
        if (line == NULL)
            return INT_MAX;

        /* return int equivalent to text if possible */
        if (sscanf(line, " %d %c", &n, &c) == 1)
        {
            free(line);
            return n;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}


/*
 * long getLong()
 *
 * Reads a line of text from standard input and returns an equivalent
 * long int, if possible; if text  does not represent such a long, 
 * user is prompted to retry. 
 * Leading and trailing whitespace is ignored.  For simplicity, overflow 
 * is not detected.  If line can't be read, returns LONG_MAX.
 */

long getLong()
{
    char c;
    long n;
    char *line;

    /* try to get a long long from user */
    while (true)
    {
        /* get line of text, returning LLONG_MAX on failure */
        line = getString();
        if (line == NULL)
            return LONG_MAX;

        /* return long long equivalent to text if possible */
        if (sscanf(line, " %ld %c", &n, &c) == 1)
        {
            free(line);
            return n;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}


/*
 * char *getString()
 *
 * Reads a line of text from standard input and returns it as a string,
 * sans trailing newline character.  Leading and trailing whitespace is not
 * ignored.  Returns NULL upon input error or upon EOF.
 */

char *getString()
{
    int c;
    unsigned int n, size;
    char *buffer, *tmp;

    /* try to allocate buffer of default size */
    size = SIZE;
    buffer = (char *) malloc(size * sizeof(char));
    if (buffer == NULL)
        return NULL;

    /* iteratively get chars from standard input */
    n = 0;
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        /* grow buffer if necessary */
        if (n == size - 1)
        {
            /* keep buffer size within unsigned int range */
            if (size > (UINT_MAX / 2))
            {
                free(buffer);
                return NULL;
            }

            /* double buffer's size */
            size *= 2;
            tmp = (char *) malloc(size * sizeof(char));
            if (tmp == NULL)
            {
                free(buffer);
                return NULL;
            }
            strncpy(tmp, buffer, n);
            free(buffer);
            buffer = tmp;
        }

        /* append current character to buffer */
        buffer[n++] = c;
    }

    /* return NULL if user provided no input */
    if (n == 0 && c == EOF)
    {
        free(buffer);
        return NULL;
    }

    /* minimize size of buffer */
    tmp = (char *) malloc((n + 1) * sizeof(char));
    strncpy(tmp, buffer, n);
    free(buffer);

    /* terminate string */
    tmp[n] = '\0';

    /* return string */
    return tmp;
}
