#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

class Enemy {
public:
    Enemy(Rectangle rect, float speed);
    void Update(Vector2 playerPos);
    void Draw() const;
    bool CheckCollision(Vector2 bulletPos) const;
    bool IsAlive() const;
    void Kill();

    Rectangle GetRectangle() const; // Add a getter for `rect`

private:
    Rectangle rect;
    float speed;
    bool alive;
};

#endif
