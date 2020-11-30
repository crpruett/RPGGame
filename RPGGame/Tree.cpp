#include "Tree.h"
Tree::Tree(int x, int y, float* CameraX, float* CameraY, SDL_Setup* sdl_setup) {
	tree = new Sprite(sdl_setup->GetRenderer(), "C:\\Users\\Ginrai\\Desktop\\Game Programming\\Programming Files\\Game Assets\\tree.png", x, y, 43, 145, CameraX, CameraY);
}

Tree::~Tree(void) {
	delete tree;
}

void Tree::DrawEObject() {
	tree->Draw();
}