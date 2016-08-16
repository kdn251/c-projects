/*
 * author: Kevin Naughton Jr.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"


// Implement a C function called level_4_opt. It should perform the same 
// task as the implemented level_4 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//


// Note: Data structures like linked lists are not very
// cache friendly (their nodes can be scattered all over
// the heap). The following method compacts the nodes of a linked 
// list into adjacent memory locations in an array and it also
// preserves the traditional linked list connections. 
// Your own code needs to accomplish the same. 
 

void level_4(node** head, int length)
{
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.
    node* new_list = malloc(sizeof(node) * length);

    // go through the list and make a copy of all the 
    // nodes and place them into the contiguous block in order
    node* n = *head;
    int i;
    for(i = 0 ; i < length ; ++i) {
        node copy = { n->value, NULL };
        new_list[i] = copy;
        n = n->next;
    }

    // go through the list again and "link" each node in 
    // the contiguous block to the next node in memory; 
    // free all the nodes in the old list
    n = *head;
    for(i = 0 ; i < length - 1 ; ++i) {
        // link each node in the new list
        new_list[i].next = &new_list[i+1];
        // free the old nodes
        node* free_me = n;
        n = n->next;
        free(free_me);
    }

    // free the last node of the old list
    free(n);

    // point head at the new packed list
    *head = new_list;
}


/*
 * performs the same task as level_4 with fewer cache misses
 * as a result combining the two for loops in level_4 into one
 * for loop. Performs operations in such an order that recognizes
 * what pieces of memory are currently stored in the cache. This
 * improves our temporal locatity.
 */
void level_4_opt(node** head, int length)
{
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.
    node* new_list = malloc(sizeof(node) * length);

    // go through the list and make a copy of all the 
    // nodes and place them into the contiguous block in order
    
    //set reference to head of list
    node* n = *head;
    
    //declare i
    int i;
    
    //copy linked list into contiguous memory using an array
    for(i = 0 ; i < length ; ++i) {
		
		//copy current node
        node copy = { n->value, NULL }; 
        		
        //store reference of the node to free
		node *freeN = n;
        
        //assign current index of array to current node
        new_list[i] = copy; 
        
        //link nodes in array to each other
        if(i < length - 1) {
			
			//point next of current node to next node in array
			new_list[i].next = &new_list[i + 1];
			
		}
				
		//free node
		free(freeN);
        
        //move to next node
        n = n->next; 
             
    }

    // free the last node of the old list
    free(n);

    // point head at the new packed list
    *head = new_list;
}


/* DO NOT MODIFY THE FUNCTION THAT FOLLOWS */


void addFront(data * s,  node ** head) {
	if (head == 0 ) return;
	if (s == 0 ) return; 
	
    //allocate memory for storing the node 
    node *n = ( node *)malloc(sizeof( node));
    //make sure that the memory was allocated,
    //if not, just quit
    if (n == NULL) return;
    n->value = *s;
    
    n->next = (*head);
    (*head) = n;
}


