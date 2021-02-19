//003092073		Scott Jackson
//
//File: sa8.h
//
//Class implemented: Deck class

//Constructors:	
//Deck(): default constructor: creates an object of Deck class consisting of an array filled 
//			with 52 objects of Card class
//Deck(const Deck &d):	creates an object of Deck class and copies each element of the original 
//						array into the new array
//
//Member functions:
//void Deck::shuffle():  shuffles the Cards of the Deck array randomly
//
//value_type & dealACard(const size_type & i): returns a single Card from the Deck array
//
//Overloaded Operator functions:
//friend std::ostream& operator <<(std::ostream& outs, Card c): outputs the Deck consisting of
//			the array of objects from the Card class to the screen 



#ifndef SA8_H
#define SA8_H

#include <iostream>
#include "sa7.h"

namespace pic10b{

	class Deck {

	public:

		typedef Card value_type;
		typedef int size_type;
		const static size_type capacity=52;

		//Constructors

		Deck();
		Deck(const Deck &d);//copy constructor

		//Member functions
		void shuffle();

		value_type & dealACard(const size_type & i);

		//Overloaded operator functions
		friend std::ostream& operator <<(std::ostream& outs, Deck c);

	private:

		value_type data [capacity];

	};

}
#endif