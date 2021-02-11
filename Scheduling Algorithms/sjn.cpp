#include <iostream>
using namespace std;

int main (){
	
	int N, S, seed, index, currentServiceTime, arrivalTimePrevious, arrivalTime=0, i, runningServiceTime=0, 
	shortestJobNextPrevious, shortestJobNext=0, shortestJobArrival;
	
	cout << "Input number of processes: ";
	cin >> N;
		
	cout << "Input average service time: ";
	cin >> S;
		
	cout << "Input seed number: ";
	cin >> seed;
		
	srand(seed);
	
	int serviceTimeArray[N];
	int arrivalTimeArray[N];

	

	
	int serviceTime = (S*N);//total service time used to calculate the average
	int totalServiceTime = serviceTime;//save the total service time
	
	if(N<30){
			cout<< endl << "Process	Arrival Service Waiting Turnaround"<<endl;
			cout<< "        Time    Time	Time    Time "<<endl;
		}
	
	 for (i=0; i<N-1; i++){
	    	currentServiceTime=(rand()%serviceTime)+1;//create random service time for current process
	    	
	 if(currentServiceTime==serviceTime)//make sure currentServiceTime is not too large
	        currentServiceTime=currentServiceTime-1;
	
	 //runningServiceTime += currentServiceTime
	 
	 serviceTimeArray[i] = currentServiceTime;
	 
	 arrivalTimeArray[i]= arrivalTime;
	 
	 arrivalTimePrevious = arrivalTime;//save the current arrival time in arrivalTimePrevious
		    
	 while((arrivalTime=rand()%totalServiceTime)<arrivalTimePrevious){}//stay in loop until an arrival time larger than
	 
	 serviceTime -=currentServiceTime;
	

	// if(arrivalTime > runningServiceTime)
		// runningServiceTime = runningServiceTime + (arrivalTime - runningServiceTime);
	 
	 
	 
 }
 
	 arrivalTimeArray[i]= arrivalTime;
	 
	 serviceTimeArray[i] = serviceTime;

	 cout<<0<<"\t"<<arrivalTimeArray[0]<<"\t"<<serviceTimeArray[0]<<endl;
	 
	 runningServiceTime += serviceTimeArray[0];
	 
	 for (i=1; i<N; i++){
		 
			 if(arrivalTimeArray[i] > runningServiceTime){//if no processes in the queue, sjn will be the next process to arrive
				 runningServiceTime = arrivalTimeArray[i] + serviceTimeArray[i];
				 cout<<i<<"\t"<<arrivalTimeArray[i]<<"\t"<<serviceTimeArray[i]<<endl;
				 serviceTimeArray[i]=0;
			 }
		 
			 else{
				 shortestJobNextPrevious = shortestJobNext;
				 shortestJobNext = serviceTimeArray[i];
				 shortestJobArrival = arrivalTimeArray[i];
				 index = i;
				 
				 for(int j=0; j<N; j++){
					 
					 if((arrivalTimeArray[j]<runningServiceTime) && (serviceTimeArray[j]!=0) ){//consider process only if it has already arrived
						 if((serviceTimeArray[j]<shortestJobNext) && (shortestJobNextPrevious < shortestJobNext) ){//find the shortest job of the processes waiting
							 shortestJobNext = serviceTimeArray[j];
							 shortestJobArrival = arrivalTimeArray[j];
							 index = j;
							 serviceTimeArray[j]=0;
							 
						 }
				 	 }
				 }
				 runningServiceTime += shortestJobNext;
				 
				 cout<<index<<"\t"<<shortestJobArrival<<"\t"<<shortestJobNext<<endl;
				 
				 
			 }
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 //cout<<i<<"\t"<<arrivalTimeArray[i]<<"\t"<<serviceTimeArray[i]<<endl;
		 	 
		 
	 }
	 
	 exit (0);
}	
