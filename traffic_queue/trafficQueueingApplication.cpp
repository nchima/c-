/*

   trafficQueueingApplication.cpp - application file for a program named trafficQueueing
   ==================================================================================

   "Write a program to simulate the queuing behaviour of cars in a single lane of traffic as a function of the arrival rate of the cars 
   and the traffic light sequencing, i.e. the amount of time the lights stay green, amber, and red."

   The program is expected to simulate the actions of a traffic queue at a junction and calculate the average and maximum lengths of
   the queue of cars and the average and maximu waiting time for the carsd in the simulation period.

   Input data included a list of traffic simulation scenarios, with each of the seven required key-value pairs provided in an input file named input.txt.
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory
   where the .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"

   There are a maximum of seven key-value pairs required for every simulation. These pairs include the keys: 
   Arrival, Departure, Runtime, Increment, Green, Amber and Red. An example layout of the key-value pairs has been provided 
   in the sample input section below.
   It is worthy to note that the order of the pairs can vary for every test case.

   Input
   -----

   - This involves the number of simulation scenarios to be processed, indicated as a number on top of the input file.
   - This is followed by the values needed to process the queueing computations. These are: 
			Arrival rate, Departure rate, Increment time, Green light sequence, Amber light sequence and Red light sequence.


   Output
   ------

   - The first output line is the andrewid.
   - A copy of the values read from the input files, used in the program.
   - Computation values for the following values:
		Average queue length
		Maximum queue length
		Average waiting time
		Maximum waiting time


   Sample Input
   ------------

   1
   Arrival 10
   Departure 5
   Runtime 5
   Increment 10
   Green 10
   Amber 1
   Red 20

   Sample Output
   -------------
   Arrival rate: 	100 cars per min
   Departure rate: 	5  s per car
   Runtime: 		5 min
   Time Increment: 	10 ms
   Light sequence: 	Green 10 s; 	Amber 1 s;	Red 20 s
   Average length:	245  cars
   Maximum length:	489  cars
   Average wait:	286 s
   Maximum wait:	291 s


   Solution Strategy
   -----------------
   The solution strategy initially involved understanding and conceptualizing the problem provided. This required describing traffic behaviour 
   and simulating by hand how cars can arrive at a queue and depart at different intervals.
   
   The solution design involved the following steps:
		-> Read the input file values and print them to the terminal. 
			The requirement for this step was to be able to read the key-value pairs correctly and provide an output of them. Sample application code
			was initially provided that helped carry out the step.

		-> Implement the function to sample the Poisson distribution and return a value that represented the number of cars arrived.
			This step was guided through, as sample code to implement the function was provided. However, basic understanding of the
			Poisson distribution was required to understand the random value generation that would be expected from the function.

		-> The next step involved implementation of the queue data structure. Choosing the appropriate implementation was vital for this program, as the
			two main implementation schemes both have their pros and cons. The chosen implementation of the queue was based on the linked list implementation.

		-> After selection of the implementation, the operations to enqueue and dequeue the cars was to be implemented. The functions implemented the following
			procedures:
				ENQUEUE: - Insert element at the end of the current queue
								Insert(e, End(Q), Q)

				DEQUEUE: - Retrieve the element at the beginning of the queue (first element)
								Retrieve(First(Q), Q)

							Delete the retrieved element
								Delete(Firse(Q), Q)

		
		-> Keep track of the vital values in the simulation. These included: running total for the number of cars.
																			 queue length
																			 time a car was in the queue
																			 running total of the waiting time
																			 maximum waiting time
																			 maximum queue length

		-> Implement the operations of the traffic light simulation, in order to perform the enqueue (when the lights are red) and
			dequeue (when the lighs are green). 
					IF (traffic_light is green and timer is greater than green_light_duration)
						change traffic_light to amber
						reset timer

					IF (traffic_light is amber and timer is greater than amber_light_duration)
						change traffic_light to red
						reset timer

					IF (traffic_light is red and timer is greater than red_light_duration)
						change traffic_light to green
						reset timer

		-> Check if there are any cars left in the queue at the end of the simulation loop.
					IF (car_queue is not empty)
						dequeue cars and store data

		-> Compute the needed statistics and write them to file. The statistics are:
				Average queue length
				Maximum queue length
				Average waiting time
				Maximum waiting time





   Test Strategy
   -----------------

   The program has been tested with a variety of test data sets that were meant to reflect all valid conditions, including boundary conditions
   and the behavior of the program:

   DEFAULT TEST CASE: 
   - This was the provided test case that was provided with the assignment. The program succecssfully peroformed its calculations
   and provided the required average values, indicating that there were intervals of enqueue and dequeue taking place in the simulation.

   TEST CASE WITH ALL VALUES AS 0:
   - This was the provided test case that was provided with the assignment. The program succecssfully peroformed its calculations
   and provided the required average values, indicating that there were intervals of enqueue and dequeue taking place in the simulation.

   VARYING ARRIVAL RATE VALUE:
   - This test case involved varying the value of the cars arrival rate for different simulation instances. The instances included having the value of
   the arrival rate at 0, which resulted to a successful run, with the computed values being 0 as there were no cars arriving at the simulation.

   - The other instance involved running the simulation with high values of the arrival rate. With this, the arrival of cars may end up being faster than
   the departure. This results to higher waiting periods recorded, that are closer to the maximum waiting time.

   VARYING DEPARTURE RATE:
   - This test was modified to test the program's behavior when the departure rate decreased to 0. The test was passed as the program
   computed the required values. The departure rate of the cars was determined by the time interval increment, which once it was greater than
   the departure rate from the file, the cars would be dequeued. Thus, the maximum waiting time would be close to the duration of the red light.

   - The second variation involved having a higher rate of departure being read from the file or increased to relatively higher values. 

   VARYING INCREMENT VALUE:
   - Increment value at 0: This test case results to the program running infinitely. This happens as a result of having a lambda value = 0,
	 which results in not producing any value from the samplePoisson function for cars to be queued and subsequently dequeued.
	 To correct this, a check function was implemented to ensure that a test case with the Increment =0 would not be processed and proceed
	 to the next test case.

   VARYING TRAFFIC SEQUENCE VALUES:
   - Red Light sequence:
		*The program was tested when the red light value was 0. The test passed and the behavior of the program was recorded as
		*The program was tested with the red light value being higher than the other lights. The test passed and the behavior recorded was that the
		average waiting time was higher than other instances as majority of the cars in the simulation were still in the queue at the end of the simulation
		period.

   - Amber Light sequence:

		The program was tested when the amber light value was 0. The test passed and the behavior of the program was recorded as operating normally,
		where the enqueuing and dequeing of cars was performed accordingly. This is because despite the significance of the amber light, majority of the simulation
		to enqueue would be dependent on the red light and that the factors to process the dequeue process were not met.

   - Green Light sequence:

		*The program was tested when the green light value was 0. The test passed and the behavior of the program was recorded as that through out the entire simulation,
		no car became dequeued, therefore the average wait time was the value of the simulation runtime and the maximum wait time was 0. All cars were in the queue
		and became dequeued at the end of the simulation.

   - All lights at 0 : 
		*The situation at this test case is that the traffic lights are constantly changing. However, the operations of queue and dequeue
		operations are dependent on the departure time rate condition that it should be greater than the read value. The test was passed and values recorded
		as stipulated by the requirements.



   Order of Complexity
   -----------------------------------------------
   The Order of Complexity of the program varies throughout the program. 

	 - The Order of complexity of the enqueue function is O(n). This is because every new value has to be queued at the rear of the queue. This requires navigating
     through the entire list to find the rear.
	
	 - The order of complexity of the dequeue function is O(1). This is because the value at the front of the queue is the one to exit the queue, requiring to only
	 navigate through the list once to find the front value.

	 - The order of complexity of the application can be viewed as O(n^2). This is because of the enqueue function that has been implemented in loops that would need
	 to perform the operations throughout the number of values present for the runtime. Given that the order of complexity of the enqueue function has been defined
	 as O(n), running it in a loop results to O(n^2). 
	 The other value to consider would be for the dequeue function at the end of the simulation period. For example, once the runtime is over, 
	 all remaining values in the queue need to be dequeued. However, this only results to an O(n) at the worst case, and therefore does not surpass that of the simulation period.

	 - Therefore, there being 2 main loops that perform the enqueue and dequeue operations: the first one, for both, where the conditions needed to enqueue and dequeue
	 need to be met, based on the simulation time not being greather than the runtime, and the second one, for the final dequeue process for all remaining values in the
	 queue, the maximum order of complexity can be described as O(n^2).




   File organization
   -----------------

   trafficQueueing.h					interface file:	contains the declarations required to use the functions that implement the solution to this problem
												   typically, these will include the definitions of the abstract data types used in the implementation

   trafficQueueingImplementation.cpp	implementation file: contains the definitions of the functions that implement the algorithms used in the implementation

   trafficQueueingApplication.cpp		application file:    contains the code that instantiates the abstract data types and calls the associated functions
												   in order to effect the required functionality for this application



   Audit Trail
   -----------

	- This program utilized the implementation of a queue using a linkedListImplementation
*/

