#include "Loaders.h"

bool Loaders::EventTriggered1(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime1 >= interval)
	{
		lastUpdateTime1 = currentTime;
		return true;
	}
	return false;
}

void Loaders::Draw5(){
	DrawTexture(loader, loaders_x, loaders_y, WHITE);
}

void Loaders::Update2(float box_x,float box_y,float box_height,float box_width) {
	//Нажали
	//Не зависимо нажали или нет
	//Двигаемся в эту сторону
	if (IsKeyDown(KEY_W)) {
		if (IsKeyDown(KEY_W) && EventTriggered1(0.43) && frame == 0 && loaders_y > 50) {
			loaders_y -= 2;
			w = true;
			frame++;
			return;
		}
		if (loaders_y <= 50) {
			loaders_y = 700;
		}
	}
	if (IsKeyDown(KEY_S)) {
		if (IsKeyDown(KEY_S) && EventTriggered1(0.43) && frame == 0 && loaders_y < 700) {
			loaders_y += 2;
			s = true;
			frame++;
			return;
		}
		if (loaders_y >= 700) {
			loaders_y = 50;
		}
	}
	if (IsKeyDown(KEY_A)) {
		if (IsKeyDown(KEY_A) && EventTriggered1(0.43) && frame == 0 && loaders_x >0) {
			loaders_x -= 2;
			a = true;
			frame++;
			return;
		}
		if (loaders_x<=0) {
			loaders_x = 850;
		}
	}
	if (IsKeyDown(KEY_D)) {
		if (IsKeyDown(KEY_D) && EventTriggered1(0.43) && frame == 0 && loaders_x<850) {
			loaders_x += 2;
			d = true;
			frame++;
			return;
		}
		if (loaders_x>=850) {
			loaders_x = 0;
		}
	}

	if (frame > 0) {
		if (w || s || a || d) {
			if (w) {
				loaders_y -= 2;
			}
			if (s) {
				loaders_y += 2;
			}
			if (a) {
				loaders_x -= 2;
			}
			if (d) {
				loaders_x += 2;
			}
			frame++;
			if (frame == 25) {
				frame = 0;
				w = false;
				s = false;
				a = false;
				d = false;
				return;
			}
			return;
		}
		
	}
	if (loaders_y == 350 && loaders_x < 200) {
		loaders_x += 1;
	}
}

void Loaders::Reset2() {
	loaders_x = GetScreenWidth() / 2 - 25;
	loaders_y = (GetScreenHeight() - 50) / 2 - 25;
	speed = 50;
}