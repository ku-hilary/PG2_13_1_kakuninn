#include "Player.h"
#include "Novice.h"

Player::Player(Transform transform, int r, int speed)
{
	transform_ = transform;
	r_ = r;
	speed_ = speed;
}

Player::~Player()
{
}

void Player::Move(char* keys) {
	if (keys[DIK_S]) {
		transform_.y += speed_;
	}
	if (keys[DIK_W]) {
		transform_.y -= speed_;
	}
	if (keys[DIK_A]) {
		transform_.x -= speed_;
	}
	if (keys[DIK_D]) {
		transform_.x += speed_;
	}
}

void Player::Draw() {
	Novice::DrawEllipse(transform_.x, transform_.y, r_, r_, 0.0f, WHITE, kFillModeSolid);
}