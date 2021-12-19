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
    Room(int w_, int x_, int z_, int y_) : x(x_), y(y_), z(z_), w(w_);
    Wall walls[8];
    int w,x, z ,y;
    RoomType roomtype;
};

typedef std::vector<int> Coord;

typedef std::map<Coord, Room> Maze;

Maze generete(int w,int x, int z ,int y);

#endif