#include <iostream>
#include <cstdlib>
#include <time.h>
#include "GameSystem.h"
#include "Player.h"

using namespace std;

int main ()
{
	// Inicia variaveis dos jogo

	// Semente para gerar numeros aleatorios
	srand(time(NULL));

	// Objetos usados no jogo
	GameSystem gs;
	Player you;
	Player enemy;

	// Variaveis locais para input e calculos
	int inputDirection, inputNumberX, inputNumberY;
	int enemyAttackX, enemyAttackY;


	// Mostra o menu inicial do jogo
	gs.printMenu();

	// Pede para alocar os navios desejados
	while (you.ships < 5)
	{
		// Popula manualmente
		// cout << " Digite a coordenada X e Y para o Navio [" << (you.ships+1) << "] (1x" << (you.ships+1) << "):" << endl;
		// cin >> inputNumberX;
		// cin >> inputNumberY;
		// cout << " Digite a posicao Vertical (0) ou Horizontal (1):" << endl;
		// cin >> inputDirection;

		// // Testa se foi possivel adicionar um navio na posicao desejada
		// if (you.placeShip(you.ships+1, inputDirection, inputNumberX, inputNumberY))
		// {
		// 	cout << "Navio [" << you.ships+1 <<  "] adicionado com sucesso." << endl;
		// 	you.ships++;
		// }
		// else
		// {
		// 	cout << "Nao foi possivel adicionar um navio na posicao desejada." << endl;
		// 	cout << endl;
		// 	cout << "Confira seu tabuleiro:" << endl;
		// 	cout << endl;
		// 	you.printBoard();
		// 	cout << endl;
		// }

		// Popula de uma forma basica (mais rapido para testes)
		if (you.placeShip(you.ships+1, 0, 0, you.ships))
		{
			you.ships++;
		}
	}


	// Aloca os navios inimigos
	while (enemy.ships < 5)
	{
		// if (enemy.placeShip(enemy.ships+1, (rand() % 2), (rand() % 9), (rand() % 9)))
		if (enemy.placeShip(enemy.ships+1, 0, 0, enemy.ships))
		{
			enemy.ships++;
		}
	}


	// Looping entre turnos
	while (!gs.end)
	{
		// Imprime o seu tabuleiro e o numero do turno atual
		cout << "Turno: " << gs.actualRound << endl;
		cout << "Seu Tabuleiro: " << endl;
		you.printBoard();

		// Para casos de Debug, mostrar infos do inimigo
		// cout << "Tabuleiro do inimigo: " << endl;
		// enemy.printBoard();

		// Pergunta onde quer atacar o inimigo
		cout << " Digite as coordenadas de onde quer atacar o inimigo. " << endl;

		// Captura seu input para X
		cin >> inputNumberX;
		// Captura seu input para Y
		cin >> inputNumberY;

		// Tenta atacar baseado nas coordenadas
		if (you.attackEnemy(enemy, inputNumberX, inputNumberY))
		{
			cout << "O inimigo foi acertado com sucesso!" << endl;
		}
		else
		{
			cout << "Voce errou o tiro!" << endl;
		}

		// Testa se o inimigo ainda tem navios
		if (enemy.checkBoard())
		{
			gs.end = 1;
			gs.winner = 0;
			break;
		}

		// Inimigo tenta te atacar
		enemyAttackX = (rand() % 9);
		enemyAttackY = (rand() % 9);
		if (enemy.attackEnemy(you, enemyAttackX, enemyAttackY))
		{
			cout << "O inimigo te atacou em (" << enemyAttackX << ", " << enemyAttackY << ")" << endl;
			cout << "Voce foi acertado com sucesso!" << endl;
		}
		else
		{
			cout << "O inimigo te atacou em (" << enemyAttackX << ", " << enemyAttackY << ")" << endl;
			cout << "O inimigo errou o tiro!" << endl;
		}

		// Testa se voce ainda tem navios
		if (you.checkBoard())
		{
			gs.end = 1;
			gs.winner = 1;
			break;
		}

		// Incrementa o turno
		gs.actualRound++;
	}

	// Mostra o ganhador
	gs.showWinner();

	// Retorno padrão que foi executado OK
	return 0;
}
