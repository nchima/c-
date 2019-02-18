/*

   scanpath.h - This is the interface file for a program named scanpath, where all the function prototypes have been declared to be used for the remainder of the program.
   ======================================================

   Please refer to the application file, scanpathApplication.cpp, for details of the functionality and purpose of this program


   File organization
   -----------------

   scanpath.h                  interface file:     contains the declarations required to use the functions that implement the solution to this problem
												   typically, these will include the definitions of the abstract data types used in the implementation

   scanpathImplementation.cpp  implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

   scanpathApplication.cpp     application file:    contains the code that instantiates the abstract data types and calls the associated functions
												  in order to effect the required functionality for this application


*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_NUMBER_OF_POINTS 1000
#define values 3


/* function prototypes go here */

void prompt_and_exit(int status);
void insertion_sort(int fixation_points[][values], int n, char key);
void printData(int fixation_points[][values], FILE *fp_out);


