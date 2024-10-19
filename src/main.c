#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Use for boolean values

// Constants
#define BOARD_SIZE 3
#define TOTAL_SLOTS 9

// Game variables
char player1[20]; // Player 1 name
char player2[20]; // Player 2 name
char gameBoard[BOARD_SIZE][BOARD_SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

// Function prototypes
void gameInit();
void drawGameBoard();
void playGame();
int playerTurn(int currentPlayer);
bool updateBoard(int choice, char symbol);
int checkWin();
bool checkDraw();

int main()
{
    gameInit();      // Initialize players and greet them
    drawGameBoard(); // Draw the initial game board
    playGame();      // Start the game
    printf("\nThanks for playing!\n");
    return 0;
}

// Initialize player names and greet them
void gameInit()
{
    printf("Tic-Tac-Toe\n");
    printf("============\n\n");
    printf("Enter player 1 name: ");
    scanf("%s", player1);
    printf("Enter player 2 name: ");
    scanf("%s", player2);
    printf("\n%s (X) vs %s (O), may the best player win!\n\n", player1, player2);
}

// Draw the game board
void drawGameBoard()
{
    printf("\nCurrent Game Board:\n\n");
    printf("<*******><*******><*******>\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf(" *   %c   *   %c   *   %c   *\n",
               gameBoard[i][0], gameBoard[i][1], gameBoard[i][2]);
        if (i < BOARD_SIZE - 1)
        {
            printf("<*******><*******><*******>\n"); // Draw separators between rows
        }
    }
    printf("<*******><*******><*******>\n\n");
}

// Main game loop
void playGame()
{
    int currentPlayer = 1;
    while (true)
    {
        if (playerTurn(currentPlayer))
        {
            break; // Game ends if a player wins or there's a draw
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player
    }
}

// Handle a player's turn
int playerTurn(int currentPlayer)
{
    int choice;
    bool validInput = false;
    char symbol = (currentPlayer == 1) ? 'X' : 'O';
    char *playerName = (currentPlayer == 1) ? player1 : player2;

    do
    {
        printf("\n(%c) %s's turn: ", symbol, playerName);
        scanf("%d", &choice);

        if (choice < 1 || choice > TOTAL_SLOTS)
        {
            printf("\nEnter a valid slot number between 1 and 9!\n");
            drawGameBoard();
        }
        else if (!updateBoard(choice, symbol))
        {
            printf("\nSlot %d unavailable, try again!\n", choice);
        }
        else
        {
            validInput = true;
            drawGameBoard();
            if (checkWin())
            {
                printf("Congratulations! %s wins!\n", playerName);
                return 1; // Game over, player wins
            }
            else if (checkDraw())
            {
                printf("\n\nIt's a draw!\n");
                return 1; // Game over, it's a draw
            }
        }
    } while (!validInput);

    return 0; // Game continues
}

// Update the board with the player's move
bool updateBoard(int choice, char symbol)
{
    int row = (choice - 1) / BOARD_SIZE;
    int col = (choice - 1) % BOARD_SIZE;

    if (gameBoard[row][col] == 'X' || gameBoard[row][col] == 'O')
    {
        return false; // Slot is already taken
    }

    gameBoard[row][col] = symbol; // Place the symbol on the board
    return true;
}

// Check if there is a winner
int checkWin()
{
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
        {
            return 1;
        }
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
        {
            return 1;
        }
    }
    // Check diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
    {
        return 1;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
    {
        return 1;
    }
    return 0;
}

// Check if the game is a draw
bool checkDraw()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O')
            {
                return false; // There's still an empty slot
            }
        }
    }
    return true; // All slots are filled and no winner
}