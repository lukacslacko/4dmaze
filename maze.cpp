#include "maze.hpp"
#include <cstdlib>

Room::Room(int w_, int x_, int z_, int y_, int tmp_) {
    roomtype = ROOM;
    for (auto wall : walls) wall = WALL;
}

Maze generate(int x,int y, int z ,int w) {
    Maze maze;
    int cnt = 0;
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            for (int k=0;k<w;k++){
                for (int l=0;l<z;l++) {
                    maze[Coord{i,j,k,l}] = Room(i, j, k, l, cnt++);
                }
            }
        }
    }
    int parts = cnt;
    while (parts > 1) {
        int a = rand()%x;
        int b = rand()%y;
        int c = rand()%z;
        int d = rand()%w;
        int dir = rand()%4;
        int da = dir==0;
        int db = dir==1;
        int dc = dir==2;
        int dd = dir==3;
        int aa=a+da;
        int bb=b+db;
        int cc=c+dc;
        int dd=d+dd;
        if (aa>=x || bb >=y || cc >= z || dd >= w) continue;
        if (maze[Coord{a,b,c,d}].walls[dir] != WALL) continue;
        int from = maze[Coord{a,b,c,d}].tmp;
        int to = maze[Coord{aa,bb,cc,dd}].tmp;
        if (from == to) continue;
        maze[Coord{a,b,c,d}].walls[dir] = DOOR;
        maze[Coord{aa,bb,cc,dd}].walls[dir+4] = DOOR;
        for (int i=0;i<x;i++){
            for (int j=0;j<y;j++){
                for (int k=0;k<w;k++){
                    for (int l=0;l<z;l++) {
                        if (maze[Coord{i,j,k,l}].tmp == to) maze[Coord{i,j,k,l}].tmp = from;
                    }
                }
            }
        }
        --parts;
    }
    return maze;
}