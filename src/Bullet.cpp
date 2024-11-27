#include "Bullet.h"

Bullet::Bullet(Vector2 position, Vector2 direction, float speed)
    : position(position), direction(direction), speed(speed), active(true) {}

void Bullet::Update() {
    if (active) {
        position.x += direction.x * speed * GetFrameTime();
        position.y += direction.y * speed * GetFrameTime();

        // Deactivate bullet if it hits the screen boundary
        if (position.x < 0 || position.x > GetScreenWidth() ||
            position.y < 0 || position.y > GetScreenHeight()) {
            active = false;
        }
    }
}

void Bullet::Draw() const {
    if (active) {
        DrawCircleV(position, 5, YELLOW);
    }
}

bool Bullet::IsActive() const {
    return active;
}

Vector2 Bullet::GetPosition() const {
    return position;
}

void Bullet::Deactivate() {
    active = false;
}
