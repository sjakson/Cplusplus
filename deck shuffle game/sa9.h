//003092073		Scott Jackson
//
//File: sa8.h
//
//Class implemented: rowOfCards class
//Constructors:	
//rowOfCards(): default constructor: creates an object of rowOfCards of an empty linked list
//
//Member functions:
//rowOfCards & addCard (value_type & v):  inserts an object of type Card class into the rowOfCards
//				linked list
//
//bool consolidate(): returns true if a consolidation occurs, which happens when the last card
//				matches the rank and suit of either the card directly before it, or three cards
//				before it, and then the last card replaces that card. If no consolidation occurs
//				the function returns false
//
//size_type size(): returns the number of nodes filled up with Cards in the rowOfCards linked list
//
//Overloaded Operator functions:
//friend std::ostream& operator <<(std::ostream& outs, Card c): outputs the rowOfCards consisting of
//			the linked list of objects from the Card class to the screen 



#ifndef SA9_H
#define SA9_H

#include <iostream>
#include "sa7.h"
#include "sa8.h"
#include "llistTemplate.h"

namespace pic10b{


	class rowOfCards {

		//Overloaded Member function
		friend std::ostream& operator <<(std::ostream& os, rowOfCards& r);


	public:

		typedef Card value_type;
		typedef llist<Card>::size_type size_type;

		//Constructor
		rowOfCards();

		//Member functions
		rowOfCards & addCard (value_type & v) {source.insert(source.begin(),v); return *this;}

		bool consolidate();

		size_type size() const {return source.size();}


	private:

		llist<Card> source;



	};

}

#endif