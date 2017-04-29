#ifndef _GAMESYSTEM_H_
#define _GAMESYSTEM_H_
#include <iostream>
#include <vector>

using namespace std;

class GameSystem
{
	public:
		int actualRound;	// Turno atual
		int end;			// 0 = Mantem o loop, 1 = Termina o jogo
		int winner;			// 0 = Voce, 1 = Inimigo
		
		GameSystem();		// Construtor
		void printMenu();	// Menu inicial
		void showWinner();	// Mostra o vencedor
};

#endif // _GAMESYSTEM_H_
