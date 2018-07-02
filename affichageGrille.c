#include "main.h"

void afficherCase(int couleur)
{
	switch(couleur)
	{
		case VIDE: //On affiche rien
			printf(" ");
			break;
		case YELLOW: //On affiche un jeton jaune
			printf("\e[1;33mO\e[0m");
			break;
		case RED: //On affiche un jeton rouge
			printf("\e[1;31mO\e[0m");
			break;
		default:
			break;
	}
}

void afficherGrille()
{
	int i, j;
	printf("\e[1;1H\e[2J"); // on nettoie le terminale
	for (i = 0; i < HEIGHT; i++)//affichage ligne par ligne
	{
		for (j = 0; j < LENGTH; j++)
			printf("+---");
		printf("+\n");
		for (j = 0; j < LENGTH; j++)
		{
			printf("| ");
			afficherCase(board[i + OFFSET][j + OFFSET]);
			printf(" ");
		}
		printf("|\n");
	}
	for (j = 0; j < LENGTH; j++)
		printf("+---");
	printf("+\n");
	for (i = 0; i < LENGTH; i++) //affichage du numéro de chaque colonne
		printf(" [%d]", i + 1);
	printf("\n");
}
