#include <iostream>
#include "Player.h"
#include "Game.h"

//#include "board.h"
int main(int argc, char *argv[])
{


    Player *player1= new Player();
    Board pc(player1->getPlayerSymbol(), player1->getPlayer2Symbol());
    Game game(player1,pc);
    game.startGame();

    return 0;
}
