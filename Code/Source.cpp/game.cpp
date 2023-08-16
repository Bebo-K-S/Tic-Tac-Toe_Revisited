#include "game.h"

Game::Game()
{
	int i;

	for (i = 0; i < 3; i++)
		board[i][i] = ' ';
}

bool Game::checkWin(char symbol)
{
	if (symbol == board[0][0] == board[1][0] == board[2][0])	{ return (true); }		// upper -

	else if (symbol == board[0][1] == board[1][1] == board[2][1]) { return(true); }		// middle -

	else if (symbol == board[0][2] == board[1][2] == board[2][2]) { return(true); }		// lower -

	else if (symbol == board[0][0] == board[0][1] == board[0][2]) {return(true);}		// left |

	else if (symbol == board[1][0] == board[1][1] == board[1][2]) {return(true);}		// middle |

	else if (symbol == board[2][0] == board[2][1] == board[2][2]) { return (true); }	// right |

	else if (symbol == board[0][0] == board[1][1] == board[2][2]) { return (true); }	// \

	else if (symbol == board[0][2] == board[1][1] == board[2][0]) { return (true); }	// /

	return (false);
}


void Game::placeMove(char symbol,int row, int column)
{
	if (isValidMove(row, column))
		board[row][column] = symbol;
}

bool Game::isValidMove(int row, int column)
{
	if (board[row][column] == ' ')
		return (true);
	return (false);
}