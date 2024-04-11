/** 
* @file main.c 
* @brief Testing Program. 
* @author Mohamed Malek Turki 
* @version 0.1 
* @date Apr 19, 2021
* 
* Testing program for enigme sans fichier * 
*/
#include"enigme.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include<math.h>
int main()
{SDL_Surface *screen=NULL,*load=NULL,*control=NULL,*mouse=NULL,*keyboard=NULL,*car=NULL,*load2=NULL;char ch[30];
enigme e;
int joueur=0,i,k=0;
SDL_Event event;
SDL_Rect pos;

Mix_Music *musique;
SDL_Init(SDL_INIT_EVERYTHING);
screen=SDL_SetVideoMode(1500,844,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN);
TTF_Init();
pos.x=0;
pos.y=0;

mouse=IMG_Load("mouse.png");
keyboard=IMG_Load("KEYBOARD.png");
load=IMG_Load("bip.png");
control=IMG_Load("control.png");
car=IMG_Load("car.png");
SDL_BlitSurface(control,NULL,screen,&pos);
SDL_Flip(screen);




Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
musique = Mix_LoadMUS("heloenigme.mp3");
Mix_PlayMusic(musique, -1);

e.num=0;
while(e.num==0)
{while(SDL_PollEvent(&event))
 { switch(event.type)
                     {case SDL_QUIT:

              return EXIT_FAILURE;
                     break;
 case SDL_MOUSEBUTTONUP:
		          if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=560 && event.motion.x<=560+420 && event.motion.y>=550 && event.motion.y<=550+75))
                               { 
                               SDL_BlitSurface(mouse,NULL,screen,&pos);
                               SDL_Flip(screen);
                               e.num=1;
                               SDL_Delay(1000);
                               }
                          else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=480 && event.motion.x<=480+550 && event.motion.y>=200 && event.motion.y<=200+75))
                             {SDL_BlitSurface(keyboard,NULL,screen,&pos);
                               SDL_Flip(screen);
                               e.num=2;
                               SDL_Delay(1000);

                               }



break;
}
}
}

SDL_BlitSurface(load,NULL,screen,&pos);
SDL_Flip(screen);
SDL_Delay(2500);


afficheEnigme(e,screen);


do
{
for(i=0;i<7;i++)
{
sprintf(ch,"%d.png",i);
load2=IMG_Load(ch);
SDL_BlitSurface(load2,NULL,screen,&pos);
SDL_Flip(screen);
SDL_FreeSurface(load2);
SDL_Delay(300);
}
k++;
}while(k!=3);


SDL_BlitSurface(car,NULL,screen,&pos);
SDL_Flip(screen);
while(joueur==0)
{while(SDL_PollEvent(&event))
 { switch(event.type)
                     {case SDL_QUIT:

              return EXIT_FAILURE;
                     break;
 case  SDL_MOUSEBUTTONUP:
                  if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x<=750 && event.motion.y>=0 ))
                               { 
                               
                               e.num=1;
                               joueur=e.num;

                              
                               }
                          else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=750 && event.motion.y>=0 ))
                             {
                               e.num=2;
                                joueur=e.num;
                               

                               }





break;

}
}
}

do
{
for(i=0;i<7;i++)
{
sprintf(ch,"0%d.png",i);
load2=IMG_Load(ch);
SDL_BlitSurface(load2,NULL,screen,&pos);
SDL_Flip(screen);
SDL_FreeSurface(load2);
SDL_Delay(300);
}
k--;
}while(k!=0);
SDL_FreeSurface(screen);

Mix_FreeMusic(musique);
Mix_CloseAudio();

SDL_Quit();
return EXIT_SUCCESS;
}



