#include <stdio.h>

double series(int n, double x); //function declaration

int main() {
	
	//Print heading for 1st term
	printf("  x	 n	series\n");
	printf("-----------------------------------------\n");
	int i;
		for(i = -2; i <= 10; i++) {
			double current= 1.0; //1st x term
			printf("%.2f %5i %12.10f\n", current, i, series(i, 1.0));
		}
		
	printf("\n");
	
	//Print heading for 2nd term
	printf("  x	 n	series\n");
	printf("-----------------------------------------\n");
	int a;
		for(a = -2; a <= 10; a++) {
			double current= 0.10; //2nd x term
			printf("%.2f %5i %12.10f\n", current, a, series(a, 0.10));
		}
		
	printf("\n");
		
	//Print heading for 3rd term
	printf("  x	 n	series\n");
	printf("-----------------------------------------\n");
	int c;
		for(c = -2; c <= 10; c++) {
			double current= 3.14; //3rd x term
			printf("%.2f %5i %12.10f\n", current, c, series(c,3.14));
		}
		
	printf("\n");
	
	//Print heading for 4th term
	printf("  x	 n	series\n");
	printf("-----------------------------------------\n");
	int z;
		for(z = -2; z <= 10; z++) {
			double current= 23.0; //4th x term
			printf("%.2f %5i %12.10f\n", current, z, series(z, 23.0));
		}
}

double series(int n, double x) { //function definition
	if(n <= 0) { //refuse invalid input
		return -1;
	}
	int i;
	int j;
	double sum = 0;
	double numerator = 1;

	for(i = 1; i <= n; i++) { //loop until nth term is reached
		for(j = 1; j <= i; j++) { //perform exponentiation
			numerator *= x; //check to make sure numerator is being incremented 
		}
		double currentTermValue = numerator / i; //divide exponentiation
		numerator = 1;
		sum += currentTermValue; //increment sum
			
	}
return sum;

}
	


