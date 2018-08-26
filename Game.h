#ifndef	GAME_H
#define GAME_H
#include <string>
#include "Board.h"
#include "Player.h"

class Game {



public:

    /** Constructor for creating game with Player and Board
     * @brief Game
     * @param player1
     * @param playingBoard
     */

    Game(Player *player1, Board playingBoard);
    /**This function run game.
     * @brief startGame
     */
    void startGame();
    /** call function from object Board.
     * @brief isGameOver
     * @return true of false if game have a winner
     */
    bool isGameOver();
    /** this function insert one move from player into play field.
     * @brief getMoveFromPlayer
     * @param player
     * @return
     */
    Board::Position getMoveFromPlayer(Player *player);
    /** this function discards unwanted characters from stdin
     * @brief cleanStream
     */
    void cleanStream();
    /** This function set , which player start the game.
     * @brief setStartPlayer
     */
    void setStartPlayer();


private:

    Player *player1;
    Player *player2;
    Board playingPlayField;
    int turn;



};
#endif
