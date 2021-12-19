#ifndef MAZE_HPP
#define MAZE_HPP

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

#endif