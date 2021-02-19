h//003092073		Scott Jackson
//This is the implementation file, where the functions declared in the
//file "sa4.h" are implemented

#include "sa4.h"
#include <string>
#include <sstream>
#include <iostream>

namespace player{

	Player::Player(){}
	
	Player::Player(std::string name){

		myName=name;
		myChips=0;

	}

	std::string Player::getName(){

		return myName;

	}

	int Player::getChips() const{

		return myChips;

	}


	void Player::chipsAdded(int added){

		myChips+=added;
	}

	std::string Player::describe(){

		std::string s; //a string called s
		std::stringstream sin; //a stream that reads in strings
		sin << myChips; //reads x in through sin
		std::string strX(sin.str()); //converts int x into a string whose entries are the digits of x


		return myName+" has "+strX+" chip(s)";
	}

}