#pragma once
class GameController
{
	const int ROW = 6;
	const int COL = 7;
	char data[6][7];
	int allColIndex[7];
	char input;
	int player;

public:

	GameController() {
		initData();
	}
	void printData();
	int setData(int col);
	int indexIncrement(int index);
	void showBanner();
	void play();
	void getInput();
	void initData();
	int getResult();
};

enum GAME_RESULT
{
	NONE = 0,
	RED_WON = 1,
	BLUE_WON = 2,
	DRAW = 3
};