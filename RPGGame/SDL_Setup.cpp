#include "SDL_Setup.h"
#include "stdafx.h"
using namespace std;

SDL_Setup::SDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight) { //might have to pass a pointer to quit as a parameter
	window = NULL;
	window = SDL_CreateWindow("RPG Game!", 120, 120, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		cout << "Error: Window Couldn't Be Created!";
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	events = new SDL_Event();
}

SDL_Setup::~SDL_Setup(void) {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete events;
}

//Getter methods
SDL_Renderer* SDL_Setup::GetRenderer() {

	return renderer;
}

SDL_Event* SDL_Setup::GetEvents() {
	return events;
}

void SDL_Setup::Begin() {
	SDL_PollEvent(GetEvents()); //Updates events. Could just say "events"
	SDL_RenderClear(GetRenderer()); //Clears the screen. Could just say "renderer"
}

void SDL_Setup::End() {
	SDL_RenderPresent(GetRenderer()); //Updating the screen
}