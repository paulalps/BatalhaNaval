# Projeto: Batalha Naval
Neste projeto pretendemos fazer um jogo em C++ orientado a objetos utilizando a biblioteca gráfica Allegro para fazer um jogo de __Batalha Naval__ simples.

## Arquitetura
* __Sistema operacional:__ Multi-plataforma (Windows, Linux, Mac OS)
* __Linguagem de programação:__ C++
* __Framework usado:__ Allegro

## Instalação
1. Copie a pasta instalada para onde tiver permissão de executar. Ex.: ``C:\BatalhaNaval\`` ou ``~/BatalhaNaval``.
2. Rode o binário ``batalha_naval.exe`` (Windows) ou ``batalha_naval`` (Mac OS X ou Linux).

## Regras do jogo
* Esta versão possui apenas __2 jogadores__, __você__ e o __computador__.
* O tabuleiro de cada é uma __matriz 10 x 10__, devendo ser expresso por X e Y sendo __inteiros__ de 0 a 9.
* Cada jogador deverá no __início do jogo__ posicionar __5 navios__, variando o tamanho de 1x1 a 1x5.
* O jogo __não__ possui um limite de turnos, sendo um turno composto por __uma ação para cada jogador__.
* Vence o jogador que acertar todos os pontos do tabuleiro do inimigo que houver um navio ou parte dele.
* Trivia:
	* O menor tempo de jogo é 15 turnos.
	* Se conseguir saia e jogue na mega-sena ;)

## Lógica programacional
### Objetos:
* Jogador (__Player__):
	* __vector< vector ``<int>`` >__ ``board``;
	* __void__ ``initializeBoard()``;
	* __void__ ``printBoard()``;
	* __bool__ ``checkOccupiedPosition(int x, int y)``;
		* Retorna 0/False se não tinha nada no local.
		* Retorna 1/True se tinha algo no local.
	* __bool__ ``checkBoard()``;
		* Retorna 0/False se o tabuleiro ainda possuir navios.
		* Retorna 1/True se o tabuleiro estiver com todos os navios abatidos.
	* __bool__ ``placeShip(int type, int direction, int line, int column)``;
		* Retorna 0/false se não foi possivel alocá-lo.
		* Retorna 1/true se foi possivel alocá-lo.
	* __bool__ ``attackEnemy(int line, int column)``;
		* Retorna 0/false se errou o alvo.
		* Retorna 1/true se o alvo foi atacado com sucesso.
* Sistema (__GameSystem__):
	* __void__ ``printMenu()``;
		* Mostra o menu inicial do jogo.
	* __void__ ``showWinner()``;
		* Mostra quem foi o vencedor do jogo.


### Informações:
* __Navio__:
	* __int__ type;
		* 1 = 1x1;
		* 2 = 1x2;
		* 3 = 1x3;
		* 4 = 1x4;
		* 5 = 1x5;
	* __int__ direction;
		* 0 = vertical;
		* 1 = horizontal;
	* __int__ x, y;

* __Tabuleiro__ (legenda para __Console__):
	* 0 = Água
	* 1 = Navio 1x1
	* 2 = Navio 1x2
	* 3 = Navio 1x3
	* 4 = Navio 1x4
	* 5 = Navio 1x5
	* 9 = Navio abatido

## Autores
* Ana Paula Lopes de Souza
* Henrique Maraschin Granja

## Créditos extras
* Imagens dos navios [link](http://opengameart.org/content/battleships)