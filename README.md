# **Tic-Tac-Toe Game**

This is a **simple two-player Tic-Tac-Toe game** implemented in C. Players take turns marking cells on a 3x3 grid. The player who aligns three symbols in a row, column, or diagonal wins the game. If all slots are filled and no player wins, the game ends in a draw.

## **Table of Contents**

- [Features](#features)
- [How to Compile and Run](#how-to-compile-and-run)
- [Gameplay Rules](#gameplay-rules)
- [How to Play](#how-to-play)
- [Code Structure](#code-structure)
- [Example Output](#example-output)
- [Known Issues](#known-issues)
- [Future Improvements](#future-improvements)

---

## **Features**

- Two-player game: Player 1 (X) vs Player 2 (O).
- Simple and clean **text-based interface**.
- **Input validation** for valid slot numbers.
- **Detection of wins** and **draws**.
- Dynamic player turn switching.
- Easy to compile and run on any platform with GCC.

---

## **How to Compile and Run**

### **Prerequisites:**

- A C compiler (like GCC) installed on your machine.
- (Optional) A terminal or command prompt to compile and run the program.

### **Compilation:**

Open your terminal or command prompt, navigate to the project directory, and compile the code with:

```bash
gcc -Wall -Wextra -o tictactoe tictactoe.c
```

### **Running the Game:**

Once compiled, run the executable:

```bash
./tictactoe
```

On **Windows**, run:

```bash
tictactoe.exe
```

---

## **Gameplay Rules**

1. Player 1 uses **X** and Player 2 uses **O**.
2. Players take turns to **choose a slot number (1-9)** corresponding to a position on the board.
3. **Objective:** Align three of your symbols in a row, column, or diagonal.
4. **Winning Conditions:**
   - A player wins by aligning their symbols horizontally, vertically, or diagonally.
5. **Draw Condition:** If all slots are filled and no player has won, the game ends in a draw.

---

## **How to Play**

1. When prompted, enter the **names** of Player 1 and Player 2.
2. The **game board** will be displayed with numbers representing available slots:

   ```C
   Current Game Board:

   <*******><*******><*******>
    *   1   *   2   *   3   *
   <*******><*******><*******>
    *   4   *   5   *   6   *
   <*******><*******><*******>
    *   7   *   8   *   9   *
   <*******><*******><*******>
   ```

3. On each turn, the active player will be prompted to **choose a slot number** to place their symbol.
4. If a player selects an **occupied slot**, they will be prompted to try again.
5. The game continues until **one player wins** or the game ends in a **draw**.

---

## **Code Structure**

```bash
TicTacToe/
├── src/
│   └── tictactoe.c        # Source code for the game
├── README.md              # Documentation (this file)
└── Makefile (optional)    # For easy compilation
```

### **Key Functions:**

- **`gameInit()`**: Initializes player names and displays a welcome message.
- **`drawGameBoard()`**: Draws the current state of the game board.
- **`playGame()`**: Manages the main game loop and player turns.
- **`playerTurn()`**: Handles player input and validates moves.
- **`updateBoard()`**: Updates the game board with the player's symbol.
- **`checkWin()`**: Checks if a player has won the game.
- **`checkDraw()`**: Checks if the game has ended in a draw.

---

## **Example Output**

```bash
Tic-Tac-Toe
============
Enter player 1 name: Alice
Enter player 2 name: Bob

Alice (X) vs Bob (O), may the best player win!

Current Game Board:

<*******><*******><*******>
 *   1   *   2   *   3   *
<*******><*******><*******>
 *   4   *   5   *   6   *
<*******><*******><*******>
 *   7   *   8   *   9   *
<*******><*******><*******>

(X) Alice's turn:
1

Current Game Board:

<*******><*******><*******>
 *   X   *   2   *   3   *
<*******><*******><*******>
 *   4   *   5   *   6   *
<*******><*******><*******>
 *   7   *   8   *   9   *
<*******><*******><*******>

(O) Bob's turn:
5

Current Game Board:

<*******><*******><*******>
 *   X   *   2   *   3   *
<*******><*******><*******>
 *   4   *   O   *   6   *
<*******><*******><*******>
 *   7   *   8   *   9   *
<*******><*******><*******>
```

---

## **Known Issues**

1. **No Replay Option:** After a game ends, the program exits. Players need to restart the game manually.
2. **No Error Handling for Non-Integer Input:** If a player inputs a non-integer (e.g., a letter), the program may behave unexpectedly.

---

## **Future Improvements**

1. **Add Replay Feature:** Allow players to start a new game without restarting the program.
2. **Input Validation:** Handle non-integer inputs gracefully.
3. **Score Tracking:** Implement a system to track wins for each player across multiple games.
4. **AI Opponent:** Add an AI opponent for single-player mode.

---

## **License**

This project is open-source and free to use under the **MIT License**.

---

## **Contributing**

If you'd like to contribute:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature-branch`.
3. Commit your changes: `git commit -m "Add feature"`.
4. Push to the branch: `git push origin feature-branch`.
5. Open a pull request.

---

## **Author**

This project was developed by **[Your Name]** as a learning project. Feel free to reach out with any questions or feedback!

---

## **Conclusion**

Enjoy the game! If you find any bugs or have ideas for improvements, feel free to contribute or contact me. Thank you for playing!
