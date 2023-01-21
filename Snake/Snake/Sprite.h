#pragma once
#include <graphics.h>
#include <conio.h>
#include"Position.h"

class Sprite
{
	//ͼƬ
	IMAGE m_img;
	//ͼƬ��ֵ
	int m_value;
	

public:

	static const int SNAKE_HEAD = 1;
	static const int SNAKE_BODY = 2;
	static const int FOOD = 3;
	//ͼƬ���߼�λ��
	Position m_position;
	//��ʼ��ͼƬ
	void init(int value,Position p);
	//ͼƬ�ļ���
	LPCTSTR image_name(int value);
	//��ȡλ��
	Position get_position() { return m_position; }
	void set_position(Position p,bool is_tail);
};