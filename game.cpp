#include "game.hpp"

#include <map>

void Game::draw() {
    int maxx = 0;
    int maxy = 0;
    std::map<int, std::map<int, char>> c;
    for (auto entry : maze_) {
        if (entry.first[2] != player_[2] || entry.first[3] != player_[3]) continue;
        int x = entry.first[0];
        int y = entry.first[1];
        bool here = x == player_[0] && y == player_[1];
        Wall* walls = entry.second.walls;
        c[4*x][4*y] = here ? '╔' : '┌';
        c[4*x+3][4*y] = here ? '╗' : '┐';
        c[4*x][4*y+3] = here ? '╚' : '└';
        c[4*x+3][4*y+3] = here ? '╝' : '┘';
        c[4*x][4*y+1] = here ? (walls[4] == DOOR ? '╜' : '║') : (walls[4] == DOOR ? '┘' : '│');
        c[4*x+3][4*y+1] = here ? (walls[0] == DOOR ? '╙' : '║') : (walls[0] == DOOR ? '└' : '│');
        c[4*x][4*y+2] = here ? (walls[4] == DOOR ? '╖' : '║') : (walls[4] == DOOR ? '┐' : '│');
        c[4*x+3][4*y+2] = here ? (walls[0] == DOOR ? '╓' : '║') : (walls[0] == DOOR ? '┌' : '│');
        c[4*x+1][4*y] = here ? (walls[5] == DOOR ? '╛' : '═') : (walls[5] == DOOR ? '┘' : '─');
        c[4*x+1][4*y] = here ? (walls[1] == DOOR ? '╘' : '═') : (walls[1] == DOOR ? '└' : '─');
        c[4*x+2][4*y+3] = here ? (walls[5] == DOOR ? '╕' : '═') : (walls[5] == DOOR ? '┐' : '─');
        c[4*x+2][4*y+3] = here ? (walls[1] == DOOR ? '╒' : '═') : (walls[1] == DOOR ? '┌' : '─');
        c[4*x+1][4*y+1] = walls[2] == DOOR ? '↑' : ' ';
        c[4*x+2][4*y+1] = walls[6] == DOOR ? '↓' : ' ';
        c[4*x+1][4*y+2] = walls[3] == DOOR ? '←' : ' ';
        c[4*x+1][4*y+2] = walls[7] == DOOR ? '→' : ' ';
        if (x > maxx) maxx = x;
        if (y > maxy) maxy = y;
    }
    for (int row = 0; row < 4*maxy; ++row) {
        std::string s;
        for (int i = 0; i < 4*maxx; ++i) {
            if (c[i][row]) s+= c[i][row];
            else s += ".";
        }
        printf("%s\n", s);
    }
}
bool Game::canMove(int dx, int dy, int dz, int dw) { 
    return true;
}
void Game::move(int dx, int dy, int dz, int dw) {}
