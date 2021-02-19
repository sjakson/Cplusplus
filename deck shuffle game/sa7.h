//003092073		Scott Jackson
//
//File: sa7.h
//
//Class implemented: Card class

//Constructors:	
//Card(): default constructor
//Card(Rank RankInit, Suit SuitInit): creates an object of Card class with a rank and suit
//Card(const Card & c):	creates an object of Card class and copies the rank and suit from 
//						another card into it
//
//Member functions:
//Rank getRank() {return rank;}:  returns the rank of the card
//Suit getSuit() {return suit;}:  returns teh suit of the card
//std::string toString(): converts the suit and rank of the card into a string
//std::string abbr(): converts the suit and rank of the card into an abbreviated string
//bool isFaceCard(): returns true if the card is a face card
//
//Overloaded Operator functions:
//friend std::ostream& operator <<(std::ostream& outs, Card c): outputs the suit and rank of
//			the card using the t oString function
//friend bool operator ==(Card& c1,Card& c2): used to see if two cards are equal in either rank or suit
//friend bool operator <(Card& c1,Card& c2); used to see if one card is less than another card in 
//			rank and suit
//friend bool operator <=(Card& c1,Card& c2); used to see if one card is less than or equal to another 
//			card in rank and suit
//friend bool operator !=(Card& c1,Card& c2); used to see if two cards are not equal in rank and suit
//friend bool operator >(Card& c1,Card& c2); used to see if one card is greater than another card in 
//			rank and suit
//friend bool operator >=(Card& c1,Card& c2); used to see if one card is greater than or equal to another 
//			card in rank and suit

#ifndef SA7_H
#define SA7_H

#include <iostream>

namespace pic10b{

	enum Suit{Clubs,Diamonds,Hearts,Spades};
	enum Rank{two,three,four,five,six,seven,eight,nine,ten,jack,queen,king,ace};

	class Card {

	public:

		//Constructors
		Card();
		Card(Rank RankInit, Suit SuitInit);
		Card(const Card & c);//copy constructor

		//Member functions
		Rank getRank() {return rank;}
		Suit getSuit() {return suit;} 
		std::string toString();
		std::string abbr();
		bool isFaceCard();

		//Overloaded operator functions
		friend std::ostream& operator <<(std::ostream& outs, Card c);
		friend bool operator ==(Card& c1,Card& c2);
		friend bool operator <(Card& c1,Card& c2);
		friend bool operator <=(Card& c1,Card& c2);
		friend bool operator !=(Card& c1,Card& c2);
		friend bool operator >(Card& c1,Card& c2);
		friend bool operator >=(Card& c1,Card& c2);


	private:

		Suit suit;
		Rank rank;

	};

}
#endif