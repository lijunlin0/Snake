#include"Map.h"
#include"Time.h"
#include<iostream>
#include<cmath>
using namespace std;

Map::Map()
{
	moveMS = 0;
	gap = SNAKE_MOVE_GAP;
	init_snake();
	init_food();
}
void Map::SnakeMove()
{
	cout << "蛇走"<<gap << endl;
}
void Map::update()
{
	if (Time::UpdateMS - moveMS < gap)
	{
		return;
	}
	moveMS = Time::UpdateMS;

	// 蛇走
	SnakeMove();
}

//初始化蛇
void Map::init_snake()
{
	Sprite head;
	Position p1;
	p1.x = WIDTH / 2;
	p1.y = HEIGHT / 2;
	head.init(Sprite::SNAKE_HEAD, p1);
	snake.push_back(head);

	Sprite body1;
	Position p2;
	p2.x = WIDTH / 2-1;
	p2.y = HEIGHT / 2;
	body1.init(Sprite::SNAKE_BODY,p2);
	snake.push_back(body1);

	Sprite body2;
	Position p3;
	p3.x = WIDTH / 2 - 2;
	p3.y = HEIGHT / 2;
	body2.init(Sprite::SNAKE_BODY, p3);
	snake.push_back(body2);
}
//初始化食物
void Map::init_food()
{
	int x = 0;
	int y = 0;
	while (true)
	{
		bool same = false;
		x = rand() % Map::WIDTH;
		y = rand() % Map::HEIGHT;
		for (int i = 0; i < snake.size(); i++)
		{
			if (x == snake[i].get_position().x && y == snake[i].get_position().y)
			{
				same = true;
				break;
			}
		}
		if (!same)
		{
			break;
		}
	}
	Sprite food;
	Position p;
	p.x = x;
	p.y = y;
	food.init(Sprite::FOOD, p);
}