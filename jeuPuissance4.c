#include "main.h"
#include "affichageGrille.h"
#include "manipulationGrille.h"

int estCoupGagnant(int col)
{
	//calcule de la position du jeton {x, y}
	int x = OFFSET + HEIGHT - nbToken[col - 1];
	int y = col + OFFSET - 1;

	int somme = 0;
	int i, j;
	// On regarde la diagonale haut-gauche -> bas-droite
	for (j = 0; j < WIN; j++)
	{
		somme = 0;
		for (i = 0; i < WIN; i++)
		{
			somme += board[x - i + j][y - i + j];
		}
		if (somme == WIN || somme == -WIN)
			return 1;
	}
	//On regarde la ligne
	for (j = 0; j < WIN; j++)
	{
		somme = 0;
		for (i = 0; i < WIN; i++)
		{
			somme += board[x][y - i + j];
		}
		if (somme == WIN || somme == -WIN)
			return 1;
	}
	//On regarde la diagonale bas-gauche -> haut-droite
	for (j = 0; j < WIN; j++)
	{
		somme = 0;
		for (i = 0; i < WIN; i++)
		{
			somme += board[x + i - j][y - i + j];
		}
		if (somme == WIN || somme == -WIN)
			return 1;
	}
	somme = 0;
	//On regarde la colonne
	for (j = 0; j < WIN; j++)
	{	
		somme += board[x + j][y];
	}
	if (somme == WIN || somme == -WIN)
		return 1;
	return 0;
}

void analyserFinDePartie(int even)
{
	if (even) // Si égalité
	{
		afficherGrille();
		printf("Egalité !\n");
	}
	else // Sinon on affiche le gagnant
	{
		afficherGrille();
		if (player == YELLOW)
			printf("Le joueur \e[1;33mjaune\e[0m a gagné !\n");
		else
			printf("Le joueur \e[1;31mrouge\e[0m a gagné !\n");
	}
}

int estCoupValide(int col)
{
	if(nbToken[col - 1] >= HEIGHT) // Si la colonne n'est pas pleine
		return 0;
	return 1;
}

int jouerCoupPuissance4()
{
	int i = 0; // = 0 tant que le coup joué n'est pas correcte
	int col = 1;
	int error = 0; // Si il y a une erreur dans l'input de la colonne
	while(!i)
	{
		afficherGrille();
		switch (error) // gestion de l'erreur
		{
		case 1:
			printf("Erreur : colonne %d inexistante !\n", col);
			break;
		case 2:
			printf("Erreur : colonne %d pleine !\n", col);
			break;
		default:
			printf("\n");
		}
		if (player == YELLOW) // affichage du joueur en cours
			printf("\e[1;33mOù souhaitez vous jouer ?\e[0m\n");
		else
			printf("\e[1;31mOù souhaitez vous jouer ?\e[0m\n");
		scanf("%d", &col);
		if (col > LENGTH || col <= 0)
		{	
			error = 1; // => colonne inexistante
			continue;
		}
		i = estCoupValide(col);
		error = 2; // => colonne pleine
	}
	return col;
}

int jouerPartiePuissance4()
{
	player = YELLOW; // Joueur en cours (1 = jaune, -1 = rouge)
	int col;
	int even = 1; // Si égalité ( 1 = oui, 0 = non )
	while (tokens < LENGTH * HEIGHT) //tant que la grille n'est pas pleine
	{
		col = jouerCoupPuissance4();
		ajouterJeton(col);
		if (estCoupGagnant(col))// si un joueur gagne
		{
			even = 0; // un joueur a gagné donc even = 0
			break;
		}
		player *= -1;
	}
	analyserFinDePartie(even);
	return 1;
}
