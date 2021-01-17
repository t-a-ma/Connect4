
#ifndef _PLAYER_H_
#define _PLAYER_H_


#include <iostream>
#include <string>

class Player {
    public:
        Player(std::string piece);
        bool getTurn();
        void setTurn();
        int getScore();
        void setScore();
        std::string getPiece();

    private:
        int score;
        bool turn;
        std::string piece;

};


#endif