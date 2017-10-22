/*main.cpp

par Little Dragoon

regroupe le menu principal du jeu
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <time.h>

#include "constantes.h"
#include "jouer.h"

int main ( int argc, char** argv )
{
    SDL_Surface *ecran = NULL, *fond = NULL, *menu = NULL, *smiley = NULL;
    SDL_Rect positionFond, positionMenu, positionSmiley;
    SDL_Event event;
    bool continuer = true;


    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load("sprites/mine.ico"), NULL);
    ecran = SDL_SetVideoMode( LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Demineur", NULL);

    srand(time(NULL));//initiatliation des aléatoires

    fond = IMG_Load ("sprites/demineur_fond.jpg");
    menu = IMG_Load ("sprites/demineur_menu.bmp");
    smiley = IMG_Load ("sprites/smiley_normal.bmp");

    positionFond.x = 0;
    positionFond.y = 0;
    positionMenu.x = TAILLE_BORDURE;
    positionMenu.y = TAILLE_HAUT + TAILLE_BORDURE * 2;
    positionSmiley.x = ecran->w /2 - smiley->w/2;
    positionSmiley.y = 38;


    SDL_FillRect (ecran, NULL, SDL_MapRGB (ecran->format, 0, 0, 0));
    SDL_BlitSurface (fond, NULL, ecran, &positionFond);
    SDL_BlitSurface (smiley, NULL, ecran, &positionSmiley);
    SDL_BlitSurface (menu, NULL, ecran, &positionMenu);
    SDL_Flip(ecran);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                continuer = false;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_1:
                        jouer(ecran, 1);
                        break;

                    case SDLK_2:
                        jouer(ecran, 2);
                        break;

                    case SDLK_3:
                        jouer(ecran, 3);
                        break;

                    case SDLK_KP1:
                        jouer(ecran, 1);
                        break;

                    case SDLK_KP2:
                        jouer(ecran, 2);
                        break;

                    case SDLK_KP3:
                        jouer(ecran, 3);
                        break;



                    case SDLK_ESCAPE:
                        continuer = false;
                        break;

                    default:
                        break;
                }
                break;
        }
        SDL_BlitSurface (fond, NULL, ecran, &positionFond);
        SDL_BlitSurface (smiley, NULL, ecran, &positionSmiley);
        SDL_BlitSurface (menu, NULL, ecran, &positionMenu);
        SDL_Flip(ecran);
        }

    SDL_FreeSurface(fond);
    SDL_FreeSurface(menu);
    SDL_QUIT;
    return EXIT_SUCCESS;

}

