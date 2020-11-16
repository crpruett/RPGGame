#include "CMain.h"
#include "stdafx.h"
#include "Sprite.h"
#include "Environment.h"

using namespace std;
CMain::CMain(int pScreenWidth, int pScreenHeight) {
	
	ScreenWidth = pScreenWidth;
	ScreenHeight = pScreenHeight;
	quit = false;
	sdl_setup = new SDL_Setup(&quit, ScreenWidth, ScreenHeight);
	

	cecil = new Character(sdl_setup, &CameraX, &CameraY);

	CameraX = 0;
	CameraY = 0;

	StageArea = new Environment(sdl_setup, ScreenWidth, ScreenHeight, &CameraX, &CameraY);
}

CMain::~CMain(void) {
	delete sdl_setup;
	
	delete cecil;
}

void CMain::GameLoop(void) { //void isn't necessary but good practice
	//Game Loop
	while (!quit && sdl_setup->GetEvents()->type != SDL_QUIT) { //use arrows for pointers and dots for non-pointers
		sdl_setup->Begin();
		//grass->Draw();
		StageArea->DrawBack();
		cecil->Draw();
		cecil->Update();

		StageArea->DrawFront(); //Front area drawn after everything else 
		sdl_setup->End(); //Updating the screen
	}
}