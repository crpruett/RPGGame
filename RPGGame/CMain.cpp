#include "CMain.h"
#include "stdafx.h"
#include "Sprite.h"
using namespace std;
CMain::CMain(int pScreenWidth, int pScreenHeight) {
	ScreenWidth = pScreenWidth;
	ScreenHeight = pScreenHeight;
	quit = false;
	sdl_setup = new SDL_Setup(&quit, ScreenWidth, ScreenHeight);
	
	grass = new Sprite(sdl_setup->GetRenderer(), "C:\\Users\\Ginrai\\Desktop\\Game Programming\\Programming Files\\Game Assets\\grass.bmp", 0, 0, ScreenWidth, ScreenHeight, &CameraX, &CameraY);
	cecil = new Character(sdl_setup, &CameraX, &CameraY);

	CameraX = 0;
	CameraY = 0;
}

CMain::~CMain(void) {
	delete sdl_setup;
	delete grass;
	delete cecil;
}

void CMain::GameLoop(void) { //void isn't necessary but good practice
	//Game Loop
	while (!quit && sdl_setup->GetEvents()->type != SDL_QUIT) { //use arrows for pointers and dots for non-pointers
		sdl_setup->Begin();
		grass->Draw();
		cecil->Draw();

		CameraX += 0.05f;
		//cecil->PlayerAnimation(0, 2, 1, 200); //rows count from 0
		cecil->Update();
		sdl_setup->End(); //Updating the screen
	}
}