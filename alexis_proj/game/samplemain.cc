/*****************************************************
This is a sample of what the main should like for the second phase of 
the Mancala game.The only change is that the game now announces a 
winner.
	John Dolan	Ohio University		Spring 2018
*************************************************************/
#include<iostream>
#include "mancala.h"
#include "game.h"
using namespace std;
using namespace main_savitch_14;


int main(){
	//char answer;
    
	//answer = 'y';
	//while(answer != 'n'){
		mancala stonegame;
		game::who winner;
		winner=stonegame.play();
		if (winner == game::HUMAN)
			std::cout<<"YOU WIN!!" << endl;
		else if(winner == game::COMPUTER)	
			std::cout<<"YOU LOSE!!" << endl;
		else
			std::cout<<"TIE!" << endl;
		//cout << "Would you like to play again? (y/n): ";
	//	cin >> answer;
//	}
	return 0;
}

