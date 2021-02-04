#include "Player.h"

#include <iostream>
#include <string>

using namespace std;


Player::Player(){
    turn = false;
    score = 0;
}

bool Player::setPiece(string wanted_piece) {
    bool equal_one;
    equal_one = (wanted_piece.length() == 1) ? true : false;
    
    if (equal_one){
        piece = wanted_piece;
    }
    
    return equal_one;
};

bool Player::getTurn(){
    return turn;
}
        
        
void Player::setTurn(){
    if (turn){
        turn = false;
    } else {
        turn = true;
    }
}


int Player::getScore(){
    return score;
}

/*

*/
void Player::setScore(){
    score++;
}

string Player::getPiece(){
    return piece;
}




