#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc > 0 ) {
		printf("program name: %s \n", argv[0] ); 
		int i = 1;
		while (i < argc ) {
			printf("\targv[%d] = %s \n", i, argv[i] );
			i++;
		}
	}
	else {
		printf("Running with no arguments - this is strange\n");
	}
	return 0;
}
