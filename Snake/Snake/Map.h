#pragma once
#include"Sprite.h"
#include<vector>

//蛇头移动方向
enum Direction
{
	Up,
	Down,
	Left,
	Right
};

class Map
{
public:
	//地图高度
	static const int HEIGHT = 28;
	//地图宽度
	static const int WIDTH = 28;
	//蛇移动间隔
	static const int SNAKE_MOVE_GAP = 1000;
	//蛇移动最小间隔
	static const int SNAKE_MOVE_GAP_MIN = 50;
	Map();
	//更新
	void update();

private:
	//蛇
	std::vector<Sprite> snake;
	//食物
	Sprite food;
	//蛇移动方向
	Direction direction;
	//上次移动的时间
	long long moveMS;
	//蛇移动的间隔
	int gap;
	//初始化蛇
	void init_snake();
	//初始化食物
	void init_food();

	
	void SnakeMove();

};
