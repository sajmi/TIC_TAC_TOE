#ifndef PLAYER_H
#define	PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    Player();
    ~Player();
    /** This function set atributes for player.
     * @brief setPlayerAttributes
     * @param playerNumber
     */
    void setPlayerAttributes(int playerNumber);
    /** this function return character for player
     * @brief getPlayerSymbol
     * @return
     */
    char getPlayerSymbol();
    string getPlayerName();

    void setPlayerSymbol(char value);
    char getPlayer2Symbol();
    Player * getPlayer2();

    void setGameMode(int mode);



    static int getGameMode();

    void cleanStream();


private:
    class PlayerPrivate;
    PlayerPrivate *mPlayer;

    string playerName;
    char playerSymbol;

    Player* player2;
    void setPlayer2(int mode, char sym);
    static int gameMode;
    static char SYMBOL;



};
#endif
