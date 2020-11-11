#include "stdafx.h"
#include "CMain.h"
using namespace std;
int main(int argc, char *argv[]) {
	//SDL_Init(SDL_INIT_EVERYTHING); //Initalizing SDL
	//Bad Programming practice... so
	SDL_Init(SDL_INIT_VIDEO);

	CMain* cmain = new CMain(600, 600);
	cmain->GameLoop();
	return 0;
}