/**
* @file source.c
* @brief Testing Program.
* @author MedAmine Abid
* @version 0.1
* @date may 03, 2024
*
* Testing program for functions
*
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"personnage.h"
/**
* @brief To initialize the personna.
* @param p personne
* @return Nothing
*/
void init_perso(personne *p)
{ 
 p->image[0][0]=IMG_Load("L1.png");
 p->image[0][1]=IMG_Load("L2.png");
 p->image[0][2]=IMG_Load("L3.png");
 p->image[0][3]=IMG_Load("L4.png");
 p->image[0][4]=IMG_Load("L5.png");
 p->image[0][5]=IMG_Load("L6.png");
 p->image[0][6]=IMG_Load("L7.png");
 p->image[1][0]=IMG_Load("R1.png");
 p->image[1][1]=IMG_Load("R2.png");
 p->image[1][2]=IMG_Load("R3.png");
 p->image[1][3]=IMG_Load("R4.png");
 p->image[1][4]=IMG_Load("R5.png");
 p->image[1][5]=IMG_Load("R6.png");
 p->image[1][6]=IMG_Load("R7.png");
 p->up=0;
 p->direction=1;
 p->num=0;
 p->vitesse=2;
 p->acceleration=0;
 //position de personnage
 p->POSperso.x=0;
 p->POSperso.y=600;
 p->POSperso.w=p->image[0][0]->w;
 p->POSperso.h=p->image[0][0]->h;
}
/**
* @brief To show the personna on the surface .
* @param p the personna
* @param screen the surface
* @return Nothing
*/
void afficherperso(personne *p,SDL_Surface *screen)
{
SDL_BlitSurface(p->image[p->direction][p->num], NULL, screen, &p->POSperso);
}
/**
* @brief To mouve the personna.
* @param p the personna
* @param move an int to know if he is mouving
* @param dt time
* @return Nothing
*/
void deplacerperso(personne *p,Uint32 dt,int move)
{
if(move==1)
 p->POSperso.x+=0.5*p->acceleration*(dt*dt)+p->vitesse*dt;
else if(move==2)
 p->POSperso.x-=0.5*p->acceleration*(dt*dt)+p->vitesse*dt;
}
/**
* @brief To animate the personna.
* @param p the personna
* @return Nothing
*/
void animerperso(personne *p)
{
if(p->num==6)
{
p->num=0;
}
else{
p->num++;
}
}
/**
* @brief To makethe personna jump .
* @param p the personna
* @param c int to know persona place
* @return Nothing
*/
void saut(personne *p, int *c){
	int x=-100;
	int y=0;
	
	if(p->up==1){
		x+=4;
		y=(-0.04*(x*x))+400;
		if(*c==1){
			p->POSperso.x+=x+100;
			p->POSperso.y-=y;	
		}
		else{
			p->POSperso.x+=x+100;
			p->POSperso.y+=y;
		}
		
	}
	if(p->POSperso.y>=550){
			p->up=0;
			*c=1;
			x=-100;
			p->POSperso.y=550;
		}

}
/**
* @brief To realese the personna from memory .
* @param p the personna
* @return Nothing
*/
void libererperso(personne p)
{
SDL_FreeSurface(p.image[0][0]);
SDL_FreeSurface(p.image[0][1]);
SDL_FreeSurface(p.image[0][2]);
SDL_FreeSurface(p.image[0][3]);
SDL_FreeSurface(p.image[0][4]);
SDL_FreeSurface(p.image[0][5]);
SDL_FreeSurface(p.image[0][6]);
SDL_FreeSurface(p.image[1][0]);
SDL_FreeSurface(p.image[1][1]);
SDL_FreeSurface(p.image[1][2]);
SDL_FreeSurface(p.image[1][3]);
SDL_FreeSurface(p.image[1][4]);
SDL_FreeSurface(p.image[1][5]);
SDL_FreeSurface(p.image[1][6]);
SDL_Quit();
}
