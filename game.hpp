#ifndef GAME_HPP
#define GAME_HPP

#include "maze.hpp"

class Game {
    public:
    Game(const Maze& maze) : maze_(maze) {}

    void draw();
    bool canMove(int dx, int dy, int dz, int dw);
    void move(int dx, int dy, int dz, int dw);

    private:
    int x, y, z, w;

    const Maze& maze_;
};

#endif
