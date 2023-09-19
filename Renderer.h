#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"

class Renderer
{
public:
	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator = (const Renderer&) = delete;

	bool initialize(Window& window);
	void beginDraw();
	void endDraw();
	void close();

	inline SDL_Renderer* toSDLRenderer() const { return SDLRenderer; }

private:
	SDL_Renderer* SDLRenderer = nullptr;
};