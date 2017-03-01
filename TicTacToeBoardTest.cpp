/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, checkConstructorClearedBoard){
	TicTacToeBoard tb;
	bool clear = true;
	for (int i = 0; i < BOARDSIZE; i++){
		for (int j = 0; j < BOARDSIZE; j++){
			if (tb.getPiece(i, j) != Blank){
				clear = false;
				break;
			}
		}
	}
	ASSERT_TRUE(clear == true);
}

TEST(TicTacToeBoardTest, checkClearBoard){
	TicTacToeBoard tb;
	bool clear = true;
	for (int i = 0; i < BOARDSIZE; i++){
		for (int j = 0; j < BOARDSIZE; j++){
			if (tb.getPiece(i, j) != Blank){
				clear = false;
				break;
			}
		}
	}
	ASSERT_TRUE(clear == true);
}

TEST(TicTacToeBoardTest, checkFirstTurnIsX){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(0,0) == X);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceRowTooHighColValid){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(10,1) == Invalid);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceColTooHighRowValid){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(1,10) == Invalid);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceRowTooHighColTooHigh){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(10,10) == Invalid);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceColNegativeRowNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(-10,-10) == Invalid);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceRowTooHighColNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(10,-10) == Invalid);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceColTooHighRowNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(-10, 10) == Invalid);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceRowNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(-10,1) == Invalid);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceColNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(0,-1) == Invalid);
}
TEST(TicTacToeBoardTest, checkValidPlacePiece){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(0,2) == X);
}

TEST(TicTacToeBoardTest, checkValidPlacePieceToggleTurn){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.placePiece(0,1) == O);
}

TEST(TicTacToeBoardTest, checkInvalidPlacePieceToggleTurn){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(-2,10);
	ASSERT_TRUE(tb.placePiece(0,1) == X);
}

TEST(TicTacToeBoardTest, checkPlaceNotEmpty){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.placePiece(0,0) == X);
}

TEST(TicTacToeBoardTest, checkPlaceNotEmptyToggleTurn){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.placePiece(0,1) == X);
}

TEST(TicTacToeBoardTest, checkTurnsAreTogglingX){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.placePiece(0,1) == O);
}

TEST(TicTacToeBoardTest, checkTurnsAreTogglingO){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(0,1);
	ASSERT_TRUE(tb.placePiece(0,2) == X);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsRowValueTooHigh){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(10,0) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsRowValueNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(-1,2) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsColValueTooHigh){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(0,10) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsColValueNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(0,-1) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsBothTooHigh){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(10, 10) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsBothNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(-10,-10) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsRowValueNegativeColTooHigh){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(-1, 10) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsRowValueTooHighColNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(10,-1) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceValidSpot){

	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.getPiece(0,0) == X);
}

TEST(TicTacToeBoardTest, checkGetPieceBlank){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(0,0) == Blank);
}

TEST(TicTacToeBoardTest, checkNoWinnerOnePiecePlaced){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerFirstTwoPiecesInRow){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(1,0);
	tb.placePiece(0,1);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerSecondTwoPiecesInRow){
	TicTacToeBoard tb;
	tb.placePiece(0,1);
	tb.placePiece(1,0);
	tb.placePiece(0,2);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerFirstTwoPiecesInCol){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(1,1);
	tb.placePiece(1,0);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerSecondTwoPiecesInCol){
	TicTacToeBoard tb;
	tb.placePiece(1,0);
	tb.placePiece(1,1);
	tb.placePiece(2,0);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerTopLeftDiagonalFirstTwoPieces){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(1,0);
	tb.placePiece(1,1);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerTopLeftDiagonalSecondTwoPieces){
	TicTacToeBoard tb;
	tb.placePiece(1,1);
	tb.placePiece(1,0);
	tb.placePiece(2,2);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerBottomLeftDiagonalFirstTwoPieces){
	TicTacToeBoard tb;
	tb.placePiece(2,0);
	tb.placePiece(1,0);
	tb.placePiece(1,1);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkNoWinnerBottomLeftDiagonalSecondTwoPieces){
	TicTacToeBoard tb;
	tb.placePiece(0,2);
	tb.placePiece(1,0);
	tb.placePiece(1,1);
	ASSERT_TRUE(tb.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, checkWinnerHorizontalTop){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(1,2);
	tb.placePiece(0,1);
	tb.placePiece(1,0);
	tb.placePiece(0,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkWinnerHorizontalMiddle){
	TicTacToeBoard tb;
	tb.placePiece(1,0);
	tb.placePiece(0,2);
	tb.placePiece(1,1);
	tb.placePiece(0,0);
	tb.placePiece(1,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkWinnerHorizontalBottom){
	TicTacToeBoard tb;
	tb.placePiece(2,0);
	tb.placePiece(1,2);
	tb.placePiece(2,1);
	tb.placePiece(1,0);
	tb.placePiece(2,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkWinnerVerticalLeft){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(0,2);
	tb.placePiece(1,0);
	tb.placePiece(1,2);
	tb.placePiece(2,0);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkWinnerVerticalMiddle){
	TicTacToeBoard tb;
	tb.placePiece(0,1);
	tb.placePiece(0,2);
	tb.placePiece(1,1);
	tb.placePiece(1,2);
	tb.placePiece(2,1);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkWinnerVerticalRight){
	TicTacToeBoard tb;
	tb.placePiece(0,2);
	tb.placePiece(1,1);
	tb.placePiece(1,2);
	tb.placePiece(1,0);
	tb.placePiece(2,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkWinnerDiagonalTopLeft){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(0,2);
	tb.placePiece(1,1);
	tb.placePiece(1,2);
	tb.placePiece(2,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkWinnerDiagonalBottomLeft){
	TicTacToeBoard tb;
	tb.placePiece(2,0);
	tb.placePiece(0,1);
	tb.placePiece(1,1);
	tb.placePiece(1,2);
	tb.placePiece(0,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkFullBoard){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(0,1);
	tb.placePiece(0,2);
	tb.placePiece(1,1);
	tb.placePiece(1,0);
	tb.placePiece(2,0);
	tb.placePiece(2,1);
	tb.placePiece(2,2);
	tb.placePiece(1,2);
	ASSERT_TRUE(tb.getWinner() == Blank);
}

TEST(TicTacToeBoardTest, checkNoFullBoard){
	TicTacToeBoard tb;
	ASSERT_FALSE(tb.getWinner() == Blank);
}
