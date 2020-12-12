#include "Piezas.h"
#include <vector>

/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    board.resize(3, std::vector<Piece>(4));
    for(int i = 0; i < (int) board.size(); i++) 
    {
        for(int j = 0; j < (int) board[i].size(); j++)
        {
            board[i][j] = Blank;
        }
    }
    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    board.resize(3, std::vector<Piece>(4));
    for(int i = 0; i < (int) board.size(); i++) 
    {
        for(int j = 0; j < (int) board[i].size(); j++)
        {
            board[i][j] = Blank;
        }
    }
    turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if (column >= 4){
        turn = (turn == X) ? O : X;
        return Invalid;
    }
    
    else if (board[2][column] != Blank)
    {   
        turn = (turn == X) ? O : X;
        return Blank;
    }
    
    else
    {
        Piece rp = turn;
        for (int i = 0; i < BOARD_ROWS; i++)
        {
            if (board[i][column] == Blank)
            {
                board[i][column] = turn;
                turn = (turn == X) ? O : X;
                break;
            }
        }
    return rp ;
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if (row >= 3 || column >= 4 || row < 0 || column < 0)
    {
        return Invalid;
    }
    if(board[row][column] != Blank)
        return board[row][column];
    return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int xrow = 0; 
    int xcolum = 0;
    int orow = 0;
    int ocolum = 0;
    int xmax = 0;
    int omax = 0;
    
    for (int i = 0; i < BOARD_ROWS; i++){
        for (int j = 0; j < BOARD_COLS; j++){
            if(board[i][j] == Blank)
                return Invalid;
        }
    }
    
    //checks how many X in a row
    for(int t = 0; t < BOARD_ROWS-1; t++){
         if(xmax < xrow)
            xmax = xrow;
        for (int i = 0; i < BOARD_COLS; i++){
            if( (board[t][i] == X) && (board[t+1][i] == X))
            xrow += 1;
        }
    }
    
    //checks how many Y rows
    for(int t = 0; t < BOARD_ROWS-1; t++){
         if(omax < orow)
            omax = orow;
        for (int i = 0; i < BOARD_COLS; i++){
            if( (board[t][i] == O) && (board[t+1][i] == O))
            orow += 1;
        }
    }

    
    //checks how many x Colums
    for(int i=0; i<3; i++){
        if(xmax < xcolum)
            xmax = xcolum;
        xcolum = 0;
        for(int t=0; t<4; t++)
            if( board[i][t] == X)
                xcolum += 1; 
    }

    
    //check how many y Colums
    for(int i=0; i<3; i++){
        if(omax < ocolum)
            omax = ocolum;
        ocolum = 0;
        for(int t=0; t<4; t++)
            if( board[i][t] == O)
                ocolum += 1; 
    }
    
    if(xmax > omax)
        return X;
    else if(omax > xmax)
        return O;
    else
        return Blank;
}