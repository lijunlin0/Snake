#include"Position.h"

//�߼�ת����
void Position::to_plotting(int& coordinatesX, int& coordinatesY)
{
	coordinatesX = x * LOGIC_TO_PIXEL_FACTOR;
	coordinatesY = y * LOGIC_TO_PIXEL_FACTOR;
}