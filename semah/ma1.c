
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include "affenigme.h"
#include <time.h>
int main(int argc, char *argv[])
{
	 srand(time(NULL));
aff_eng enig;
int colusion=0;
colusion=rand()%5;
resol_enigme (enig,colusion);
pause();

return EXIT_SUCCESS;
}
