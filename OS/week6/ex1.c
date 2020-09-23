#include <stdio.h> 
#include <stdlib.h>

/* 
	In First Come First Server algorithm
	Processes are exectuting in order of they requested it.
	
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
	int bt[max_n], at[max_n], ct[max_n], wt[max_n];
	double tat[max_n];
	
	//5 for test case
	int n = 5;
	
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
  	
  	int i;
  	for(i = 0; i < n; i++) {
  		printf("Enter arrival time and burst time respectively for process %d:", i);
		scanf("%d %d", &at[i], &bt[i]);
	}
  	
  	//Sort by AT in increasing order to handle processes in right order
  	bubbleSort(at, bt, n);
	
	//Executing
	for(i = 0; i < n; i++) {
		//Calculate CT
		if(i == 0) {
			ct[i] = bt[i];
		}
		else {
			ct[i] = bt[i] + ct[i - 1];
		}
		
		//Calculate TAT = CT - AT
		tat[i] = ct[i] - at[i];
		//WT = TAT - BT
		wt[i] = tat[i] - bt[i];
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
