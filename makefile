# Makefile for Tic-Tac-Toe Game

# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -pedantic

# Target Executable
TARGET = tictactoe

# Source Files
SRC = src/main.c

# Default Rule: Build the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean Rule: Remove the executable
clean:
	rm -f $(TARGET)

# Run Rule: Build and run the game
run: all
	./$(TARGET)
