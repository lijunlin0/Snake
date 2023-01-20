#pragma once
#include"Sprite.h"
#include<vector>
#include<utility>

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
	static const byte KEY_W = 0x57;
	static const byte KEY_A = 0x41;
	static const byte KEY_S = 0x53;
	static const byte KEY_D = 0x44;
	//地图高度
	static const int HEIGHT = 28;
	//地图宽度
	static const int WIDTH = 28;
	//蛇移动间隔
	static const int SNAKE_MOVE_GAP = 300;
	//蛇移动最小间隔
	static const int SNAKE_MOVE_GAP_MIN = 50;
	//进食后减少的间隔量
	static const int SNAKE_MOVE_GAP_SUB = 20;
	Map();
	//更新
	void update();
	//设置蛇的移动方向
	void set_direction(Direction d);

private:
	//蛇
	std::vector<Sprite> snake;
	//食物
	Sprite food;
	//蛇移动方向
	Direction direction;
	//方向是否已经改变
	bool direction_is_changed;
	//上次移动的时间
	long long moveMS;
	//蛇移动的间隔
	int gap;
	//游戏是否结束
	bool is_over;
	//初始化蛇
	void init_snake();
	//初始化食物
	void init_food();
	//获取蛇的当前移动方向对应的移动偏移量
	std::pair<int,int> get_offset();
	//蛇移动
	void SnakeMove();
	//吃食物
	void Eat();
	//死亡
	void Dead();
	//移动
	void Move();
	//播放吃食物音效
	void play_sound();
	

};
