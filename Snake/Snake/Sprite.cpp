#include"Sprite.h"

//初始化图片
void Sprite::init(int value,Position p)
{
	m_value = value;
	m_position = p;

	int x = 0;
	int y = 0;
	m_position.to_plotting(x, y);
	loadimage(&m_img, image_name(m_value));
	putimage(x, y, &m_img);
}
//图片文件名
LPCTSTR Sprite::image_name(int value)
{
	switch (value)
	{
	case SNAKE_HEAD:return "./images/snake.png";
	case SNAKE_BODY:return "./images/body.png";
	case FOOD:return "./images/food.png";
	default:return 0;
	}
}

void Sprite::set_position(Position p,bool is_tail)
{
	int x = 0;
	int y = 0;
	if (is_tail)
	{
		m_position.to_plotting(x, y);
		clearrectangle(x, y, x + Position::LOGIC_TO_PIXEL_FACTOR, y + Position::LOGIC_TO_PIXEL_FACTOR);
	}
	m_position = p;
	m_position.to_plotting(x, y);
	putimage(x, y, &m_img);
}