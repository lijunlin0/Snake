#pragma once
#include <graphics.h>
#include <conio.h>
#include"Position.h"

class Sprite
{
	//图片
	IMAGE m_img;
	//图片的值
	int m_value;
	

public:

	static const int SNAKE_HEAD = 1;
	static const int SNAKE_BODY = 2;
	static const int FOOD = 3;
	//图片的逻辑位置
	Position m_position;
	//初始化图片
	void init(int value,Position p);
	//图片文件名
	LPCTSTR image_name(int value);
	//获取位置
	Position get_position() { return m_position; }
	void set_position(Position p,bool is_tail);
};