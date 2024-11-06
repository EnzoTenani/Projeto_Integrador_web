#include <raylib.h>
#include "grid.hpp"


Grid::Grid(int width, int height)
    : rows(height), columns(width), cells(rows, std::vector<int>(columns, 1)) {
    grassSprite = LoadTexture("assets/Tilesets/Grass.png");
    playerSprite = LoadTexture("assets/Characters/Basic Charakter Spritesheet.png");


    playerSrc = (Rectangle){0, 0, 48, 48};
    playerDest = (Rectangle){200, 200, 100, 100};

    music = LoadMusic("assets/backgroundTrack.mp3");


}

Grid::~Grid() {
    UnloadTexture(grassSprite);
    UnloadTexture(playerSprite);
    UnloadMusicStream(music);
    CloseAudioDevice();
}
void Grid::Draw()
{
    DrawTexture(grassSprite, 100, 50, WHITE);
    DrawTexturePro(playerSprite, playerSrc, playerDest, (Vector2){playerDest.width, playerDest.height}, 0, WHITE);

}



void Grid::Clear()
{
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            cells[row][column] = 0;
        }
    }
}


void Grid::WalkUp(){
    playerDest.y -= playerSpeed;

}
void Grid::WalkDown(){

    playerDest.y += playerSpeed;
}
void Grid::WalkRight(){

    playerDest.x += playerSpeed;
}
void Grid::WalkLeft(){

    playerDest.x -= playerSpeed;
}
