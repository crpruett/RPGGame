#include "Sprite.h"
#include "stdafx.h"
using namespace std;

Sprite::Sprite(SDL_Renderer* passed_renderer, string FilePath, int x, int y, int w, int h, int *passed_CameraX, int *passed_CameraY) {
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());

	//Check if the images are loaded correctly
	if (image == NULL) {
		cout << "Couldn't load " << FilePath.c_str() << endl;
	}

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	//Queries a texture and gets its width and height
	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);
	
	crop.x = 0;
	crop.y = 0;
	crop.w = img_width/2;
	crop.h = img_height;

	currentFrame = 0;

	CameraX = passed_CameraX;
	CameraY = passed_CameraY;

	Camera.x = rect.x + *CameraX;
	Camera.y = rect.y + *CameraY;
	Camera.w = rect.w;
	Camera.h = rect.h;
}

Sprite::~Sprite(void) {
	SDL_DestroyTexture(image);
}

void Sprite::Draw() {
	Camera.x = rect.x + *CameraX;
	Camera.y = rect.y + *CameraY;
	
	SDL_RenderCopy(renderer, image, &crop, &Camera); //Copies image/texture to renderer for the RenderPresent
} //Replaced the third parameter (NULL) which is used for cropping images.

void Sprite::SetX(int X) {
	rect.x = X;
}

void Sprite::SetY(int Y) {
	rect.y = Y;
}

void Sprite::SetPosition(int X, int Y) {
	rect.x = X;
	rect.y = Y;
}

int Sprite::GetX() {
	return rect.x;
}

int Sprite::GetY() {
	return rect.y;
}

void Sprite::PlayerAnimation(int FirstFrame, int LastFrame, int Row, float Speed) {
	if (animationDelay + Speed < SDL_GetTicks()) {
		if (LastFrame <= currentFrame) {
			currentFrame = FirstFrame;

		}
		else {
			currentFrame++;
		}
		crop.y = Row * (img_height / 8);
		crop.x = currentFrame * (img_width / 12);
		crop.w = img_width / 12;
		crop.h = img_height / 8;
		//cout << crop.w << endl << crop.h;
		animationDelay = SDL_GetTicks();
	}
}