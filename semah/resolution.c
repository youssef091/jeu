
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "affenigme.h"

int resol_enigme (aff_eng enig , int colusion)

{
    SDL_Init(SDL_INIT_EVERYTHING);
int i=0,exit=0,mus=1 , faux=0 ;
    aff_eng e1 ,e3 , e2 , e4 , e5  ;
    SDL_Surface *ecran = NULL,*b1 = NULL,*fleche=NULL  ;
    SDL_Rect positionb1;
    SDL_Rect pfleche;
    Mix_Music *music , *music1;
    

    SDL_Event event;
    
    positionb1.x = 0;
    positionb1.y = 0;
    (e1.posenig).x=0;
    (e1.posenig).y=0;
    (e2.posenig).x=0;
    (e2.posenig).y=0;

    int continuer = 1;
SDL_Init(SDL_INIT_EVERYTHING);

    ecran = SDL_SetVideoMode(1300,720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 
    srand(time NULL);
    //colusion=rand() % 5+0 ;
    //colusion=5;
    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);
e1.enig[0]=IMG_Load("bub1.png");
e1.enig[1]=IMG_Load("enig1.png");
e1.enig[2]=IMG_Load("e1true.png");
e1.enig[3]=IMG_Load("e1false.png");
e2.enig[1]=IMG_Load("enig2.png");
e2.enig[2]=IMG_Load("e2true.png");
e3.enig[1]=IMG_Load("enig3.png");
e3.enig[2]=IMG_Load("e3true.png");
e4.enig[1]=IMG_Load("enig4.png");
e4.enig[2]=IMG_Load("e4true.png");
e5.enig[1]=IMG_Load("enig5.png");
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)

   {

      printf("%s", Mix_GetError());

   }
music = Mix_LoadMUS("true1.mp3");
music1 = Mix_LoadMUS("wha.mp3");



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
if (( pfleche.x > 575 ) && ( pfleche.y > 250 ) && ( pfleche.x < 625 ) && ( pfleche.y < 300 ) && (colusion==0) )
   {             

   i=1 ;         

}
else
{
if (faux==0)
 i=2;
 }

if (( pfleche.x > 575 ) && ( pfleche.y > 300 ) && ( pfleche.x < 625 ) && ( pfleche.y < 340 ) && (colusion==1) )
{
 i=3;

}

if (( pfleche.x > 475 ) && ( pfleche.y > 250 ) && ( pfleche.x < 525 ) && ( pfleche.y < 300 ) && (colusion==2) )
{
 i=4;

}
if (( pfleche.x > 675 ) && ( pfleche.y > 250 ) && ( pfleche.x < 725 ) && ( pfleche.y < 300 ) && (colusion==3) )
{
 i=5;

}

if (( pfleche.x > 625 ) && ( pfleche.y > 250 ) && ( pfleche.x < 675 ) && ( pfleche.y < 310 ) && (colusion==4) )
{
 i=6;

}

if (exit==1)
{
   continuer = 0;
   
}
break;
         }
         
                   
 if ((i==0) && (colusion == 0))
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[1], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
SDL_Flip(ecran);
if ((i==1) && (colusion == 0))
        
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[2], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
faux=1;
if (mus == 1)
{
Mix_PlayMusic(music, 1);
mus =0;
}
SDL_Flip(ecran);
exit=1;
}

if ((i==2) && (colusion == 0))
        
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[3], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);

if (mus == 1)
{
Mix_PlayMusic(music1, 1);
mus =0;
}

SDL_Flip(ecran);
exit=1;
}
 if ((i==0) && (colusion == 1))
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e2.enig[1], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
if ((i==3) && (colusion == 1))   
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e2.enig[2], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
faux=1;
if (mus == 1)
{
Mix_PlayMusic(music, 1);
mus =0;
}
SDL_Flip(ecran);

exit=1;
}
if ((i==2) && (colusion == 1))    
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[3], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
if (mus == 1)
{
Mix_PlayMusic(music1, 1);
mus =0;
}

exit=1;
}

 if ((i==0) && (colusion == 2))
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e3.enig[1], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
if ((i==4) && (colusion == 2))   
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e3.enig[2], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
faux=1;
if (mus == 1)
{
Mix_PlayMusic(music, 1);
mus =0;
}
SDL_Flip(ecran);

exit=1;
}
if ((i==2) && (colusion == 2))    
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[3], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
if (mus == 1)
{
Mix_PlayMusic(music1, 1);
mus =0;
}

exit=1;
}
if ((i==0) && (colusion == 3))    
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e4.enig[1], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
if ((i==5) && (colusion == 3))   
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e4.enig[2], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
faux=1;
if (mus == 1)
{
Mix_PlayMusic(music, 1);
mus =0;
}
SDL_Flip(ecran);

exit=1;
}
if ((i==2) && (colusion == 3))    
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[3], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
if (mus == 1)
{
Mix_PlayMusic(music1, 1);
mus =0;
}

exit=1;
}
if ((i==0) && (colusion == 4))    
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e5.enig[1], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}

if ((i==2) && (colusion == 4))    
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[3], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
if (mus == 1)
{
Mix_PlayMusic(music1, 1);
mus =0;
}

exit=1;
}
        
if ((i==6) && (colusion == 4))   
{       
SDL_BlitSurface(b1, NULL, ecran, &positionb1);
SDL_BlitSurface(e4.enig[2], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
faux=1;
if (mus == 1)
{
Mix_PlayMusic(music, 1);
mus =0;
}
SDL_Flip(ecran);

exit=1;
}




}
SDL_FreeSurface (b1);
   
SDL_FreeSurface(e1.enig[0]);
SDL_FreeSurface(e1.enig[1]);
SDL_FreeSurface(e1.enig[2]);
SDL_FreeSurface(e1.enig[3]);
SDL_FreeSurface(e2.enig[1]);
SDL_FreeSurface(e2.enig[2]);
SDL_FreeSurface(e3.enig[1]);
SDL_FreeSurface(e3.enig[2]);
SDL_FreeSurface(e4.enig[1]);
SDL_FreeSurface(e4.enig[2]);
SDL_FreeSurface(e5.enig[1]);



 SDL_FreeSurface (fleche);


    SDL_Quit();


return i;
 

}

