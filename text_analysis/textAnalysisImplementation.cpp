/*

   textAnalysisImplementation.cpp - implementation file for a program named trafficQueueing
   ============================================================================

   Please refer to the application file, Application.cpp, for details of the functionality of this program


   File organization
   -----------------

   textAnalysis.h                  interface file:  contains the declarations required to use the functions that implement the solution to this problem
													typically, these will include the definitions of the abstract data types used in the implementation

   textAnalysisImplementation.cpp  implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

   textAnalysisApplication.cpp     application file:    contains the code that instantiates the abstract data types and calls the associated functions
												   in order to effect the required functionality for this application



*/


#include "textAnalysis.h"

/*Globally declared variables that would be initialized for every tree*/
BINARY_TREE_TYPE word_tree;
ELEMENT_TYPE unique_word;
int nodes;
int count_left = 0;
int count_right = 0;
int total_probes = 0;
float avg = 0.0;



void readFile(char filename[], FILE *fp_out)
{

	FILE *fp_in;
	char word[STRING_LENGTH];

	int frequency = 1;

	/*Pass in the file to be opened and read*/
	if ((fp_in = fopen(filename, "r")) == 0)
	{
		printf("Error can't open input %s\n", filename);
		prompt_and_exit(1);
	}

	fprintf(fp_out, "%s\n", filename);

	initialize(&word_tree);

	/*ensuring that words to be a sequence of alphanumeric characters*/
	while (fscanf(fp_in, "%*[^a-zA-Z-'0-9]"), fscanf(fp_in, "%255[a-zA-Z-'0-9]", word) != EOF)
	{

		/*convert the words read to lowercase to be safe*/

		for (int j = 0; j < (int)strlen(word); j++)
		{
			word[j] = tolower(word[j]);

			if (word[j] == '\'') /*check for ' in the current position of j*/
			{
				if (word[j + 1] == 's') /*check for the letter s in the next postion*/
				{
					word[j] = '\0'; /*terminate with eof character*/
					word[j + 1] = '\0';
				}

				else
				{
					word[j] = word[j + 1];
					word[j + 1] = '\0';
				}
			}

			if (word[j] == '\-' && !(isalnum(word[j + 1])))
			{
				for (int i = j; i < strlen(word); i++)
				{

					word[i] = '\0';

				}

				break;
			}
		}
		if (strcmp("", word) == 0)
		{
			*word = EOF;
			break;
		}

		/*Create the nodes for the binary search tree by assigning the word and frequency values from the word read*/
		assign_element_values(&unique_word, frequency, word);

		/*Insert the word to the binary search tree*/
		insert(unique_word, &word_tree);

	}

	/*finding total number of probes*/
	int probes_total = tree_probes(word_tree, 0);

	/*finding size of tree*/
	int tree_size = size(word_tree);

	/*finding average number of probes*/
	avg = average_probes(probes_total, tree_size);

	/*printing the maximum number of probes*/

	fprintf(fp_out, "Maximum number of probes: %d\n", height(word_tree));

	/*printing the average number of probes*/
	fprintf(fp_out, "Average number of probes: %.1f\n", avg);

	/*printing the words in order to the output file*/
	inorder_print(word_tree, 0, fp_out);


	fprintf(fp_out, "------------------------------------------\n");

	fclose(fp_in);

	count_left = 0;
	count_right = 0;
	total_probes = 0;

	initialize(&word_tree);

}

/*Function to calculate the average number of probes*/
float average_probes(int total, int size)
{
	float avg = 0.0;
	if (total == 0 || size == 0)
	{
		avg = 0.0;
	}
	else
	{
		avg = (float)total / (float)size;

	}


	return avg;
}

/*Function to height of the tree*/

int height(BINARY_TREE_TYPE tree)
{

	if (tree != NULL)
	{
		int left_tree_height = height(tree->left);

		int right_tree_height = height(tree->right);

		if (left_tree_height > right_tree_height)
			return  left_tree_height + 1;

		else
			return	 right_tree_height + 1;
	}
	return 0;
}

/*Function to size of the tree*/
int size(BINARY_TREE_TYPE tree)
{
	if (tree != NULL)
	{
		return 1 + size(tree->left) + size(tree->right);
	}

	return 0;
}



/*** inorder traversal of a tree, printing node elements **/

int inorder_print(BINARY_TREE_TYPE tree, int n, FILE *fp_out)
{

	int i;

	if (tree != NULL)
	{
		inorder_print(tree->left, n + 1, fp_out);

		for (i = 0; i <= n; i++) fprintf(fp_out, "");

		fprintf(fp_out, "%s\t\t\t%d (%d)\n", tree->element.word, tree->element.frequency, n);

		inorder_print(tree->right, n + 1, fp_out);
	}
	return(0);
}

/*Function to calculate the total number of probes for a tree of the tree*/
int tree_probes(BINARY_TREE_TYPE tree, int n)
{

	if (tree != NULL)
	{

		count_left = tree_probes(tree->left, n + 1);
		count_right = tree_probes(tree->right, n + 1);
		total_probes += n + 1;

		if (total_probes <= 0)
		{
			total_probes = 0;
		}
		return  total_probes;

	}
	return (0);
}


void prompt_and_exit(int status)
{
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void print_message_to_file(FILE *fp, char message[])
{

	fprintf(fp, "The message is: %s\n", message);
}

