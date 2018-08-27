#include <iostream>
#include "Player.h"
#include "Game.h"


int main(int argc, char *argv[])
{

    while(true){

        Player *player1= new Player();
        Board pc(player1->getPlayerSymbol(), player1->getPlayer2Symbol());
        Game game(player1,pc);
        game.startGame();
        player1->setGameMode(2);
        free(player1);//=NULL;

        cout<<"Run again y/n ? ";
        string gameEnd="";
        cin>>gameEnd;

        if(gameEnd=="n"|| gameEnd=="N")
            break;




    }


    return 0;
}
