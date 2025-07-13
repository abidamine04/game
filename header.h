#ifndef HEADERS_H
#define HEADERS_H

#include <SDL/SDL.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h> 
typedef struct background{
SDL_Surface *image[3];
SDL_Rect pos;
}background;
typedef struct images{
SDL_Surface *image[10];
SDL_Rect pos;
} images;
typedef struct text{
    SDL_Surface *surfacetext;
    SDL_Rect pos;
    TTF_Font *font;
    SDL_Color textcolor;
    char message [50];
} text;
void initialize(background *b);
void initializean1(images *i);
void initializean2(images *i);
void initializeplay(images *i);
void initializesetting(images *i);
void initializequit(images *i);
void initializetext(text *t);
void initialize_audio(Mix_Music **backgmusic);
void initialize_hover_sound(Mix_Chunk **hover);
void initializepl(images *i);
void initializemi(images *i);
void initializenor(images *i);
void initializenfu(images *i);
void initializebar(images *i);
void initializex1(images *i);
void initializex2(images *i);
void initializemulti(images *i);
void initializenone(images *i);
void initializeplay2(images *i);
void initializeplay1(images *i);
void initializecontrol(images *i);
void initializekey(images *i);
void initializesing(images *i);
void afficher(SDL_Surface *p,SDL_Surface *screen,SDL_Rect pos);
void animer(int *n);
void free_backg(background b);
void free_images(images i);
void free_txt(text t);
void free_audio(Mix_Music *backgmusic);
#endif
