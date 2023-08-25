#include "game.h"

/**
* Game - A constructor that sets the board with empty spaces.
*/
Game::Game()
{
	int i;

	for (i = 0; i < 3; i++)
		board[i][i] = ' ';
}

/**
* checkWin - A function that checks the 8 possible winning conditions for a 
*            given symbol and changes the state of gameFinished variable in the Game class.
* 
* @symbol: The symbol to check the winning condition on.
* 
* Return: (true) if it met one of those conditions otherwise (false).
*/
bool Game::checkWin(char symbol)
{
	if (moves >= 4)
	{
		if (symbol == board[0][0] == board[1][0] == board[2][0]) { gameFinished = true; return (true); }		// upper -

		else if (symbol == board[0][1] == board[1][1] == board[2][1]) { gameFinished = true; return(true); }		// middle -

		else if (symbol == board[0][2] == board[1][2] == board[2][2]) { gameFinished = true; return(true); }		// lower -

		else if (symbol == board[0][0] == board[0][1] == board[0][2]) { gameFinished = true; return(true); }		// left |

		else if (symbol == board[1][0] == board[1][1] == board[1][2]) { gameFinished = true; return(true); }		// middle |

		else if (symbol == board[2][0] == board[2][1] == board[2][2]) { gameFinished = true; return (true); }	// right |

		else if (symbol == board[0][0] == board[1][1] == board[2][2]) { gameFinished = true; return (true); }	// \

		else if (symbol == board[0][2] == board[1][1] == board[2][0]) { gameFinished = true; return (true); }	// /
	}

	return (false);
}

/**
* placeMove - A function that places the symbol in the entered row & column
* 
* @symbol: The symbol to be inserted.
* @row: The row at which to insert in the array.
* @column: The column at which to insert in the array.
*/
void Game::placeMove(char symbol,int row, int column)
{
	if (isValidMove(row, column))
		board[row][column] = symbol;
}

/**
* isValidMove - A function that checks on the board array if it's a valid
*               move to be played or not.
* 
* @row: The row of the array.
* @column: The column of the array.
* 
* Return: (true) if it's valid otherwise (false).
*/
bool Game::isValidMove(int row, int column)
{
	if (board[row][column] == ' ')
		return (true);
	return (false);
}

/**
* incrementMove - A function that increments the number of moves by 1.
*/
void Game::incrementMove()
{
	moves += 1;
}

/**
* getMove - A function that returns the current number of moves done.
* 
* Return: Number of moves done.
*/
int Game::getMove()
{
	return (moves);
}

/**
* isXsTurn - A function that checks if the current turn is X's or not.
* 
* Return: (true) if it's X's turn (false) otherwise.
*/
bool Game::isXsTurn()
{
	if (moves % 2 == 0)
		return (true);
	return (false);
}