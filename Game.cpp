#include "Game.h"
#include "Player.h"
#include <iostream>
#include <string>

#include <limits>

using namespace std;


Game::Game(Player *player1, Board playingBoard){
    this->player1 = player1;
    this->player2 = player1->getPlayer2();
    this->playingPlayField = playingBoard;
    this->turn = 0;
    setStartPlayer();
}

void Game::startGame() {

    while(!isGameOver()) {
        playingPlayField.printCurrentField();
        Board::Position playerMove;
        if (turn % 2 != 0) {
            playerMove = getMoveFromPlayer(player1);
            playingPlayField.placeMoveOnPlayField(player1->getPlayerSymbol(), playerMove.x,playerMove.y);
        }
        else {
            if(this->player1->getGameMode()==0){
                playerMove = getMoveFromPlayer(player2);

            }
            else{
                playerMove.x=rand()%playingPlayField.getFieldSize();
                playerMove.y=rand()%playingPlayField.getFieldSize();
            }

            playingPlayField.placeMoveOnPlayField(player2->getPlayerSymbol(), playerMove.x,playerMove.y);
        }
        turn++;
    }

    playingPlayField.printCurrentField();

    if (turn % 2 == 0 )
        cout << "Congrats, " << player1->getPlayerName() << "! You won this game." << endl;
    else
        cout << "Congrats, " << player2->getPlayerName() << "! You won this game." << endl;




}

bool Game::isGameOver() {
    return playingPlayField.isWinner() ;
}

Board::Position Game::getMoveFromPlayer(Player *player) {
    Board::Position playedSpacePosition;

    do {
        cout << player->getPlayerName() << ", what tile do you wish to play? ";
        cin >> playedSpacePosition.x >> playedSpacePosition.y;
        cleanStream();

    } while (0 <= playedSpacePosition.x && playedSpacePosition.x <= 9 && 0 <= playedSpacePosition.y  &&playedSpacePosition.y <= 9 &&
             playingPlayField.isSpaceAlreadyPlayed( playedSpacePosition.x, playedSpacePosition.y));
    return playedSpacePosition;
}
void Game::setStartPlayer(){



    bool  error = false;

    do
    {
        error=false;
        cout <<"Which player will start the game? ";
        cin >> turn;

        if (cin.fail()||turn>2 || turn<0)
        {
            cout << "Please enter a valid integer" << endl;
            error = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr <<  "Input was not an integer!Input muss be 1 or 2." << endl;

        }
    }while(error);

}
void Game::cleanStream() {
    while (getchar() != '\n');
}



