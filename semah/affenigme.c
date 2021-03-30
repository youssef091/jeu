
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include "affenigme.h"

int afficher_enigme (aff_eng enig)

{
    SDL_Init(SDL_INIT_EVERYTHING);
int i=0,colusion=1;
    
    aff_eng e1 ;
    aff_eng e2 ;
    aff_eng e3 ;
    SDL_Surface *ecran = NULL,*b1 = NULL,*fleche=NULL  ;
    SDL_Rect positionb1;
    SDL_Rect pfleche;
    

    SDL_Event event;
    
    positionb1.x = 0;
    positionb1.y = 0;
    (e1.posenig).x=0;
    (e1.posenig).y=0;
    (e2.posenig).x=0;
    (e2.posenig).y=0;
    (e3.posenig).x=0;
    (e3.posenig).y=0;

    int continuer = 1;
SDL_Init(SDL_INIT_EVERYTHING);

    ecran = SDL_SetVideoMode(1300,720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 

    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);
e1.enig[0]=IMG_Load("bub1.png");
e2.enig[0]=IMG_Load("bub2.png");
e3.enig[0]=IMG_Load("bub3.png");


b1 = IMG_Load("b1.png");

fleche = IMG_Load("fleche.png");  

SDL_ShowCursor(SDL_DISABLE);

    
    
SDL_Flip(ecran);

    SDL_SetColorKey(b1, SDL_SRCCOLORKEY, SDL_MapRGB(b1->format, 255, 255, 255));


    SDL_EnableKeyRepeat(10, 10); 



    while (continuer)

    {
SDL_WaitEvent(&event);
SDL_PollEvent(&event);
switch(event.type)

        {
case SDL_QUIT:

                continuer = 0;

                break;
case SDL_MOUSEMOTION:
            pfleche.x = event.motion.x;
            pfleche.y = event.motion.y;
break;
case SDL_MOUSEBUTTONUP :
          
   continuer = 0;         

break;
         }
 if ((i==0) && (colusion==1))
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[0], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
SDL_Flip(ecran);
if ((i==0) && (colusion==2))        
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e2.enig[0], NULL, ecran,&e2.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
SDL_Flip(ecran);
if ((i==0) && (colusion==3))        
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e3.enig[0], NULL, ecran,&e3.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
SDL_Flip(ecran);


        


}
SDL_FreeSurface (b1);
SDL_FreeSurface(e1.enig[0]);
SDL_FreeSurface(e2.enig[0]);
SDL_FreeSurface(e3.enig[0]);


 SDL_FreeSurface (fleche);


    SDL_Quit();


return EXIT_SUCCESS;
 

}

