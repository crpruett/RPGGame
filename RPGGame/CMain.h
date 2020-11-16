#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Character.h"
#include "Environment.h"

class CMain {
public:
	CMain(int ScreenWidth, int ScreenHeight); //Default constructor
	~CMain(void);//Default destructor to release resources

	void GameLoop();

private:
	Environment* StageArea;

	int ScreenWidth;
	int ScreenHeight;
	bool quit;
	Sprite* grass[4][7];
	Character* cecil;
	SDL_Setup* sdl_setup;

	float CameraX, CameraY;
};

