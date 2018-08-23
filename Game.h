#ifndef	GAME_H
#define GAME_H
#include <string>
//#include "PlayField.h"
#include "Board.h"
#include "Player.h"
//using namespace std;
#include <vector>
class Game {
    struct Position{
        int x;
        int y;
    };


public:
    //    Game(Player *player1, Player *player2, Board playingBoard);
    Game(Player *player1, Board playingBoard);
    void startGame();
    bool isGameOver();

    Position getMoveFromPlayer(Player *player);
    void cleanStream();
    void setStartPlayer();

private:

    Player *player1;
    Player *player2;
    Board playingPlayField;
    int turn;



};
#endif
