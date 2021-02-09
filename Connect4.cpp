
#include "Connect4.h"
#include "limits.h"

#include <iostream> 
#include <string>

using namespace std;

void Connect4::initGame(){
    cout << "WELCOME TO: CONNECT 4" << endl;
    cout << "Would you like to customize your games pieces? y/n:";
    char answer;
    cin >> answer;
    cout << endl;
    if (answer == 'y' or answer == 'Y') {
        chooseGamePiece();
    } else {
        cout << "Going with the default pieces X and O." << endl;
        play1.setPiece("X");
        play2.setPiece("O");    
    }
    
    cout << "CHOOSE A MODE (by entering the corresponding number):" << endl;
    cout << "1. One round       " << "2. Best of Three       " << "3. Best of Five       " << "4. ENDLESS MODE" << endl;
    while (!chooseMode()) {
        chooseMode();        
    }
    
}

void Connect4::chooseGamePiece(){
    
    cout << "Enter a one character-long piece for Player 1:";
    string player_piece;
    cin >> player_piece;
    
    while(!play1.setPiece(player_piece)){
        cout << "Too long! Piece must only be one letter. Try again and enter a new piece: ";
        cin >> player_piece;
    }
    
    cout << "Enter a one character-long piece for Player 2:";
    cin >> player_piece;
    
    while(!play2.setPiece(player_piece) or player_piece == play1.getPiece()){
        if (!play2.setPiece(player_piece)){
            cout << "Too long! Piece must only be one letter. Try again and enter a new piece: ";    
        }
        
        if (player_piece == play1.getPiece()){
            cout << "This is the same piece as player 1's! enter a new piece that's different: ";    
        }
        
        cin >> player_piece;
    }   
    
}


int Connect4::playGame() {
    initGame();
    
    while (rounds != 0){
        playRound();
        cout << "Player 1 score: " << play1.getScore() << "     ";
        cout << "Player 2 score: " << play2.getScore() << "     " << endl;
        rounds--;
        resetRound();
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

void Connect4::playRound(){
    int colNum = 0;
    won = false;
    play1.setTurn();
    Gameboard.printBoard();

    while (!won){
        if (play1.getTurn()){
            cout << "PLAYER 1 (" << play1.getPiece() << "'s): It is your turn." << endl;
            currPlayer = &play1;
        } else {
            cout << "PLAYER 2 (" << play2.getPiece() << "'s): It is your turn." << endl;
            currPlayer = &play2;
        }

        cout << "Enter the column number to place your piece: ";
        cin >> colNum;
        cout << endl;
        
        valid = Gameboard.updateBoard(colNum - 1, currPlayer->getPiece(), &won);

        while (!cin or !valid){
            cout << endl << "Invalid Move. Please re-enter a column number (1-7) and try again: " ;
            cin.clear();
            cin.ignore();
            cin >> colNum;
            valid = Gameboard.updateBoard(colNum - 1, currPlayer->getPiece(), &won);
        }

        Gameboard.printBoard();
        if (won){
            if (currPlayer->getPiece() == "X"){
                cout << "PLAYER 1 WINS THIS ROUND" << endl;
            } else {
                cout << "PLAYER 2 WINS THIS ROUND" << endl;
            }
            currPlayer->setScore();
            
            return;
        } else if (Gameboard.getFull()) {
            cout << "IT'S A TIE" << endl;
            return;
        }
        switchPlayers();
    }
}

void Connect4::switchPlayers(){
    play1.setTurn();
    play2.setTurn();
}

/*
Choose between one game, best of three, best of five, and endless mode
Prompts the user for a number 1-4, each corresponding to one of the modes
*/
bool Connect4::chooseMode(){
    int mode;
    cin >> mode;
    cout << endl;
    if (!cin) {
        cout << "Please enter a number!: ";
        cin.clear();
        cin.ignore();
        return false;
    }
    
    if (mode == 1){
        rounds = 1;
    } else if (mode == 2){
        rounds = 3;
    } else if (mode == 3){
        rounds = 5;
    } else if (mode == 4){
        rounds = -1;
    } else {
        cout << "Invalid Choice: Please enter a number 1-4:";
    }
    
    return true;
}

/*
Sets both player's turn to false
Clears the board of pieces
reanitializes won bool to false
*/
void Connect4::resetRound(){
    if (play1.getTurn()){   play1.setTurn();    }
    if (play2.getTurn()){   play2.setTurn();    }

    Gameboard.clearBoard();
    won = false;
    valid = false;


}


