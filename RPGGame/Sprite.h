#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
class Sprite
{
public:
	Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, float *CameraX, float *CameraY);
	~Sprite(void);
	void SetX(int X);
	void SetY(int Y);
	void SetPosition(int X, int Y); // For character movement

	int GetX();
	int GetY();

	void Draw();
	void DrawSteady();
	void PlayerAnimation(int FirstFrame, int LastFrame, int Row, float Speed);
private:
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Renderer* renderer;

	int img_width;
	int img_height;
	int currentFrame;
	int animationDelay;

	float* CameraX;
	float *CameraY;
	SDL_Rect Camera;
	//dd
};

