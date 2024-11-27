#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

class Bullet {
public:
    Bullet(Vector2 position, Vector2 direction, float speed);
    void Update();
    void Draw() const;
    bool IsActive() const;
    Vector2 GetPosition() const;
    void Deactivate();

private:
    Vector2 position;
    Vector2 direction;
    float speed;
    bool active;
};

#endif
