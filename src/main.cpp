#include "../include/tictactoe.hpp"
#include "../include/AI.hpp"
#include "../include/display.hpp"

void getInput(int& move) {
    std::cin >> move;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        move = -1;
    }
}

int main() {

    //Set up the game.
    char p1, p2;
    bool first, aiGame;
    int diff = 1;
    isAIGame(aiGame);
    if (aiGame) {
        setDifficulty(diff);
    }
    setPlayerSymbols(p1, p2);
    setOrder(first);


    TicTacToe g(p1, p2, first);
    AI ai(g, p2, p1, diff);

    GameResult result = CONTINUE;
    int move = 0;

    //Game loop.
    while (result == CONTINUE || result == INVALID) {
        g.printBoard();
        if (result == INVALID) {
            std::cout << "Invalid Move!\n";
        }
        std::cout << "Current Player: " << g.getPlayer() << "\n\n";
        if (aiGame && (g.getPlayer() == ai.getAISymb())) {
            move = ai.pickMove();
            result = g.move(move);
        } else {
            getInput(move);
            result = g.move(move);
        }
    }

    g.printBoard();

    //Output result.
    switch(result) {
        case P1_WIN:
            std::cout << "Player 1 Wins!\n";
            break;

        case P2_WIN:
            if (aiGame) {
                std::cout << "AI Wins!\n";
            } else {
                std::cout << "Player 2 Wins!\n";
            }
            break;

        case DRAW:
            std::cout << "Draw!\n";
            break;

        default:break;
    }

    return 0;
}

