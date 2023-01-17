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
	case SNAKE_HEAD:return ".//images//snake.png";
	case SNAKE_BODY:return ".//images//body.png";
	case FOOD:return ".//images//food.png";
	default:return 0;
	}
}