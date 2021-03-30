
#ifndef AFFENIGME_H_INCLUDED
#define AFFENIGME_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct aff_eng
{
    SDL_Surface* enig[4] ;
    SDL_Rect posenig ;
} aff_eng;

int afficher_enigme (aff_eng enig );
int resol_enigme (aff_eng enig , int colusion );
void pause();

#endif
