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
	direction = Right;
}

//��ȡ�ߵĵ�ǰ�ƶ������Ӧ���ƶ�ƫ����
std::pair<int, int> Map::get_offset()
{
	if (direction == Up)
	{
		return pair<int, int>(0, -1);
	}
	if (direction == Down)
	{
		return pair<int, int>(0, 1);
	}
	if (direction == Left)
	{
		return pair<int, int>(-1, 0);
	}
	if (direction == Right)
	{
		return pair<int, int>(1, 0);
	}
}

//�����ߵ��ƶ�����
void Map::set_direction(Direction d)
{
	cout << "�����޸ķ���Ϊ��" << d << endl;
	if (direction_is_changed == true)
	{
		return;
	}

	Direction prev = direction;
	if (direction == Up&&d!=Down&&d!=Up)
	{
		direction = d;
	}
	else if (direction == Down && d != Up && d != Down)
	{
		direction = d;
	}
	else if (direction == Left && d != Right && d != Left)
	{
		direction = d;
	}
	else if (direction == Right && d != Left && d != Right)
	{
		direction = d;
	}
	//����ı�
	if (prev != direction)
	{
		direction_is_changed = true;
	}
}

void Map::SnakeMove()
{
	cout << "����"<<gap << endl;
	//�����ƶ�
	for (int i = snake.size() - 1; i > 0; i--)
	{
		bool is_tail = i == snake.size() - 1;
		snake[i].set_position(snake[i - 1].m_position,is_tail);
	}
	// ��ͷ�ƶ�
	std::pair<int, int> offset = get_offset();
	Position p1 = snake[0].get_position();
	p1.x += offset.first;
	p1.y += offset.second;
	snake[0].set_position(p1,false);
	direction_is_changed = false;
}
void Map::update()
{
	if (Time::UpdateMS - moveMS < gap)
	{
		return;
	}
	moveMS = Time::UpdateMS;

	// ����
	SnakeMove();
}

//��ʼ����
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
//��ʼ��ʳ��
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