/*
Created by Gizem Gezici
Modified by Zeynep Dogmus
Modify Date: April 2013
Player Class
*/
#include "Player.h"
#include "Board.h"
#include<iostream>
#include<string>

using namespace std;

//The play function of the board (shared object) is called.
bool Player::Play(string playedStr, int row, int col)
{
#ifdef WITHPOINTER
    //TODO: For the students
	//add another form of return command similar to the below here
	return board->ToBePlayed(playedStr, row, col);
#else
	return board.ToBePlayed(playedStr, row, col);
#endif
}

//The function to check whether this player is winning or not
//Calls the function of board (shared object)
bool Player::wins()
{
#ifdef WITHPOINTER
	return board->checkSomeoneWins(this->playerChar);
#else
	return board.checkSomeoneWins(this->playerChar);
#endif
}
