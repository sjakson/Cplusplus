//003092073		Scott Jackson
/*This program declares array of a Deck class fixed with objects of Card class. It then 
 shuffles all the cards in the deck, and deals a card one at a time into a linked list of
 type rowOfCards class. Each time a card is dealt into the linked list, the program checks to
 to see if it can consolidate the list. Consolidation occurs if the last card in the list
 either matches the suit or rank of the card before it, or 3 cards before it. After the 
 program deals the whole deck , if there is one card remaining, then the game is won*/

#include <iostream>
#include "sa7.h"
#include "sa8.h"
#include "sa9.h"
#include "llistTemplate.h"


using namespace std;
using namespace pic10b;


int main(){


	Deck deck1;

	deck1.shuffle();

	rowOfCards d;




	for(Deck::size_type i=0;i<Deck::capacity;i++){
		d.addCard(deck1.dealACard(i));


		do{
			cout<<i+1<<": "<<d<<endl;
			d.consolidate;


		}while(d.consolidate());


	}


if(d.size()>1)
	cout<<"\nThere were "<<d.size()<<" piles left. Try again!"<<endl;
else
	cout<<"There is one pile left. You win!"<<endl;



	return 0;

}