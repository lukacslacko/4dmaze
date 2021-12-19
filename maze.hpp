#ifndef MAZE_HPP
#define MAZE_HPP

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
    Wall walls[8];
    int w,x, z ,y;
    RoomType roomtype;
};

typedef std::vector<Room> Maze;

Maze generete(int w,int x, int z ,int y);

#endif