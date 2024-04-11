

/** 
* @struct enigme 
* @brief struct for enigme
*/ 
 /** 
* @file enigme.c 
*/ 
#ifndef ENIGME_H_
#define ENIGME_H_
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include<math.h>
typedef struct
{
char question[30];
char reponse1[30];
char reponse2[30];
char reponse3[30];
int num;
}enigme;

enigme generer();
void afficheEnigme(enigme e,SDL_Surface *screen);
 






#endif /* ENIGME_H_ */
