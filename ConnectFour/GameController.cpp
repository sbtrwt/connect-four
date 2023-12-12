#include "GameController.h"
#include <iostream>
using namespace std;


void GameController::printData()
{
	for (int i = 0; i < MAXROW; i++) {
		cout << "\n- - - - - - - - \n";
		cout << "|";
		for (int j = 0; j < MAXCOL;j++) {

			cout << data[i][j];
			cout << "|";
		}
	}
	//cout << "\n- - - - - - - - \n";
	cout << "\n-1-2-3-4-5-6-7- \n";
}

void GameController::initData()
{
	player = 1;
	
	for (int i = 0; i < MAXROW; i++) {

		for (int j = 0; j < MAXCOL;j++) {
			data[i][j] = ' ';
		}
	}
	for (int i = 0; i < MAXCOL; i++) {
		allColIndex[i] = 0;
	}
}
int GameController::getResult()
{

	//Check for result

	 // horizontal check 
	for (int j = 0; j < MAXCOL - 3; j++) {
		for (int i = 0; i < MAXROW; i++) {
			if (data[i][j] == RED && data[i][j + 1] == RED && data[i][j + 2] == RED && data[i][j + 3] == RED) {
				return RED_WON;
			}
			if (data[i][j] == BLUE && data[i][j + 1] == BLUE && data[i][j + 2] == BLUE && data[i][j + 3] == BLUE) {
				return BLUE_WON;
			}
		}
	}
	// vertical check
	for (int i = 0; i < MAXCOL - 3; i++) {
		for (int j = 0; j < MAXROW; j++) {
			if (data[i][j] == RED && data[i + 1][j] == RED && data[i + 2][j] == RED && data[i + 3][j] == RED) {
				return RED_WON;
			}
			if (data[i][j] == BLUE && data[i + 1][j] == BLUE && data[i + 2][j] == BLUE && data[i + 3][j] == BLUE) {
				return BLUE_WON;
			}
		}
	}
	// ascending diagonal check 
	for (int i = 3; i < MAXCOL; i++) {
		for (int j = 0; j < MAXROW - 3; j++) {
			if (data[i][j] == RED && data[i - 1][j + 1] == RED && data[i - 2][j + 2] == RED && data[i - 3][j + 3] == RED)
				return RED_WON;

			if (data[i][j] == BLUE && data[i - 1][j + 1] == BLUE && data[i - 2][j + 2] == BLUE && data[i - 3][j + 3] == BLUE)
				return BLUE_WON;
		}
	}
	// descending diagonal check
	for (int i = 3; i < MAXCOL; i++) {
		for (int j = 3; j < MAXROW; j++) {
			if (data[i][j] == RED && data[i - 1][j - 1] == RED && data[i - 2][j - 2] == RED && data[i - 3][j - 3] == RED)
				return RED_WON;

			if (data[i][j] == BLUE && data[i - 1][j - 1] == BLUE && data[i - 2][j - 2] == BLUE && data[i - 3][j - 3] == BLUE)
				return BLUE_WON;
		}
	}

	//draw Check
	int allInputs = 0;
	for (int i = 0; i < MAXROW; i++) {
		for (int j = 0; j < MAXCOL ; j++) {
			if (data[i][j] != ' ')
				allInputs++;
		}
	}

	if (allInputs >= (MAXROW * MAXCOL))
	return DRAW;

	return NONE;
}
int GameController::indexIncrement(int index)
{
	if (allColIndex[index] >= MAXROW - 1) {
		cout << "\n Column is full";
		return -1;
	}
	if (allColIndex[index] < MAXROW - 1 ) {
		allColIndex[index]++;
		
	}
	
	return 0;
}
void GameController::showBanner()
{
	cout << "\n-----------------------------------------------------------";
	cout << "\n|                                                         |";
	cout << "\n|                 WELCOME TO CONNECT-4 GAME               |";
	cout << "\n|                                                         |";
	cout << "\n-----------------------------------------------------------\n";

	cout << "\n RULES:\n";
	cout << "\n1. Two-player ( Red(R)  & Blue(B) ) game.";
	cout << "\n2. Board size is 6 X 7.";
	cout << "\n3. A player wins if he/she is able to connect 4 dots horizontally, vertically or digonally.";
	cout << "\n4. Draw when the board is fully filled.";

	cout << "\n\n How to Play:\n";
	cout << "\n1. Game always start with player - 1 i.e. Red(R)";
	cout << "\n2. In each step choose the column number in which you want to drop the ball.";
	cout << "\n3. Rows will be filled from bottom to top in any column.";

	cout << "\n\n Press Y to continue or N to exit the game\n";

}

void GameController::play()
{
	if (input == 'n' || input == 'N') {
		return;
	}

	cout << "\n\n---------------------";
	cout << "\n|    GAME STARTS    |";
	cout << "\n---------------------\n";
	do {

		printData();
		if (player == 1) {
			cout << "\n Player - 1 : (R)";
		}
		else {
			cout << "\n Player - 2 : (B)";
		}
		cout << "\n Enter the column number \n";
		getInput();

		//Process 
		int col = int(input - '0');
		if (setData(col) == 0) {
			
			player *= -1;
		}

		//Check for result
		switch (getResult()) {
		case RED_WON:
			printData();
			cout << "\n\n---------------------";
			cout << "\n|       RED WON     |";
			cout << "\n---------------------\n";
			input = 'n';
			break;
		case BLUE_WON:
			printData();
			cout << "\n\n---------------------";
			cout << "\n|      BLUE WON     |";
			cout << "\n---------------------\n";
			input = 'n';
			break;
		case DRAW:
			printData();
			cout << "\n\n---------------------";
			cout << "\n|        DRAW       |";
			cout << "\n---------------------\n";
			input = 'n';
			break;
		default:
			break;
		}
	} while (input != 'n' && input != 'N');
	cout << "\n\n---------------------";
	cout << "\n|     THANK YOU     |";
	cout << "\n|     GAME ENDS     |";
	cout << "\n---------------------\n";

}

void GameController::getInput()
{
	cin >> input;
}

int GameController::setData(int col)
{
	if (col > 0 && col <= MAXCOL) {
		data[(MAXROW - 1) - (allColIndex[col - 1])][col - 1] = (player == 1) ? RED : BLUE;

		return indexIncrement(col - 1);
	}
	else {
		cout << "\n Wrong column number \n";
		return -1;
	}

	return 0;
}
