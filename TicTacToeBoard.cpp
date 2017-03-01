#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if (turn == X) turn = O;
	else turn = X;
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	clearBoard();
	turn = X;
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for (int i = 0; i < BOARDSIZE; i++){
		for (int j = 0; j < BOARDSIZE; j++){
			board[i][j] = Blank;
		}
	}	
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	Piece current = getPiece(row, column);  	
	if (current != Blank){
		toggleTurn();
		return current;
	}
	else {
		board[row][column] = turn;
		Piece placed = turn;
		toggleTurn();
		return placed;		
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  	if (row < 0 || row >= BOARDSIZE || column < 0 || column >= BOARDSIZE){
		return Invalid;
	}
	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  	for (int i = 0; i < BOARDSIZE; i++){
		if (board[i][0] != Blank && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
		if (board[0][i] != Blank && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Blank)
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != Blank)
		return board[2][0];
	
	// Check to see if board is full
	bool full = true;
	for (int i = 0; i < BOARDSIZE; i++){
		for (int j = 0; j < BOARDSIZE; j++){
			if (board[i][j] == Blank){
				full = false;
				break;
			}
		}
	}
	if (full) return Blank;	


	return Invalid;
}
