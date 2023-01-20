#include"Position.h"
#include"Map.h"

//逻辑转像素
void Position::to_plotting(int& coordinatesX, int& coordinatesY)
{
	coordinatesX = x * LOGIC_TO_PIXEL_FACTOR;
	coordinatesY = y * LOGIC_TO_PIXEL_FACTOR;
}

//位置是否合法
bool Position::is_valid()
{
	return !(x < 0 || x >= Map::WIDTH || y < 0 || y >= Map::HEIGHT);
}