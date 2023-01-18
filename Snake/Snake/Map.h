#pragma once
#include"Sprite.h"
#include<vector>
#include<utility>

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
	static const byte KEY_W = 0x57;
	static const byte KEY_A = 0x41;
	static const byte KEY_S = 0x53;
	static const byte KEY_D = 0x44;
	//��ͼ�߶�
	static const int HEIGHT = 28;
	//��ͼ���
	static const int WIDTH = 28;
	//���ƶ����
	static const int SNAKE_MOVE_GAP = 30;
	//���ƶ���С���
	static const int SNAKE_MOVE_GAP_MIN = 50;
	Map();
	//����
	void update();
	//�����ߵ��ƶ�����
	void set_direction(Direction d);

private:
	//��
	std::vector<Sprite> snake;
	//ʳ��
	Sprite food;
	//���ƶ�����
	Direction direction;
	//�����Ƿ��Ѿ��ı�
	bool direction_is_changed;
	//�ϴ��ƶ���ʱ��
	long long moveMS;
	//���ƶ��ļ��
	int gap;
	//��ʼ����
	void init_snake();
	//��ʼ��ʳ��
	void init_food();
	//��ȡ�ߵĵ�ǰ�ƶ������Ӧ���ƶ�ƫ����
	std::pair<int,int> get_offset();
	//���ƶ�
	void SnakeMove();
	

};
