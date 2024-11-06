#include <vector>
#include <utility>
#include "simulation.hpp"
#include <raylib.h>

void Simulation::Draw()
{
    grid.Draw();
}

bool Simulation::Update(bool musicPaused, Music music)
{
    UpdateMusicStream(music);
    if (musicPaused){
        PauseMusicStream(music);
    }
    else {
        ResumeMusicStream(music);
    }


    return !WindowShouldClose();

}

bool Simulation::MusicControl(musicPaused){
    return !musicPaused;
}

void Simulation::ClearGrid()
{
    if(!IsRunning())
    {
        grid.Clear();
    }
}

void Simulation::WalkUp(){

    if(!IsRunning())
    {
        grid.WalkUp();
    }
}
void Simulation::WalkDown(){

    if(!IsRunning())
    {
        grid.WalkDown();
    }
}
void Simulation::WalkRight(){

    if(!IsRunning())
    {
        grid.WalkRight();
    }
}
void Simulation::WalkLeft(){

    if(!IsRunning())
    {
        grid.WalkLeft();

    }
}
