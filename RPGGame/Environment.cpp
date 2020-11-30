#include "stdafx.h"
#include "Environment.h"
Environment::Environment(SDL_Setup* passed_sdl_setup, int passed_ScreenWidth, int passed_ScreenHeight, float* passed_CameraX, float* passed_CameraY) {
	sdl_setup = passed_sdl_setup;
	CameraX = passed_CameraX;
	CameraY = passed_CameraY;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			grass[i][j] = new Sprite(sdl_setup->GetRenderer(), "C:\\Users\\Ginrai\\Desktop\\Game Programming\\Programming Files\\Game Assets\\grass.bmp", passed_ScreenWidth * i, passed_ScreenHeight * j, passed_ScreenWidth, passed_ScreenHeight, CameraX, CameraY);
		}
	}

	Pressed = false;
	//for (int i = 0; i < 100; i++) {
	//	trees.push_back(new Tree(300+ (50 * i), 300, CameraX, CameraY, sdl_setup));
	//}

}

Environment::~Environment(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			delete grass[i][j];
		}
	}

	for (std::vector<Tree*>::iterator i = trees.begin(); i != trees.end(); ++i) {
		delete (*i);
	}

	trees.clear();
}

void Environment::DrawBack() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			grass[i][j]->Draw();
		}
	}
	
	//could just not use iterators, but that's okay
	for (std::vector<Tree*>::iterator i = trees.begin(); i != trees.end(); ++i) {
		(*i)->DrawEObject();
	}

}

void Environment::DrawFront() {

}

void Environment::Update() {

	if (sdl_setup->GetEvents()->type == SDL_KEYDOWN) {
		if (!Pressed && sdl_setup->GetEvents()->key.keysym.sym == SDLK_b) {
			trees.push_back(new Tree(-*CameraX + 300, -*CameraY + 250, CameraX, CameraY, sdl_setup));
			Pressed = true;
		}
	}

	if (sdl_setup->GetEvents()->type == SDL_KEYUP) {
		if (Pressed && sdl_setup->GetEvents()->key.keysym.sym == SDLK_b) {
			Pressed = false;
		}
	}
}