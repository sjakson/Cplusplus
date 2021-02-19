//003092073		Scott Jackson
//This is the implementation file, where the functions declared in the
//file "sa8.h" are implemented

#include "sa8.h"
#include "sa7.h"
#include <iostream>
#include <ctime>

namespace pic10b{

	//Default Constructor
	Deck::Deck(){

		size_type k=0;

		for(size_type i=0;i<13;i++){
			for(size_type j=0;j<4;j++){
				data[k]= Card(Rank(i),Suit(j));
				k++;
			}
		}

	}

	//Copy Constructor
	Deck::Deck(const Deck & d){

		for(size_type i=0;i<capacity;i++)
			data[i]=d.data[i];

	}

	//Member functions
	void Deck::shuffle(){

		srand(time(NULL));

		value_type temp[capacity];
		value_type random[capacity];
		bool move[capacity]={false};

		for(size_type i=0;i<capacity;i++){

			size_type j=(rand()%52+1);

			if(move[j]==false){

				temp[i]=data[i];
				data[i]=data[j];
				data[j]=temp[i];

				move[j]=true;
			}

		}
	}


	Deck::value_type & Deck::dealACard(const size_type & i){

		return data[i];

	}


	//Overloaded Operator
	std::ostream& operator <<(std::ostream& outs, Deck c){

		for(Deck::size_type i=0;i<Deck::capacity;i++)
			outs<<c.data[i]<<" ";
		outs<<"\n";

		return outs;
	}



}