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
	ASSERT_TRUE(tb.getPiece(0,1) == Blank);
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

TEST(TicTacToeBoardTest, checkTurnsAreToggling){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_FALSE(tb.placePiece(0,1) == X);
}

TEST(TicTacToeBoardTest, checkGetPieceOutOfBounds){
	TicTacToeBoard tb;
	ASSERT_TRUE(tb.getPiece(10,0) == Invalid);
}

TEST(TicTacToeBoardTest, checkGetPieceValidSpot){

	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.getPiece(0,0) == X);
}

TEST(TicTacToeBoardTest, checkNoWinner){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	ASSERT_TRUE(tb.getWinner() == Blank);
}

TEST(TicTacToeBoardTest, checkWinner){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(1,2);
	tb.placePiece(0,1);
	tb.placePiece(1,0);
	tb.placePiece(0,2);
	ASSERT_TRUE(tb.getWinner() == X);
}

TEST(TicTacToeBoardTest, checkFullBoard){
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(0,1);
	tb.placePiece(0,2);
	tb.placePiece(1,0);
	tb.placePiece(1,1);
	tb.placePiece(1,2);
	tb.placePiece(2,0);
	tb.placePiece(2,1);
	tb.placePiece(2,2);
	ASSERT_TRUE(tb.getWinner() == Blank);
}
