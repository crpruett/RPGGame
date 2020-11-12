#include "CMain.h"
#include "stdafx.h"
#include "Sprite.h"

using namespace std;
CMain::CMain(int pScreenWidth, int pScreenHeight) {
	
	ScreenWidth = pScreenWidth;
	ScreenHeight = pScreenHeight;
	quit = false;
	sdl_setup = new SDL_Setup(&quit, ScreenWidth, ScreenHeight);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			grass[i][j] = new Sprite(sdl_setup->GetRenderer(), "C:\\Users\\Ginrai\\Desktop\\Game Programming\\Programming Files\\Game Assets\\grass.bmp", ScreenWidth * i, ScreenHeight * j, ScreenWidth, ScreenHeight, &CameraX, &CameraY);
		}
	}

	cecil = new Character(sdl_setup, &CameraX, &CameraY);

	CameraX = 0;
	CameraY = 0;
}

CMain::~CMain(void) {
	delete sdl_setup;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			delete grass[i][j];
		}
	}
	delete cecil;
}

void CMain::GameLoop(void) { //void isn't necessary but good practice
	//Game Loop
	while (!quit && sdl_setup->GetEvents()->type != SDL_QUIT) { //use arrows for pointers and dots for non-pointers
		sdl_setup->Begin();
		//grass->Draw();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 7; j++) {
				grass[i][j]->Draw();
			}
		}
		cecil->Draw();
		cecil->Update();
		sdl_setup->End(); //Updating the screen
	}
}