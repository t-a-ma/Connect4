
#include "Connect4.h"

#include <iostream>  //in out put 
#include <string>

using namespace std; //don't wanna use std:: for everything

/*
constructor 
*/

int Connect4::playGame() {
    chooseMode();
    Player play1("X"); //can customize your piece! lol leave that for later
    Player play2("O");
 
    while (rounds > 0){
        playRound(play1, play2);
        cout << "Player 1 score: " << play1.getScore() << "     ";
        cout << "Player 2 score: " << play2.getScore() << "     " << endl;
        rounds--;
        resetRound(play1, play2); // wonder if I should make the players class members
    }
    
    if (play1.getScore() > play2.getScore()) {
        cout << "PLAYER 1 WINS" << endl;
    } else if (play1.getScore() < play2.getScore()) {
        cout << "PLAYER 2 WINS" << endl;
    } else {
        cout << "TIED" << endl;
    }

    return 0;
}

void Connect4::playRound(Player &play1, Player &play2){
    int colNum = 0;
    Player *currPlayer;
    play1.setTurn();
    Gameboard.printBoard();

    while (!won){
        if (play1.getTurn()){
            cout << "PLAYER 1 (X's): It is your turn." << endl;
            currPlayer = &play1;
        } else {
            cout << "PLAYER 2 (O's): It is your turn" << endl;
            currPlayer = &play2;
        }

        cout << "Enter the column number to place your piece: ";
        cin >> colNum;
        cout << endl;

        // so something is going wrong here? 
        valid = Gameboard.updateBoard(colNum - 1, currPlayer->getPiece(), &won);

        while (!valid){
            cout << "Invalid Move. Please re-enter a column number (1-7) and try again: ";
            cin >> colNum;
            cout << endl;
            valid = Gameboard.updateBoard(colNum - 1, currPlayer->getPiece(), &won);
            // forgot to add functionality about if entire board is filled and to call a draw when that happens
        }

        Gameboard.printBoard();
        if (won){
            if (currPlayer->getPiece() == "X"){
                cout << "PLAYER 1 WINS THIS ROUND" << endl;
            } else {
                cout << "PLAYER 2 WINS THIS ROUND" << endl;
            }
            currPlayer->setScore();
            //print current score is probably a good idea
            return;
        } else if (Gameboard.getFull()) {
            cout << "IT'S A TIE" << endl;
            return;
        }
        switchPlayers(play1, play2);
    }
}


void Connect4::switchPlayers(Player &play1, Player &play2){
    play1.setTurn();
    play2.setTurn();
}

void Connect4::chooseMode(){
    cout << "WELCOME TO: CONNECT 4" << endl;
    cout << "CHOOSE A MODE (by entering the corresponding number):" << endl;
    cout << "1. One round       " << "2. Best of Three       " << "3. Best of Five       " << "4. ENDLESS MODE" << endl;
    int mode;
    cin >> mode;
    if (mode == 1){
        rounds = 1;
    } else if (mode == 2){
        rounds = 3;
    }else if (mode == 3){
        rounds = 5;
    }else if (mode == 4){
        rounds = -1;
    }
}

/*

*/
void Connect4::resetRound(Player &play1, Player &play2){
    if (play1.getTurn()){   play1.setTurn();    }
    if (play2.getTurn()){   play2.setTurn();    }

    Gameboard.clearBoard();
    won = false;
    valid = false;


}


