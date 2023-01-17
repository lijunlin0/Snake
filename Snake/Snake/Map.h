#pragma once
#include"Sprite.h"
#include<vector>

//��ͷ�ƶ�����
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
	//��ͼ�߶�
	static const int HEIGHT = 28;
	//��ͼ���
	static const int WIDTH = 28;
	//���ƶ����
	static const int SNAKE_MOVE_GAP = 1000;
	//���ƶ���С���
	static const int SNAKE_MOVE_GAP_MIN = 50;
	Map();
	//����
	void update();

private:
	//��
	std::vector<Sprite> snake;
	//ʳ��
	Sprite food;
	//���ƶ�����
	Direction direction;
	//�ϴ��ƶ���ʱ��
	long long moveMS;
	//���ƶ��ļ��
	int gap;
	//��ʼ����
	void init_snake();
	//��ʼ��ʳ��
	void init_food();

	
	void SnakeMove();

};
