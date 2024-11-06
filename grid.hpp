#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
    public:
       Grid(int width, int height);
        ~Grid();
        void Draw();
        int GetRows() {return rows;}
        int GetColumns() {return columns;}
        void Clear();
        void WalkUp();
        void WalkDown();
        void WalkRight();
        void WalkLeft();
    private:
        Texture2D grassSprite;
        Texture2D playerSprite;
        Rectangle playerSrc;
        Rectangle playerDest;
        Music music;
        int rows;
        int columns;
        float playerSpeed = 3;
        std::vector<std::vector<int>> cells;
};
