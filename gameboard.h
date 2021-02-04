
#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_


#include <iostream>
#include <string>

/*
Gameboard 
overview: Contains the 6x7 board where pieces are placed
all funtions that interact with and depend on the board
i.e. placing a piece, check for a win

members:

methods
*/

class gameboard {    
    public:
        gameboard();
        void printBoard();
        void initBoard();
        bool updateBoard(int col, std::string piece, bool *won);
        void clearBoard();
        ~gameboard();
        bool getFull();

    private:
        int TABLE_COLS;
        int TABLE_ROWS;
        bool isFull;
        
        std::string **board;
        int *colCounter;

        //for checking 4-in-a-row 
        struct cornerBound{
            int row;
            int col;
        };

        
        bool checkWin(int row, int col);
        bool checkRow(int row, int col);
        bool checkCol(int row, int col);
        bool checkDiagonal(int row, int col);
        bool checkRightDiagonal(int row, int col);
        bool checkLeftDiagonal(int row, int col);
        bool checkIfFull();

        
        //debugging functions
        

};

#endif