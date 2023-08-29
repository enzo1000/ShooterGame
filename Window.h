#pragma once
#include <SDL.h>

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

class Window {
public:
	//Its a good habit to always destroy the constructors and
	// the operator of a class that don't use them. (C++ may used them even if you didn't ask for)
	Window();
	Window(const Window&) = delete;
	Window& operator = (const Window&) = delete;

	bool initialize();
	void close();

	SDL_Window* getSDLWindow() const { return SDLWindow; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }

private:
	//We store the SDL_Window pointer into our wrapper class
	SDL_Window* SDLWindow;
	int width;
	int height;
};