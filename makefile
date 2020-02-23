NAME = app

TARGET_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

HEADERS = $(wildcard include/*.h) $(wildcard include/*/*.h)
TARGET = $(TARGET_DIR)/$(NAME)

NECESSARY_DIRS = $(dir $(OBJ) $(TARGET)) 

CC = g++
CFLAGS = -c -g -Wall -Iinclude

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(sort $(NECESSARY_DIRS)):
	mkdir -p $@

.PHONY: compile run

clean:
	rm -rf bin
	rm -rf obj

compile: $(NECESSARY_DIRS) $(TARGET)

run: compile
	./$(TARGET)