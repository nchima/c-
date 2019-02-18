/*

   textAnalysis.h - interface file for a program named example
   ======================================================

   Please refer to the application file, trafficQueueingApplication.cpp, for details of the functionality of this program


   File organization
   -----------------

   textAnalysis.h                  interface file:      contains the declarations required to use the functions that implement the solution to this problem
												   typically, these will include the definitions of the abstract data types used in the implementation

   textAnalysisImplementation.cpp  implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

   textAnalysisApplication.cpp     application file:    contains the code that instantiates the abstract data types and calls the associated functions
												   in order to effect the required functionality for this application

*/


/* function prototypes go here */


#include "stdio.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "binaryTree.h"


#define TRUE 1
#define FALSE 0
#define STRING_LENGTH 300

/*** function prototypes ***/

void readFile(char filename[], FILE *fp_out);
int height(BINARY_TREE_TYPE tree);
int size(BINARY_TREE_TYPE tree);
int inorder_print(BINARY_TREE_TYPE tree, int n, FILE *fp_out);
int tree_probes(BINARY_TREE_TYPE tree, int n);
float average_probes(int total, int height);
void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);
