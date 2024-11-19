// Sorter2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "Game.h"



#define RAYGUI_IMPLEMENTATION

using namespace std;


int main()
{
	Color Dark_Green = Color{ 20, 160, 133, 255 };
	const float screenWidth = 850;
	const float screenHeight = 700;
	InitWindow(screenWidth, screenHeight, "My first program!");
	Game game = Game();

	SetTargetFPS(60);
	game.Reset();
	while (WindowShouldClose() == false)
	{

		game.Score();
		game.Draw();
		game.Update();
		game.Stop();

		DrawText(TextFormat("%i", game.score), 162.5, 12.5, 30, BLACK);
		DrawText(TextFormat("%s", "score:"), 55, 12.5, 30, BLACK);
		ClearBackground(GREEN);
		EndDrawing();

	}
	CloseWindow();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
