#include "Player.h"
#include <iostream>
#include <string>
int Player::gmMode =2;
char Player::SYMBOL='\0';
using namespace std;
class  Player::PlayerPrivate
{
public:

    Player *player;
};

Player::Player(){
    if(gmMode==2){
        int mode;
        cout << "Game mode:\n\t0 ----> Human vs Human\n\t1 ----> Human vs Computer\n" ;
        cin >> mode;
        setGameMode(mode);
        setPlayerAttributes(1);
        mPlayer= new PlayerPrivate();
        mPlayer->player= new Player(mode);
        setPlayer2(mode,SYMBOL);
    }

}

Player::Player(int mode){

}
void Player::setPlayer2(int mode,char sym){

    if(mode==0){
        mPlayer->player->setPlayerAttributes(2);
    }else if(mode==1){
        char symb=sym=='X'?'O':'X';
        mPlayer->player->setPlayerSymbol(symb);
        mPlayer->player->playerName="COMPUTER";
    }
}
Player::~Player(){
    if(player2!=NULL)
        delete player2;
}

void Player::setPlayerAttributes(int playerNumber) {

    cout << "Player " << playerNumber << ", what is your name? ";
    cin >> playerName;
    this->cleanStream();
    cout << "Player " << playerNumber << ", what symbol do you wish to place on the PlayField? ";
    cin >> this->playerSymbol;
    SYMBOL=playerSymbol;
    cleanStream();
}

void Player::setGameMode(int mode){
    Player::gmMode = mode;
}

void Player::setPlayerName(string value)
{
    playerName = value;
}

void Player::setPlayerSymbol(char value)
{
    playerSymbol = value;
}
char Player::getPlayerSymbol() {
    return this->playerSymbol;
}

string Player::getPlayerName() {
    return this->playerName;
}
char Player::player2Symbol(){
    return mPlayer->player->getPlayerSymbol();
}
Player* Player::getPlayer2(){
    return mPlayer->player;
}

int Player::getGmMode()
{
    return gmMode;
}
void Player::cleanStream() {
    while (getchar() != '\n');
}

