#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <thread>
#include"Map.h"
#include"Sprite.h"
#include"Position.h"
using namespace std;
int main()
{
	int screen_width = Position::LOGIC_TO_PIXEL_FACTOR * Map::WIDTH;
	int screen_height = Position::LOGIC_TO_PIXEL_FACTOR * Map::HEIGHT;
	initgraph(screen_width,screen_height);
	while (true)
	{
		this_thread::sleep_for(std::chrono::milliseconds(6));
	}
	system("pause");
	return 0;
}