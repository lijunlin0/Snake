#pragma once
class Position
{
public:
	int x;
	int y;
	static const int LOGIC_TO_PIXEL_FACTOR = 32;
	//�߼�ת����
	void to_plotting(int& coordinatesX, int& coordinatesY);
	//λ���Ƿ�Ϸ�
	bool is_valid();
};