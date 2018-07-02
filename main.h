#include <stdio.h>
#include <unistd.h>

#define LENGTH 8 // longueur du board
#define HEIGHT 7 // largeur
#define WIN 4 // nombre de jeton à aligner pour gagner
#define OFFSET ((WIN) - 1) // décalage (cf énoncé)

#define YELLOW 1
#define RED -1
#define VIDE 0

extern int board[LENGTH + 2 * OFFSET][HEIGHT + 2 * OFFSET];
extern int nbToken[LENGTH]; // nombre de jeton sur chaque colonnes
extern int tokens; // nombre de jeton total

extern int player; // joueur en cours
