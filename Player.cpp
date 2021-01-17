#include "Player.h"

#include <iostream>
#include <string>

using namespace std;


Player::Player(string wantedPiece){
    turn = false;
    score = 0;
    piece = wantedPiece;
}

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




