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

TEST(TicTacToeBoardTest, checkInvalidPlacePiece){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(10,15) == Invalid);
}

TEST(TicTacToeBoardTest, checkValidPlacePiece){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.placePiece(0,2) == X);
}

TEST(TicTacToeBoardTest, checkPlaceNotEmpty){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.placePiece(0,0) == X);
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
	ASSERT_TRUE(tb.getPiece(-1, 2) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsColValueTooHigh){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(0,10) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBoundsColValueNegative){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(2, -1) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceValidSpot){

	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.getPiece(0,0) == X);
}

TEST(TicTacToeBoardTest, checkNoWinner){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
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
