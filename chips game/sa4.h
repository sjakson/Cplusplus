//File: sa4.h 
//Class provided:  Player
//
//Constructors for the Player class:
//	Player()
//		Postcondition:  nothing is done.  This is needed for a technical reason:  since the Game class
//						will have Player objects and the game constructor takes in no parameters, there
//						must be a Player constructor that takes in no parameters.  It never gets called.
//
//  Player(std::string name):	initializes the player to have name as its name and to have no chips.

//
//Modification member functions:  
//	void chipsAdded (int added):	increases the number of chips the player has
//Constant member functions:
//	std::string describe():	returns a string which is a message containing the player's name 
//							and the number of chip s/he has 
//	std::string getName():  returns the player's name as a string
//	int getChips() const:	returns the number of chips the player has
//
//Instance variables:
//	std::string myName:	the player's name
//	int myChips:		the number of chips the players has

#ifndef SA4_H
#define SA4_H
#include<string>
#include<sstream>

namespace player{
	class Player {
	public:
		//Constructors
		Player(); 
		Player(std::string name); 
		
		//Modification methods
		void chipsAdded (int added);  
		//Constant methods
		std::string describe();	 
		std::string getName();	
		int getChips() const;			
	private:
		std::string myName;	
		int myChips;		
	};
}
#endif
