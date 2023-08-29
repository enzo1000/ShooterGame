#include "Window.h"
#include "Log.h"

//It's better to initialise member variables above the constructor body
Window::Window() : SDLWindow(nullptr), width(WINDOW_WIDTH), height(WINDOW_HEIGHT) {

}

bool Window::initialize() {
	int sdlInitResult = SDL_Init(SDL_INIT_VIDEO);	//Init SDL sys
	if (sdlInitResult != 0) {
		Log::error(LogCategory::Video, "Unable to initialize SDL");
		return false;
	}

	//Create the window (name, positionx, y, dimension, flag).
	SDLWindow = SDL_CreateWindow("Wall Pong", 100, 100, width, height, 0);	//0 for flag
	if (!SDLWindow) {
		Log::error(LogCategory::System, "Failed to create window");
		return false;
	}
	return true;
}

void Window::close() {
	SDL_DestroyWindow(SDLWindow);
}