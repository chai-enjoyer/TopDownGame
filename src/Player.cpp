#include "Player.h"
#include <cmath>

Player::Player(Rectangle rect, float speed) : rect(rect), speed(speed) {}

void Player::Update() {
    // Movement with boundary checks
    if (IsKeyDown(KEY_W) && rect.y > 0) rect.y -= speed * GetFrameTime();
    if (IsKeyDown(KEY_S) && rect.y + rect.height < GetScreenHeight()) rect.y += speed * GetFrameTime();
    if (IsKeyDown(KEY_A) && rect.x > 0) rect.x -= speed * GetFrameTime();
    if (IsKeyDown(KEY_D) && rect.x + rect.width < GetScreenWidth()) rect.x += speed * GetFrameTime();

    // Shooting
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Shoot();
    }

    // Update bullets
    for (Bullet& bullet : bullets) {
        bullet.Update();
    }
}

void Player::Draw() const {
    DrawRectangleRec(rect, WHITE);

    for (const Bullet& bullet : bullets) {
        bullet.Draw();
    }
}

Vector2 Player::GetPosition() const {
    return {rect.x, rect.y};
}

std::vector<Bullet>& Player::GetBullets() {
    return bullets;
}

void Player::Shoot() {
    Vector2 mousePos = GetMousePosition();
    Vector2 playerCenter = {rect.x + rect.width / 2, rect.y + rect.height / 2};
    Vector2 direction = {mousePos.x - playerCenter.x, mousePos.y - playerCenter.y};

    // Normalize direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > 0) {
        direction.x /= length;
        direction.y /= length;
    }

    bullets.emplace_back(playerCenter, direction, 500.0f);
}
