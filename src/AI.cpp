#include "../include/AI.hpp"

AI::AI(TicTacToe& g, char ai_symb, char p_symb, int diff) : game(g), ai_symb(ai_symb), p_symb(p_symb), difficulty(diff) {
}


int AI::pickMove() {
	int result;

	if ((result = searchWins(ai_symb)) > -1) {
		return result + 1;
	}

	if ((result = searchWins(p_symb)) > -1) {
		return result + 1;
	}

	if (difficulty > 1) {

		if ((result = searchForks(ai_symb)) > -1) {
			return result + 1;
		}
		if (difficulty > 2) {
			if ((result = blockFork()) > -1) {
				return result + 1;
			}
		}

		if ((result = searchForks(p_symb)) > -1) {
			return result + 1;
		}
	}
	if ((result = center()) > -1) {
		return result + 1;
	}

	if ((result = oppositeCorner()) > -1) {
		return result + 1;
	}

	if ((result = emptyCorner()) > -1) {
		return result + 1;
	}

	return emptySide() + 1;
}

char AI::getAISymb() {
	return ai_symb;
}


int AI::searchWins(char symb) {
	spots.clear();
	checkRows(symb);
	checkColumns(symb);
	checkDiagonals(symb);

	//If any number of spots are found, return the first one.
	if (spots.size() > 0) {
		return spots.at(0);
	}

	return -1;
}

int AI::searchForks(char symb) {
	for (int i = 0; i < 9; i++) {
		if (game.board[i] == ' ') {
			game.board[i] = symb; //Move on an empty spot.
			searchWins(symb);
			game.board[i] = ' '; //Remove it to not mess up the board.

			//If two or more wins are detected after moving at a certain
			//position then a fork has been found.
			if (spots.size() > 1) {
				return i;
			}
		}
	}
	return -1;
}


int AI::blockFork() {
	int numWins;
	int pos;
	for (int i = 0 ; i < 9; i++) {
		numWins = 0;
		pos = -1;
		if (game.board[i] == ' ') {
			game.board[i] = ai_symb; //Move.
			searchWins(ai_symb);
			numWins = spots.size();
			if (numWins > 0) { //If the move would cause a 2-in-a-row scenario
				pos = searchWins(ai_symb); 
				game.board[pos] = p_symb; //Block that move with player symbol.
				searchWins(p_symb);
				game.board[i] = ' ';
				game.board[pos] = ' ';

				//As long as the human player's block would not lead to a fork
				//the move is good.
				if (spots.size() < 2) {
					return i;
				}
			}
			game.board[i] = ' ';
 		}
	}
	return -1;
}

int AI::center() {
	if (game.board[4] == ' ') {
		return 4;
	}
	return -1;
}

int AI::oppositeCorner() {
	if (game.prevMove == 0 && game.board[8] == ' ') {
		return 8;
	}

	if (game.prevMove == 2 && game.board[6] == ' ') {
		return 6;
	}

	if (game.prevMove == 6 && game.board[2] == ' ') {
		return 2;
	}

	if (game.prevMove == 8 && game.board[0] == ' ') {
	 	return 0;
	}

	 return -1;
}


int AI::emptyCorner() {
	if (game.board[0] == ' ') {
		return 0;
	}

	if (game.board[2] == ' ') {
		return 2;
	}

	if (game.board[6] == ' ') {
		return 6;
	}

	if (game.board[8] == ' ') {
		return 8;
	}
	return -1;
}

int AI::emptySide() {
	if (game.board[1] == ' ') {
		return 1;
	}

	if (game.board[3] == ' ') {
		return 3;
	}

	if (game.board[5] == ' ') {
		return 5;
	}

	if (game.board[7] == ' ') {
		return 7;
	}
	return -1;
}

void AI::checkRows(char symb){
	int empty;
	int count;

	for (int i = 0; i < 7; i+=3) {
		count = 0;
		empty = -1;
		for (int j = i; j < i + 3; j++) {
			if (game.board[j] == ' ') {
				empty = j;
			}

			if (game.board[j] == symb) {
				count++;
			}
		}
		if (count == 2 && empty > -1) {
			spots.push_back(empty);
		}
	}
}


void AI::checkColumns(char symb){
	int count;
	int empty;
	for (int i = 0; i < 3; i++) {
		count = 0;
		empty = -1;
		for (int j = i; j < i + 7; j+=3) {
			if (game.board[j] == ' ') {
				empty = j;
			}
			if (game.board[j] == symb) {
				count++;
			}
		}
		if (count == 2 && empty > -1) {
			spots.push_back(empty);
		}
	}
}

void AI::checkDiagonals(char symb){
	int count = 0;
	int empty = -1;

	for (int i = 0; i < 9; i += 4) {
		if (game.board[i] == ' ') {
				empty = i;
			}
		if (game.board[i] == symb) {
			count++;
		}
	}

	if (count == 2 && empty > -1) {
		spots.push_back(empty);
	}

	count = 0;
	empty = -1;
	for (int i = 2; i < 7; i += 2) {
		if (game.board[i] == ' ') {
				empty = i;
			}
		if (game.board[i] == symb) {
			count++;
		}
	}
	if (count == 2 && empty > -1) {
		spots.push_back(empty);
	}
}
