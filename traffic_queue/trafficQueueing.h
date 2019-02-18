/*

   trafficQueueing.h - interface file for a program named example
   ======================================================

   This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 3

   Please refer to the application file, trafficQueueingApplication.cpp, for details of the functionality of this program


   File organization
   -----------------

   trafficQueueing.h                  interface file:      contains the declarations required to use the functions that implement the solution to this problem
												   typically, these will include the definitions of the abstract data types used in the implementation

   trafficQueueingImplementation.cpp  implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

   trafficQueueingApplication.cpp     application file:    contains the code that instantiates the abstract data types and calls the associated functions
												   in order to effect the required functionality for this application


*/


/* function prototypes go here */


#include "stdio.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "linkedList.h"


#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define STRING_LENGTH 100
#define KEY_LENGTH 100
#define MAX_TEST_CASES 1000
#define NUMBER_OF_KEYS 7

const int RED = 0;
const int AMBER = 1;
const int GREEN = 2;

typedef char keyword[KEY_LENGTH];

struct Tests
{
	int arrival,
		departure,
		runtime,
		increment,
		red,
		amber,
		green;
};


/*** function prototypes ***/

/*** position following last element in a list ***/

int samplePoisson(double lambda);


void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);
