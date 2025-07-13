#ifndef HEADER
#define HEADER
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define GAME_NAME "Journey Of Rehab"
/**
* @struct personnage
* @brief struct for personnage
*/
typedef struct personne{
int num; /*!< numero*/
int up; /*!< saut*/
int direction; /*!< direction*/
float vitesse; /*!< vitesse*/
float acceleration; /*!< acceleration*/
SDL_Surface *image[2][7]; /*!< surface*/
SDL_Rect POSperso; /*!< Rectangle*/
}personne;
void init_perso(personne *p);
void afficherperso(personne *p,SDL_Surface *screen);
void deplacerperso(personne *p,Uint32 dt,int move);
void animerperso(personne *p);
void saut(personne *p,int *c);
void libererperso(personne p);
#endif /* HEADER */
