GCC_FLAGS = -Wall -g

all : puissance4

affichageGrille.o : affichageGrille.c
	gcc -c affichageGrille.c ${GCC_FLAGS}

manipulationGrille.o : manipulationGrille.c
	gcc -c manipulationGrille.c ${GCC_FLAGS}

jeuPuissance4.o : jeuPuissance4.c
	gcc -c jeuPuissance4.c ${GCC_FLAGS}

main.o : main.c
	gcc -c main.c ${GCC_FLAGS}

puissance4 : affichageGrille.o manipulationGrille.o jeuPuissance4.o main.o
	gcc -o puissance4 affichageGrille.o manipulationGrille.o jeuPuissance4.o main.o ${GCC_FLAGS}

clean :
	rm -f puissance4 *.o

re : clean all