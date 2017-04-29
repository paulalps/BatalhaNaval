#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <vector>

using namespace std;

class Player
{
	public:
		vector< vector<int> > board;
		int ships;

		Player();
		void initializeBoard();
		void printBoard();
		bool checkOccupiedPosition(int x, int y);
		bool checkBoard();

		bool placeShip(int type, int direction, int x, int y);
		bool attackEnemy(Player& attacked, int x, int y);
};

#endif // _PLAYER_H_
