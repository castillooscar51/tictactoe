#ifndef AI_H
#define AI_H

#include "tictactoe.hpp"
#include <vector>

class AI {

	private:
		TicTacToe& game;

		//Holds the empty spots of 2-in-a-row occurrences
		std::vector<int> spots;

		char ai_symb;
		char p_symb;

		//Normal(1), Hard(2), Impossible(3).
		int difficulty;

		//Strategies

		//Counts the number of 2-in-a-row occurences of the given symbol.
		int searchWins(char symb);

		//Searches for a spot where a fork can be created with the given symbol.
		int searchForks(char symb);

		//Blocks fork by forcing 2-in-a-row.
		int blockFork();

		//Moves onto center if available.
		int center();

		//Moves onto corner opposite the user's last move if available.
		int oppositeCorner();

		//Moves onto an empty corner if available.
		int emptyCorner();

		//moves onto an empty side if available.
		int emptySide();

		//Helpers
		void checkRows(char symb);
		void checkColumns(char symb);
		void checkDiagonals(char symb);

	public:

		//Constructor.
		AI(TicTacToe& g, char ai_symb, char p_symb, int diff);

		//Destructor.
		~AI(){}

		//Returns the AI's symbol (X or O).
		char getAISymb();

		//Picks the move that should be made.
		int pickMove();
};
#endif
