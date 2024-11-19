#include "Textures.h"

Textures::Textures(){
	loader = LoadTexture(".\\loader.png");
	boxr = LoadTexture(".\\rbox.png");
	boxb = LoadTexture(".\\bbox.png");
	boxg = LoadTexture(".\\gbox.png");
	boxy = LoadTexture(".\\ybox.png");
	plater = LoadTexture(".\\rrplate.png");
	plateb = LoadTexture(".\\bbplate.png");
	plateg = LoadTexture(".\\ggplate.png");
	platey = LoadTexture(".\\yplate.png");
	background = LoadTexture(".\\background.png");
	conveyor = LoadTexture(".\\conveyor.png");
}