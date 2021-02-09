#include "gameboard.h"

#include <string>
#include <iostream>

using namespace std;

/*
Purpose: Initializes an empty 6x7 board with vectors and ASCII related art
Parameters: None
Return: None
*/
gameboard::gameboard(){
    TABLE_COLS = 7;
    TABLE_ROWS = 6;
    board = new string *[TABLE_ROWS];
    colCounter = new int [TABLE_COLS];

    for (int i = 0; i < TABLE_ROWS; i++){
        board[i] = new string[7];
    }
    initBoard();

};

/*
initializes the board; adds the empty space 
*/
void gameboard::initBoard(){
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            board[i][j] = "|   |";
        } 
    }
    for (int i = 0; i < TABLE_COLS; i++){
        colCounter[i] = TABLE_ROWS;
    }
    isFull = false;
}


/*
What: Prints out the gameboard and current state of game to terminal
*/
void gameboard::printBoard() {
    cout << endl;
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            cout << board[i][j];
        } 
        cout << endl;
    }
    for (int j = 0; j < TABLE_COLS; j++) {
            cout << "  " << j + 1 << "  ";
    } 
    
    cout << endl;
}

bool gameboard::updateBoard(int col, string piece, bool *won){
    if ((col < 0) or (col > 6)) {
         return false;
    }
    
    if (colCounter[col] != 0) {
        board[colCounter[col] - 1][col] = "| " + piece + " |";
        *won = checkWin(colCounter[col] - 1, col);     
        colCounter[col]--;
        isFull = checkIfFull();
        return true;
    } 

    return false;
}

/*

*/
bool gameboard::checkIfFull(){
    for (int i = 0; i < TABLE_COLS; i++) {
        if (colCounter[i] != 0){
            return false;
        }
    }
    return true;
}

/*
What: Returns true if the entire board is full 
*/
bool gameboard::getFull(){
    return isFull;
}

/*
What: after a piece is placed on the board, check if that
creates a connect4 (4 in a row, column, or diagonally)
*/
bool gameboard::checkWin(int row, int col) {
    if (checkRow(row, col) or checkCol(row, col) or checkDiagonal(row, col)){
        return true;
    } else {
        return false;
    }
}

/*
What: Checks if there are four of the same pieces in a row
*/
bool gameboard::checkRow(int row, int col){
    int leftBound;
    leftBound =  ((col - 3) >= 0) ? col - 3 : 0;
    int rightBound;
    rightBound = ((col + 3) <= TABLE_COLS) ? (col + 3) : 6;
    int right = leftBound + 3;
    //check sliding windows of four around int col 
    while (right <= rightBound){
        if ((board[row][leftBound] == board[row][leftBound + 1]) 
        and (board[row][leftBound + 2] == board[row][leftBound]) 
        and (board[row][leftBound] == board[row][right])) {
            return true;
        } else {
            leftBound++;
            right++;
        }
    }
    return false;
}

/*
What: Checks for connect 4 in a column
*/
bool gameboard::checkCol(int row, int col){
    int topBound, bottomBound; //top meaning 0 row 
    topBound = ((row - 3) >= 0) ? row - 3 : 0;
    bottomBound = ((row + 3) <= TABLE_ROWS)? row + 3: 5;
    int top = bottomBound - 3;

    while (top >= topBound){    
        if (board[bottomBound][col] == board[bottomBound - 1][col] 
        and board[bottomBound][col] == board[bottomBound - 2][col] 
        and board[top][col] == board[bottomBound][col]) {
            return true;
        } else {
            bottomBound--;
            top--;
        }
    }
    return false;
}


bool gameboard::checkDiagonal(int row, int col){
    if (checkRightDiagonal(row, col) or checkLeftDiagonal(row, col)){
        return true;
    }
    return false;
}

bool gameboard::checkRightDiagonal(int row, int col) {
    cornerBound topRH, botLH, tRHBound;
    
    /*checks how many cols right we need to check (i.e)
    if piece is placed in col 5, only need to check one col over (col 6)
    and one row up
    */
    int tri_incr = 3;
    if (row - 3 < 0){
        tri_incr = row;
    } 
    
    if (col + 3 >= TABLE_COLS) {
        if (TABLE_COLS - 1 - col < tri_incr) {
            tri_incr = TABLE_COLS - 1 - col;
        }
    } 
        
    topRH.col = col + tri_incr;
    topRH.row = row - tri_incr;
    
    tri_incr = 3;

    if (row + 3 >= TABLE_ROWS){
        tri_incr = TABLE_ROWS - 1 - row;
    } 
    
    if (col - 3 < 0) {
        if (col < tri_incr){
            tri_incr = col;
        }
    } 

    botLH.col = col - tri_incr;
    botLH.row = row + tri_incr;

    tRHBound.col = botLH.col + 3;
    tRHBound.row = botLH.row - 3;
    
    while (tRHBound.col <= topRH.col and tRHBound.row >= topRH.row ){
        if (board[botLH.row][botLH.col] == board[botLH.row - 1][botLH.col + 1]
            and board[botLH.row][botLH.col] == board[botLH.row - 2][botLH.col + 2]
            and board[botLH.row][botLH.col] == board[tRHBound.row][tRHBound.col]){
                return true; 
        } else {
            tRHBound.row--;
            tRHBound.col++;
            botLH.row--;
            botLH.col++;
        }
    }
    return false;
}

bool gameboard::checkLeftDiagonal(int row, int col){
    cornerBound botRH, topLH, tLHBound;
    int tri_incr = 3;
    if (row - 3 < 0){
        tri_incr = row;
    } 
    
    if (col - 3 < 0) {
        if (col < tri_incr) {
            tri_incr = col;
        }
    } 
    topLH.col = col - tri_incr;
    topLH.row = row - tri_incr;
    tri_incr = 3;
    if (row + 3 >= TABLE_ROWS){
        tri_incr = TABLE_ROWS - 1 - row;
    } 
    
    if (col + 3 >= TABLE_COLS) {
        if (TABLE_COLS - 1 < tri_incr){
            tri_incr = TABLE_COLS - 1 - col;
        }
    } 

    botRH.col = col + tri_incr;
    botRH.row = row + tri_incr;
    
    tLHBound.row = botRH.row - 3;
    tLHBound.col = botRH.col - 3;

    while (tLHBound.col >= topLH.col and tLHBound.row >= topLH.row ){
        if (board[botRH.row][botRH.col] == board[botRH.row - 1][botRH.col - 1]
            and board[botRH.row][botRH.col] == board[botRH.row - 2][botRH.col - 2]
            and board[botRH.row][botRH.col] == board[tLHBound.row][tLHBound.col]){
                return true; 
        } else {
            tLHBound.row--;
            tLHBound.col--;
            botRH.row--;
            botRH.col--;
        }
    }
    return false;
  
}

/*
What: Clears gameboard to be empty
*/
void gameboard::clearBoard(){
    initBoard();
}


/*
Destructor: Frees the memory used by the gameboard 
*/
gameboard::~gameboard(){ 
    delete colCounter;
    for (int i = 0; i < TABLE_ROWS; i++) {
        delete board[i];
    }
    delete board;
}
