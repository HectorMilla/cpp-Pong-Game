# Pong Game (C++ with SFML)

A simple **Pong game** created with **C++** and **SFML**. This game features two paddles, a bouncing ball, and a scoring system for two players. It uses object-oriented principles and game loops, making it a great learning project for beginners.

## Table of Contents
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Game Logic](#game-logic)

## Installation

To run the **Pong Game**, you'll need to set up the following:

### 1. **Install SFML (Simple and Fast Multimedia Library)**
   - **Windows:**
     - Download the latest version of SFML for your platform from the official website: [SFML Downloads](https://www.sfml-dev.org/download.php).
     - Follow the instructions to set up SFML with Visual Studio.
   - **macOS/Linux:**
     - Use your package manager (e.g., `brew` on macOS or `apt` on Ubuntu) to install SFML.
     - Alternatively, follow the installation instructions in the [SFML Documentation](https://www.sfml-dev.org/tutorials/2.5/).

### 2. **Clone the Repository**
   Clone this repository to your local machine using the following command:
   ```bash
   git clone https://github.com/HectorMilla/cpp-Pong-Game.git

3. Build and Run the Project
Open the project in Visual Studio (Windows) or your preferred IDE.
Set up the project to link against the SFML libraries (see SFML setup guide for more details).
Build and run the project. The game window should open, and you can start playing!
How to Play
Player 1: Move up with W and down with S to control the left paddle.
Player 2: Move up with the Up Arrow key and down with the Down Arrow key to control the right paddle.
The ball bounces off the top and bottom walls.
The game keeps score for both players. The game resets the ball after each point.
The first player to reach the winning score wins the game.
Features
Two-player local multiplayer.
Ball bounce mechanics.
Score tracking for both players.
Simple and responsive controls.
Technologies Used
C++: The game is built using C++ for high performance and learning.
SFML: The Simple and Fast Multimedia Library is used to create the graphical window and handle game rendering.
Visual Studio 2022: The development environment used for building the game on Windows.
Game Logic
1. Paddles:
Each player controls a paddle with up/down keys (W/S for Player 1 and Arrow Keys for Player 2).
The paddles move vertically within the window boundaries and do not overlap the top or bottom walls.
2. Ball:
The ball bounces off the paddles and the top/bottom walls.
The ball’s speed is adjusted at the start of each round after a player scores.
3. Scoring:
The game tracks the score of both players.
When the ball passes one of the paddles, the opposing player scores a point.
The ball is reset to the center of the screen after each point.
