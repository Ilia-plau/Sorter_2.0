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
	if (IsKeyDown(KEY_W) && EventTriggered1(0.15) && c==0 && loaders_y - 50 >= 25) {
		if (c==0) {
			loaders_y -= 5;
			c += 1;
		}
		if (c==1) {
			loaders_y -= 40;
			c += 1;
		}
		if (c==2) {
			loaders_y -= 5;
			c = 0;
		}
	}
	if (IsKeyDown(KEY_S) && EventTriggered1(0.15) && c == 0 && loaders_y + 100 <= 700) {
		if (c == 0) {
			loaders_y += 5;
			c += 1;
		}
		if (c == 1) {
			loaders_y += 40;
			c += 1;
		}
		if (c == 2) {
			loaders_y += 5;
			c = 0;
		}
	}
	if (IsKeyDown(KEY_A) && EventTriggered1(0.15) && c == 0 && loaders_x >= 25) {
		if (c == 0) {
			loaders_x -= 5;
			c += 1;
		}
		if (c == 1) {
			loaders_x -= 40;
			c += 1;
		}
		if (c == 2) {
			loaders_x -= 5;
			c = 0;
		}
	}
	if (IsKeyDown(KEY_D) && EventTriggered1(0.15) && c == 0 && loaders_x + 100 <= 850) {
		if (c == 0) {
			loaders_x += 5;
			c += 1;
		}
		if (c == 1) {
			loaders_x += 40;
			c += 1;
		}
		if (c == 2) {
			loaders_x += 5;
			c = 0;
		}
	}
	/*if (!((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2)) {
		if (IsKeyDown(KEY_W) && EventTriggered1(0.15) && loaders_y - 50 >= 25) {
			loaders_y -= speed;
		}
		if (IsKeyDown(KEY_S) && EventTriggered1(0.15) && loaders_y + 100 <= 700) {
			loaders_y += speed;
		}
		if (IsKeyDown(KEY_A) && EventTriggered1(0.15) && loaders_x >= 25) {
			loaders_x -= speed;
		}
		if (IsKeyDown(KEY_D) && EventTriggered1(0.15) && loaders_x + 100 <= 850) {
			loaders_x += speed;
		}
		if (loaders_y == 150 && loaders_x < 200) {
			loaders_x += 0.5;
		}
	}*/
}

void Loaders::Reset2() {
	loaders_x = GetScreenWidth() / 2 - 25;
	loaders_y = (GetScreenHeight() - 50) / 2 - 25;
	speed = 50;
}