#ifndef GAME_HPP
#define GAME_HPP

#include "maze.hpp"

class Game {
    public:
    Game(Maze& maze) : maze_(maze), player_{0,0,0,0} {}

    void draw();
    bool canMove(int dx, int dy, int dz, int dw);
    void move(int dx, int dy, int dz, int dw);

    private:
    Coord player_;

    Maze& maze_;
};

#endif
