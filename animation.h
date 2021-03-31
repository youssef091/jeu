#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;

  
}Objet ;

void initialiser (Objet tab [],Objet tab2 [] );
void deplacement_objet(SDL_Surface **screen , Objet tab [],Objet tab2[],int *running,int *i) ;