#pragma once
#include "Vector2.h"

struct Ball {
	Ball() : ballPos(Vector2(0, 0)), ballVelocity(0, 1) {};	//TODO init au milieu de la map pas en 0,0
	Ball(Vector2 VecPos, Vector2 VecVelo) : ballPos(VecPos), ballVelocity(VecVelo) {}

public:
	Vector2 ballPos;
	Vector2 ballVelocity;
};