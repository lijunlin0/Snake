#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <thread>
#include"Map.h"
#include"Sprite.h"
#include"Position.h"
#include"Time.h"
using namespace std;

long long Time::UpdateMS = 0;

int main()
{
	srand((unsigned)time(NULL));//根据系统时间改变的随机种子
	//地图大小28*28
	static const int screen_width = Position::LOGIC_TO_PIXEL_FACTOR * Map::WIDTH;
	static const int screen_height = Position::LOGIC_TO_PIXEL_FACTOR * Map::HEIGHT;
	initgraph(screen_width,screen_height);
	Map m;
	while (true)
	{
		long long currentMS = Time::CurrentTime();
		if (currentMS - Time::UpdateMS < Time::FrameMS)
		{
			continue;
		}
		Time::UpdateMS = currentMS;

		//逻辑
		m.update();
	}
	return 0;
}