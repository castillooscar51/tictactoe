INC_DIR = ../include

OBJ_DIR = ./obj

BIN_DIR = ../bin

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

$(BIN_DIR)/tictactoe: $(OBJ_DIR)/main.o $(OBJ_DIR)/tictactoe.o $(OBJ_DIR)/AI.o $(OBJ_DIR)/display.o
	g++ -g -O0 -lm $(OBJ_DIR)/main.o $(OBJ_DIR)/tictactoe.o $(OBJ_DIR)/AI.o $(OBJ_DIR)/display.o  -o $(BIN_DIR)/tictactoe

$(OBJ_DIR)/tictactoe.o: tictactoe.cpp $(INC_DIR)/tictactoe.hpp
	g++ -Wall -Wextra -pedantic -std=c++11 -g -O0 -c tictactoe.cpp -o $(OBJ_DIR)/tictactoe.o

$(OBJ_DIR)/main.o: main.cpp $(INC_DIR)/tictactoe.hpp
	g++ -Wall -Wextra -pedantic -std=c++11 -g -O0 main.cpp -c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/AI.o: AI.cpp $(INC_DIR)/AI.hpp
	g++ -Wall -Wextra -pedantic -std=c++11 -g -O0 AI.cpp -c -o $(OBJ_DIR)/AI.o

$(OBJ_DIR)/display.o: display.cpp $(INC_DIR)/display.hpp
	g++ -Wall -Wextra -pedantic -std=c++11 -g -O0 display.cpp -c -o $(OBJ_DIR)/display.o


tictactoe: $(BIN_DIR)/tictactoe
clean:
	@echo removing generated files...
	@rm -r $(OBJ_DIR)/*.o
       
