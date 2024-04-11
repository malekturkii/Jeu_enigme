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
enigme generer()
{
enigme e;int i,tab[3];float sol[3];char v1[30],v2[30],v3[30];


for(i=0;i<3;i++)
tab[i]=rand()%10+1;



sprintf(v1, "%dX",tab[0]);
sprintf(v2, "   %dX",tab[1]);
sprintf(v3, "    %d",tab[2]);
strcat(v1,v2);
strcat(v1,v3);
strcpy(e.question,v1);


sol[0]=(-tab[1]+sqrt((tab[1]*tab[1])+(4*tab[2]*tab[0])))/(2*tab[0]);
sol[1]=(0.15-sqrt(sqrt(sqrt(sqrt(tab[0])))));
sol[2]=((rand()%2)+2.71);
sprintf(e.reponse1, "   %.2f",sol[0]);
sprintf(e.reponse2, "   %.2f",sol[1]);
sprintf(e.reponse3, "   %.2f",sol[2]);




return e;
}






void afficheEnigme(enigme e,SDL_Surface *screen)
{
SDL_Color font={90,56,37},font2={77,25,27};
TTF_Font *police=NULL;
police=TTF_OpenFont("roman_2.ttf",100);
SDL_Surface *eq,*solu1,*solu2,*solu3,*a,*b,*c,*groupe=NULL,*win=NULL,*lose=NULL,*texte=NULL;
int i,continuer=1,x,num;
char temps[30];
SDL_Event event;
SDL_Rect poseq,posi[3],pos,postemps;
pos.x=0;
pos.y=0;
postemps.x=60;
postemps.y=60;
groupe=IMG_Load("ena.png");
win=IMG_Load("win.png");
lose=IMG_Load("lose.png");
srand(time(NULL));
num=e.num;
do
{
x=rand()%3; 
e=generer();
for(i=10;i>=0;i--)
{

SDL_BlitSurface(groupe,NULL,screen,&pos);
SDL_Flip(screen);
sprintf(temps, "Timer : %d",i);
texte=TTF_RenderText_Blended(police,temps,font2);
SDL_BlitSurface(texte,NULL,screen,&postemps);
SDL_Flip(screen);

poseq.x=60;
poseq.y=300;
eq=TTF_RenderText_Blended(police,e.question,font);
SDL_BlitSurface(eq,NULL,screen,&poseq);
SDL_Flip(screen);
posi[0].x=60;
posi[0].y=450;
posi[1].x=60;
posi[1].y=550;
posi[2].x=60;
posi[2].y=650;
solu1=TTF_RenderText_Blended(police,e.reponse1,font);
solu2=TTF_RenderText_Blended(police,e.reponse2,font);
solu3=TTF_RenderText_Blended(police,e.reponse3,font);
a=TTF_RenderText_Blended(police,"a/",font);
b=TTF_RenderText_Blended(police,"b/",font);
c=TTF_RenderText_Blended(police,"c/",font);
SDL_BlitSurface(a,NULL,screen,&posi[0]);
SDL_Flip(screen);
SDL_BlitSurface(b,NULL,screen,&posi[1]);
SDL_Flip(screen);
SDL_BlitSurface(c,NULL,screen,&posi[2]);
SDL_Flip(screen);



if(x==0)
{
SDL_BlitSurface(solu1,NULL,screen,&posi[0]);
SDL_Flip(screen);



SDL_BlitSurface(solu2,NULL,screen,&posi[1]);
SDL_Flip(screen);



SDL_BlitSurface(solu3,NULL,screen,&posi[2]);
SDL_Flip(screen);
}

else if(x==1)

{
SDL_BlitSurface(solu1,NULL,screen,&posi[1]);
SDL_Flip(screen);



SDL_BlitSurface(solu2,NULL,screen,&posi[0]);
SDL_Flip(screen);



SDL_BlitSurface(solu3,NULL,screen,&posi[2]);
SDL_Flip(screen);
}
else if(x==2)

{
SDL_BlitSurface(solu1,NULL,screen,&posi[2]);
SDL_Flip(screen);



SDL_BlitSurface(solu2,NULL,screen,&posi[0]);
SDL_Flip(screen);



SDL_BlitSurface(solu3,NULL,screen,&posi[1]);
SDL_Flip(screen);
}

if(i!=0)
{while (SDL_PollEvent(&event))
{    switch(event.type)
                     {case SDL_QUIT:
                 
                     SDL_Quit();
                     break;
	             case SDL_MOUSEBUTTONUP:
		     if(num==1)
{ 
                     if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=posi[0].x && event.motion.x<=(posi[0].x+270) && event.motion.y>=posi[0].y && event.motion.y<=posi[0].y+70))
                          {
                          
                    
                          if(x==0)
                          {
                          SDL_BlitSurface(win,NULL,screen,&pos);
                          SDL_Flip(screen);
                          continuer=0;
		          SDL_Delay(3000);		          
                          i=0;}
                          else 
                          {
                          SDL_BlitSurface(lose,NULL,screen,&pos);
                          SDL_Flip(screen);                          
                          continuer=1;
                          SDL_Delay(3000);		          
                       	  i=0;
                          }
                          } 
                          
                           else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=posi[1].x && event.motion.x<=(posi[1].x+270) && event.motion.y>=posi[1].y && event.motion.y<=posi[1].y+70))


                           {
                   
                          if(x==1)
                          {
                          SDL_BlitSurface(win,NULL,screen,&pos);
                          SDL_Flip(screen);
                          continuer=0;
		          SDL_Delay(3000);		          
                          i=0;}
                          else 
                          {
                          SDL_BlitSurface(lose,NULL,screen,&pos);
                          SDL_Flip(screen);                          
                          continuer=1;
                          SDL_Delay(3000);		          
                       	  i=0;
                          
                           
                          } 
                          }


                         else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=posi[2].x && event.motion.x<=(posi[2].x+270) && event.motion.y>=posi[2].y && event.motion.y<=posi[2].y+70))
                          {
                    
                          if(x==2)
                          {
                          SDL_BlitSurface(win,NULL,screen,&pos);
                          SDL_Flip(screen);
                          continuer=0;
		          SDL_Delay(3000);		          
                          i=0;}
                          else 
                          {
                          SDL_BlitSurface(lose,NULL,screen,&pos);
                          SDL_Flip(screen);                          
                          continuer=1;
                          SDL_Delay(3000);		          
                       	  i=0;
                          }
                          } 
                          } 
                          
