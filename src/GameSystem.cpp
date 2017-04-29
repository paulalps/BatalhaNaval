#include <iostream>
#include <cstdlib>

#include "GameSystem.h"

using namespace std;

GameSystem::GameSystem ()
{
	actualRound = 1;
	end = 0;
}

void GameSystem::printMenu ()
{

	cout << "-------------------------------------------------------------" << endl;
	cout << "|       Jogo de Batalha Naval             UFRN 2015.1       |" << endl;
	cout << "-------------------------------------------------------------" << endl;
}

void GameSystem::showWinner ()
{
	cout << "Parabens jogador: " << this->winner+1 << " !" << endl;
}