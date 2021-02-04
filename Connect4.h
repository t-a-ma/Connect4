#ifndef _CONNECT4_H_
#define _CONNECT4_H_

#include "gameboard.h"
#include "player.h"
#include <iostream>
#include <string>

/*

*/

class Connect4 {
    public:
        int playGame();
        
    private:
        gameboard Gameboard;
        bool valid;
        bool won;
        int rounds;
        Player play1;
        Player play2;
        Player *currPlayer;

        void initGame();
        void chooseGamePiece();
        void newGame();
        void chooseMode();
        void playRound();
        void switchPlayers();
        void resetRound();


};


#endif