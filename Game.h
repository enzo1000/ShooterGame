#pragma once
#include <vector>
#include "Window.h"
#include "Renderer.h"
#include "Vector2.h"
#include "Actor.h"
using std::vector;

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
		isUpdatingActors(false)
	{}

public:
	bool initialize();
	void loop();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);

private:
	void processInput();
	void update(float dt);
	void render();

	Window window;
	bool isRunning;
	Renderer renderer;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;
};