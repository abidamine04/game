#ifndef ennemi_H_INCLUDED
#define ennemi_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
 /**
 * @struct enemy 1
 * @brief structure for first enemy
 */
 
typedef struct 
	{
        SDL_Surface* sprite; /*!<sprite sheet surface*/
        SDL_Rect pos; /*!<Rectangle*/
        int direction;/*!<direction*/
        SDL_Rect pos_sp; /*!<Rectangle for position*/
        int etat; 

	}Ennemi;
 /**
 * @struct enemy 2
 * @brief structure for second enemy
 */
typedef struct 
	{
        SDL_Surface* sprite; /*!<sprite sheet surface*/
        SDL_Rect pos; /*!<Rectangle*/
        SDL_Rect pos_sp;/*!<Rectangle for position*/ 
        int direction;/*!<direction*/  

	}Ennemi2;



void initEnnemi(Ennemi *e, Ennemi2 *e2);    
void afficherEnnemi(Ennemi *e,Ennemi2 *e2,SDL_Surface * screen);
void animerEnnemi(Ennemi *e,Ennemi2 *e2);
void deplacer(Ennemi *e,Ennemi2 *e2);
 int collisionBB( SDL_Rect posp,  SDL_Rect pose) ;
int collisiontrigo(SDL_Rect posp, SDL_Rect pose);
void  deplacerIA(Ennemi * e,SDL_Rect pers);



#endif 
