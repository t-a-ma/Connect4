
#ifndef _PLAYER_H_
#define _PLAYER_H_


#include <iostream>
#include <string>

class Player {
    public:
        Player();
        bool getTurn();
        void setTurn();
        int getScore();
        void setScore();

    private:
        int score;
        bool turn;




}






#endif