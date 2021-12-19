#include <stdio.h>

#include "game.hpp"
#include "maze.hpp"

int main() {
    Maze maze = generate(3, 3, 3, 3);
    Game game(maze);

    printf("Welcome to 4D Maze!\n\n");
    while (true) {
        game.draw();
    }
}
