#include <stdio.h> 
#include <stdlib.h>

/* 
	In Shortest Job First Algorithm each process
	gets a quantum of time for execution, then it goes to the
	end of queue and wait until scheduler gives for the process
	some time for execution. All processes are put in the queue.
	
	
	Description of each case:
	1) FCFS algorithm: just works as a queue, and in the output we see 
	all processes which are executed in order of arriving to ready state.
	2) SJF algorithm: let small processess be executed as soon
	as possible. Before execution, it picks the shortest process, then execute,
	and in the output: we can see such order as described above.
	3) Round Robin algorithm: all processes are in the queue, and scheduler
	gives in order for each process a quantum of time until process will be
	executed, and in the output we can see ordered execution of each process 1 by 1.  
	
	Terms:
	CT = Completion Time
	BT = Burst Time
	AT = Arrival Time
	ET = Exit Time
	RT = Response Time
	WT = Waiting Time
	TAT = Turnaround Time  
	
	Made by Vladislav Lamzenkov. Thank you.
*/

//Swap a and b
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

// A function to implement STABLE bubble sort
// Also, this function swaps the element in sec_arr
// if it swaps elements in arr, it needs to maintain
// the right order of elements
void bubbleSort(int arr[], int sec_arr[], int n) 
{ 
   int i, j; 
   
   for (i = 0; i < n-1; i++)       
   		for (j = 0; j < n-i-1; j++)  
        	if (arr[j] > arr[j+1]) {
            	swap(&arr[j], &arr[j+1]); 
            	swap(&sec_arr[j], &sec_arr[j + 1]);
			}
}  

int main() 
{ 
	int max_n = 10;
	int bt[max_n], at[max_n], ct[max_n], wt[max_n], remaining_bt[max_n];
	double tat[max_n];
	
	//1 is for test case
	float quantum = 1.0;
	
	//5 for test case
	int n = 5;
	
	
	//Input data
  	printf("Enter number of processes(max 10):");
  	scanf("%d", &n);
  	
  	if(n > max_n) {
  		printf("I am really sorry, but max number of processes is 10 :(");
		return -1;	
	}
	
	//Test case
//	at[0] = 0;
//	bt[0] = 3;
//	at[1] = 2;
//	bt[1] = 6;
//	at[2] = 4;
//	bt[2] = 4;
//	at[3] = 6;
//	bt[3] = 5;
//	at[4] = 8;
//	bt[4] = 2;

	printf("Enter a quantum of time: ");
	scanf("%f", &quantum);
  	
  	int i;
  	for(i = 0; i < n; i++) {
  		printf("Enter arrival time and burst time respectively for process %d:", i);
		scanf("%d %d", &at[i], &bt[i]);
	}
  	
  	//Sort by AT in increasing order to handle processes in right order
  	bubbleSort(at, bt, n);
  	
  	//Do the copy of burst time to remember remaining time for each process
  	for(i = 0; i < n; i++) {
  		remaining_bt[i] = bt[i];
	}
  	
  	//Current time in our system
  	float current_time = at[0];
	
	//Executing
	while(1) {
		int j;
		unsigned char flag = 0;
		
		//Check at for each process and give it a quantum of time for their executions
		for(j = 0; j < n; j++) {
			if(current_time >= at[j] && remaining_bt[j] > 0) {
				flag = 1;
				remaining_bt[j] -= quantum; 
				current_time += quantum;
				
				if(remaining_bt[j] <= 0) {
					//Finished process
					
					//Calculate CT
					ct[j] = current_time;
					//Calculate TAT = CT - AT
					tat[j] = ct[j] - at[j];
					//WT = TAT - BT
					wt[j] = tat[j] - bt[j];
					
				}		
			}
		}
		
		//If there was no changes, all processes are done, terminate the loop
		if(flag == 0) break;
	}
	
	//Find AVT = (TAT[1]+...+TAT[N]) / n 
	//Find AWT = (WT[1]+...+WT[N]) / n
	float avt = 0;
	float awt = 0;
	
	for(i = 0; i < n; i++) {
		avt += tat[i];
		awt += wt[i];
	}
	
	avt = avt / n;
	awt = awt / n;
	
	//Output all information
	for(i = 0; i < n; i++) {
		printf("\n");
		printf("Process[%d] CT time = %d\n", i, ct[i]);
		printf("Process[%d] TAT time = %3.2f\n", i, tat[i]);
		printf("Process[%d] WT time = %d\n", i, wt[i]);
		printf("\n");
	}
	
	printf("AVT = %3.2f\n", avt);
	printf("AWT = %3.2f", awt);
  	
    return 0; 
} 
