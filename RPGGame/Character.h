#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "SDL_Setup.h"
#include "Sprite.h"
class Character
{

public:
	 Character(SDL_Setup* passed_SDL_Setup, float* CameraX, float* CameraY);
	 ~Character(void);

	 void Update();
	 void Draw();

private:
	Sprite* cecil;
	int timeCheck;
	bool MovingUp, MovingDown, MovingLeft, MovingRight;//Used for more fluid character movement
	int tickCheck;
	int SpriteRow;
	SDL_Setup* sdl_setup;

	float *CameraX, *CameraY;

};

