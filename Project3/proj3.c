/* 
 * Project3: 
 * This program calls each of the functions that you implement
 * for this project. It runs the original function and your
 * optimized function.
 * The program performs preliminary evaluation of correctness
 * (but you should make sure on your own that you function is
 * equivalent to the one that is given to you). 
 * 
 * author: Joanna Klukowska 
 * 
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "proj3.h"

/////////////////////////////////////////////
//                                         //
// DO NOT MODIFY anything in this program. //
//                                         //
/////////////////////////////////////////////

int list[LARGER];

void flood_cache () ;

/***********************************************/

int main(int argc, char *argv[])
{

    int i, j, level = -1 ;
	int b, n1, n2; 
	int x,y;
	double d1, d2; 
	long l1, l2;
	
	srand(time(0));
	srand48(time(0));
	
/* level 0 - this is a warmup exercise - it will not be graded*/
	int * B1 = (int * ) malloc ( N*N*sizeof(int) ) ;
	if (!B1) return -1; 
	int * B2 = (int * ) malloc ( N*N*sizeof(int) ) ;
	if (!B2) return -1; 
	for (i = 0; i < N*N; i++) {
		b = rand();
		B1[i] = b;
		B2[i] = b;
	}
	flood_cache(); 
	x =  rand()%N; 
	y =  rand()%N;
	
	n1 = level_0(B1, x, y);
	
	printf("level_0 completed \n" ) ;
	
	n2 = level_0_opt(B2, x, y);
	
	printf("level_0_opt completed  \n" ) ;
	
	if (n1==n2)	printf("\tlevel_0_opt PASSED\n");
	else printf("\tlevel_0_opt FAILED\n"); 
	
	if ( B1!= 0 ) { free(B1); B1 = 0; } 
	if ( B2!= 0 ) { free(B2); B2 = 0; } 
	

/* level 1 */    

	double * D1 = (double * ) malloc( SMALL*LARGE*sizeof(double) ) ;
	if (!D1) return 0; 
	double * D2 = (double * ) calloc( LARGE, sizeof(double) ) ;
	if (!D2) return 0; 
	double * D3 = (double * ) calloc( LARGE, sizeof(double) ) ;
	if (!D3) return 0; 
	for (i = 0; i < SMALL*LARGE; i++) {
		D1[i] = drand48();
	}
	
	x =  rand()%LARGE / 2; 
	y =  rand()%LARGE / 2;
	
	flood_cache();
	d1 = level_1(D1, D2, x, y);
	
	printf("level_1 completed \n") ;
	
	flood_cache();
	d2 = level_1_opt(D1, D3, x, y);
	
	printf("level_1_opt completed\n") ;
	
	if (d1==d2)	printf("\tlevel_1_opt PASSED\n");
	else printf("\tlevel_1_opt FAILED\n"); 
	
	if (D1 != 0) { free(D1); D1 = 0; }
	if (D2 != 0) { free(D2); D2 = 0; }
	if (D3 != 0) { free(D3); D3 = 0; }


/* level 2 */    
	
	flood_cache();
	char * c1 =  level_2();
	printf("level_2 completed \n" ) ; 
	
	flood_cache();
    char * c2 = level_2_opt();
	printf("level_2_opt completed \n" ) ; 
	
	if (strcmp(c1,c2)==0)	printf("\tlevel_2_opt PASSED\n");
	else printf("\tlevel_2_opt FAILED\n"); 
	
	if (c1 != 0 ) { free (c1); c1 = 0; } 
	if (c2 != 0 ) { free (c2); c2 = 0; } 
		
/* level 3 */ 
	long * F1 = (long * ) malloc( N*N*sizeof(long) ) ;
	if (!F1) return 0; 
	long * F2 = (long * ) malloc (N*N*sizeof(long) );
	if (!F2) return 0; 

	for (i = 0; i < N*N; i++) {
		F1[i] =  rand();
		F2[i] =  rand();
	}
	x =  rand()%N; 
	
	flood_cache(); 
	l1 = level_3(F1, F2, x);
	
	printf("level_3 completed \n" ) ; 
	
	flood_cache(); 
	l2 = level_3_opt(F1, F2, x);
	
	printf("level_3 completed  \n") ; 

	if (l1==l2)	printf("\tlevel_3_opt PASSED\n");
	else printf("\tlevel_3_opt FAILED\n"); 
    
    if (F1 != 0 ){  free (F1); F1=0; }
    if (F2 != 0 ){  free (F2); F2=0; }
		
/* level 4 */    
    node * head1 = 0;
    node * head2 = 0; 
    
    for (i = 0; i < LARGER; i++)  {
		data s = { drand48(),rand(), rand() } ; 
		addFront (&s, &head1 );
		addFront (&s, &head2 ); 
	}
	
	node * head1_org = head1;
	node * head2_org = head2;
	
	flood_cache();
	level_4( &head1, LARGER ); 
	
	printf("level_4 completed \n" ) ; 
		
	flood_cache();
	level_4_opt( &head2, LARGER ); 
	
	//attempt to overwrite the memory locations that were used
	//by the original list
	long * stuff = (long*) calloc(LARGER,  sizeof(long) ); 
	if (stuff == 0 ) return -1;
	else free (stuff); 
	
	
	printf("level_4_opt completed \n" ) ; 
	
	int passed = 1;
	if (head2_org == head2) 
		passed = 0;
	node * h1 = head1;
	node * h2 = head2; 
    for (i = 0; i < LARGER && passed; i++)  {
		if ( (h1->value).n1  != (h2->value).n1 ) {
			passed = 0;
			break;
		}
		if (h1->next != 0 ) {
			h1 = h1->next; 
		}
		else if (i != LARGER-1) {
			passed = 0;
			break;
		}
		if (h2->next != 0 ) {
			h2 = h2->next; 
		}
		else if (i != LARGER-1) {
			passed = 0; 
			break;
		} 
	}
	if (passed ) 	printf("\tlevel_4_opt PASSED\n");
	else printf("\tlevel_4_opt FAILED\n"); 
    
	if (head1!=0) { free(head1); head1=0; }  
    if (head2!=0) { free(head2); head2=0; }  
    
	
    
}

// Perform an operation that will replace the cache content
// forcing the function to start with an "empty" cache. 
void flood_cache () { 
	int i = 0;
	
	for ( i =0; i < LARGER; i++ ){
		list[i] = rand(); 	
	}	
}
