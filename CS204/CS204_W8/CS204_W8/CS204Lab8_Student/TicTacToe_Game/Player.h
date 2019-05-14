/*
Created by Gizem Gezici
Modified by Zeynep Dogmus
Modify Date: April 2013
Player Class
Please pay attention to the class design.
*/
#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include<string>
#include<iostream>
using namespace std;

//Uncomment the line below to see an example of object sharing with pointer
#define WITHPOINTER

class Player
{
	public:
		Player();
#ifdef WITHPOINTER
		Player::Player(Board *myboard,string c)
		: board(myboard), playerChar(c)
		{ }
#else
		Player::Player(Board &myboard,string c)
		: board(myboard), playerChar(c)
		{ }
#endif

		//Play function of the player class will call ToBePlayed function of Board Class.
		bool Play(string playedStr, int row, int col);
		bool wins();

	private:
#ifdef WITHPOINTER
        //TODO: For the students
		//Pointer to keep the shared object between two players
		//declare "board" variable here
		Board * board;
#else
        //TODO: For the students
		//Referenced variable (shared object between two players)
		// declare "board" variable here
		Board & board;
#endif
		string playerChar;
};

#endif