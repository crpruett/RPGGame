#pragma once
#include "stdafx.h"
class SDL_Setup
{
public:
	SDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight);
	~SDL_Setup(void);

	//creating getters
	SDL_Renderer* GetRenderer();
	SDL_Event* GetEvents();

	void Begin();
	void End();

private:
	bool quit;
	SDL_Window* window;
	SDL_Renderer* renderer; //Creating render pointer
	SDL_Event* events;
};

