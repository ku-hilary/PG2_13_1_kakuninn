#pragma once
#include "Transform.h"

class Player {

public:

	Transform transform_;
	int x_;
	int y_;
	int r_;
	int speed_;


public://ここから
	Player(Transform transform, int r, int speed);
	~Player();
	void Move(char* keys);
	void Draw();
};