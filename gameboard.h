
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
        bool updateBoard(int col, bool player, bool *won);
        ~gameboard();

    private:
        int TABLE_COLS;
        int TABLE_ROWS;
        //makes more sense for the player to be part of the connect 4 thing
        
        std::string **board;
        
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
        
        //debugging functions
        

};

#endif