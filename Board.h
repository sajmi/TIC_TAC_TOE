#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define Blank ' '


class Board
{

public:
    struct Position{
        int x;
        int y;
    };
    Board();
    Board(char symbolPlayer1,char symbolPlayer2);

    /** this function insert into playing field one character
     * @brief placeMoveOnPlayField
     * @param playerSymbol
     * @param x row in field
     * @param y column in field
     */
    void placeMoveOnPlayField(char playerSymbol, int x, int y);
    /** clear all characters from console
     * @brief cleanStream
     */
    void cleanStream();
    /** This function check if winner is in columns
     * @brief isWinnerByColumns
     * @return
     */
    bool isWinnerByColumns();
    /**This function check if winner is in row
     * @brief isWinnerByRows
     * @return true if is winner else false
     */
    bool isWinnerByRows();
    /** this function check if winner is in diagonal from top left to bottom right
     * @brief isWinnerByTopRigthToBottomLeftDiagonal
     * @return true if is winner else false
     */
    bool isWinnerByTopRigthToBottomLeftDiagonal();
    /**
     * @brief isWinnerByBottemLeftToTopRightDiagonal
     * @return   true if is winner else false
     */
    bool isWinnerByBottemLeftToTopRightDiagonal();
    /** This function print actual playing field to console
     * @brief printCurrentField
     */
    void printCurrentField();
    /** this function check if winner is in actual playing field
     * @brief isWinner
     * @return true if is else false
     */
    bool isWinner();

    /** check if actual position in playing field is reserved
     * @brief isSpaceAlreadyPlayed
     * @param x
     * @param y
     * @return true if is reserved else false
     */
    bool isSpaceAlreadyPlayed(int x,int y);
    /** set number of character to winnig game
     * @brief setCountWinCharacters
     */
    void setCountWinCharacters();
    /** This function return size of playing field (NxN)
     * @brief getFieldSize
     * @return
     */
    int getFieldSize() ;
    /** clear all position in playing field
     * @brief clearField
     */
    void clearField();


//    vec_tup getAllAvailablePosition();

    void copyBoardToTmpBoard();
    void deleteCopyBoard();
    Position minimax();

private:

    void createFieldForGame();
    char **board;
    char playerSymbol1, playerSymbol2;
    int countWinCharacters;
    int fieldSize;


};


#endif // BOARD_H
