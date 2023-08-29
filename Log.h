#pragma once
#include <string>
using std::string;
#include <SDL_log.h>

//Enum are actually intergers from 0 by default (to 8 in this case)
enum class LogCategory
{
	Application = SDL_LOG_CATEGORY_APPLICATION,
	Assert = SDL_LOG_CATEGORY_ASSERT,
	Audio = SDL_LOG_CATEGORY_AUDIO,
	Error = SDL_LOG_CATEGORY_ERROR,
	Input = SDL_LOG_CATEGORY_INPUT,
	Render = SDL_LOG_CATEGORY_RENDER,
	System = SDL_LOG_CATEGORY_SYSTEM,
	Test = SDL_LOG_CATEGORY_TEST,
	Video = SDL_LOG_CATEGORY_VIDEO
};

class Log {
public:
	//Destroying default constructor, copy constructor and assignement operator
	// so they cannot be used
	Log() = delete;
	Log(const Log&) = delete;
	Log& operator = (const Log&) = delete;

	//Static function are callable without instance
	// perfect for a log class without constructor
	static void info(const string& message);
	static void error(LogCategory category, const string& message);
};