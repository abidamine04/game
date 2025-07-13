#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"


void initializean1(images *i){
i->image[9] = IMG_Load("rehab(1).png");
i->image[8] = IMG_Load("rehab(1).png");
i->image[7] = IMG_Load("rehab(1).png");
i->image[6] = IMG_Load("rehabt(1).png");
i->image[5] = IMG_Load("rehabt(1).png");
i->image[4] = IMG_Load("rehabt(1).png");
i->image[3] = IMG_Load("rehabt(1).png");
i->image[2] = IMG_Load("rehabt(1).png");
i->image[1] = IMG_Load("rehabt(1).png");
i->image[0] = IMG_Load("rehabt(1).png");
i->pos.x = 1103;
i->pos.y = 109;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializean2(images *i){
i->image[9] = IMG_Load("of.png");
i->image[8] = IMG_Load("of.png");
i->image[7] = IMG_Load("of.png");
i->image[6] = IMG_Load("of.png");
i->image[5] = IMG_Load("of.png");
i->image[4] = IMG_Load("journey.png");
i->image[3] = IMG_Load("journey.png");
i->image[2] = IMG_Load("journey.png");
i->image[1] = IMG_Load("journey.png");
i->image[0] = IMG_Load("journey.png");
i->pos.x = 37;
i->pos.y = 109;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initialize(background *b){
b->image[0] = IMG_Load("menut.png");
b->image[1] = IMG_Load("optiont.png");
b->image[2] = IMG_Load("menutt.png");
b->pos.x = 0;
b->pos.y = 0;
b->pos.h = 1440;
b->pos.w = 900;
}
void initializeplay(images *i){
i->image[1] = IMG_Load("play.png");
i->image[0] = IMG_Load("playt.png");
i->pos.x = 576;
i->pos.y = 425;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializeplay1(images *i){
i->image[1] = IMG_Load("player1.png");
i->image[0] = IMG_Load("playert1.png");
i->pos.x = 576;
i->pos.y = 400;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializecontrol(images *i){
i->image[1] = IMG_Load("controller.png");
i->image[0] = IMG_Load("controllert.png");
i->pos.x = 576;
i->pos.y = 425;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializesing(images *i){
i->image[1] = IMG_Load("single.png");
i->image[0] = IMG_Load("singlet.png");
i->pos.x = 576;
i->pos.y = 425;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializesetting(images *i){
i->image[1] = IMG_Load("settings.png");
i->image[0] = IMG_Load("settingt.png");
i->pos.x = 576;
i->pos.y = 535;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializeplay2(images *i){
i->image[1] = IMG_Load("player2.png");
i->image[0] = IMG_Load("playert2.png");
i->pos.x = 576;
i->pos.y = 500;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializekey(images *i){
i->image[1] = IMG_Load("keyboard.png");
i->image[0] = IMG_Load("keyboardt.png");
i->pos.x = 576;
i->pos.y = 535;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializemulti(images *i){
i->image[1] = IMG_Load("multi.png");
i->image[0] = IMG_Load("multit.png");
i->pos.x = 576;
i->pos.y = 535;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializequit(images *i){
i->image[1] = IMG_Load("quit.png");
i->image[0] = IMG_Load("quitt.png");
i->pos.x = 576;
i->pos.y = 645;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializenone(images *i){
i->image[1] = IMG_Load("none.png");
i->image[0] = IMG_Load("nonet.png");
i->pos.x = 576;
i->pos.y = 600;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializepl(images *i){
i->image[1] = IMG_Load("+.png");
i->image[0] = IMG_Load("++.png");
i->pos.x = 930;
i->pos.y = 400;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializemi(images *i){
i->image[1] = IMG_Load("-.png");
i->image[0] = IMG_Load("--.png");
i->pos.x = 540;
i->pos.y = 425;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializenor(images *i){
i->image[1] = IMG_Load("normal.png");
i->image[0] = IMG_Load("normalt.png");
i->pos.x = 100;
i->pos.y = 300;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializenfu(images *i){
i->image[1] = IMG_Load("fullscreen.png");
i->image[0] = IMG_Load("fullscreent.png");
i->pos.x = 100;
i->pos.y = 500;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializex1(images *i){
i->image[1] = IMG_Load("x.png");
i->image[0] = IMG_Load("xx.png");
i->pos.x = 1230;
i->pos.y = 155;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializex2(images *i){
i->image[1] = IMG_Load("x.png");
i->image[0] = IMG_Load("xx.png");
i->pos.x = 675;
i->pos.y = 700;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializebar(images *i){
i->image[5] = IMG_Load("bar6.png");
i->image[4] = IMG_Load("bar5.png");
i->image[3] = IMG_Load("bar4.png");
i->image[2] = IMG_Load("bar3.png");
i->image[1] = IMG_Load("bar2.png");
i->image[0] = IMG_Load("bar1.png");
i->pos.x = 600;
i->pos.y = 450;
i->pos.h = i->image[0]->h;
i->pos.w = i->image[0]->w;
}
void initializetext(text *t){
t->textcolor.r=0;
t->textcolor.g=0;
t->textcolor.b=0;
t->font = TTF_OpenFont( "arial.ttf", 20 );
t->pos.x=576;
t->pos.y=100;
t->surfacetext=TTF_RenderText_Solid(t->font, "MENU", t->textcolor );
}
void initialize_hover_sound(Mix_Chunk **hover) {
    *hover = Mix_LoadWAV("click.wav");
    if (*hover== NULL) {
        printf("Unable to load hover sound: %s\n", Mix_GetError());
    }
}
void initialize_audio(Mix_Music **backgmusic) {
    *backgmusic = Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(*backgmusic, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME);
}	
void animer(int *n){
if((*n)==8)
{
(*n)=0;
}
else{
(*n)++;
}
}

void afficher(SDL_Surface *p,SDL_Surface *screen,SDL_Rect pos)
{
SDL_BlitSurface(p, NULL, screen, &pos);
}
void free_backg(background b) {
    SDL_FreeSurface(b.image[0]);
    SDL_FreeSurface(b.image[1]);
    SDL_FreeSurface(b.image[2]);
}
void free_images(images i) {
    SDL_FreeSurface(i.image[0]);
    SDL_FreeSurface(i.image[1]);
    SDL_FreeSurface(i.image[2]);
    SDL_FreeSurface(i.image[3]);
    SDL_FreeSurface(i.image[4]);
    SDL_FreeSurface(i.image[5]);
    SDL_FreeSurface(i.image[6]);
    SDL_FreeSurface(i.image[7]);
    SDL_FreeSurface(i.image[8]);
    SDL_FreeSurface(i.image[9]);
}
void free_txt(text t){
    SDL_FreeSurface (t.surfacetext);
}
void free_audio(Mix_Music *backgmusic) {
    Mix_FreeMusic(backgmusic);
}
