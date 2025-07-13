prog: main.o function.o personnage.o serie.o ennemi.o
	gcc main.o function.o personnage.o ennemi.o serie.o -o prog -lSDL -lSDL_mixer -lSDL_ttf -lSDL_image -g -lm
function.o:function.c
	gcc -c function.c -g
main.o:main.c
	gcc -c main.c -g
personnage.o: personnage.c
	gcc -c personnage.c
ennemi.o: ennemi.c
	gcc -c ennemi.c -g
serie.o: serie.c
	gcc -c serie.c
