//003092073		Scott Jackson
//This is the implementation file, where the functions declared in the
//file "la1.h" are implemented

#include "la1.h"
#include "sa4.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

namespace game{

	Game::Game(){

		std::string name;

		std::cout<<"What is the name of the first player? ";
		std::cin>>name;
		player::Player temp(name);
		currentPlayer = temp;
		
		
		std::cout<<"What is the name of the second player? ";
		std::cin>>name;
		player::Player temp2(name);
		otherPlayer=temp2;

		
		std::cout<<"How many chips does the initial pile contain? ";
		do{
			std::cin>>chips;

			if(chips<3)
				std::cout<<"You have to start with at least 3 chips. Choose another number: ";
			else if(chips%2==0)
				std::cout<<"You have to start with an odd number of chips. Choose another number: ";

		}while((chips<3)||(chips%2==0));

		maxMove=chips/2;

		std::cout<<"\n";
	}

	bool Game::isOver() const{

		if (chips==0)
			
			return true;
		else
			return false;

	}

	void Game::describeState(){

		std::cout<<describePlayers()<<"\n";
		std::cout<<"It is your turn, "<<currentPlayer.getName()<<"\n";
		std::cout<<"There are "<<chips<<" chips remaining\n";

	}

	void Game::announceWinner(){

		std::cout<<describePlayers()<<"\n";

		if(currentPlayer.getChips()%2==0)
			std::cout<<currentPlayer.getName()<<" wins\n";

		if(otherPlayer.getChips()%2==0)
			std::cout<<otherPlayer.getName()<<" wins\n";


	}

	int Game::getLegalMove(){

		int move;

		std::cout<<"You may take any number of chips from 1 to "<<maxMove<<"\n";

		do{
			std::cout<<"How many will you take, "<<currentPlayer.getName()<<"?: ";
			std::cin>>move;
			getIllegalMoveMessage(move);

		}while(!isLegal(move));

		return move;
	}

	void Game::updateState(int move){

		chips-=move;
		currentPlayer.chipsAdded(move);

		std::string name;
		player::Player temp(name);

		temp=currentPlayer;
		currentPlayer=otherPlayer;
		otherPlayer=temp;


		if(2*move>chips)
			maxMove=chips;
		else
			maxMove=2*move;

	}

	//private
	bool Game::isLegal(int move){
		
		if((1<=move)&&(move<=maxMove))
			return true;
		else
			return false;

	}


	std::string Game::describePlayers(){

	return currentPlayer.describe()+"\n"+ otherPlayer.describe();
	}


	void Game::getIllegalMoveMessage(int move){

		if(move<1)
			std::cout<<"Illegal move. You must take at least one chip\n";
		if(move>maxMove)
			std::cout<<"Illegal move. You may not take more than "<<maxMove<<" chips\n";


	}

}