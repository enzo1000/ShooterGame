#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Vector2.h"
#include "Timer.h"
#include "Ball.h"
#include <vector>

class Game
{
public:
	//Dooable since C++11 to guaranty the unicity of the Game instance
	static Game& instance() {
		static Game inst;
		return inst;
	}

	static void doze() {
	}

	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;

	/*
		&& is new in C++11 and it signifies that the function accepts an RValue Reference
		that is a reference to an argument that is about to be destroy
	 */
	Game(Game&&) = delete;	//avoiding implicit move constructor
	Game& operator = (Game&&) = delete;

private:
	Game() :
		isRunning(true),	//Singleton Constructor is private
		paddlePosLeft({ 50, 100 }),
		paddlePosRight({ 974, 100 }),
		paddleVelocity({ 0, 450 }),
		paddleDirectionLeft(0),
		paddleDirectionRight(0),
		wallThickness(10),
		topWall(Rectangle()),
		bottomWall(Rectangle()),
		balls({ Ball(Vector2(100,100), Vector2(500,100)), Ball(Vector2(300,300), Vector2(500,100)), Ball(Vector2(400,400), Vector2(100,50)) })
	{}

public:
	bool initialize();
	void loop();
	void close();

private:
	void processInput();
	void update(float dt);
	void render();

	Window window;
	bool isRunning;
	Renderer renderer;

	Rectangle topWall;
	Rectangle bottomWall;
	const float wallThickness = 10;

	const float ballSize = 10;

	Vector2 paddlePosLeft;
	Vector2 paddlePosRight;
	Vector2 paddleVelocity;
	const float paddleWidth = 10;
	const float paddleHeight = 64;
	float paddleDirectionLeft;
	float paddleDirectionRight;

	std::vector<Ball> balls = {};
};