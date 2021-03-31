#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"
#include <SDL/SDL_ttf.h>

int main(int argc, char **argv)
{
  SDL_Surface *screen = NULL, *texte = NULL;
  ;
  SDL_Event event;
  Objet tab[20];
  Objet tab2[20];
  Objet tab3[5];





  int i = 0, running = 1, vie = 0;


  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(1000, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("Animation", NULL);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

  initialiser(tab, tab2);



  SDL_BlitSurface(tab2[0].img, NULL, screen, &tab[i].pos);

 
  
  SDL_EnableKeyRepeat(80, 80);
  while (running)
  {

    deplacement_objet(&screen, tab, tab2, &running, &i);


     SDL_Flip(screen) ;

  }
SDL_Delay(1000) ;

  SDL_Quit();

  return EXIT_SUCCESS;
}
