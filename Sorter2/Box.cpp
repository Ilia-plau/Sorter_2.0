#include "Box.h"
#include <raylib.h>

void Box::Draw2(){
	if (GetRandomType() == "rbox") {
		DrawTexture(boxr, box_x, box_y, WHITE);
	}
	if (GetRandomType() == "bbox") {
		DrawTexture(boxb, box_x, box_y, WHITE);
	}
	if (GetRandomType() == "gbox") {
		DrawTexture(boxg,box_x,box_y, WHITE);
	}
	if (GetRandomType() == "ybox") {
		DrawTexture(boxy, box_x, box_y, WHITE);
	}
}

void Box::Update1(float loaders_y, float loaders_x, float loaders_height, float loaders_width) {
	if ((2 * loaders_y + loaders_height) / 2-50 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_W) && !(IsKeyDown(KEY_S) || IsKeyDown(KEY_D) || IsKeyDown(KEY_A)) && loaders.EventTriggered1(0.43) && box_y > 50 && f == 0) {
			box_y -= 2;
			w = true;
			f++;
			return;
		}
		if (box_y <= 50 and !(IsKeyDown(KEY_W))) {
			box_y = 700;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 + 50 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_S) && !(IsKeyDown(KEY_W) || IsKeyDown(KEY_D) || IsKeyDown(KEY_A)) && loaders.EventTriggered1(0.43) && box_y < 700 && f == 0) {
			box_y += 2;
			s = true;
			f++;
			return;
		}
		if (box_y>=700 and !(IsKeyDown(KEY_S))) {
			box_y = 50;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 - 50  == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_A) && !(IsKeyDown(KEY_S) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W)) && loaders.EventTriggered1(0.43) && box_x >0 && f == 0) {
			box_x -= 2;
			a = true;
			f++;
			return;
		}
		if (box_x<=0 and !(IsKeyDown(KEY_A))) {
			box_x = 850;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 + 50  == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_D) && !(IsKeyDown(KEY_S) || IsKeyDown(KEY_W) || IsKeyDown(KEY_A)) && loaders.EventTriggered1(0.43) && box_x < 850 && f == 0) {
			box_x += 2;
			d = true;
			f++;
			return;
		}
		if (box_x>=850 and !(IsKeyDown(KEY_D))) {
			box_x = 0;
		}
	}
	if (f > 0) {
		if (w || s || a || d) {
			if (w) {
				box_y -= 2;
			}
			if (s) {
				box_y += 2;
			}
			if (a) {
				box_x -= 2;
			}
			if (d) {
				box_x += 2;
			}
			f++;
			if (f == 25) {
				f = 0;
				w = false;
				s = false;
				a = false;
				d = false;
				return;
			}
			return;
		}

	}
	if (box_x < 200 && box_y == 350) {
	box_x += 0.5;
	}
}
string Box::GetRandomType() {
	if (count == 0) {
		tmp = GetRandomValue(1, 4);
		count += 1;
	}
	if (tmp == 1) {
		return "rbox";
	}
	if (tmp == 2) {
		return "bbox";
	}
	if (tmp == 3) {
		return "gbox";
	}
	if (tmp == 4) {
		return "ybox";
	}
};
void Box::Reset1() {
	box_x = 50;
	box_y = 350;
	box_width = 50;
	box_height = 50;
	speed = 50;
	count = 0;
}
