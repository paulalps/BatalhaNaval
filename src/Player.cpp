#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

#include "Player.h"

using namespace std;

Player::Player ()
{
	// Gera os vetores necessarios para matriz 
	for (int i = 0; i < 10; i++)
	{
		vector<int> newVector;
		this->board.push_back(newVector);
		ships = 0;
	}

	// Preenche tudo de zero (0)
	this->initializeBoard();
}

void Player::initializeBoard ()
{
	for (int k = 0; k < 10; k++) // Linhas
	{
		for (int i = 0; i < 10; i++) // Colunas
		{
			this->board.at(k).push_back(0); // 0 = Oceano
		}
	}
}

void Player::printBoard ()
{
	for (int k = 0; k < 10; k++) // Linhas
	{
		for (int i = 0; i < 10; i++) // Colunas
		{
			cout << this->board.at(k).at(i) << " ";
		}

		cout << endl;
	}
}

bool Player::checkOccupiedPosition (int x, int y)
{
	if (this->board.at(x).at(y) == 0)
	{
		return 0;
	}
	return 1;
}

bool Player::checkBoard ()
{
	for (int k = 0; k < 8; k++) // Lines
	{
		for (int i = 0; i < 8; i++) // Columns
		{
			if (this->board.at(k).at(i) != 0		// Somente agua
				&& this->board.at(k).at(i) != 9)	// Somente navios abatidos
			{
				return 0;
			}
		}
	}
	return 1;
}

bool Player::placeShip (int type, int direction, int x, int y)
{
	if (direction == 0) // Vertical
	{
		if (type == 1)	// 1x1
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y)) 
			{
				this->board.at(x).at(y) = 1;
				return 1;
			}
		}
		else if (type == 2)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					this->board.at(x).at(y) = 2;
					this->board.at(x+1).at(y) = 2;
					return 1;
				}
			}
			
			return 0;
		}
		else if (type == 3)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					if (!this->checkOccupiedPosition(x+2, y))
					{
						this->board.at(x).at(y) = 3;
						this->board.at(x+1).at(y) = 3;
						this->board.at(x+2).at(y) = 3;
						return 1;
					}
				}
			}
		}
		else if (type == 4)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					if (!this->checkOccupiedPosition(x+2, y))
					{
						if (!this->checkOccupiedPosition(x+3, y))
						{
							this->board.at(x).at(y) = 4;
							this->board.at(x+1).at(y) = 4;
							this->board.at(x+2).at(y) = 4;
							this->board.at(x+3).at(y) = 4;
							return 1;
						}
					}
				}
			}
		}
		else if (type == 5)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					if (!this->checkOccupiedPosition(x+2, y))
					{
						if (!this->checkOccupiedPosition(x+3, y))
						{
							if (!this->checkOccupiedPosition(x+4, y))
							{
								this->board.at(x).at(y) = 5;
								this->board.at(x+1).at(y) = 5;
								this->board.at(x+2).at(y) = 5;
								this->board.at(x+3).at(y) = 5;
								this->board.at(x+4).at(y) = 5;
								return 1;
							}
						}
					}
				}
			}
		}
	}
	else if (direction == 1) // Horizontal
	{
		if (type == 1)	// 1x1
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y)) 
			{
				this->board.at(x).at(y) = 1;
				return 1;
			}
		}
		else if (type == 2)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					this->board.at(x).at(y) = 2;
					this->board.at(x).at(y+1) = 2;
					return 1;
				}
			}
		}
		else if (type == 3)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					if (!this->checkOccupiedPosition(x+2, y))
					{
						this->board.at(x).at(y) = 3;
						this->board.at(x).at(y+1) = 3;
						this->board.at(x).at(y+2) = 3;
						return 1;
					}
				}
			}
		}
		else if (type == 4)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					if (!this->checkOccupiedPosition(x+2, y))
					{
						if (!this->checkOccupiedPosition(x+3, y))
						{
							this->board.at(x).at(y) = 4;
							this->board.at(x).at(y+1) = 4;
							this->board.at(x).at(y+2) = 4;
							this->board.at(x).at(y+3) = 4;
							return 1;
						}
					}
				}
			}
		}
		else if (type == 5)
		{
			// Checa se a posicao esta livre
			if (!this->checkOccupiedPosition(x, y))
			{
				if (!this->checkOccupiedPosition(x+1, y))
				{
					if (!this->checkOccupiedPosition(x+2, y))
					{
						if (!this->checkOccupiedPosition(x+3, y))
						{
							if (!this->checkOccupiedPosition(x+4, y))
							{
								this->board.at(x).at(y) = 5;
								this->board.at(x).at(y+1) = 5;
								this->board.at(x).at(y+2) = 5;
								this->board.at(x).at(y+3) = 5;
								this->board.at(x).at(y+4) = 5;
								return 1;
							}
						}
					}
				}
			}
		}
	}

	return 0; // Error
}

bool Player::attackEnemy (Player& attacked, int x, int y)
{
	if (attacked.board.at(x).at(y) > 0
		&& attacked.board.at(x).at(y) < 6) // Checa se a posicao esta livre
	{
		attacked.board.at(x).at(y) = 9;
		return 1; // Success
	}

	return 0; // Error
}
