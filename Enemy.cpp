#include "Enemy.h"
#include "Bullet.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include<math.h>

Enemy::Enemy(Transform transform, int r, int speed)
{
	transform_ = transform;
	r_ = r;
	speed_ = speed;
	isHit_ = false;
	timer_ = 0;
	isAlive_ = true;
}

Enemy::~Enemy()
{
}

void Enemy::Update() {
	transform_.x += speed_;
	if (transform_.x > 1280-r_) {
		speed_ *= -1;
	}
	if (transform_.x < r_) {
		speed_ *= -1;
	}
}

void Enemy::Damage(Bullet* bullet)
{
	int a = transform_.x - bullet->transform_.x;
	int b = transform_.y - bullet->transform_.y;
	if ((sqrt(a*a) + (b*b)) < r_ + bullet->r_) {
		isHit_ = true;
	}

	if (isHit_) {
		timer_++;
	}
	if (timer_ >= 120) {
		isHit_ = false;
		timer_ = 0;
	}
}


void Enemy::Draw() {
	if (isHit_ == false) {
		Novice::DrawEllipse(transform_.x, transform_.y, r_, r_, 0.0f, BLUE, kFillModeSolid);
	}
}