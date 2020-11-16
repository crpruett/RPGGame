#include "Environment.h"

Environment::Environment(SDL_Setup* sdl_setup, int passed_ScreenWidth, int passed_ScreenHeight, float* CameraX, float* CameraY) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			grass[i][j] = new Sprite(sdl_setup->GetRenderer(), "C:\\Users\\Ginrai\\Desktop\\Game Programming\\Programming Files\\Game Assets\\grass.bmp", passed_ScreenWidth * i, passed_ScreenHeight * j, passed_ScreenWidth, passed_ScreenHeight, CameraX, CameraY);
		}
	}
}

Environment::~Environment(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			delete grass[i][j];
		}
	}
}

void Environment::DrawBack() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			grass[i][j]->Draw();
		}
	}
}

void Environment::DrawFront() {

}