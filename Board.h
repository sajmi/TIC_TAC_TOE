#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef vector<tuple<int,int>> vec_tup ;
enum Piece
{
    X = 'X',
    O = 'O',
    Invalid = '?',
    Blank = ' '
};

class Board
{

public:
    Board();
    Board(char symbolPlayer1,char symbolPlayer2);


    void placeMoveOnPlayField(char playerSymbol, int x, int y);
    void cleanStream();
    bool isWinnerByColumns();
    bool isWinnerByRows();
    bool isWinnerByTopRigthToBottomLeftDiagonal();
    bool isWinnerByBottemLeftToTopRightDiagonal();
    void printCurrentField();
    bool isWinner();


    bool isSpaceAlreadyPlayed(int x,int y);
    void setCountWinCharacters();
    int getFieldSize() ;


    vec_tup getAllAvailablePosition();


private:

    void createFieldForGame();
    char **board;
    //    Piece turn;
    char playerSymbol1, playerSymbol2;
    int countWinCharacters;
    int fieldSize;
    char **copyBoard;

};


#endif // BOARD_H
