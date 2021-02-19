//003092073		Scott Jackson
/*This program executes the chips game and all the necessary functions to run the game, then
asks the user if they would like to play again*/


#include <iostream>
#include "sa4.h"
#include "la1.h"
using namespace std;
using namespace player;
using namespace game;

void playAGame();

int main(){

char ans;
	do{
		playAGame();//executes the game and the necessary functions to run it

		cout<<"Play Another game? ";
		cin>>ans;

	}while(ans=='y'||ans=='Y');

	return 0;
}
void playAGame(){

	Game chipsGame;

	while(!chipsGame.isOver()){

		//The necessary functions needed to run the game
		chipsGame.describeState();
		int move=chipsGame.getLegalMove();
		chipsGame.updateState(move);
	}

		chipsGame.announceWinner();

}