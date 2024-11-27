#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Bullet.h"
#include <vector>

class Player
{
private:
    Rectangle rect;
    float speed;
    std::vector<Bullet> bullets;
    void Shoot();

public:
    Player(Rectangle rect, float speed);
    void Update();
    void Draw() const;
    Vector2 GetPosition() const;
    std::vector<Bullet>& GetBullets();
};

#endif
