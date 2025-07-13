#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h> 
#include "serie.h"
#include <string.h>
#include "ennemi.h"
#include "personnage.h"
int main(int argc, char *argv[]){
uint8_t b;
char buffer[1];
personne pp,p1;
Ennemi ennemi;
Ennemi2 ennemi2;
Uint32 dt, t_prev;
int quit=0,p=0,s=0,q=0,nor=0,ful=0,min=0,plus=0,ex1=0,bar=0,ecran=1,m=6,co=0,num=0,move=-1,move1=-1,c=1,c1=1,i,n=1,distance;
background backg;
images buttonp,buttons,buttonq,buttonpl,buttonmi,buttonor,buttonfu,buttonx,buttonx2,barr,buttonsing,buttonmult,buttonkey,buttoncon,buttonp1,buttonp2,buttonone,an1,an;
text t;
Mix_Music *backgmusic;
Mix_Chunk *hover;
SDL_Event event;
SDL_Surface* screen;
/*int fd = serialport_init("/dev/ttyUSB0", 9600);
    if (fd==-1) return -1;*/
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
	{
		printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
		return 1;
	
	}
	
	else
	printf("Bonjour le monde, SDL est initialisé avec succès.\n");
	screen = SDL_SetVideoMode(1440, 900,  32,SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_RESIZABLE);
	if ( screen == NULL )
	{
		fprintf(stderr, "Echec de creation de la fenetre de 1440*900: %s.\n", SDL_GetError());
		return 1;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1) {
    printf("Unable to initialize SDL Mixer: %s\n", Mix_GetError());
    return -1;
}
init_perso(&pp);
init_perso(&p1);
initEnnemi(&ennemi,&ennemi2);
initialize_hover_sound(&hover);
initialize_audio(&backgmusic);
initialize(&backg);
initializeplay(&buttonp);
initializesetting(&buttons);
initializequit(&buttonq);
initializetext(&t);
initializepl(&buttonpl);
initializemi(&buttonmi);
initializenfu(&buttonfu);
initializenor(&buttonor);
initializebar(&barr);
initializex1(&buttonx);
initializex2(&buttonx2);
initializemulti(&buttonmult);
initializesing(&buttonsing);
initializenone(&buttonone);
initializeplay2(&buttonp2);
initializeplay1(&buttonp1);
initializecontrol(&buttoncon);
initializekey(&buttonkey);
initializean1(&an1);
initializean2(&an);
while(quit==0){
if(ecran==1)
{
afficher(backg.image[0],screen,backg.pos);
afficher(buttons.image[s],screen,buttons.pos);
afficher(buttonq.image[q],screen,buttonq.pos);
afficher(buttonp.image[p],screen,buttonp.pos);
afficher(t.surfacetext,screen,t.pos);
afficher(an1.image[num],screen,an1.pos);
afficher(an.image[num],screen,an.pos);
}
if(ecran==2)
{
afficher(backg.image[1],screen,backg.pos);
afficher(buttonpl.image[plus],screen,buttonpl.pos);
afficher(buttonmi.image[min],screen,buttonmi.pos);
afficher(buttonor.image[nor],screen,buttonor.pos);
afficher(buttonfu.image[ful],screen,buttonfu.pos);
afficher(barr.image[bar],screen,barr.pos);
afficher(buttonx.image[ex1],screen,buttonx.pos);
}
if(ecran==3)
{
afficher(backg.image[2],screen,backg.pos);
afficher(buttonx2.image[ex1],screen,buttonx2.pos);
afficher(buttonsing.image[p],screen,buttonsing.pos);
afficher(buttonmult.image[s],screen,buttonmult.pos);
}
if(ecran==4)
{
afficher(backg.image[2],screen,backg.pos);
afficher(buttonx2.image[ex1],screen,buttonx2.pos);
afficher(buttoncon.image[p],screen,buttoncon.pos);
afficher(buttonkey.image[s],screen,buttonkey.pos);
}
if(ecran==5)
{
afficher(backg.image[2],screen,backg.pos);
afficher(buttonx2.image[ex1],screen,buttonx2.pos);
afficher(buttonp1.image[p],screen,buttonp1.pos);
afficher(buttonp2.image[s],screen,buttonp2.pos);
afficher(buttonone.image[q],screen,buttonone.pos);
}
if(ecran==6)
{
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
afficherperso(&pp,screen);
afficherEnnemi(&ennemi, &ennemi2,screen);
if(ennemi.pos.x>=pp.POSperso.x)
distance=ennemi.pos.x-pp.POSperso.x;
else
distance = pp.POSperso.x - ennemi.pos.x;
if ((ennemi.etat = 0)&&(distance >100))
  {
   deplacer( &ennemi, &ennemi2);
   animerEnnemi(&ennemi,&ennemi2);
  }
else
  {
   deplacerIA(&ennemi,pp.POSperso);
   animerEnnemi(&ennemi,&ennemi2);
   }
        
     collisiontrigo(pp.POSperso,ennemi.pos);
     if(n==2)
     afficherperso(&p1,screen);
    /*//  lecture d'une ligne
     serialport_read_until(fd, buffer, '\r', 1, 10);
     // suppression de la fin de ligne
     for (i=0 ; buffer[i]!='\r' && i<3 ; i++);
     buffer[i] = 0;

     // écriture du résultat
     printf("%s", buffer);
   if(co==1)
    {
    if(strstr(buffer,"l")){
     pp.direction = 0; 
     move = 2;
    }
    if(strstr(buffer,"r")){
     pp.direction = 1; 
     move = 1;
    }
    if(strstr(buffer,"u")){
     pp.acceleration += 0.05;
    }
    if(strstr(buffer,"d")){
     pp.acceleration -= 0.05;
    }
    if(strstr(buffer,"B")){
     pp.up=1;
    }
    if(strstr(buffer,"S")){ 
    move=-1;
    }
    if(strstr(buffer,"p")){
     quit=1;
    } 
    }
    if(co==2)
    {
    if(strstr(buffer,"l")){
     p1.direction = 0; 
     move1 = 2;
    }
    if(strstr(buffer,"r")){
     p1.direction = 1; 
     move1 = 1;
    }
    if(strstr(buffer,"u")){
     p1.acceleration += 0.05;
    }
    if(strstr(buffer,"d")){
     p1.acceleration -= 0.05;
    }
    if(strstr(buffer,"B")){
     p1.up=1;
    }
    if(strstr(buffer,"S")){ 
    move1=-1;
    }
    if(strstr(buffer,"p")){
     quit=1;
    } 
    }*/
}
SDL_Flip(screen);
t_prev = SDL_GetTicks();
SDL_EnableKeyRepeat(20,20);
 while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_MOUSEMOTION:
                {
                switch(ecran){
                 case 1:
                 {
                 if ((event.motion.y >= 425 && event.motion.y <= 491) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  p=1;
                  s=0;
                  q=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 535 && event.motion.y <=601 ) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  s=1;
                  p=0;
                  q=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 645 && event.motion.y <= 711) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  q=1;
                  p=0;
                  s=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else {
                  q=0;
                  p=0;
                  s=0;
                  }
                  }break;
                  case 2:
                  {
                   if ((event.motion.y >= 300 && event.motion.y <= 374) &&(event.motion.x >= 100 && event.motion.x <= 406)){
                  nor=1;
                  ful=0;
                  plus=0;
                  min=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 500 && event.motion.y <=574 ) &&(event.motion.x >= 100 && event.motion.x <= 406)){
                  nor=0;
                  ful=1;
                  min=0;
                  plus=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 400 && event.motion.y <= 450) &&(event.motion.x >= 930 && event.motion.x <= 980)){
                  nor=0;
                  ful=0;
                  min=0;
                  plus=1;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 425 && event.motion.y <= 475) &&(event.motion.x >= 540 && event.motion.x <= 590)){
                  nor=0;
                  ful=0;
                  min=1;
                  plus=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 155 && event.motion.y <= 256) &&(event.motion.x >= 1230 && event.motion.x <= 1331)){
                  nor=0;
                  ful=0;
                  min=0;
                  plus=0;
                  ex1=1;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else {
                  nor=0;
                  ful=0;
                  min=0;
                  plus=0;
                  ex1=0;
                  }
                  }break;
                 case 3:
                  {
                   if ((event.motion.y >= 425 && event.motion.y <= 491) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  p=1;
                  s=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 535 && event.motion.y <=601 ) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  s=1;
                  p=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 700 && event.motion.y <= 801) &&(event.motion.x >= 675 && event.motion.x <= 775)){
                  ex1=1;
                  p=0;
                  s=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else {
                  ex1=0;
                  p=0;
                  s=0;
                  }
                  }break;
                 case 4:
                  {
                   if ((event.motion.y >= 425 && event.motion.y <= 474) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  p=1;
                  s=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 535 && event.motion.y <=574 ) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  s=1;
                  p=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 700 && event.motion.y <= 801) &&(event.motion.x >= 675 && event.motion.x <= 775)){
                  ex1=1;
                  p=0;
                  s=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else {
                  ex1=0;
                  p=0;
                  s=0;
                  }
                  }break;
                 case 5:
                  {
                   if ((event.motion.y >= 425 && event.motion.y <= 491) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  p=1;
                  s=0;
                  ex1=0;
                  q=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 535 && event.motion.y <=601 ) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  s=1;
                  p=0;
                  ex1=0;
                  q=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 700 && event.motion.y <= 801) &&(event.motion.x >= 675 && event.motion.x <= 775)){
                  ex1=1;
                  p=0;
                  s=0;
                  q=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else if ((event.motion.y >= 600 && event.motion.y <= 675) &&(event.motion.x >= 576 && event.motion.x <= 872)){
                  q=1;
                  p=0;
                  s=0;
                  ex1=0;
                  Mix_PlayChannel(-1, hover, 1);
                  }
                 else {
                  ex1=0;
                  p=0;
                  s=0;
                  }
                  }break;
                  }
                  }break;
                  case SDL_MOUSEBUTTONDOWN:
                   {
                   switch(ecran)
                    {
                     case 1:
                     {
                    if (event.button.button == SDL_BUTTON_LEFT){
                      if(p==1)
                      {
                       ecran=3;
                       }
                      if(s==1)
                      {
                       ecran=2;
                       }
                      if(q==1)
                      {
                       quit=1;
                       }
                       }
                       }break;
                      case 2:
                       {
                      if (event.button.button == SDL_BUTTON_LEFT){
                      if(plus==1)
                      {
                       m++;
	               switch (m){
	                case 1:
	                {
			 Mix_VolumeMusic(0);
                         Mix_Volume(-1, 0);
                         bar=6;
                         }
		        break;
	                case 2:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/5);
			 Mix_Volume(-1, 1);
			 bar=5;
                        }
		        break;
	                case 3:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/3);
			 Mix_Volume(-1, 1);
			 bar=3;
			}
		        break;
	                case 4:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/2);
			 Mix_Volume(-1, 1);
			 bar=2;
			}
		        break;
	                case 5:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/1.2);
			 Mix_Volume(-1, 1);
			 }
		        break;
	                case 6:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME);
			 Mix_Volume(-1, 1);
			 bar=1;
			}
		        break;
	                default:
		         m=6;
	                break;
	                }
                      }
                      if(min==1)
                      {
                       m--;
	               switch (m){
	                case 1:
	                {
			 Mix_VolumeMusic(0);
                         Mix_Volume(-1, 0);
                         bar=6;
                         }
		        break;
	                case 2:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/5);
			 Mix_Volume(-1, 1);
			 bar=5;
                        }
		        break;
	                case 3:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/3);
			 Mix_Volume(-1, 1);
			 bar=3;
			}
		        break;
	                case 4:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/2);
			 Mix_Volume(-1, 1);
			 bar=2;
			}
		        break;
	                case 5:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME/1.2);
			 Mix_Volume(-1, 1);
			 }
		        break;
	                case 6:
	                {
		         Mix_VolumeMusic(MIX_MAX_VOLUME);
			 Mix_Volume(-1, 1);
			 bar=1;
			}
		        break;
	                default:
		         m=6;
	                break;
	                }
                      }
                     if(ful==1)
                      {
                       screen = SDL_SetVideoMode(1440, 900,  32,SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN);
                      }
                     if(nor==1)
                      {
                       screen = SDL_SetVideoMode(1440, 900,  32,SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_RESIZABLE);
                      }
                     if(ex1==1)
                      {
                       ecran=1;
                      }
                      }
                     }break;
                    case 3:
                    {
                     if (event.button.button == SDL_BUTTON_LEFT){
                     if(p==1)
                      {
                       ecran=4;
                       n=1;
                       }
                      if(s==1)
                      {
                       ecran=5;
                       n=2;
                       }
                      if(ex1==1)
                      {
                       ecran=1;
                       }
                     }
                     }break;
                    case 4:
                    {
                     if (event.button.button == SDL_BUTTON_LEFT){
                     if(p==1)
                      {
                       ecran=6;
                       co=1;
                       }
                      if(s==1)
                      {
                       ecran=6;
                       co=0;
                       }
                      if(ex1==1)
                      {
                       ecran=3;
                       }
                     }
                    }break;
                   case 5:
                   {
                    if (event.button.button == SDL_BUTTON_LEFT){
                     if(p==1)
                      {
                       ecran=6;
                       co=1;
                       }
                      if(s==1)
                      {
                       ecran=6;
                       co=2;
                       }
                      if(q==1)
                      {
                       ecran=6;
                       co=0;
                      }
                      if(ex1==1)
                      {
                       ecran=3;
                       }
                     }
                   }break;
         	   }
                  }break;
                 case SDL_KEYDOWN:
                 {
                   switch(ecran)
                   {
                   case 1:
                   {
                    switch(event.key.keysym.sym)
                    {
                    case SDLK_UP:
                     {
                            if(p == 1) {
                                p = 0;
                                q = 1;
				Mix_PlayChannel(-1, hover, 1);
                            }
                            else if(s == 1) {
                                s = 0;
                                p = 1;
				Mix_PlayChannel(-1, hover, 1);
                            }
                            else if(q == 1) {
                                q = 0;
                                s = 1;
				Mix_PlayChannel(-1, hover, 1);
                            }
                            else {
                                p = 1;
                            }
                            }break;
                    case SDLK_DOWN:
                      {
                             if(p == 1) {
                                p = 0;
                                s = 1;
				Mix_PlayChannel(-1, hover, 1);
                            }
                            else if(s == 1) {
                                s = 0;
                                q = 1;
				Mix_PlayChannel(-1, hover, 1);
                            }
                            else if(q == 1) {
                                q = 0;
                                p = 1;
				Mix_PlayChannel(-1, hover, 1);
                            }
                            else {
                                p = 1;
                            }
                            }break;
                     case SDLK_RETURN:
                      {
                       if(p==1)
                      {
                       ecran=3;
                       }
                      if(s==1)
                      {
                       ecran=2;
                       }
                      if(q==1)
                      {
                       quit=1;
                       }
                      }break;
                    case SDLK_p:
                     {
                      ecran=3;
                     }break;
                    case SDLK_m:
                    {
                     ecran=2;
                    }break;
                    case SDLK_ESCAPE:
                    {
                     quit=1;
                    }break;
                     }
                    }break;
                   case 2:
                   {
                    switch(event.key.keysym.sym)
                    {
                     case SDLK_ESCAPE:
                     {
                      ecran=1;
                     }break;
                    }
                   }break;
                   case 3:
                   {
                    switch(event.key.keysym.sym)
                    {
                     case SDLK_ESCAPE:
                     {
                      ecran=1;
                     }break;
                    }
                   }break;
                   case 4:
                   {
                    switch(event.key.keysym.sym)
                    {
                     case SDLK_ESCAPE:
                     {
                      ecran=3;
                     }break;
                    }
                   }break;
                   case 5:
                   {
                    switch(event.key.keysym.sym)
                    {
                     case SDLK_ESCAPE:
                     {
                      ecran=3;
                     }break;
                    }
                   }break;
                   case 6:
                   {
                    switch(event.key.keysym.sym)
                    {
                     case SDLK_ESCAPE:
                     {
                      ecran=1;
                     }break;
                     case SDLK_RIGHT:
                     {
                      pp.direction = 1; 
                      move = 1;
                     }break;
                     case SDLK_LEFT:
                     {
                      pp.direction = 0; 
                      move = 2;
                     }break;
                     case SDLK_KP0:
                     {
                      pp.up=1;
                     }break;
                     case SDLK_UP:
                     {
                      pp.acceleration += 0.05;
                     }break;
                     case SDLK_DOWN:
                     {
                      pp.acceleration -= 0.05;
                     }break;
                     case SDLK_d:
                     {
                      p1.direction = 1; 
                      move1 = 1;
                     }break;
                     case SDLK_q:
                     {
                      p1.direction = 0; 
                      move1 = 2;
                     }break;
                     case SDLK_SPACE:
                     {
                      p1.up=1;
                     }break;
                     case SDLK_z:
                     {
                      p1.acceleration += 0.05;
                     }break;
                     case SDLK_s:
                     {
                      p1.acceleration -= 0.05;
                     }break;
                    }
                   }break;
                   }
                  }break;
                  case SDL_KEYUP:
                  {
                   switch(ecran)
                   {
                   case 6:
                    {
                    switch(event.key.keysym.sym)
                    {
                     case SDLK_RIGHT:
                    {
                        move = -1;
                        }
                        break;
                    case SDLK_LEFT:
                    {
                        move = -1; 
                        }
                        break;
                    case SDLK_d:
                    {
                        move1 = -1;
                        }
                        break;
                    case SDLK_q:
                    {
                        move1 = -1; 
                        }
                        break;
                    }
                   }break;
                   }
                  }break;
                 }
                }
                if(ecran==1)
                {
                 animer(&num);
                }
                if(ecran==6)
                {
                 if ((SDL_GetTicks() - t_prev) < 1000 / 60)
                    {
                     SDL_Delay((1000 / 60) - (SDL_GetTicks() - t_prev));
                    }
                 dt = SDL_GetTicks() - t_prev;
                 if(move != -1)
                 {
                  deplacerperso(&pp,dt,move);
                  animerperso(&pp);
                 }
                 if(move1 != -1)
                 {
                  deplacerperso(&p1,dt,move1);
                  animerperso(&p1);
                 }
                 if(pp.POSperso.y<=400)
	          c=2;
	         saut(&pp,&c); 
                 if(p1.POSperso.y<=400)
	          c1=2;
	         saut(&p1,&c1);
	         if (!collisiontrigo(pp.POSperso, ennemi.pos)) 
	         {
                  printf("il n y a pas de Collision\n");
                 }
                 else if (!collisiontrigo(pp.POSperso, ennemi2.pos)) 
	         {
                  printf("il n y a pas de Collision\n");
                 }
                 else 
                  printf("Collision\n");
	         SDL_Delay(20);
                }
               }
libererperso(pp);
libererperso(p1);
free_backg(backg);
free_images(buttonp);
free_images(buttons);
free_images(buttonq);
free_images(buttonpl);
free_images(buttonmi);
free_images(buttonor);
free_images(buttonfu);
free_images(barr);
free_images(buttonx);
free_images(buttonx2);
free_images(buttonmult);
free_images(buttonsing);
free_images(buttonkey);
free_images(buttoncon);
free_images(buttonp1);
free_images(buttonp2);
free_images(buttonone);
free_images(an1);
free_txt(t);
free_audio(backgmusic);
Mix_FreeChunk(hover);
SDL_Quit();
return 0;   
}
 
