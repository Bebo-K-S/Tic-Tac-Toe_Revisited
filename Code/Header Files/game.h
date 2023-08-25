#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

using namespace std;

class Game
{
private:
	/* The internal board for the game */
	char board[3][3]; 

	/* Counter for the total moves */
	int moves = 0; 

	string player1Name = "", player2Name = "";

	/* The boolean that'll determine the end of the game*/
	bool gameFinished = false;

public:
	Game();
	bool checkWin(char);
	void placeMove(char, int, int);
	bool isValidMove(int, int);
	void incrementMove();
	int getMove();
	bool isXsTurn();
};

#endif