animation:main.o animation.o 
	gcc   main.o animation.o -o animation -lSDL -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -g

animation.o:animation.c
	gcc -c animation.c -g 
