/* 

   trafficQueueingImplementation.cpp - implementation file for a program named trafficQueueing
   ============================================================================

   Please refer to the application file, trafficQueueingApplication.cpp, for details of the functionality of this program


   File organization
   -----------------

   trafficQueueing.h                  interface file:  contains the declarations required to use the functions that implement the solution to this problem
													typically, these will include the definitions of the abstract data types used in the implementation

   trafficQueueingImplementation.cpp  implementation file: contains the definitions of the functions that implement the algorithms used in the implementation
 
   trafficQueueingApplication.cpp     application file:    contains the code that instantiates the abstract data types and calls the associated functions
                                                   in order to effect the required functionality for this application


*/




#include "trafficQueueing.h"

int samplePoisson(double lambda)
{
	/*Generate a random sample from a Poisson distribution with a given mean, lambda. Use the function rand to generate a random number*/

	static bool first_call = true;
	int count;
	double product;
	double zero_probability;

	/*Seed the random-number generator with the current time so that the numbers will be different everytime we run*/
	if (first_call)
	{
		srand((unsigned)time(NULL));
		first_call = false;
	}

	count = 0;
	product = (double)rand() / (double)RAND_MAX;

	
	zero_probability = exp(-lambda);

	while (product > zero_probability)
	{
		count++;
		product = product * ((double)rand() / (double)RAND_MAX);
	}
	return (count);
}


void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
 
   fprintf(fp,"The message is: %s\n", message);
}