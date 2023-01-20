#include"Position.h"
#include"Map.h"

//�߼�ת����
void Position::to_plotting(int& coordinatesX, int& coordinatesY)
{
	coordinatesX = x * LOGIC_TO_PIXEL_FACTOR;
	coordinatesY = y * LOGIC_TO_PIXEL_FACTOR;
}

//λ���Ƿ�Ϸ�
bool Position::is_valid()
{
	return !(x < 0 || x >= Map::WIDTH || y < 0 || y >= Map::HEIGHT);
}