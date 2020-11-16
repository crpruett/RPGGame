#pragma once
#include "Sprite.h"
#include "stdafx.h"
#include "SDL_Setup.h"
class Environment
{
public:
	Environment(SDL_Setup* sdl_setup, int passed_ScreenWidth, int passed_ScreenHeight, float* CameraX, float* CameraY);
	~Environment(void);

	void DrawBack();
	void DrawFront();
private:
	Sprite* grass[4][7];
};

