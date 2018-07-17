//003092073		Scott Jackson
/*This program asks the user to input two words of five letters each, then the program finds 
a ladder of words that connects the two words, done by changing one letter at a time, and
it prints out the ladder of words to the screen*/

#include <iostream>
#include "la4.h"
#include "qqueue.h"
#include "llist.h"


using namespace std;
using namespace pic10b;


int main(){

	ladder l;

	l.LoadWords();
	l.Clear();

	string first,target;
	cout<<"Enter two words between which a ladder you want to find: ";
	cin>>first;
	cin>>target;

	if(first.length()!=5 || target.length()!=5)
		cout<<"Enter five letter words, next time!"<<endl;

	l.FindLadder(first,target);
	l.Print();

	return 0;

}