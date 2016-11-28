#include "../include/tictactoe.hpp"

TicTacToe::TicTacToe(char p1, char p2, bool first) : player1(p1), player2(p2), turn(0) {
    
    if (first) {
        currentPlayer = p1;
    } else {
        currentPlayer = p2;
    }

    //Empty array.
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }

}

GameResult TicTacToe::move(int move) {
    if (!valid(move)) {
        return INVALID;
    }

    board[move - 1] = currentPlayer; 
    turn++;

    GameResult r =  result();


    if (r == CONTINUE) {
        //Switch
        if (currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
    }

    prevMove = move - 1;
    return r;
}

bool TicTacToe::valid(int move) {
    if (move < 1 || move > 9 || board[move - 1] != ' ') {
        return false;
    }
    return true;
}


GameResult TicTacToe::result() {
    //Check who would wins if there is a winner.
    GameResult win;
    if (currentPlayer == player1) {
        win = P1_WIN;
    } else {
        win = P2_WIN;
    }

    //0 1 2
    //3 4 5
    //6 7 8
    //Checks for victory.
    if ((board[0] == currentPlayer && board[1] == currentPlayer 
        && board[2] == currentPlayer)
        || (board[3] == currentPlayer && board[4] == currentPlayer 
        && board[5] == currentPlayer)
        || (board[6] == currentPlayer && board[7] == currentPlayer 
        && board[8] == currentPlayer)
        || (board[0] == currentPlayer && board[3] == currentPlayer 
        && board[6] == currentPlayer)
        || (board[1] == currentPlayer && board[4] == currentPlayer 
        && board[7] == currentPlayer)
        || (board[2] == currentPlayer && board[5] == currentPlayer 
        && board[8] == currentPlayer)
        || (board[0] == currentPlayer && board[4] == currentPlayer 
        && board[8] == currentPlayer)
        || (board[2] == currentPlayer && board[4] == currentPlayer 
        && board[6] == currentPlayer)) {
            
        return win;
    }   
    
    //If it's the 9th turn with no victor then we have a draw.
    if (turn == 9) {
        return DRAW;
    }

    //If no one won and there is no draw then continue the game.
    return CONTINUE;
}

void TicTacToe::printBoard() {

    std::cout << "     " << board[0] << "\t|   " << board[1] << "\t|  " << board[2] << "\t\t\t" 
        << "     " << 1 << "\t|   " << 2 << "\t|  " << 3 << std::endl; 
    std::cout << "   ------------------" << "\t\t\t" << "   ------------------" << std::endl;

    std::cout << "     " << board[3] << "\t|   " << board[4] << "\t|  " << board[5] << "\t\t\t"
        << "     " << 4 << "\t|   " << 5 << "\t|  " << 6 << std::endl; 
    std::cout << "   ------------------" << "\t\t\t" << "   ------------------" << std::endl;

    std::cout << "     " << board[6] << "\t|   " << board[7] << "\t|  " << board[8] << "\t\t\t"
        << "     " << 7 << "\t|   " << 8 << "\t|  " << 9 << std::endl; 
} 

char TicTacToe::getPlayer() {
    return currentPlayer;
}
