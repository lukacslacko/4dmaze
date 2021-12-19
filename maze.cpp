#include "maze.hpp"
#include <cstdlib>

Room::Room(int w_, int x_, int z_, int y_) {
    roomtype = ROOM;
    for (auto wall : walls) wall = WALL;
}

Maze generete(int w,int x, int z ,int y) {
    Maze maze;
    std::vector<int> szamok;
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            for (int k=0;k<w;k++){
                for (int l=0;l<z;l++) {
                    maze[Coord{i,j,k,l}] = Room(k, i, l, j);
                }
            }
        }
    }
    return maze;
}