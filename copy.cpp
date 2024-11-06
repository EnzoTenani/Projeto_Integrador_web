#include "raylib.h"

const int screenWidth = 1000;
const int screenHeight = 480;

bool running = true;
Color bkgColor;
Texture2D grassSprite;
Texture2D playerSprite;
Rectangle playerSrc;
Rectangle playerDest;

void drawScene() {
    DrawTexture(grassSprite, 100, 50, WHITE);
    DrawTexturePro(playerSprite, playerSrc, playerDest, (Vector2){playerDest.width / 2, playerDest.height / 2}, 0, WHITE);
}

void input() {
    // Função de entrada de controle (vazia por enquanto)
}

void update() {
    running = !WindowShouldClose();
}

void init() {
    InitWindow(screenWidth, screenHeight, "Spring Game");
    SetTargetFPS(60);

    grassSprite = LoadTexture("assets/Tilesets/Grass.png");
    playerSprite = LoadTexture("assets/Characters/Basic Charakter Spritesheet.png");

    playerSrc = (Rectangle){0, 0, 48, 48};
    playerDest = (Rectangle){200, 200, 100, 100};
}

void quit() {
    UnloadTexture(grassSprite);
    UnloadTexture(playerSprite);
    CloseWindow();
}

int main() {
    init();
    while (running) {
        input();
        update();
        BeginDrawing();
        ClearBackground(bkgColor);
        drawScene();
        EndDrawing();
    }
    quit();
    return 0;
}

