#ifndef _CONNECT4_H_
#define _CONNECT4_H_

#include "gameboard.h"
#include <iostream>
#include <string>

class Connect4 {
    public:
        int playGame();
        
    private:
        bool player;
        bool valid;
        bool won;


};


#endif