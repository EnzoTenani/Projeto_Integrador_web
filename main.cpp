#include <iostream>
#include "simulation.hpp"
#include <raylib.h>
#include "grid.hpp"

int main()
{
    Color GREY = {147,211,196,255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    int FPS = 60;
    bool running = true;
    bool musicPaused = false;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    InitAudioDevice();
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT};

    //Simulation Loop
    while(running){

        // 1. Event Handling
        if(IsKeyDown(KEY_W)){
            simulation.WalkUp();
        }
        else if(IsKeyDown(KEY_S)){
            simulation.WalkDown();
        }
        else if(IsKeyDown(KEY_D)){
            simulation.WalkRight();
        }
        else if (IsKeyDown(KEY_A)){
            simulation.WalkLeft();
        }
        else if (IsKeyDown(KEY_Q)){
            musicPaused = simulation.MusicControl(musicPaused);
        }


        // 2. Updating State
        running = simulation.Update(musicPaused,music);


        // 3. Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }
//    UnloadTexture(grassSprite);
 //   UnloadTexture(playerSprite);
    CloseWindow();
}
