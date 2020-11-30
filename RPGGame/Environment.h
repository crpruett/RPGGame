#pragma once
#include "Sprite.h"
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Tree.h"
#include <vector>;

class Environment
{
public:
	Environment(SDL_Setup* sdl_setup, int passed_ScreenWidth, int passed_ScreenHeight, float* CameraX, float* CameraY);
	~Environment(void);

	void DrawBack();
	void DrawFront();

	void Update();
private:
	SDL_Setup* sdl_setup;
	float* CameraX;
	float* CameraY;

	Sprite* grass[4][7];
	std::vector<Tree*> trees;
	bool Pressed;

};

