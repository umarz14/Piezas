/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, constructor)
{
	Piezas board;
	ASSERT_TRUE(true);
}

// Place piece OFB
TEST(PiezasTest, outOfBounds){
	Piezas board;
	Piece cur1 = board.dropPiece(4);
	ASSERT_EQ(cur1, Invalid);
}

TEST(PiezasTest, empty){
	Piezas board;
	Piece cur1 = board.pieceAt(0,0);
	ASSERT_EQ(cur1, Blank);
}

// Place X piece
TEST(PiezasTest, xPiece){
	Piezas board;
	Piece cur2 = board.dropPiece(0);
	ASSERT_EQ(cur2, X);
}

// check they are place right
TEST(PiezasTest, placement){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(1,0), O);
}

// check they are place right
TEST(PiezasTest, placement1){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(2,0), X);
}

TEST(PiezasTest, placement2){
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	ASSERT_EQ(board.pieceAt(2,1), X);
}

TEST(PiezasTest, placement3){
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	ASSERT_EQ(board.pieceAt(2,2), X);
}

TEST(PiezasTest, placement4){
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	ASSERT_EQ(board.pieceAt(2,3), X);
}

TEST(PiezasTest, placement5){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	ASSERT_EQ(board.pieceAt(1,1), X);
}

// reset
TEST(PiezasTest, reset){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.reset();
	ASSERT_EQ(board.pieceAt(0,2), Blank);	
}
//Out of Bounds
TEST(PiezasTest, InvPos){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(1);
	ASSERT_EQ(board.dropPiece(0), Blank);	
}

// Game not done
TEST(PiezasTest, notDone){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(2);
	ASSERT_EQ(board.gameState(), Invalid);
}



// X X X O 
// O X O O
// X O X O
//X wins here

TEST(PiezasTest, xRowWin){
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	ASSERT_EQ(board.gameState(), X);
}

