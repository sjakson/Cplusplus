//003092073		Scott Jackson
//
//File: la4.h
//
//Struct implemented: Wnode struct
//
//Class implemented: ladder class
//Constructors:	
//ladder(): default constructor
//
//Member functions:
//void LoadWords(): loads the words in from a file into a vector containing objects of type
//			Wnode struct
//
//void Clear(): intializes all prev pointers in the vector to point to NULL
//
//bool FindLadder(const std::string & first,const std::string & target): takes in two strings
//				and returns true when it finds the target word in the vector, while keeping track
//				of the words needed to get from the first word to the target word in a queue
//
//void Print(): Prints out the ladder of words connecting the first word to the target word
//
//Nonmember function
//bool isOneApart(const std::string & s1,const std::string & s2): takes in two strings and
//				returns true if the string differ by one letter, otherwise it returns false


#ifndef LA4_H
#define LA4_H

#include "llist.h"
#include "qqueue.h"
#include <iostream>
#include <string>
#include <vector>

namespace pic10b{

	struct Wnode
	{
		std::string word;
		Wnode * prev;
	};

	class ladder {

	public:

		//Default constructor
		ladder();

		//Member functions
		void LoadWords();
		void Clear();
		bool FindLadder(const std::string & first,const std::string & target);
		void Print();

	private:

		std::vector<Wnode *> myWords;
		qqueue<Wnode *> q;
		Wnode* temp;
		Wnode* begin;
		Wnode* end;
	};

	//Nonmember function
	bool isOneApart(const std::string & s1,const std::string & s2);
}

#endif
