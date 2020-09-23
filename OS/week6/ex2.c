#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

/* 
	In Shortest Job First algorithm
	Processes are exectuting depending their arraival time
	and their service time. The algorithm usually picks the
	process with the shortest bt.
	
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
//	at[1] = 0;
//	bt[1] = 6;
//	at[2] = 0;
//	bt[2] = 4;
//	at[3] = 0;
//	bt[3] = 5;
//	at[4] = 0;
//	bt[4] = 2;

  	
  	int i;
  	for(i = 0; i < n; i++) {
  		printf("Enter arrival time and burst time respectively for process %d:", i);
		scanf("%d %d", &at[i], &bt[i]);
	}
  	
  	//Store our current time 
	int current_time = at[0];
		
	//Executing
	for(i = 0; i < n; i++) {
		int j;
		
		int shortest_bt = INT_MAX;
		int shortest_bt_id = INT_MAX;
		
		//Find the shortest process(min elem) which holds next properties:
		//at < current_time and bt < shortest_bt
		
		//To find such element we go through array
		for(j = 0; j < n; j++) {
			if(current_time >= at[j] && bt[j] != -1 && shortest_bt > bt[j]) {
				shortest_bt = bt[j];
				shortest_bt_id = j;
			}	
		}

		//Calculate CT
		current_time += bt[shortest_bt_id];
		ct[shortest_bt_id] = current_time;
		
		//Calculate TAT = CT - AT
		tat[shortest_bt_id] = ct[shortest_bt_id] - at[shortest_bt_id];
		//WT = TAT - BT
		wt[shortest_bt_id] = tat[shortest_bt_id] - bt[shortest_bt_id];
		
		bt[shortest_bt_id] = -1; //flag that we already done with the process
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
