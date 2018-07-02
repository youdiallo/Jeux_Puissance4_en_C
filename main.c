#include "main.h"
#include "jeuPuissance4.h"

int board[LENGTH + 2 * OFFSET][HEIGHT + 2 * OFFSET];
int nbToken[LENGTH];
int tokens;

int player;

int main()
{
	jouerPartiePuissance4();
	return 0;
}
