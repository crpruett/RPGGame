#include "Character.h"
#include "stdafx.h"


Character::Character(SDL_Setup* passed_SDL_Setup, float *passed_CameraX, float *passed_CameraY) {
	CameraX = passed_CameraX;
	CameraY = passed_CameraY;
	
	sdl_setup = passed_SDL_Setup;
	tickCheck = SDL_GetTicks();
	cecil = new Sprite(sdl_setup->GetRenderer(), "C:\\Users\\Ginrai\\Desktop\\Game Programming\\Programming Files\\Game Assets\\ff42.png", 0, 0, 40, 60, CameraX, CameraY);

}

Character::~Character(void) {
	delete cecil;
}

void Character::Update() {


	switch (sdl_setup->GetEvents()->type) {
	case SDL_KEYDOWN: // If key is pressed. If this is not used, keys are constantly called if any event type.
		switch (sdl_setup->GetEvents()->key.keysym.sym) {
		case SDLK_a:
			MovingLeft = true;
			SpriteRow = 3;
			break;
		case SDLK_d:
			MovingRight = true;
			SpriteRow = 1;
			break;
		case SDLK_w:
			MovingUp = true;
			SpriteRow = 0;
			break;
		case SDLK_s:
			MovingDown = true;
			SpriteRow = 2;
			break;
		default:
			break;
		}

		break;

	case SDL_KEYUP:
		switch (sdl_setup->GetEvents()->key.keysym.sym) {
		case SDLK_a:
			MovingLeft = false;
			break;
		case SDLK_d:
			MovingRight = false;
			break;
		case SDLK_w:
			MovingUp = false;
			break;
		case SDLK_s:
			MovingDown = false;
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
	// SDL_GetTicks(); //Number of seconds since the game started
	//std::cout << tickCheck << std::endl;

	if (tickCheck+5 < SDL_GetTicks()) { //500 is half of a second. So it's in milliseconds.


		if (MovingUp) {
			cecil->SetY(cecil->GetY() - 3);
			cecil->PlayerAnimation(0, 2, SpriteRow, 200); //rows count from 0
			//std::cout << "Testing: MovingUP = " << MovingUp << std::endl;
		}

		if (MovingDown) {
			cecil->SetY(cecil->GetY() + 3);
			cecil->PlayerAnimation(0, 2, SpriteRow, 200); //rows count from 0
		}

		if (MovingRight) {
			cecil->SetX(cecil->GetX() + 3);
			cecil->PlayerAnimation(0, 2, SpriteRow, 200); //rows count from 0
		}

		if (MovingLeft) {
			cecil->SetX(cecil->GetX() - 3);
			cecil->PlayerAnimation(0, 2, SpriteRow, 200); //rows count from 0
		}//Notice there are no "else-if" statements because that would cause only one key to be read at a time.
		cecil->PlayerAnimation(1, 1, SpriteRow, 200); //rows count from 0
		tickCheck = SDL_GetTicks();
	}
}


void Character::Draw() {
	cecil->Draw();
}