
markdown
Copy code
# Snake GUI

Snake GUI is a snake game project developed for COMP.CS.110 Programming 2: Structures in 2022.

Author: Magnus Forsblom  
Email: magnus.forsblom@tuni.fi  

## Game Overview

In Snake GUI, players control a snake that grows in length by eating food. The objective is to grow the snake to the size of the playing field without hitting itself or walls. The snake's direction is controlled using the WASD keys.

## Program Description

### Game Rules

- **Win Condition:** Grow the snake to the size of the gameboard.
- **Loss Conditions:** Snake hits itself or a wall.

### Images

![Gameplay](https://github.com/GitMag/SnakeGame/assets/34399030/fac300b1-1385-4604-a7f5-6abe4c093c92)


### Customizable Game Settings

- Gameboard width and height (1-99).
- Snake movement speed (milliseconds).
- Game seed for consistent spawning.

### Gameplay Features

- Track snake size and elapsed game time.
- Pause/resume functionality.
- Reset game state option.

### Scoring System

- Score = Snake length / (Gameboard width * height).

## Extra Features

1. Adjustable game grid size.
2. Real-time snake length display.
3. Game timer.
4. Scoring based on performance.
5. Dynamic UI background based on game outcome.
6. Pause button with visual feedback.
7. Separate window for game options.
8. Snake speed customization.

## Implementation Details

### User Interface (UI)

- **MainWindow:** Game menu and settings.
- **GameWindow:** Displays the game using QGraphicsScene.
- **Pause Functionality:** Implemented with a separate timer.

### Game Logic

- **GameBoard and Point Classes:** Control snake logic and coordinates.
- **Main Menu:** Controlled by MainWindow class.
- **UI Integration:** GameBoard displayed in GameWindow.

---
