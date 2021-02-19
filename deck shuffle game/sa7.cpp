//003092073		Scott Jackson
//This is the implementation file, where the functions declared in the
//file "sa7.h" are implemented

#include "sa7.h"
#include <iostream>
#include <string>

namespace pic10b{

	//Constructors
	Card::Card(){}//default constructor

	Card::Card(Rank RankInit, Suit SuitInit){

		rank=RankInit;
		suit=SuitInit;

	}

	Card::Card(const Card & c){//copy constructor

		rank=c.rank;
		suit=c.suit;


	}

	//Member functions
	bool Card::isFaceCard(){

		return (rank>=9);

	}

	std::string Card::toString(){

		std::string temp;
		std::string temp2;

		switch(rank){

		case 0:
			temp="two";
			break;

		case 1:
			temp="three";
			break;

		case 2:
			temp="four";
			break;

		case 3:
			temp="five";
			break;

		case 4:
			temp="six";
			break;

		case 5:
			temp="seven";
			break;

		case 6:
			temp="eight";
			break;

		case 7:
			temp="nine";
			break;

		case 8:
			temp="ten";
			break;

		case 9:
			temp="jack";
			break;

		case 10:
			temp="queen";
			break;

		case 11:
			temp="king";
			break;

		case 12:
			temp="ace";
			break;

		}

		switch(suit){

		case 0:
			temp2="Clubs";
			break;

		case 1:
			temp2="Diamonds";
			break;

		case 2:
			temp2="Hearts";
			break;

		case 3:
			temp2="Spades";
			break;

		}

		return temp+" of "+temp2;

	}

	std::string Card::abbr(){

		std::string temp;
		std::string temp2;

		switch(rank){

		case 0:
			temp="2";
			break;

		case 1:
			temp="3";
			break;

		case 2:
			temp="4";
			break;

		case 3:
			temp="5";
			break;

		case 4:
			temp="6";
			break;

		case 5:
			temp="7";
			break;

		case 6:
			temp="8";
			break;

		case 7:
			temp="9";
			break;

		case 8:
			temp="10";
			break;

		case 9:
			temp="J";
			break;

		case 10:
			temp="Q";
			break;

		case 11:
			temp="K";
			break;

		case 12:
			temp="A";
			break;

		}

		switch(suit){

		case 0:
			temp2="C";
			break;

		case 1:
			temp2="D";
			break;

		case 2:
			temp2="H";
			break;

		case 3:
			temp2="S";
			break;

		}

		return temp+temp2;

	}

	//Overloaded operator functions
	std::ostream& operator <<(std::ostream& outs, Card c){

		outs<<c.abbr();

		return outs;
	}


		bool operator ==(Card& c1,Card& c2){

			return ((c1.rank==c2.rank) || (c1.suit==c2.suit));

		}

		bool operator <(Card& c1,Card& c2){

			return ((c1.rank<c2.rank) && (c1.suit<c2.suit));

		}

		bool operator <=(Card& c1,Card& c2){

			return ((c1.rank<=c2.rank) && (c1.suit<=c2.suit));

		}

		bool operator !=(Card& c1,Card& c2){

			return ((c1.rank!=c2.rank) && (c1.suit!=c2.suit));

		}

		bool operator >(Card& c1,Card& c2){

			return ((c1.rank>c2.rank) && (c1.suit>c2.suit));

		}

		bool operator >=(Card& c1,Card& c2){

			return ((c1.rank>=c2.rank) && (c1.suit>=c2.suit));

		}

	
}