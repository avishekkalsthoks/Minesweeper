#Minesweeper

A classic terminal-based Minesweeper game written in C. 

Mines are placed randomly across the grid, and the player must pinpoint their locations and flag them without detonating the mines. Digging up a safe square reveals the number of mines in the surrounding 3×3 neighborhood, providing clues to clear the rest of the board. Built as a personal skill-maxing project in C.

## Installation

### Prerequisites
* A C compiler (`gcc` or `clang`)
* `make`
* External library 'SDL3'

### Build and Install
1. Clone the repository:
   ```bash
   git clone "https://github.com/avishekkalsthoks/Minesweeper"
   cd Minesweeper
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the project:
```bash 
./minesweeper
```
## How to Play
* **Dig** (Left Click) on any square to find hint about the surrounding squares.
* **Flag** (Right Click) any suspicious square 
* **Win Condition** Accurately find all the mines and flag them up.
