#pragma once
#include "Transform.h"
#include "Bullet.h"

class Enemy {

public:

	Transform transform_;
	int x_;
	int y_;
	int r_;
	int speed_;
	bool isHit_;
	int timer_;


public://ここから
	static bool isAlive_;
	Enemy(Transform transform, int r, int speed);
	~Enemy();
	void Update();
	void Damage(Bullet*bullet);
	void Draw();
};
