
# Lights Out Game

Welcome to **Lights Out**, a classic logic puzzle game recreated in C!  
This project was built as part of an academic exercise to explore array manipulation, bitwise logic, and game loop design in a low-level programming environment.

---

## Game Description

**Lights Out** is a 3x3 grid-based game where each cell (or "light") can be either ON or OFF.  
The objective is simple: **turn off all the lights**. However, each move toggles not only the selected light but also its adjacent neighbors (up, down, left, right).

The challenge lies in figuring out the right sequence of moves that will switch off every light!

---

## Features

-  3x3 grid logic implementation
-  Turn-based game loop
-  Logic-based toggling rules
-  Win condition detection
-  Console-based user interface

---

## How It Works

1. The grid starts in a random or pre-defined state.
2. The player chooses a position to toggle (row, column).
3. The program toggles the chosen cell and its immediate neighbors.
4. The game continues until all cells are OFF.

---

## Example

```
Initial State:

1 1 0  
0 1 0  
1 0 1  

Player selects (2, 2)

Updated State:

1 1 0  
0 0 0  
1 0 1
```

---

## Technologies Used

- C Programming Language
- CLI-based interaction
- 2D array manipulation
- Modular code with helper functions

---

## Project Structure

```
LightsOutGame/
├── main.c             # Game logic and main loop
├── lights.c           # Grid state manipulation
├── lights.h           # Header file for grid logic
├── display.c          # Visual display on console
├── display.h          # Header file for display
├── Makefile           # Build instructions
└── README.md          # Project documentation
```

---

## How to Run

1. **Clone the repo:**
   ```bash
   git clone https://github.com/surabhirajbhandari/LightsOutGame.git
   cd LightsOutGame
   ```

2. **Compile the code using Makefile:**
   ```bash
   make
   ```

3. **Run the game:**
   ```bash
   ./lightsout
   ```

>  _Note: Ensure you have a C compiler (like `gcc`) installed on your system._

---

##  What I learnt after doing this project?

- Grid-based game state management
- Array indexing and manipulation
- Modular programming with header files
- Logic implementation in C
- Handling user input and console output


