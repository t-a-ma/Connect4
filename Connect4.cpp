
#include "Connect4.h"

#include <iostream>  //in out put 
#include <string>

using namespace std; //don't wanna use std:: for everything

/*
constructor 
*/


int Connect4::playGame() {
    gameboard testGameBoard;
    testGameBoard.printBoard();
    int colNum = 0;

    player = true;
    
    while (!won){
        if (player){
            cout << "PLAYER 1 (X's): It is your turn." << endl;
        } else {
            cout << "PLAYER 2 (O's): It is your turn" << endl;
        }

        cout << "Enter the column number to place your piece: ";
        cin >> colNum;
        cout << endl;
        valid = testGameBoard.updateBoard(colNum - 1, player, &won);
        
        //check if moe is valid 
        while (!valid){
            cout << "Invalid Move. Please re-enter a column number (1-7) and try again: ";
            cin >> colNum;
            cout << endl;
            valid = testGameBoard.updateBoard(colNum - 1, player, &won);
        }
        testGameBoard.printBoard();
        if (won){
            if (player){
                cout << "PLAYER 1 WINS";
            } else {
                cout << "PLAYER 2 WINS";
            }
        }

        player = !player;
    }
    return 0;
}

//int playGame(){
    /*
    then check if there's a four-in-a-row surrounding that piece
    if there is, return that whoever placed the last piece has one
    if not, then go on to the next player. Players can technically just be ... structs? bools at most
        bool player = true if player one; player = false if on player 2

    */


//}

