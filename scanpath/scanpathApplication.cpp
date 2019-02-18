/*
	scanpathApplication.cpp - application file for a program named scanpath
	=====================================================================

	"Write a program to produce a sort a list of fixations points, each one specified by its fixation point number and x and y coordinates. 
	The list should be sorted by two keys: the x coordinate and the y coordinate."

	The goal of the program was to use a stable sorting algorithm to perform a multi-key sort on a list of fixation points test cases, that need to be read in from a text file,
	that listed the fixation points by order of appearance. Each list of points/ test case needed to be terminated by point (-1 -1). This is the delimiter. 
	After reading in the points and implementing the sorting algorithm and sort the points by the x-coordinates and y-coordinates as the keys, 
	a list of the sorted points needed to be printed on to an output text file, as the result of the operation.

	The input data with the set test cases is stored in an input file named input.txt.
	This input file is located in the data directory. Since this directory is a sibling directory of the bin directory where the example .exe file resides, the filename used when opening the file is "../data/input.txt".

	Output for the test case is written to an output file "../data/output.txt"

	For the purpose of this, it was taken that the number of points would not be greater than 1000 for any particular test case.

	Input
	-----
	- The input used is a set of test cases, each with a varying number of points. This input is read in from the input.txt file.
	- The input is assumed to contain no more than 10 test cases, based on the problem defined. However, for every operation, the number of test cases to be processed is indicated
	  at the top of the input file, for example, you may have 7 test cases but only wish to process 3, then the first 3 test cases would be subjected to the sorting.
	- In addition to this, the input would be in a three-column format:
		Fixation Number | X-Coordinate| Y-Coordinate


	Output
	------
	- The output is a sequence of the three numbers, the fixation point number, the x-coordinate of the point and the y-coordinate of the point, sorted in ascending order
      and printed to a file.
	- At the beginning of the output, the andrew id must be present, followed by the number of test cases processed from the input.
      From this display, the list(s) of sorted points is printed out, with each test case separated by a dotted line (----------) to illustrate the different test cases that were passed.


	Sample Input
	------------
	1
	1 56 98
	2 98 14
	3 20 14
	4 20 14
	5 56 98
	6 -1 -1
	1 12 12
	2 5 10
	3 -1 -1

	- This is an example of how the input is arranged and how the test cases begin with a point and terminated by a point (-1,-1). 
	- In this example, there are 2 test cases, but the indication of 1 at the beginning of the file indicates that we only want to sort the first test cases.


	Sample Output
	-------------
	1
	3 20 14 
	4 20 14 
	1 56 98 
	5 56 98 
	2 98 14 
	----------

	Solution Strategy
	-----------------
	The solution strategy selected for this problem was to identify a suitable sort algorithm that would be used to sort the fixation points using two keys. 
	Thus, the sorting algorithm needed to be stable in order to successfully carry out the multi-key sorting.  
	The algorithm used followed the following steps:
	- Read in each line of text from the text file, starting with the test case number.
	- While reading in the fixation points, analyze the entry so as the x-coordinate and y-coordinate are not -1, -1.
	- In the case the fixation points are not (-1, -1), store it into a data structure for future sorting processes.
	- Once the test cases have been read in and stored, pass in the data structure into the sorting function, using the first key.
	- Call the sorting function for the second time, but this time with the second key.
	- Print out the sorted points to the file, in ascending order.

	The stable sort algorithm chosen for this program was the insertion sort as it was identified as a suitable candidate. 
	The order of time complexity for this sorting algorithm is of O(n^2). This is because the operations would need to be processed by two loops, the first loop to iterate through the array, the second one to swap the elements.
	For the solution to call the method twice, this means that the complexity would be processed twice.
	The sorting order begins with sorting with the y-coordinate as its first key, followed by the x-coordinate. This ensures that any identical keys would be printed out in the order of their fixation numbers.
   
	Assumptions Used
	-------------------
	For this program, a number of assumptions were put into consideration and the algorithm was designed to carry out no action if these conditions were not fulfilled.
	The assumptions made were:
	- The number of valid test cases in a text file to be processed would be no less than 1 and not greater than 10 test cases (1<= N <=10). 
      Therefore, at the top of the input file, the number of test cases to be processed would be indicated and would be between 1 and 10.
	- The valid coordinates for x and y would not be between 0 and 2000 for either of them (0 <= x, y <=200).
	- The maximum number of fixation points in a test case would not exceed 1000.


	Test Strategy
	-----------------

	The program has been tested with a variety of test data sets that are needed to test the sorting algorithm and to ensure that the program would work effectively.
	- against provided example test cases, that contain repeated fixation points
	- against a test case with only one repeating fixation point, appearing multiple times
	- against a test case with points that have the same values in either the x-coordinate or the y-coordinate.
	- against a test case with only 1 valid fixation point, i.e, (1,1) as the x and y coordinates and terminated by (-1, -1)
	- against a test case that contains (0,0) as a fixation point in the test case
	- against a test case that has no fixation points, i.e, only termination point (-1, -1) is present
	- against a test case with 1000 fixation points
	


	File organization
	-----------------

	scanpath.h                  interface file:      contains the declarations required to use the functions that implement the solution to this problem
												   typically, these will include the definitions of the abstract data types used in the implementation

	scanpathImplementation.cpp  implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

	scanpathApplication.cpp     application file:    contains the code that instantiates the abstract data types and calls the associated functions
												   in order to effect the required functionality for this application


	Author
	------

	Credit
	------
	Some of the functions and declarations for the files are from Dr. David Vernon's examples.

*/

#include "scanpath.h"



int main()
{
	int number_of_test_cases;

	int count;
	

	int seen_number, x, y;

	FILE *fp_in, *fp_out;

	if ((fp_in = fopen("../data/input.txt", "r")) == 0)
	{
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt", "w")) == 0)
	{
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}

	fscanf(fp_in, "%d", &number_of_test_cases);    	//read the number of test cases from a file

	fprintf(fp_out, "%d\n", number_of_test_cases);   	//write the test case number to file 


	for (int n = number_of_test_cases; n <= 10; n--)
	{
		if (n < 1)
		{
			break;
		}

		count = 0;
		int fix_points[MAX_NUMBER_OF_POINTS][values] = { -1 };

		/* read the fixation point data from a file */
		int num = 0;
		fscanf(fp_in, "%d %d %d", &seen_number, &x, &y);

		while (x != -1 && y != -1)
		{
			if (x < 0 || y < 0)
			{
				break;
			}
			else if (x > 2000 || y > 2000)
			{
				break;
			}

			//store the read fixation points from the file into the data structure.

			fix_points[num][0] = num + 1;
			fix_points[num][1] = x;
			fix_points[num][2] = y;

			num++;
			fscanf(fp_in, "%d %d %d", &seen_number, &x, &y);
			fix_points[num][values] = '\0';
		}

		insertion_sort(fix_points, num, 'y');  /*Calling the sorting algorithm with the first key, y*/
		insertion_sort(fix_points, num, 'x'); /*Calling the sorting algorithm with the second key, x*/
		printData(fix_points, fp_out);        /*Printing the sorted list of points*/

		fprintf(fp_out, "-------------------------------------\n");

	}

	fclose(fp_in);
	fclose(fp_out);

	prompt_and_exit(0);
}
