#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

enum GameResult {
    P1_WIN,
    P2_WIN,
    DRAW,
    INVALID,
    CONTINUE
};

class TicTacToe {

    //To allow access to the board.
    friend class AI;

    private:
        
        //Board where the game is played.
        char board[9];

        char currentPlayer;

        //Player 1 Symbol.
        char player1;

        //Player 2 Symbol.
        char player2;

        //Turn number.
        int turn;

        //Last move made.
        int prevMove;

        bool valid(int);
        GameResult result();

    public:

        //Constructor.
        TicTacToe(char p1, char p2, bool first);

        //Destructor.
        ~TicTacToe(){}
        
        //Where moves onto the board are made.
        GameResult move(int);

        //Prints board along with a second board showing how to move.
        void printBoard();

        //Gets the current player.
        char getPlayer();
};

#endif