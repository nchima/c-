/*

   textAnalysisApplication.cpp - application file for a program named textAnalysis
   ==================================================================================


   "Write a program to analyze a set of textfiles. For each file, compile a list of all the distinct words by reading them and inserting then in a binary search tree.
   ...Traverse the BST and write the words to an output file, one word per line, in alphabetic orderm together with the number of occurrences for each word in the file,
   and in brackets, the level at which they are stored in the BST."

   The program is expected to simulate the creation of a binary search tree of words that have been read from a text file. The words to be stored to the 
   tree are expected to be unique and in the event there are multiple repeating words, the words should not be inserted to the tree again,
   but a count of the frequency of appearance to be noted.

   Input data included a list of text files that would be read and processed individually to provide the required statistics and data for every file processed.
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory
   where the the exe file resides, the filename used when opening the file is "../data/input.txt".

   The set of text files that have the words also reside in the same data folder and an example of the filename naming was "../data/text1.txt".

   Output for the traversals of the binary search trees is written to an output file "../data/output.txt"

  

   Input
   -----

   - The input file, labelled "input.txt" contains a list of text files to be processed individually for this program, one filename per line as shown below:
		 ../data/text1.txt
		 ../data/text2.txt
		 ../data/text3.txt
		 ../data/text4.txt

   - A contiguous sequence of alphanumeric characters ('a'...'z', 'A'...'Z', or '0'...'9') formed a word, with the possible inclusion of hyphen between words. 
	 Such an arrangement (i.e, two words with a hyphen in between) would be treated as a single word. 

   Output
   ------

   - The first output line is the andrewid.
   - The filepath of the processed text file would be printed next on a line of its own.
   - For each file, the following results are to be printed:
		Height of the binary Search Tree
		The average number of probes
		List of distinct words in alphabetic order, one word per line with its frequency of occurrenece and the level of its storage in the tree
		The separator line ("--------------") to separate the contents of the different text files.


   Sample Input: input.txt
   ------------------

   ../data/text1.txt

   Sample Input (from the text file): ../data/text1.txt
   ------------
   My heart is in the work
   My heart is in the work

   Sample Output
   -------------
	../data/text1.txt
	Tree Height: 4
	Maximum number of probes: 4
	Total number of probes: 4
	Average number of probes: 2.5
	heart 		2 (1)
	in 			2 (3)
	is 			2 (2)
	my 			2 (0)
	the 		2 (1)
	work 		2 (2)
	----------------------------------------


   SOLUTION STRATEGY
   ---------------------------
   The solution strategy initially involved understanding and conceptualizing the problem provided. This required forming numerous test cases of different words and
   creating binary search trees for each simulation. This assisted to fully develop the solution to provide correct inferences as required.
   
   The main program is processed from a main loop that opens the input text file on the application code. The follow-up procedures of the code 
   are to be hidden from the user in the implementation sections so as not to worry a user of the internal operations of the programs

   The solution design involved the following steps:
		-> Read the input file data to obtain the names of the text files and print them to the terminal. 
			The requirement for this step was to be able to process the input file and progress to open the text file read to process the text contained
			by converting the words to lower case to ensure better processing. 
			
		-> Implement the Binary Search Tree data structure from the implementation code provided. This was to be used to construct the binary search
		   tree and insert the words processed to the tree in the order of encounter. The requirements for the elements in the BST were to have two
		   values: pointer to character for the words and integer value for the frequency of the word to be stored. 

		-> After the implementation of the BST and inserting the words to the tree, the next step involved writing the function to compute the height
		   of the tree. The algorithm to the height function has been described at a later section of this documentation. The function was to return
		   a value for the height of the tree which would be used for the value of the Maximum number of probes for a BST. 

		-> After the height of the tree was computed, the computation of the average number of probes was done. This involved writing recursive functions
		   for calculating the size of the tree and counting the sum of the probes required for a particular tree. These two values were to be used
		   to calculate the average value.

	   ->  The following step was to print out a list of words from the tree, in lexicographical order to an output textfile. The print would include the
		   value of the frequency of the word and the level of the word at the tree. 


	ASSUMPTIONS
	----------------------------
	-> Under the special considerations for words that have apostophe and s ('s) as part of their words, the requirements stated that the letter 's' should
	   be dropped and not considered as an individual word. For example, it's would be accepted into the bst as 'it' and the s left out.

	-> For other considerations such as don't, won't, couldn't, the program would append the hanging letter left after removing the apostrophe and therefore,
	   there would be only one word printed for each case. For example, don't would become dont, can't would become cant.

	-> The tests for this program assume that no sequence of words in the text files begin with either a hyphen or apostrophe. The first element of the 
	   words are not to be hyphen, a series of hyphens or apostrophes. However, other symbols would not be taken to account 
	   and therefore any words following the symbols would be extracted well and printed to the tree and output file correctly.


   TEST STRATEGY
   ----------------------

   The program has been tested with a variety of test cases that were meant to reflect all valid conditions, including boundary conditions
   and the behavior of the program:

   DEFAULT TEST CASE: 
   - This test case was to be inferred from the sample output provided. The test case, contained in ../data/text1.txt contained a repeated sentence. 
     The statement was "My heart is in the work" as the sample test case.
     The test case was processed successfully, with a print of the words, their frequencies and level number processed to the output file. 

   TEST CASE WITH NON-REPEATING WORDS:
   - This test case was structured to test the capability of the program to construct the binary search tree and print the words in alphabetical order, 
     with their level numbers.
     The program succecssfully performed its task and provided the required output values. This was performed for both an ordered list of words
	 and an unordered list of words. For the ordered list of words as a test case, this has been described as a separate test case.


   TEST CASE WITH EMAIL ADDRESSES AND PUNCTUATION MARKS:
   - The validity of this test case was to perform a split of the email address and print out the individual words, i.e. an email address such as
     "johndoe@ymail.com" should have an expected output of 'johndoe', 'ymail', 'com' as its words. The @ symbol and fullstop are to be ignored or removed.
	 The test case passed and punctuation marks found in the texts were removed, with the exception of hyphen between two words, for example, 
	 "real-time" would be considered as one word.

   - A second variation of this test case involved using a set of hyphens as the text on the file. The program was expected to evaluate that this
     would not be a valid word, therefore, return no word printed to the output file and the resulting values would be 0 for the maximum number
	 of probes and average number of probes respectively.


   TEST CASE WITH SIMILAR WORDS THAT INCORPORATE NUMERIC CHARACTERS:
   - Given that numbers formed part of the sequence of characters for words, the test case used here involved using words
     with slight variations using numbers,to note how they would be treated by the program. 
	 For example, "people" and altered version of  "p30pl3" would be considered as two different words. 


   TEST CASE WITH BLANK TEXT FILE:
   - This was a boundary test case to evaluate the performance of the program. The program passed this test by printing the name of the text file
     and that the values needed for the probes are printed as 0 because there are no words present in the text file.


   TEST CASE WITH ORDERED SET OF TEXT:
   - This was a test case to evaluate the construction of a skinny tree from the words present. This would form a tree that resembled a linked list.
     The program passed this test and computed the required values to the output file.


   
   ALGORITHMS FOR HEIGHT AND TRAVERSAL OPERATIONS
   -----------------------------------------------
   - The height of the tree is computed by recursively traversing the left and right subtrees. The traversal is of a postorder type and it requires
	 the processing of the left subtree first, followed by the right subtree, starting from the least node(left most node in the tree), the adding
	 up at the root of that subtree, recursively upwards until all elements have been processed in the main tree.
		height(tree)
		*while (tree is not null)
			*set height of left tree = height of left subtree : recursive call height with left subtree
			*set height of right tree = height of right subtree: recursive call height with right subtree

			*compare values of left tree and right tree:
				*if(left_height is greater than right_height)
					*add 1(root node) to left_height
				*else
					*add 1 to right_height


	-The algorithm for the traversal of the tree to find the total number of probes for the tree is an inorder traversal of the tree.
	 It would follow the proceedings:
			*if (tree is not null)
				*set the sum of the left subtree = recursive order of the level of the tree + 1( this gives the value of the node from the root node)
				*set the sum of the right subtree = recursive order of the levels of the tree + 1
				*set total number of probes = sum of left subtree + sum of the right subtree + 1

	-After obtaining the value of the total number of probes in a tree, the average number of probes would then be computed. This value was the value
	 of dividing the total number of probes by the size of the tree. The size of the tree was computed using the algorithm below:
			*check if tree is null
			*if tree is not null
				*recursively process the left subtree
				*recursively process the right subtree
				*add the values of the left subtree, the right subtree together and add 1, to cover for the root node.

	The size function is a recursive function to cater for both sides of the tree to obtain the value required. The size of the tree is the total
	number of nodes in the tree.
	

   Order of Complexity
   -----------------------------------------------
   The Order of Complexity of the program would be assessed from the view of Insertion and Traversal/Probing. 

	INSERTION:
	 - The Order of complexity of the insertion function is on average O(log n). However, on the worst case, it is O(n). This is justified by the entry values 
	   of the words for the tree. When the words are of random order (not alphabetically or lexicographically ordered), the creation of the binary search tree
	   would be relatively balanced, with elements inserted on both the left subtree and right subtree, respectively, depending on the order of the words. 
	   This provides an order of time complexity of O(log n) with n being the number of words processed into the tree. 

	 - The worst case scenario is of O(n) because the resulting tree is very unbalanced, which develops into a skinny tree or a singly-linked list. 
	   This happens when words are inserted to the tree in an ordered from, from the highest valued element to the lowest valued element.

	TRAVERSAL:
	
	 - The order of complexity for the traversal of the BST is O(log n), for traversing to one specified element in the tree. This is with respect
	   to the insertion conditions, where the left subtree values are less than the root node value and the right subtree values are greater
	   than the root node value.


   File organization
   -----------------

   textAnalysis.h					interface file:	contains the declarations required to use the functions that implement the solution to this problem
												   typically, these will include the definitions of the abstract data types used in the implementation

   textAnalysisImplementation.cpp	implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

   textAnalysisApplication.cpp		application file:    contains the code that instantiates the abstract data types and calls the associated functions
												   in order to effect the required functionality for this application

*/

#include "textAnalysis.h"

int main()
{
	int debug = TRUE;

	char input_string[STRING_LENGTH];
	
	int i = 0;
	int end_of_file;

	FILE *fp_in, *fp_out;

	/*Opening the input text file to read its contents*/

	if ((fp_in = fopen("../data/input.txt", "r")) == 0) {
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt", "w")) == 0) {
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}


	end_of_file = fscanf(fp_in, "%s", input_string);

	while (end_of_file != EOF)
	{
		readFile(input_string, fp_out);

		end_of_file = fscanf(fp_in, "%s", input_string);

	}

	fclose(fp_in);
	fclose(fp_out);

	//prompt_and_exit(0);

}
