#include <iostream>
#include <cctype>
#include "../include/display.hpp"

void isAIGame(bool& aiGame) {
	int choice;
	bool valid = false;

	while (!valid) {
		valid = true;
		std::cout << "Will you be playing against a Human(1) or AI(2)?\n";
		std::cin >> choice;
		std::cout << "\n\n";

		if (std::cin.fail() || choice > 2 || choice < 1) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "That was an invalid input.\n\n";
			valid = false;
		}
	}

	if (choice == 1) {
		aiGame = false;
	} else {
		aiGame = true;
	}
}

void setPlayerSymbols(char& p1, char& p2) {
	char choice;
	bool valid = false;

	while (!valid) {
		valid = true;
		std::cout << "Would Player 1 like to be X or O?\n";
		std::cin >> choice;
		std::cout << "\n\n";

		if (std::cin.fail() || (choice != 'X' && choice != 'x' && choice != 'O' && choice != 'o')) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "That was an invalid input.\n\n";
			valid = false;
		}
	}
	p1 = toupper(choice);
	if (toupper(choice) == 'X') {
		p2 = 'O';
	} else {
		p2 = 'X';
	}
}

void setOrder(bool& first) {
	char choice;
	bool valid = false;

	while (!valid) {
		valid = true;
		std::cout << "Would Player 1 like to go first? (y/n)\n";
		std::cin >> choice;
		std::cout << "\n\n";

		if (std::cin.fail() || (choice != 'Y' && choice != 'y' && choice != 'n' && choice != 'N')) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "That was an invalid input.\n\n";
			valid = false;
		}
	}

	if (toupper(choice) == 'Y') {
		first = true;
	} else {
		first = false;
	}
}

void setDifficulty(int& diff) {
	bool valid = false;

	while (!valid) {
		valid = true;
		std::cout << "Should AI difficulty be normal(1), hard(2), or impossible(3)?\n";
		std::cin >> diff;
		std::cout << "\n\n";

		if (std::cin.fail() || (diff != 1 && diff != 2 && diff != 3 )) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "That was an invalid input.\n\n";
			valid = false;
		}
	}

}
