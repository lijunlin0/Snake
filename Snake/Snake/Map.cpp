#include"Map.h"
#include"Time.h"
#include<string>
#include<iostream>
#include<cmath>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

Map::Map()
{
	moveMS = 0;
	gap = SNAKE_MOVE_GAP;
	init_snake();
	init_food();
	direction = Right;
	is_over = false;
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
	//��������Ѿ����ı�
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
	direction_is_changed = false;
	//�õ���ͷǰ��λ��
	std::pair<int, int> offset = get_offset();
	Position p1 = snake[0].get_position();
	p1.x += offset.first;
	p1.y += offset.second;

	//ǰ����ƻ��
	if (p1.x == food.get_position().x && p1.y == food.get_position().y)
	{
		Eat();
		return; 
	}

	//ǰ����ǽ��
	if (!p1.is_valid())
	{
		Dead();
		return;
	}
	
	//ǰ��������
	for (int i = 1; i <= snake.size() - 1; i++)
	{
		if (snake[i].get_position().x == p1.x && snake[i].get_position().y == p1.y)
		{
			Dead();
			return;
		}
	}

	//ǰ���ǿյ�
	Move();
}

//����
void Map::Dead()
{
	int x= Position::LOGIC_TO_PIXEL_FACTOR * Map::WIDTH/2;
	int y=Position::LOGIC_TO_PIXEL_FACTOR * Map::HEIGHT/2;
	//������ɫΪ��ɫ
	COLORREF color = RGB(255, 105, 180);
	settextcolor(color);
	settextstyle(64, 0, _T("Consolas"));
	int w=textwidth(" GAME OVER !");
	int h=textheight(" GAME OVER !");
	//��ʾ���� "GAME OVER!"
	outtextxy(x-w/2,y-h/2, " GAME OVER !");
	is_over = true;
}

void Map::Move()
{
	//�����ƶ�
	for (int i = snake.size() - 1; i > 0; i--)
	{
		bool is_tail = i == snake.size() - 1;
		snake[i].set_position(snake[i - 1].m_position, is_tail);
	}
	// ��ͷ�ƶ�
	std::pair<int, int> offset = get_offset();
	Position p1 = snake[0].get_position();
	p1.x += offset.first;
	p1.y += offset.second;
	snake[0].set_position(p1, false);
}

void Map::play_sound()
{
	int audio = rand() % 3;
	switch (audio)
	{
	case 0:PlaySound(("C:/D/GitHub/Snake/Snake/Snake/sound/eat1.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
	case 1:PlaySound(("C:/D/GitHub/Snake/Snake/Snake/sound/eat2.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
	case 2:PlaySound(("C:/D/GitHub/Snake/Snake/Snake/sound/eat3.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
	}
}

//��ʳ��
void Map::Eat()
{
	play_sound();
	std::pair<int, int> offset = get_offset();
	Position p1 = snake[0].get_position();
	Position a;
	a.x = p1.x;
	a.y = p1.y;
	p1.x += offset.first;
	p1.y += offset.second;
	snake[0].set_position(p1,false);

	Sprite body;
	Position p;
	p.x = a.x;
	p.y = a.y;
	body.init(Sprite::SNAKE_BODY, p);
	vector<Sprite>::iterator i = snake.begin();
	i++;
	snake.insert(i, body);
	gap -= SNAKE_MOVE_GAP_SUB;
	init_food();
}
void Map::update()
{
	if (is_over)
	{
		return;
	}
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
	Position p;
	p.x = x;
	p.y = y;
	food.init(Sprite::FOOD, p);
}