#include "trafficQueueing.h"

int main()
{
	ELEMENT_TYPE e;
	LIST_TYPE cars_queue;

	keyword keylist[NUMBER_OF_KEYS] = {
		"arrival",
		"departure",
		"runtime",
		"increment",
		"red",
		"amber",
		"green"
	};

	int debug = TRUE;

	typedef char keyword[KEY_LENGTH];

	char input_string[STRING_LENGTH];

	int value;
	int j;

	keyword key;

	int number_of_test_cases;
	struct Tests test_cases[MAX_TEST_CASES];

	Tests cases_info;

	/*Variables to represent the number of times the keywords have been encountered in the input file,
	placing them in their respective test case.*/

	int num_arrival = 0;
	int num_departure = 0;
	int num_runtime = 0;
	int num_increment = 0;
	int num_red = 0;  
	int num_amber = 0; 
	int num_green = 0; 



	FILE *fp_in, *fp_out;


	if ((fp_in = fopen("../data/input.txt", "r")) == 0) {
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt", "w")) == 0) {
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}

	fscanf(fp_in, "%d", &number_of_test_cases);    	//read the number of test cases from a file

	printf("Number of test cases %d \n", number_of_test_cases);

	initialize_list(&cars_queue); /*Initialize the variable for the queue.*/
	bool first_line = false;


	/* read the required key-value pairs from the input file. 
	This should not include the first line, for the number of test cases. */

	while (fgets(input_string, STRING_LENGTH, fp_in))
	{
		if (!first_line)
		{
			first_line = true;
			continue;
		}


		/*extract the key*/
		sscanf(input_string, "%s %d", key, &value);

		/*convert the key to lowercase to be safe*/
		for (j = 0; j < (int)strlen(key); j++)
			key[j] = tolower(key[j]);


		printf("key-value: %s %d \n", key, value);

		/*now compare it*/
		for (int i = 0; i < NUMBER_OF_KEYS; i++)
		{

			if (strcmp(key, keylist[i]) == 0)
			{
				if (i == 0)
				{
					test_cases[num_arrival++].arrival = value;
				}
				else if (i == 1)
				{
					test_cases[num_departure++].departure = value * 1000;
				}
				else if (i == 2)
				{
					test_cases[num_runtime++].runtime = value * (60 * 1000);
				}
				else if (i == 3)
				{
					test_cases[num_increment++].increment = value;
				}
				else if (i == 4)
				{
					test_cases[num_red++].red = value * 1000;
				}
				else if (i == 5)
				{
					test_cases[num_amber++].amber = value * 1000;
				}
				else if (i == 6)
				{
					test_cases[num_green++].green = value * 1000;
				}

			}

		}
	}

	printf("\n\n");

	/*Process through each test case read in to perform needed computations*/

	for (int current_testcase = 0; current_testcase < number_of_test_cases; current_testcase++)
	{
		long int arrival_rate_input = 0; /*Vehicles per minute*/
		int departure = 0; /*Value in seconds per car*/
		int runtime = 0; /*Value in minutes*/
		int increment = 0; /*In milliseconds*/
		int red = 0;  /*Value of red time*/
		int amber = 0; /*Value of amber time*/
		int green = 0; /*Value of green time*/

		double arrival_rate = 0; /*Vehicles per minute in milliseconds*/
		int count = 0;
		double lambda = 0;

		int number_cars = 0;
		int queue_length = 0;
		long int depart_timer = 0;
		int arrival_time;
		int simulation_time = 0;

		long int wait_time = 0;
		long int max_wait_time = 0;

		long int queue_time;
		long int max_queue_length = 0;
		int queue_number = 0;
		long int running_queue = 0;
		long int avg_queue_length = 0;
		long int avg_wait_time = 0;

		ELEMENT_TYPE car;
		int light_timer = 0;
		int light_status = 0;

		cases_info = test_cases[current_testcase];

		arrival_rate_input = cases_info.arrival;
		departure = cases_info.departure;
		increment = cases_info.increment;
		runtime = cases_info.runtime;
		red = cases_info.red;
		amber = cases_info.amber;
		green = cases_info.green;

		
		/*arrival_rate_input is in cars per minute, so convert to cars per millisecond*/

		arrival_rate = ((float)arrival_rate_input) / (60 * 1000);


		/*the Poisson distribution mean, lambda is the arrival rate of the cars during the simulation interval, i.e. arrival rate per millisecond
		multiplied by the number of milliseconds in each simulation interval*/
		lambda = arrival_rate * increment;

		empty(&cars_queue);

		/*Perform traffic simulation in respect to runtime and with increment value read from the file*/

		while (simulation_time < runtime)
		{
			/*Compute the number of cars that have arrived in the current simulation interval*/
			count = samplePoisson(lambda);

			if (increment <= 0)
			{
				printf("Value of Increment is invalid.\n");
				break;
			}

			if (count > 0)
			{
				for (int j = 1; j <= count; j++)
				{
					int cars_rep = 1;
					arrival_time = simulation_time;
					assign_element_values(&e, cars_rep, simulation_time);

					enqueue(e, &cars_queue);
					
					number_cars = number_cars++;
					
				}

				queue_length += count;
				running_queue += queue_length;
				queue_number++;

				if (max_queue_length < queue_length)
				{
					max_queue_length = queue_length;
				}
			}

			if ((light_status == GREEN) && (is_empty(&cars_queue) == FALSE))
			{
				if (depart_timer > departure)
				{
					car = dequeue(&cars_queue);
					
					queue_time = simulation_time - car.arrival_time;

					queue_length--;



					if (max_wait_time < queue_time)
					{
						max_wait_time = queue_time;
					}

					wait_time += queue_time;

					depart_timer = 0;
					//queue_time = 0;
				}
				else
				{

					depart_timer += increment;

				}

			}

			if (light_status == GREEN && light_timer > green)
			{
				light_status = AMBER;
				light_timer = 0;
			}
			else if (light_status == AMBER && light_timer > amber)
			{
				light_status = RED;
				light_timer = 0;
			}
			else if (light_status == RED && light_timer > red)
			{
				light_status = GREEN;
				light_timer = 0;
			}

			light_timer += increment;

			simulation_time += increment;

		}


		while (!is_empty(&cars_queue))
		{
			
			dequeue(&cars_queue);
			queue_time = simulation_time - car.arrival_time;
			queue_length--;

			wait_time += queue_time;
		}

		//printf("%d", queue_number);


		wait_time = wait_time / 1000;

		if (number_cars != 0)
		{
			avg_wait_time = wait_time / number_cars;
		}
		max_wait_time = max_wait_time / 1000;
		
		if (queue_number != 0)
		{
			avg_queue_length = running_queue / queue_number;
		}
		fprintf(fp_out, "Arrival rate: \t%d cars per min\n", arrival_rate_input);
		fprintf(fp_out, "Departure rate: \t%d  s per car\n", (departure / 1000));
		fprintf(fp_out, "Runtime: \t\t%d min\n", (runtime / (60 * 1000)));
		fprintf(fp_out, "Time Increment: \t%d ms\n", increment, +" ms");
		fprintf(fp_out, "Light sequence: \tGreen %d s; \tAmber %d s;\tRed %d s\n", green / 1000, amber / 1000, red / 1000);
		fprintf(fp_out, "Average length:\t%d  cars\n", avg_queue_length);
		fprintf(fp_out, "Maximum length:\t%d  cars\n", max_queue_length);
		fprintf(fp_out, "Average wait:\t%d s\n", avg_wait_time);
		fprintf(fp_out, "Maximum wait:\t%d s\n", max_wait_time);

		fprintf(fp_out, "------------------------------------------------------------\n");
		printf("TEST CASE NUMBER %d\n", current_testcase+1);
		printf("NUMBER OF CARS %d\n",  number_cars);

		printf("Arrival rate: \t%d cars per min\n", arrival_rate_input);
		printf("Departure rate: \t%d  s per car\n", (departure / 1000));
		printf("Runtime: \t\t%d min\n", (runtime / (60 * 1000)));
		printf("Time Increment: \t%d ms\n", increment, +" ms");
		printf("Light sequence: \tGreen %d s; \tAmber %d s;\tRed %d s\n", green / 1000, amber / 1000, red / 1000);
		printf("Average length:\t%d  cars\n", avg_queue_length);
		printf("Maximum length:\t%d  cars\n", max_queue_length);
		printf("Average wait:\t%d s\n", avg_wait_time);
		printf("Maximum wait:\t%d s\n", max_wait_time);

		printf( "------------------------------------------------------------\n");


	}

	fclose(fp_in);
	fclose(fp_out);

	prompt_and_exit(0);

}
