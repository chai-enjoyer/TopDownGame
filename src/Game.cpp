#include "Game.h"

Game::Game(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight),
      player({400, 300, 50, 50}, 200.0f) {}

Game::~Game() {
    CloseWindow();
}

void Game::Run() {
    Init();

    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Init() {
    InitWindow(screenWidth, screenHeight, "Top-Down Game with Collisions");
    SetTargetFPS(60);

    // Add enemies
    enemies.emplace_back(Rectangle{200, 200, 50, 50}, 100.0f);
    enemies.emplace_back(Rectangle{600, 400, 50, 50}, 120.0f);
}

void Game::Update() {
    player.Update();

    for (Enemy& enemy : enemies) {
        enemy.Update(player.GetPosition());
    }

    // Check bullet collisions with enemies
    for (Bullet& bullet : player.GetBullets()) {
        if (bullet.IsActive()) {
            for (Enemy& enemy : enemies) {
                if (enemy.CheckCollision(bullet.GetPosition())) {
                    bullet.Deactivate();
                    enemy.Kill();
                    break;
                }
            }
        }
    }

    // Check collisions between player and enemies
    for (Enemy& enemy : enemies) {
        if (enemy.IsAlive() && CheckCollisionRecs(
                {player.GetPosition().x, player.GetPosition().y, 50, 50},
                enemy.GetRectangle())) { // Use the getter here
            // Player and enemy collide - handle game over or health deduction
            DrawText("GAME OVER", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, RED);
            break;
        }
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    player.Draw();

    for (const Enemy& enemy : enemies) {
        enemy.Draw();
    }

    EndDrawing();
}
