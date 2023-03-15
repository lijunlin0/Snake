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
	ExMessage msg;//创建消息变量
	while (true)
	{
		bool b = peekmessage(&msg, EX_KEY);
		if (b && msg.message == WM_KEYDOWN)
		{
			if (msg.vkcode == Map::KEY_W)
			{
				m.set_direction(Up);
			}
			if (msg.vkcode == Map::KEY_S)
			{
				m.set_direction(Down);
			}
			if (msg.vkcode == Map::KEY_A)
			{
				m.set_direction(Left);
			}
			if (msg.vkcode == Map::KEY_D)
			{
				m.set_direction(Right);
			}
		}
		long long currentMS = Time::CurrentTime();
		if (currentMS - Time::UpdateMS < Time::FrameMS)
		{
			continue;
		}
		Time::UpdateMS = currentMS;

		BeginBatchDraw();

		//逻辑
		m.update();

		EndBatchDraw();

	}
	return 0;
}