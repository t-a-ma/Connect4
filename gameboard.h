
#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_


#include <iostream>
#include <string>

/*
Gameboard class: contains the 6x7 board 
    methods = anything that interacts with the board (insert piece)
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