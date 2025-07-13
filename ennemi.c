#include "ennemi.h"

/**
* @file ennemi.c
* @brief Functions code for enemy.
* @author Emir Kefi
* @version 1
* @date May 10, 2024
*
* 
*
*/

void initEnnemi(Ennemi *e, Ennemi2 *e2) {
    
    e->sprite=IMG_Load("ennemi.png"); 
    
    e->pos.y=600;
    e->pos.x=300;
    
    e->direction=0; 
    
    e->pos_sp.x=0;
    e->pos_sp.y=0;
    e->pos_sp.h=100;
    e->pos_sp.w=100;

    e2->sprite=IMG_Load("ennemi2.png"); 
	    
    e2->pos.y=600;
    e2->pos.x=900;
	    
	    
    e2->pos_sp.x=0;
    e2->pos_sp.y=0;
    e2->pos_sp.h=161;
    e2->pos_sp.w=185;
    
}



void afficherEnnemi(Ennemi *e, Ennemi2 *e2,SDL_Surface * screen){
    SDL_BlitSurface(e2->sprite , &e2->pos_sp , screen , &e2->pos) ;
    SDL_BlitSurface(e->sprite , &e->pos_sp , screen , &e->pos) ; 
     
}

void animerEnnemi( Ennemi *e, Ennemi2 *e2){ 
    e->pos_sp.x += 100;
    e2->pos_sp.x += 200; 
    if ((e->pos_sp.x==400)||(e2->pos_sp.x>=395))
    {
        e->pos_sp.x = 0;
        e2->pos_sp.x = 0;
    }
    e->pos_sp.y = e->direction * 100;
    
    
}

void deplacer( Ennemi * e, Ennemi2 *e2){
    int Xmin , Xmax , Xmin2, Xmax2;
    if(e->direction!=1){
    Xmin = rand() % (400 - 100 + 1) + 100;
    Xmax = rand() % (1350 - 1000 + 1) + 1000;
    }
    
    
    if (e->pos.x <= Xmin || e->pos.x >= Xmax) {
        Xmin = rand() % 1001;
        Xmax = rand() % 1351;
    }
    
    if (e->direction==0)
    {
        e->pos.x += 10;
    }
    else if (e->direction==1)
    {
        e->pos.x -= 10;
    }



    if (e->pos.x < Xmin)
    {
        e->direction = 0;
    }
    if (e->pos.x > Xmax)
    {
        e->direction = 1;
    }
    //mouvement ennemi 2
    if(e->direction!=1){
    
    Xmin2 = rand() % (400 - 100 + 1) + 100;
    Xmax2 = rand() % (1350 - 1000 + 1) + 1000;
    }
    
    if (e2->pos.x <= Xmin2 || e2->pos.x >= Xmax2) {
        Xmin2 = rand() % 1001;
        Xmax2 = rand() % 1351;
    }
    
    if (e2->direction==0)
    {
        e2->pos.x += 10;
    }
    else if (e->direction==1)
    {
        e2->pos.x -= 10;
    }



    if (e2->pos.x < Xmin2)
    {
        e2->direction = 0;
    }
    if (e2->pos.x > Xmax2)
    {
        e2->direction = 1;
    }
  }

int collisionBB( SDL_Rect posp, SDL_Rect pose) 
{
int c;

if((posp.x<=pose.x)||(posp.w<=pose.w)||(posp.y<=pose.y)||(posp.h<=pose.h))
c=1;
else c=0;
return c;
 
} 
int collisiontrigo(SDL_Rect posp, SDL_Rect pose){

int X1,X2,Y1,Y2,R1,R2,D1,D2;

X1 = pose.x + (pose.w/2);
Y1 = pose.y + (pose.h/2);
X2 = posp.x + (posp.w/2);
Y2 = posp.y + (posp.h/2);

if ( pose.w<pose.h)
{
R1 = pose.w/2;
}
else{
R1 = pose.h/2;
}
if ( posp.w<posp.h)
{
R2 = posp.w/2;
}
else{
R2 = posp.h/2;
}
D1 = sqrt(((X1 - X2)*(X1 - X2))+((Y1 - Y2)*(Y1 - Y2)));
D2 = R1 + R2;
if(D1 <= D2){
return 1;
}
else{
return 0;
}
}
void deplacerIA(Ennemi *e,SDL_Rect pers)
{

int distance;

  if(e->pos.x>=pers.x)
    distance=e->pos.x-pers.x;
  else
    distance=pers.x - e->pos.x;
    if(distance<100)
      {
      e->etat = 1;
        if(e->pos.x>=pers.x)
          e->direction=0;
        else
          e->direction=1;
      }

      else
   
    if(e->direction==0)
      {  e->pos.x += 10;

       }
      if(e->direction==1)
      { e->pos.x -= 10;
       
      }
      
          
}
