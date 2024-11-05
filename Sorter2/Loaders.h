#ifndef LOADERS_H
#define LOADERS_H

#include <iostream>
#include <raylib.h>
#include <string>
#include <deque>
#include <raymath.h>
#include "Textures.h"
//#include "Box.h"

using namespace std;

class Loaders : public Textures{
public:

	float loaders_x;
	float loaders_y;
	int loaders_width = 50;
	int loaders_height = 50;
	int speed = 50;
	int c = 0;
	int frame = 0;
	bool w = false;
	bool a = false;
	bool s = false;
	bool d = false;
	double lastUpdateTime1 = 0;
	//Box box = Box();

	bool EventTriggered1(double interval);
	void Draw5();
	void Update2(float box_x, float box_y, float box_height, float box_width);
	void Reset2();
};

#endif
