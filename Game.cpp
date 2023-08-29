#include "Game.h"

bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);

	int windowWidth = window.getWidth();
	int windowHeight = window.getHeight();
	topWall = { 0, 0, static_cast<float>(windowWidth), wallThickness };
	bottomWall = { 0, windowHeight - wallThickness, static_cast<float>(windowWidth), wallThickness};

	return isWindowInit && isRendererInit; // Return bool && bool && bool .. to detect error
}

void Game::loop() {

	Timer timer;
	float dt = 0;
	while (isRunning) {
		float dt = timer.computeDeltaTime() / 1000.0f;
		processInput();
		update(dt);
		render();
		timer.delayTime();
	}
}

void Game::close() {
	renderer.close();
	window.close();
	SDL_Quit();
}

void Game::processInput() {
	//SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
	// Keyboard state
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	// Escape: quit game
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}
	if (keyboardState[SDL_SCANCODE_W])
	{
		paddleDirectionLeft = - 1;
	}
	if (keyboardState[SDL_SCANCODE_S])
	{
		paddleDirectionLeft = 1;
	}
	if (keyboardState[SDL_SCANCODE_UP]) {
		paddleDirectionRight = -1;
	}
	if (keyboardState[SDL_SCANCODE_DOWN]) {
		paddleDirectionRight = 1;
	}
}

void Game::update(float dt) {
		//Paddle move Left
		paddlePosLeft += paddleVelocity * dt * paddleDirectionLeft;
		if (paddlePosLeft.y < paddleHeight / 2 + wallThickness) {
			paddlePosLeft.y = paddleHeight / 2 + wallThickness;
		}
		if (paddlePosLeft.y > window.getHeight() - paddleHeight / 2 - wallThickness) {
			paddlePosLeft.y = window.getHeight() - paddleHeight / 2 - wallThickness;
		}

		//Paddle move Right
		paddlePosRight += paddleVelocity * dt * paddleDirectionRight;
		if (paddlePosRight.y < paddleHeight / 2 + wallThickness) {
			paddlePosRight.y = paddleHeight / 2 + wallThickness;
		}
		if (paddlePosRight.y > window.getHeight() - paddleHeight / 2 - wallThickness) {
			paddlePosRight.y = window.getHeight() - paddleHeight / 2 - wallThickness;
		}

	for (int i = 0; i < balls.size(); i++) {
		//Ball move
		balls[i].ballPos += balls[i].ballVelocity * dt;
		if (balls[i].ballPos.y < ballSize / 2 + wallThickness) {
			balls[i].ballPos.y = ballSize / 2 + wallThickness;
			balls[i].ballVelocity.y *= -1;
		}
		else if (balls[i].ballPos.y > window.getHeight() - ballSize / 2 - wallThickness) {
			balls[i].ballPos.y = window.getHeight() - ballSize / 2 - wallThickness;
			balls[i].ballVelocity.y *= -1;
		}

		// Ball-Paddle collision Left
		Vector2 diffLeft = balls[i].ballPos - paddlePosLeft;
		if (fabsf(diffLeft.y) <= paddleHeight / 2
			&& fabsf(diffLeft.x) <= paddleWidth / 2 + ballSize / 2
			&& balls[i].ballVelocity.x < 0)
		{
			balls[i].ballVelocity.x *= -1;
			balls[i].ballPos.x = paddlePosLeft.x + paddleWidth / 2 + ballSize / 2;
		}

		// Ball-Paddle collision Right
		Vector2 diffRight = balls[i].ballPos - paddlePosRight;
		if (fabsf(diffRight.y) <= paddleHeight / 2
			&& fabsf(diffRight.x) <= paddleWidth / 2 + ballSize / 2
			&& balls[i].ballVelocity.x > 0)
		{
			balls[i].ballVelocity.x *= -1;
			balls[i].ballPos.x = paddlePosRight.x - paddleWidth / 2 - ballSize / 2;
		}

		//Restart automatically
		if (balls[i].ballPos.x < 0) {
			balls[i].ballVelocity.x *= -1;
			balls[i].ballPos.x = window.getWidth() / 2.f;
		}
		if (balls[i].ballPos.x > window.getWidth()) {
			balls[i].ballVelocity.x *= -1;
			balls[i].ballPos.x = window.getWidth() / 2.f;
		}
	}
}

void Game::render() {
	renderer.beginDraw();

	renderer.drawRect(topWall);
	renderer.drawRect(bottomWall);

	for (int i = 0; i < balls.size(); i++) {
		Rectangle ballRect = { balls[i].ballPos.x - ballSize / 2, balls[i].ballPos.y - ballSize / 2, ballSize, ballSize };
		renderer.drawRect(ballRect);
	}

	Rectangle paddleRectLeft = { paddlePosLeft.x - paddleWidth / 2, paddlePosLeft.y - paddleHeight / 2, paddleWidth, paddleHeight };
	renderer.drawRect(paddleRectLeft);
	Rectangle paddleRectRight = { paddlePosRight.x - paddleWidth / 2, paddlePosRight.y - paddleHeight / 2, paddleWidth, paddleHeight };
	renderer.drawRect(paddleRectRight);
	

	renderer.endDraw();
}