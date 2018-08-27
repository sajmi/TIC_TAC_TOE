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
    /** this function return player name
     * @brief getPlayerName
     * @return
     */
    string getPlayerName();
    /**this function set player symbol
     * @brief setPlayerSymbol
     * @param value
     */
    void setPlayerSymbol(char value);
    /** return player symbol from private class
     * @brief getPlayer2Symbol
     * @return
     */
    char getPlayer2Symbol();
    /** return player pointer from private class
     * @brief getPlayer2
     * @return
     */
    Player * getPlayer2();
    /** set game mode
     * @brief setGameMode
     * @param mode
     */
    void setGameMode(int mode);
    /** return game mode
     * @brief getGameMode
     * @return
     */
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
