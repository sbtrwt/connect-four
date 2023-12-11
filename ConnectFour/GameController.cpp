#include "GameController.h"
#include <iostream>
using namespace std;


void GameController::printData()
{
	for (int i = 0; i < ROW; i++) {
		cout << "\n- - - - - - - - \n";
		cout << "|";
		for (int j = 0; j < COL;j++) {

			cout << data[i][j];
			cout << "|";
		}
	}
	cout << "\n- - - - - - - - \n";
}

void GameController::initData()
{
	player = 1;
	for (int i = 0; i < ROW; i++) {
		
		for (int j = 0; j < COL;j++) {
			data[i][j] = ' ';
		}
	}
	for (int i = 0; i < COL; i++) {
		allColIndex[i] = 0;
	}
}
int GameController::getResult()
{
	//Check for result

	return 0;
}
int GameController::indexIncrement(int index)
{
	if (allColIndex[index] < ROW - 1)
		allColIndex[index]++;
	else {
		cout << "\n Column is full";
		return -1;
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
			cout << "\n Player - 1 : (R) \n";
		}
		else {
			cout << "\n Player - 2 : (B) \n";
		}
		cout << "\n Enter the column number \n";
		getInput();

		//Process 
		int col = int(input - '0');
		if (setData(col) == 0) {
		
			//Check for result
			switch (getResult()) {
				case RED_WON:
					cout << "\nRed won";
					input = 'n';
				break;
				case BLUE_WON:
					cout << "\nBlue won";
					input = 'n';
					break;
				case DRAW:
					cout << "\nDraw";
					input = 'n';
					break;
				default:
					break;
			}
			player *= -1;
		}

	} while (input != 'n' && input != 'N');

	
}

void GameController::getInput()
{
	cin >> input;
}

int GameController::setData(int col)
{
	if (col > 0 && col <= COL) {
		data[(ROW-1) - (allColIndex[col - 1] ) ][col - 1] = (player == 1) ? 'R' : 'B' ;
		return indexIncrement(col-1);
	}
	else {
		cout << "\n Wrong column number \n";
		return -1;
	}

	return 0;
}
