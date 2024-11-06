#pragma once
#include "grid.hpp"

class Simulation
{
    public:
        Simulation(int width, int height)
        : grid(width, height), tempGrid(width, height), run(false) {};
        void Draw();
        bool Update(bool musicPausedi,Music music);
        bool MusicControl(bool musicPaused);
        bool IsRunning() {return run;}
        void Start() {run = true;}
        void Stop() {run = false;}
        void ClearGrid();
        void WalkUp();
        void ToggleCell(int row, int column);
        void WalkDown();
        void WalkRight();
        void WalkLeft();
    private:
        Grid grid;
        Grid tempGrid;
        bool run;
};
