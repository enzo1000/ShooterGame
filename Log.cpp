#include "Log.h"
#include <SDL_log.h>
#include <SDL_error.h>

//c_str() ends a string with \0 and make it c compatible
void Log::info(const string & message) {
	SDL_Log(message.c_str());
}

void Log::error(LogCategory category, const string& message) {
	SDL_LogError(static_cast<int>(category), "%s | SDL: %s", message.c_str(), SDL_GetError());
}