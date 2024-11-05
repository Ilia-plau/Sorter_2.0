#include "Box.h"
#include <raylib.h>

/*double lastUpdateTime2 = 0;

bool EventTriggered2(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime2 >= interval)
	{
		lastUpdateTime2 = currentTime;
		return true;
	}
	return false;
}*/

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
}

void Box::Update1(float loaders_y, float loaders_x, float loaders_height, float loaders_width) {
	/*if ((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_W) && !(IsKeyDown(KEY_S) || IsKeyDown(KEY_D) || IsKeyDown(KEY_A)) && loaders.EventTriggered1(0.15) && box_y - 100 >= 25) {
			box_y -= speed;
		}
		if ((IsKeyDown(KEY_S) && !(IsKeyDown(KEY_W) || IsKeyDown(KEY_D) || IsKeyDown(KEY_A))) && loaders.EventTriggered1(0.15) && box_y + 150 <= 700) {
			box_y += speed;
		}
		if ((IsKeyDown(KEY_A) && !(IsKeyDown(KEY_W) || IsKeyDown(KEY_D) || IsKeyDown(KEY_S))) && loaders.EventTriggered1(0.15) && box_x - 50 >= 25) {
			box_x -= speed;
		}
		if ((IsKeyDown(KEY_D) && !(IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A))) && loaders.EventTriggered1(0.15) && box_x + 150 <= 850) {
			box_x += speed;
		}
	}*/
	if ((2 * loaders_y + loaders_height) / 2-50 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2) {
		if (/*IsKeyDown(KEY_W) && !(IsKeyDown(KEY_S) || IsKeyDown(KEY_D) || IsKeyDown(KEY_A)) && loaders.EventTriggered1(0.5) && */box_y - 100 >= 25 && f == 0) {
			box_y -= 2;
			w = true;
			f++;
			return;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 + 50 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2) {
		if (/*IsKeyDown(KEY_S) && !(IsKeyDown(KEY_W) || IsKeyDown(KEY_D) || IsKeyDown(KEY_A)) && loaders.EventTriggered1(0.5) && */box_y + 150 <= 700 && f == 0) {
			box_y += 2;
			s = true;
			f++;
			return;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 - 50  == (2 * box_x + box_width) / 2) {
		if (/*IsKeyDown(KEY_A) && !(IsKeyDown(KEY_S) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W)) && loaders.EventTriggered1(0.5) && */box_x - 50 >= 25 && f == 0) {
			box_x -= 2;
			a = true;
			f++;
			return;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 + 50  == (2 * box_x + box_width) / 2) {
		if (/*IsKeyDown(KEY_D) && !(IsKeyDown(KEY_S) || IsKeyDown(KEY_W) || IsKeyDown(KEY_A)) && loaders.EventTriggered1(0.5) && */box_x + 150 <= 850 && f == 0) {
			box_x += 2;
			d = true;
			f++;
			return;
		}
	}

	if (f > 0) {
		if (w)
		{
			box_y -= 2;
			f++;
			if (f == 25) {
				f = 0;
				w = false;
				return;
			}
			return;
		}
		if (s)
		{
			box_y += 2;
			f++;
			if (f == 25) {
				f = 0;
				s = false;
				return;
			}
			return;
		}
		if (a)
		{
			box_x -= 2;
			f++;
			if (f == 25) {
				f = 0;
				a = false;
				return;
			}
			return;
		}
		if (d)
		{
			box_x += 2;
			f++;
			if (f == 25) {
				f = 0;
				d = false;
				return;
			}
			return;
		}
	}
	if (box_x < 200 && box_y == 150) {
	box_x += 0.5;
	}
}
string Box::GetRandomType() {
	if (count == 0) {
		tmp = GetRandomValue(1, 3);
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
};
void Box::Reset1() {
	box_x = 50;
	box_y = 150;
	box_width = 50;
	box_height = 50;
	speed = 50;
	count = 0;
}
