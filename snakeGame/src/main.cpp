#include "raylib.h"
#include "raymath.h"
#include <deque>

using namespace std;

// Grid and cell configurations
const int CELL_SIZE = 30;
const int CELL_COUNT = 30;

// Game state
bool isGameOver = false;
int deathSoundCounter = 1;
int score = 0;

class Snake {
private:
    Vector2 up = {0, -1};
    Vector2 down = {0, 1};
    Vector2 left = {-1, 0};
    Vector2 right = {1, 0};

    deque<Vector2> body = {Vector2{6, 7}, Vector2{6, 8}, Vector2{6, 9}};
    Vector2 direction = {1, 0};

public:
    Vector2 getHead() { return body.front(); }
    Vector2 getDirection() { return direction; }

    void draw() {
        for (const auto &segment : body) {
            DrawRectangle((int)segment.x * CELL_SIZE, (int)segment.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, GREEN);
        }
    }

    void grow() { body.push_back(Vector2{100, 100}); }

    void checkSelfCollision() {
        for (size_t i = 1; i < body.size(); i++) {
            if (Vector2Equals(body.front(), body[i])) {
                isGameOver = true;
                break;
            }
        }
    }

    void move() {
        if (IsKeyPressed(KEY_W) && !Vector2Equals(direction, down)) direction = up;
        if (IsKeyPressed(KEY_A) && !Vector2Equals(direction, right)) direction = left;
        if (IsKeyPressed(KEY_D) && !Vector2Equals(direction, left)) direction = right;
        if (IsKeyPressed(KEY_S) && !Vector2Equals(direction, up)) direction = down;

        body.pop_back();
        body.push_front(Vector2Add(body.front(), direction));
    }

    void checkEdgeCollision() {
        if (body.front().x >= CELL_COUNT) body.front().x = 0;
        if (body.front().x < 0) body.front().x = (float)(CELL_COUNT - 1);
        if (body.front().y >= CELL_COUNT) body.front().y = 0;
        if (body.front().y < 0) body.front().y = (float)(CELL_COUNT - 1);
    }
};

class Food {
private:
    Vector2 position;

public:
    Food() { randomizePosition(); }

    Vector2 getPosition() { return position; }

    void randomizePosition() {
        position = {static_cast<float>(rand() % CELL_COUNT), static_cast<float>(rand() % CELL_COUNT)};
    }

    void draw() {
        DrawRectangle((int)position.x * CELL_SIZE, (int)position.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, RED);
    }
};

int main() {
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Snake Game");
    SetTargetFPS(12);

    Snake snake;
    Food food;

    InitAudioDevice();
    Sound eatSound = LoadSound("sounds/eat.mp3");
    Sound deathSound = LoadSound("sounds/death.mp3");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGREEN);

        DrawText(TextFormat("Score: %i", score), 10, 10, 30, WHITE);

        snake.draw();
        food.draw();
        snake.move();

        if (Vector2Equals(snake.getHead(), food.getPosition()) && !isGameOver) {
            food.randomizePosition();
            snake.grow();
            score++;
            PlaySound(eatSound);
        }

        if (isGameOver) {
            DrawText("Game Over", CELL_SIZE * CELL_COUNT / 5, CELL_SIZE * CELL_COUNT / 3, 80, DARKPURPLE);
            if (deathSoundCounter > 0) {
                PlaySound(deathSound);
                deathSoundCounter--;
            }
        }

        snake.checkSelfCollision();
        snake.checkEdgeCollision();

        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    UnloadSound(eatSound);
    UnloadSound(deathSound);

    return 0;
}
