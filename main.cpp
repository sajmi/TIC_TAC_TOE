#include <iostream>
#include "Player.h"
#include "Game.h"

//#include "board.h"
int main(int argc, char *argv[])
{


    //    int x[5][5] = {   1, 2, 3, 4, 5,
    //                      6, 7, 8, 9, 10,
    //                      11,12,13,14,15,
    //                      16,17,18,19,20,
    //                      21,22,23,24,25
    //                  };
    //    int n = 5;
    //    for (int slice = 0; slice < 2 * n - 1; ++slice) {
    //        printf("Slice %d: ", slice);
    //        int z = (slice < n) ? 0 : slice - n + 1;
    //        for (int j = z; j <= slice - z; ++j) {
    //            printf("%d ", x[j][4-slice+j]);
    //        }
    //        printf("\n");
    //    }


    Player *player1= new Player();
//    Player* player2= new Player();
//    player1->setPlayerAttributes(1);
//    player2->setPlayerAttributes(2);
    Board pc(player1->getPlayerSymbol(), player1->player2Symbol());

    Game game(player1/*, player1->getPlayer2(),*/, pc);
//        Game game(player1,  pc);
    game.startGame();

    return 0;
}
