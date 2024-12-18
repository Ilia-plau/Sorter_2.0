#include "Game.h"


void Game::Draw() {
	background.Draw1();
	conveyor.Draw3();
	plate.Draw4();
	box.Draw2();
	loaders.Draw5();
}
void Game::Score() {
	if (box.box_x >= 0 && box.box_x <= 150 && box.box_y >=50 && box.box_y <= 150 && box.GetRandomType() == "rbox") {
		score++;
		box.Reset1();
	}
	if (box.box_x >= 0 && box.box_x <= 150 && box.box_y >= 550 && box.box_y <= 700 && box.GetRandomType() == "bbox") {
		score++;
		box.Reset1();
	}
	if (box.box_x >= 700 && box.box_x <= 850 && box.box_y >=550  && box.box_y <= 700 && box.GetRandomType() == "gbox") {
		score++;
		box.Reset1();
	}
	if (box.box_x >= 700 && box.box_x <= 850 && box.box_y >= 50 && box.box_y <= 150 && box.GetRandomType() == "ybox") {
		score++;
		box.Reset1();
	}
}

void Game::Update() {
	if (running) {
		box.Update1(loaders.loaders_y,loaders.loaders_x,loaders.loaders_height,loaders.loaders_width);
		loaders.Update2(box.box_x, box.box_y, box.box_height, box.box_width);
	}
}

void Game::Reset() {
	box.Reset1();
	loaders.Reset2();
}

void Game::Stop() {
	if (IsKeyDown(KEY_TAB) && loaders.EventTriggered1(0.15)) {
		running = false;
	}
}