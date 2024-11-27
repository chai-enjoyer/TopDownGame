#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{
private:
    int screenWidth;
    int screenHeight;

    Player player;
    std::vector<Enemy> enemies;

    void Init();
    void Update();
    void Draw();

public:
    Game(int screenWidth, int screenHeight);
    ~Game();
    void Run();
};

#endif
