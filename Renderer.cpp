#include "Renderer.h"
#include "Log.h"

Renderer::Renderer() : SDLRenderer(nullptr) {

}

bool Renderer::initialize(Window& window) {
	SDLRenderer = SDL_CreateRenderer(window.getSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!SDLRenderer) {
		Log::error(LogCategory::Video, "Failed to create renderer");
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		Log::error(LogCategory::Video, "Unable to initialize SDL_Image");
		return false;
	}
	return true;
}

void Renderer::beginDraw() {	//Initialize the color and clear the screen
	SDL_SetRenderDrawColor(SDLRenderer, 120, 120, 255, 255);	//To set the background color
	SDL_RenderClear(SDLRenderer);
}

void Renderer::endDraw() {	//Update the screen with rendering performed
	SDL_RenderPresent(SDLRenderer);
}

void Renderer::close() {
	SDL_DestroyRenderer(SDLRenderer);
}