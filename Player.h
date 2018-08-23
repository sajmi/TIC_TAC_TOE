#ifndef PLAYER_H
#define	PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    Player();
    Player(int mode);
    ~Player();
    void setPlayerAttributes(int playerNumber);
    char getPlayerSymbol();
    string getPlayerName();
    void cleanStream();
    void setGameMode(int mode);
    void setPlayerName(string value);

    void setPlayerSymbol(char value);
    char player2Symbol();
    Player * getPlayer2();

    static int getGmMode();


private:
    class PlayerPrivate;
    PlayerPrivate *mPlayer;
    void setModeGame();
    string playerName;
    char playerSymbol;

    static int gmMode;
    static char SYMBOL;

    static Player* instancePlayer;
    Player* player2;
    void setPlayer2(int mode, char sym);

    /*AI TEST */



};
#endif
