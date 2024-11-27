#include "Enemy.h"
#include <cmath>

Enemy::Enemy(Rectangle rect, float speed) : rect(rect), speed(speed), alive(true) {}

void Enemy::Update(Vector2 playerPos) {
    if (!alive) return;

    Vector2 direction = {playerPos.x - rect.x, playerPos.y - rect.y};
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length > 0) {
        direction.x /= length;
        direction.y /= length;

        rect.x += direction.x * speed * GetFrameTime();
        rect.y += direction.y * speed * GetFrameTime();

        // Keep within screen bounds
        if (rect.x < 0) rect.x = 0;
        if (rect.y < 0) rect.y = 0;
        if (rect.x + rect.width > GetScreenWidth()) rect.x = GetScreenWidth() - rect.width;
        if (rect.y + rect.height > GetScreenHeight()) rect.y = GetScreenHeight() - rect.height;
    }
}

void Enemy::Draw() const {
    if (alive) {
        DrawRectangleRec(rect, RED);
    }
}

bool Enemy::CheckCollision(Vector2 bulletPos) const {
    return alive && CheckCollisionPointRec(bulletPos, rect);
}

bool Enemy::IsAlive() const {
    return alive;
}

void Enemy::Kill() {
    alive = false;
}

Rectangle Enemy::GetRectangle() const {
    return rect;
}
