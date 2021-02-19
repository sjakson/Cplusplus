//File: la1.h 
//Class provided:  Game
//
//Constructors for the counter class:
//	Game()
//		Postcondition:  two Player objects are created, the user is prompted for the names of the two players
//						the first name is assigned to currentPlayer and the second to otherPlayer.  The user
//						is also prompted for the number of chips to start the game.  The user is reprompted
//						until s/he enters an odd number bigger than three as the starting number of chips.  Next,
//						maxMove is set to half the number of chips and it finishes by printing out an empty line.
//
//Modification member functions:  
//	there aren't any
//Constant member functions:
//	bool isOver() const:	returns true if there are no chips in the pile
//	void describeState():	prints the current state of the game to the screen.  It says whose turn it is and how
//							many chips are left in the pile
//	void announceWinner():	determines which player has the even number of chips and prints a message to the screen
//	int getLegalMove():		using the private member functions isLegal and getIllegalMoveMessage, prompts the user
//							and reprompts the user until s/he enters a legal move.  Also tells the user how many
//							chips s/he can remove on this turn.
//	void updateState(int move):	Subtracts move number of chips from the pile, and subtract move number of chips
//								from currentPlayer.  Then it swaps currentPlayer and otherPlayer and computes the
//								the maxMove for the new currentPlayer (I use the min function from cstdlib.
//	bool isLegal(int move):	returns true if the number of chips is between 1 and maxMove
//	void getIllegalMoveMessage(int move):	depending on how the move is illegal it prints an appropriate message.
//											if the player tries to pick up a nonpositive number of chips, the
//											program lets he/r know.  Same if s/he tries to pick up too many chips.
//	std::string describePlayers():	returns a string saying how many chips each player has.
//Instance variables:
//	player::Player currentPlayer:	the player whose turn is being played
//	player::Player otherPlayer:		the player whose turn it is not
//	int maxMove:					the maximum moved allowed
//	int chips:						the number of chips in the pile

#ifndef LA1_H
#define LA1_H
#include<string>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include "sa4.h"

namespace game{
	class Game {
	public:
		//Constructors
		Game();
		
		//Modification methods
		
		//Constant methods
		bool isOver() const;
		void describeState();
		void announceWinner();
		int getLegalMove();
		void updateState(int move);

	private:
		
		bool isLegal(int move);
		std::string describePlayers();
		void getIllegalMoveMessage(int move);

		player::Player currentPlayer;
		player::Player otherPlayer;
		int maxMove;
		int chips;	
	};
}
#endif
