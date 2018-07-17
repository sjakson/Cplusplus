/**********************************************************************/
/* NAME: Scott Jackson						 					      */
/* CLASS: 326							  						      */
/* SECTION: Tuesday and Thursday 11 am							      */
/* PROGRAM NAME: p1.c						  					      */
/* DESCRIPTION:  This program generates a user-defined number of	  */
/* 				 processes N, and generates a random service time	  */
/* 				 for each process based on a user-defined average	  */
/* 				 service time S, for those processes, as well as a    */
/* 				 random arrival time. The user also inputs a seed	  */
/* 				 that the progranm uses for its random number 		  */
/* 				 generator. The program also calculates waiting time  */
/* 				 and turnaround time for each process based on how 	  */
/* 				 long the process has to wait before it gets serviced */
/* 				 as well as how long it take fromt he time the proess */
/* 				 arrives to the time it finishes. 		  			  */
/*																	  */
/**********************************************************************/


#include <iostream>
using namespace std;

int main () {
    
	int N, S, seed, currentServiceTime, arrivalTime=0, waitTime=0, runningServiceTime=0, 
	arrivalTimePrevious, turnaroundTime, totalTurnaroundTime=0, totalWaitTime=0, i;
	
	cout << "Input number of processes: ";//user input number of processes to generate
	cin >> N;
	
	cout << "Input average service time: ";//user input the average service time of those processes
	cin >> S;
	
	cout << "Input seed number: ";//user input the seed number used to generate service times and arrival times
	cin >> seed;
	
	srand(seed);
	
	int serviceTime = (S*N);//total service time used to calculate the average
	int totalServiceTime = serviceTime;//save the total service time
		
	if(N<30){
		cout<< endl << "Process	Service Arrival Waiting Turnaround"<<endl;
		cout<< "        Time    Time	Time    Time "<<endl;
	}
	
    for (i=0; i<N-1; i++){
    	currentServiceTime=(rand()%serviceTime)+1;//create random service time for current process
    	
    	
    	if(currentServiceTime==serviceTime)//make sure currentServiceTime is not too large
    		currentServiceTime=currentServiceTime-1;
    	
       	turnaroundTime = waitTime + currentServiceTime;
       	
       	totalTurnaroundTime += turnaroundTime;//keep track of total turnaround time
	    
       	if(N<30)
       		cout << i <<"\t"<< currentServiceTime << "\t" << arrivalTime << "\t" <<waitTime << "\t" <<turnaroundTime << endl;//print parameters of current process
	    
	    runningServiceTime = runningServiceTime + currentServiceTime;//keep track of how long the processes have been running
	    
	    arrivalTimePrevious = arrivalTime;//save the current arrival time in arrivalTimePrevious
	    
	    while((arrivalTime=rand()%totalServiceTime)<arrivalTimePrevious){}//stay in loop until an arrival time larger than
	    																  //the previous arrival time is generated
	    
	    
	    waitTime = runningServiceTime - arrivalTime;//the wait time is the total running time - the time the process arrives
	    
	    if(waitTime<0){//if the process arrival Time is greater than than the runningServiceTime, then the wait time is zero
	    	runningServiceTime = runningServiceTime + (-waitTime);
	    	waitTime=0;
	    }
	    
	    totalWaitTime += waitTime;//keep track of total wait time
	    
    	serviceTime -=currentServiceTime;
	 	 
    }

    turnaroundTime = serviceTime + waitTime;//turnaround time of last process
    
    totalTurnaroundTime += turnaroundTime;//keep track of total turnaround time
    
    if(N<30)
    	cout << i+1 << "\t" << serviceTime << "\t" <<arrivalTime << "\t" <<waitTime << "\t" << turnaroundTime << endl;
 
    cout << "\nAverage waiting time: " << (double)totalWaitTime/N << endl;
    
    cout << "Average turnaround time: " << (double)totalTurnaroundTime/N << endl;
    
    exit(0);
}
