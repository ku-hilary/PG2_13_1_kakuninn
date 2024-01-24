#include "Bullet.h"
#include "Player.h"
#include "Novice.h"

Bullet::Bullet(Transform transform, int r, int speed)
{
	transform_ = transform;
	r_ = r;
	speed_ = speed;
	isShoot_ = false;
}

Bullet::~Bullet()
{
}

void Bullet::ShootBullet(char* keys) {
	if (keys[DIK_SPACE]) {
		isShoot_ = true;
	}
	if (isShoot_) {
		transform_.y -= speed_;
	}
	if (transform_.y < 0) {
		isShoot_ = false;
	}
}

void Bullet::followPlayer(Player& player)
{
	if (isShoot_ == false) {
		transform_ = player.transform_;
	}
}

void Bullet::Draw() {
	Novice::DrawEllipse(transform_.x, transform_.y, r_, r_, 0.0f, RED, kFillModeSolid);
}