break;

             case SDL_KEYDOWN :
		      if(num==2)
{
                
                         if((event.key.keysym.sym==SDLK_a))
                          {
                          
                     
                          if(x==0)
                          {
                          SDL_BlitSurface(win,NULL,screen,&pos);
                          SDL_Flip(screen);
                          continuer=0;
		          SDL_Delay(3000);		          
                          i=0;}
                          else 
                          {
                          SDL_BlitSurface(lose,NULL,screen,&pos);
                          SDL_Flip(screen);                          
                          continuer=1;
                          SDL_Delay(3000);		          
                       	  i=0;
                          }
                          } 
                          
                           else if((event.key.keysym.sym==SDLK_b))


                           {
                    
                          if(x==1)
                          {
                          SDL_BlitSurface(win,NULL,screen,&pos);
                          SDL_Flip(screen);
                          continuer=0;
		          SDL_Delay(3000);		          
                          i=0;}
                          else 
                          {
                          SDL_BlitSurface(lose,NULL,screen,&pos);
                          SDL_Flip(screen);                          
                          continuer=1;
                          SDL_Delay(3000);		          
                       	  i=0;
                          
                           
                          } 
                          }


                         else if((event.key.keysym.sym==SDLK_c))
                          {
                    
                          if(x==2)
                          {
                          SDL_BlitSurface(win,NULL,screen,&pos);
                          SDL_Flip(screen);
                          continuer=0;
		          SDL_Delay(3000);		          
                          i=0;}
                          else 
                          {
                          SDL_BlitSurface(lose,NULL,screen,&pos);
                          SDL_Flip(screen);                          
                          continuer=1;
                          SDL_Delay(3000);		          
                       	  i=0;
                          
                          }       
                          } 
                          }
break;



}
}
SDL_Flip(screen);

SDL_Delay(2000);
}
else if(i==0)
{SDL_BlitSurface(lose,NULL,screen,&pos);                         
   SDL_Flip(screen);
SDL_Delay(3000);	
}
}

}
while(continuer!=0); 


}


