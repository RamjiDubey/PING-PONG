# Pong Game

## Introduction
This is a simple Pong game implemented in C++ using the Raylib library. The game features a ball bouncing between two paddles controlled by the players.

## Features
- Two-player Pong game.
- Left paddle controlled by 'W' and 'S' keys.
- Right paddle controlled by the 'Up' and 'Down' arrow keys.
- The ball bounces off paddles and walls.
- The game ends when the ball goes off the screen, and the player on the opposite side wins.
- Press the 'Space' key to restart the game after a winner is determined.

## How to Play
1. Run the executable.
2. Choose option '1' to start a new game or '2' to close the game.
3. Control the left paddle with 'W' and 'S' keys.
4. Control the right paddle with the 'Up' and 'Down' arrow keys.
5. Win by making the ball go off the opponent's side.

## Dependencies
- Raylib Library: [https://www.raylib.com/](https://www.raylib.com/)

## Building and Running
1. Install the Raylib library by following the instructions on the official website.
2. Compile the source code using a C++ compiler, linking against the Raylib library.
   ```bash
   g++ pong.cpp -o pong -lraylib

