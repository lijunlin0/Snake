class Position
{
public:
	int x;
	int y;
	static const int LOGIC_TO_PIXEL_FACTOR = 32;
	//ÏñËØ×ªÂß¼­
	void from_plotting(int coordinatesX, int coordinatesY);
	//Âß¼­×ªÏñËØ
	void to_plotting(int& coordinatesX, int& coordinatesY);
};