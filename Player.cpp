#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

/*
Initializes the player members to 0
*/
Player::Player(){
    turn = false;
    score = 0;
}

/*
When customizing the board piece, check that
it has a length of 1
*/
bool Player::setPiece(string wanted_piece) {
    bool equal_one;
    equal_one = (wanted_piece.length() == 1) ? true : false;
    
    if (equal_one){
        piece = wanted_piece;
    }
    
    return equal_one;
};

/*
if true, is the player's turn
*/
bool Player::getTurn(){
    return turn;
}
        
/*
if turn is true, sets it to false and vice versa
*/
void Player::setTurn(){
    turn = !turn;
}

/*
for printing purposes; tracks how many games the player has won
at the end of each round
*/
int Player::getScore(){
    return score;
}

/*
increments score by one
*/
void Player::setScore(){
    score++;
}

/*
returns what the piece of the player is
*/
string Player::getPiece(){
    return piece;
}




