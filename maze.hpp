#ifndef MAZE_HPP
#define MAZE_HPP

#include <map>
#include <vector>

enum Wall {
    WALL
    ,
    DOOR
};

enum RoomType {
    ROOM
};

struct Room {
    Room(int x_, int y_, int z_, int w_, int tmp_) : x(x_), y(y_), z(z_), w(w_), tmp(tmp_);
    Wall walls[8];
    int w,x, z ,y;
    RoomType roomtype;
    int tmp;
};

typedef std::vector<int> Coord;

typedef std::map<Coord, Room> Maze;

Maze generete(int x,int y, int z ,int w);

#endif