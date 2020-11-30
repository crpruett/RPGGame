#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"

class Tree
{
public:
	Tree(int x, int y, float* CameraX, float* CameraY, SDL_Setup* sdl_setup);
	~Tree(void);

	void  DrawEObject();
private:
	Sprite* tree;
};

