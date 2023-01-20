#pragma once
class Position
{
public:
	int x;
	int y;
	static const int LOGIC_TO_PIXEL_FACTOR = 32;
	//逻辑转像素
	void to_plotting(int& coordinatesX, int& coordinatesY);
	//位置是否合法
	bool is_valid();
};