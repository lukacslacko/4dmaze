#include <stdio.h>

#include "game.hpp"
#include "maze.hpp"

int main() {
    Maze maze = generate(3, 3, 3, 3);
    Game game(maze);

    printf("Welcome to 4D Maze!\n\n");
    while (true) {
        game.draw();
        char c = getchar();
        int dx = 0;
        int dy = 0;
        int dz = 0;
        int dw = 0;
        if (c == 'w') dy = -1;
        if (c == 's') dy = 1;
        if (c == 'a') dx = -1;
        if (c == 'd') dx = 1;
        if (c == 'l') dz = 1;
        if (c == 'j') dz = -1;
        if (c == 'i') dw = 1;
        if (c == 'k') dw = -1;
        game.move(dx, dy, dz, dw);
    }
}
