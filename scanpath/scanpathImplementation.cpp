/*

   scanpthImplementation.cpp - implementation file for a program named scanpath
   ============================================================================


   Please refer to the application file, scanpathApplication.cpp, for details of the functionality and purpose of this program.


   File organization
   -----------------

   scanpath.h                  interface file:      contains the declarations required to use the functions that implement the solution to this problem
												   typically, these will include the definitions of the abstract data types used in the implementation

   scanpathImplementation.cpp  implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

   scanpathApplication.cpp     application file:    contains the code that instantiates the abstract data types and calls the associated functions
												   in order to effect the required functionality for this application



*/

#include "scanpath.h"

FILE  *fp_out;

void prompt_and_exit(int status)
{
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}



void insertion_sort(int fixation_points[][values], int n, char key)
{
	int i, j,m;
	int temp_id, temp_x, temp_y;

	if (key == 'x')
	{
		m = 1;

		for (i = 1; i < n; i++) {
			j = i;
			while ((j > 0) && (fixation_points[j][m] < fixation_points[j - 1][m]))
			{
				temp_id = fixation_points[j - 1][0]; // swap
				fixation_points[j - 1][0] = fixation_points[j][0];
				fixation_points[j][0] = temp_id;

				temp_x = fixation_points[j - 1][1]; // swap
				fixation_points[j - 1][1] = fixation_points[j][1];
				fixation_points[j][1] = temp_x;

				temp_y = fixation_points[j - 1][2]; // swap
				fixation_points[j - 1][2] = fixation_points[j][2];
				fixation_points[j][2] = temp_y;

				j = j - 1;
			}

		}
	}
	else if (key == 'y')
	{
		m = 2;

		for (i = 1; i < n; i++) {
			j = i;
			while ((j > 0) && (fixation_points[j][m] < fixation_points[j - 1][m]))
			{
				temp_id = fixation_points[j - 1][0]; // swap
				fixation_points[j - 1][0] = fixation_points[j][0];
				fixation_points[j][0] = temp_id;

				temp_x = fixation_points[j - 1][1]; // swap
				fixation_points[j - 1][1] = fixation_points[j][1];
				fixation_points[j][1] = temp_x;

				temp_y = fixation_points[j - 1][2]; // swap
				fixation_points[j - 1][2] = fixation_points[j][2];
				fixation_points[j][2] = temp_y;
				j = j - 1;
			}

		}
	}

	

	
}

void printData(int fixation_points[][values], FILE *fp_out)
{
	for (int k = 0; k < MAX_NUMBER_OF_POINTS; k++)
	{
		if (fixation_points[k][0] > 0)
		{
			fprintf(fp_out, "%d	%d	%d \n", fixation_points[k][0], fixation_points[k][1], fixation_points[k][2]);
		}

	}
}