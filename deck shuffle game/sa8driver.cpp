//003092073		Scott Jackson
/*This program declares array of a Deck class fixed with objects of Card class. It then copies
the deck into a new deck and outputs both decks to the screen. After that, it calls the shuffle
function, which shuffles all the cards in the deck, and finally prints the decks to the screen again*/

#include <iostream>
#include "sa7.h"
#include "sa8.h"
using namespace std;
using namespace pic10b;


int main(){


	Deck deck1;

	Deck deck2(deck1);

	cout<<"Deck 1:"<<endl;
	cout<<deck1<<endl;

	cout<<"Deck 2:"<<endl;
	cout<<deck2<<endl;

	deck1.shuffle();
	deck2.shuffle();

	cout<<"After the shuffle function: "<<endl;

	cout<<"Deck 1:"<<endl;
	cout<<deck1<<endl;

	cout<<"Deck 2:"<<endl;
	cout<<deck2<<endl;



	return 0;

}