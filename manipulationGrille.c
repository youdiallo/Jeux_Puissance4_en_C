#include "main.h"
#include "affichageGrille.h"

void ajouterJeton(int col)
{
	int i;
	for (i = 0; i < HEIGHT; i++)//On part du haut de la colonne et on descend
	{
		if (board[OFFSET + i][col - 1 + OFFSET] != VIDE)// Si l'on peux plus, on break
			break;
		//Animation du jeton qui tombe
		board[OFFSET + i - 1][col - 1  + OFFSET] = VIDE;//On supprime le jeton
		board[OFFSET + i][col - 1  + OFFSET] = player;//On le descend d'une case
		afficherGrille();
		usleep(100000);
	}
	nbToken[col - 1]++;// on ajoute 1 au nombre de jeton de la colonne
	tokens++;//on ajoute 1 au nombre de jeton total
}
