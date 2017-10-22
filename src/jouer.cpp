/*jouer.cpp

par Little Dragoon

la fonction du jeu */

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>



#include "constantes.h"
#include "jouer.h"
#include "genererNiveau.h"


void jouer(SDL_Surface *ecran, long difficulte)
{
    bool restart = false;
    do
    {
        TTF_Init();

        SDL_Surface *tile[14] = {NULL};
        SDL_Surface *smiley[5] = {NULL};
        SDL_Surface *smileyActuel = NULL, *texteMine = NULL, *texteTemps = NULL;
        SDL_Rect positionFond, positionCase, positionSmiley, positionGrille, positionTexteMine, positionTexteTemps, mineReplace;
        SDL_Surface *fond = NULL;
        SDL_Event event;
        SDL_Color couleurRouge = { 255, 0, 0};

        long i = 0, j = 0, largeurChoisi = 0, hauteurChoisi = 0, mineChoisi = 0;
        long tempsDebut = 0, tempsActuel = 0, mineActuel = 0;
        bool continuer = true, explose = false, premierClic = true, gagne = false, pauseFin = true, pauseClic = true;
        char chaineMine[20] = "";
        char chaineTemps[20] = "";

        Grille carte = {0};
        Grille decouvert = {0};
        TTF_Font *police = NULL;

        //initialisatoins des variables
        fond = IMG_Load ("sprites/demineur_fond.jpg");

        police = TTF_OpenFont("times.ttf", 20);

        tile[VIDE] = IMG_Load ("sprites/tile_empty.bmp");
        tile[UN] = IMG_Load ("sprites/tile_one.bmp");
        tile[DEUX] = IMG_Load ("sprites/tile_two.bmp");
        tile[TROIS] = IMG_Load ("sprites/tile_three.bmp");
        tile[QUATRE] = IMG_Load ("sprites/tile_four.bmp");
        tile[CINQ] = IMG_Load ("sprites/tile_five.bmp");
        tile[SIX] = IMG_Load ("sprites/tile_six.bmp");
        tile[SEPT] = IMG_Load ("sprites/tile_seven.bmp");
        tile[HUIT] = IMG_Load ("sprites/tile_eight.bmp");
        tile[MINE] = IMG_Load ("sprites/tile_mine.bmp");
        tile[MINE_ROUGE] = IMG_Load ("sprites/tile_red_mine.bmp");
        tile[PLEIN] = IMG_Load ("sprites/tile_unknown.bmp");
        tile[DRAPEAU] = IMG_Load ("sprites/tile_flag.bmp");
        tile[DRAPEAU_BARRE] = IMG_Load ("sprites/tile_flag_red.bmp");
        //toutes les différentes cases du démineur

        smiley[NORMAL] = IMG_Load ("sprites/smiley_normal.bmp");
        smiley[CLIC] = IMG_Load ("sprites/smiley_clic.bmp");
        smiley[BOUM] = IMG_Load ("sprites/smiley_mine.bmp");
        smiley[BOUM_CLIC] = IMG_Load ("sprites/smiley_mine_clic.bmp");
        smiley[HAPPY] = IMG_Load ("sprites/smiley_happy.bmp");

        smileyActuel = smiley[NORMAL];


        positionFond.x = 0;
        positionFond.y = 0;
        positionSmiley.x = ecran->w /2 - smiley[NORMAL]->w/2;
        positionSmiley.y = 38;
        //initialisations terminées

        switch (difficulte)
        {
            case 1:
                carte = genererNiveau(carte, difficulte);
                hauteurChoisi = HAUTEUR_FACILE;
                largeurChoisi = LARGEUR_FACILE;
                mineChoisi = MINES_FACILE;
                break;

            case 2:
                carte = genererNiveau(carte, difficulte);
                hauteurChoisi = HAUTEUR_MOYEN;
                largeurChoisi = LARGEUR_MOYEN;
                mineChoisi = MINES_MOYEN;
                break;

            case 3:
                carte = genererNiveau(carte, difficulte);
                hauteurChoisi = HAUTEUR_DIFFICILE;
                largeurChoisi = LARGEUR_DIFFICILE;
                mineChoisi = MINES_DIFFICILE;
                break;
        }//le niveau a été généré, on blitte le tout

        sprintf(chaineMine, "mines : %ld", mineChoisi);
        sprintf(chaineTemps, "temps : %lds", tempsDebut);

        texteMine = TTF_RenderText_Solid( police, chaineMine, couleurRouge);
        texteTemps = TTF_RenderText_Solid( police, chaineTemps, couleurRouge);
        //création des surfaces textes puis calcul de leurs coordonées
        positionTexteMine.y = TAILLE_HAUT/2 - texteMine->h/2 ;
        positionTexteMine.x = LARGEUR_FENETRE/4 - texteMine->w/2;
        positionTexteTemps.x = LARGEUR_FENETRE/4*3 - texteTemps->w/2;
        positionTexteTemps.y = TAILLE_HAUT/2 - texteTemps->h /2;

        SDL_BlitSurface(fond, NULL, ecran, &positionFond);
        SDL_BlitSurface(texteMine, NULL, ecran, &positionTexteMine);
        SDL_BlitSurface(texteTemps, NULL, ecran, &positionTexteTemps);
        SDL_BlitSurface(smileyActuel, NULL, ecran, &positionSmiley);



        for (i = 0; i < largeurChoisi; i++)
        {//blit de la carte
            for (j = 0;j < hauteurChoisi; j++)
            {
                positionCase.x = TAILLE_BORDURE + TAILLE_BLOC * i;
                positionCase.y = 2* TAILLE_BORDURE + TAILLE_HAUT + TAILLE_BLOC * j;

                switch (difficulte)
                {// ce switch sert a blitter la bonne carte
                    case 1:
                        if( decouvert.facile[i][j] == INDECOUVERT)
                        {//si on a pas cliqué sur la case, on blitte un plein
                            SDL_BlitSurface(tile[PLEIN], NULL, ecran, &positionCase);
                        }
                        else if( decouvert.facile[i][j] == CASE_MINEE)
                        {//sinon on blitte un drapeau
                            SDL_BlitSurface(tile[DRAPEAU], NULL, ecran, &positionCase);
                        }
                        else
                        {//sinon on blitte un nombre ou un vide
                            SDL_BlitSurface(tile[carte.facile[i][j]], NULL, ecran, &positionCase);
                        }
                        break;

                    case 2:
                        if( decouvert.moyen[i][j] == INDECOUVERT)
                        {//si on a pas cliqué sur la case, on blitte un plein
                            SDL_BlitSurface(tile[PLEIN], NULL, ecran, &positionCase);
                        }
                        else if( decouvert.moyen[i][j] == CASE_MINEE)
                        {//sinon on blitte un drapeau
                            SDL_BlitSurface(tile[DRAPEAU], NULL, ecran, &positionCase);
                        }
                        else
                        {//sinon on blitte un nombre ou un vide
                            SDL_BlitSurface(tile[carte.moyen[i][j]], NULL, ecran, &positionCase);
                        }
                        break;

                    case 3:
                        if( decouvert.difficile[i][j] == INDECOUVERT )
                        {//si on a pas cliqué sur la case, on blitte un plein
                            SDL_BlitSurface(tile[PLEIN], NULL, ecran, &positionCase);
                        }
                        else if( decouvert.difficile[i][j] == CASE_MINEE)
                        {//sinon on blitte un drapeau
                            SDL_BlitSurface(tile[DRAPEAU], NULL, ecran, &positionCase);
                        }
                        else
                        {//sinon on blitte un nombre ou un vide
                            SDL_BlitSurface(tile[carte.difficile[i][j]], NULL, ecran, &positionCase);
                        }
                        break;
                }

            }
        }// ça y est on a enfin tout blitté :)
        SDL_Flip(ecran);



        while (continuer)
        {
            SDL_PollEvent(&event);


            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        continuer = false;
                        restart = false;
                        pauseFin = false;
                    }
                    else if( event.key.keysym.sym == SDLK_r)
                    {
                        continuer = false;
                        restart = true;
                        pauseFin = false;
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (  event.button.button == SDL_BUTTON_LEFT &&
                    event.button.x >= positionSmiley.x && event.button.x <= positionSmiley.x + positionSmiley.w &&
                    event.button.y >= positionSmiley.y && event.button.y <= positionSmiley.y + positionSmiley.h )
                    {//si on clic sur le smiley
                        if ( explose)
                        {
                            smileyActuel = smiley[BOUM_CLIC];
                        }
                        else
                        {
                            smileyActuel = smiley[CLIC];
                        }
                        pauseClic = true;
                        while (pauseClic)
                        {
                            SDL_BlitSurface( smileyActuel, NULL, ecran, &positionSmiley);
                            SDL_Flip(ecran);
                            SDL_WaitEvent(&event);
                            if ( event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
                            {
                                continuer = false;
                                pauseClic = false;
                                pauseFin = false;
                                restart = true;
                            }
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    //on transforme la position de pxl en cases
                    positionGrille.x = (event.button.x - TAILLE_BORDURE) / TAILLE_BLOC;
                    positionGrille.y = (event.button.y - (TAILLE_BORDURE *2 + TAILLE_HAUT)) / TAILLE_BLOC;
                    //si on clique en dehors de la zone, on break
                    if( positionGrille.x < 0)
                    {
                        break;
                    }
                    else if ( positionGrille.x >= largeurChoisi)
                    {//pas trop grand non plus
                        break;
                    }
                    if( positionGrille.y < 0)
                    {
                        break;
                    }
                    else if ( positionGrille.y >= hauteurChoisi)
                    {
                        break;
                    }

                    // fin de verification

                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        switch (difficulte)
                        {
                            case 1:
                                if( premierClic)
                                {//déplacer si ya une mine et démarrer le compteur
                                    tempsDebut = SDL_GetTicks();
                                    if( carte.facile[positionGrille.x][positionGrille.y] == MINE)
                                    {
                                        while (premierClic)
                                        {
                                            mineReplace.x = (rand() % LARGEUR_FACILE);
                                            mineReplace.y = (rand() % HAUTEUR_FACILE);
                                            if( carte.facile[mineReplace.x][mineReplace.y] != MINE)
                                            {//si on remet pas sur une mine
                                                if( mineReplace.x == positionGrille.x && mineReplace.y != positionGrille.y || mineReplace.y == positionGrille.y && mineReplace.x != positionGrille.x)
                                                {//si on est pas sur la case de clic alors on met la mine et on enlève celle du clic
                                                    carte.facile[mineReplace.x][mineReplace.y] = MINE;
                                                    carte.facile[positionGrille.x][positionGrille.y] = VIDE;
                                                    carte = remplirNiveau(carte, difficulte);
                                                    premierClic = false;
                                                }
                                            }
                                        }

                                    }
                                    premierClic = false;
                                }

                                if( decouvert.facile[positionGrille.x][positionGrille.y] == INDECOUVERT)
                                {// si on a pas cliqué sur cette case ben on la decouvre
                                    decouvert.facile[positionGrille.x][positionGrille.y] = DECOUVERT;
                                    if( carte.facile[positionGrille.x][positionGrille.y] ==MINE)
                                    {//si c'est une mine, on explose et on la met en rouge
                                        explose = true;
                                        carte.facile[positionGrille.x][positionGrille.y] = MINE_ROUGE;
                                    }

                                }
                                if ( carte.facile[positionGrille.x][positionGrille.y] == VIDE)
                                {//on decouvre toutes les cases autour et ainsi de suite
                                        decouvert = decouvrirNiveau(carte, difficulte, positionGrille, decouvert);
                                }

                                break;

                            case 2:
                                if( premierClic)
                                {//déplacer si ya une mine et démarrer le compteur
                                    tempsDebut = SDL_GetTicks();
                                    if( carte.moyen[positionGrille.x][positionGrille.y] == MINE)
                                    {
                                        while (premierClic)
                                        {
                                            mineReplace.x = (rand() % LARGEUR_MOYEN);
                                            mineReplace.y = (rand() % HAUTEUR_MOYEN);
                                            if( carte.moyen[mineReplace.x][mineReplace.y] != MINE)
                                            {//si on remet pas sur une mine
                                                if( mineReplace.x == positionGrille.x && mineReplace.y != positionGrille.y || mineReplace.y == positionGrille.y && mineReplace.x != positionGrille.x)
                                                {//si on est pas sur la case de clic alors on met la mine et on s'en va
                                                    carte.moyen[mineReplace.x][mineReplace.y] = MINE;
                                                    premierClic = false;
                                                }
                                            }
                                        }

                                    }
                                    premierClic = false;
                                }

                                if( decouvert.moyen [positionGrille.x][positionGrille.y] == INDECOUVERT)
                                {// si on a pas cliqué sur cette case ben on la decouvre
                                    decouvert.moyen [positionGrille.x][positionGrille.y] = DECOUVERT;
                                    if( carte.moyen [positionGrille.x][positionGrille.y] ==MINE)
                                    {//si c'est une mine, on explose et on la met en rouge
                                        explose = true;
                                        carte.moyen[positionGrille.x][positionGrille.y] = MINE_ROUGE;
                                    }
                                }
                                if ( carte.moyen[positionGrille.x][positionGrille.y] == VIDE)
                                {//on decouvre toutes les cases autour et ainsi de suite
                                        decouvert = decouvrirNiveau(carte, difficulte, positionGrille, decouvert);
                                }

                                break;

                            case 3:
                                if( premierClic)
                                {//déplacer si ya une mine et démarrer le compteur
                                    tempsDebut = SDL_GetTicks();
                                    if( carte.difficile[positionGrille.x][positionGrille.y] == MINE)
                                    {
                                        while (premierClic)
                                        {
                                            mineReplace.x = (rand() % LARGEUR_DIFFICILE);
                                            mineReplace.y = (rand() % HAUTEUR_DIFFICILE);
                                            if( carte.difficile[mineReplace.x][mineReplace.y] != MINE)
                                            {//si on remet pas sur une mine
                                                if( mineReplace.x == positionGrille.x && mineReplace.y != positionGrille.y || mineReplace.y == positionGrille.y && mineReplace.x != positionGrille.x)
                                                {//si on est pas sur la case de clic alors on met la mine et on s'en va
                                                    carte.difficile[mineReplace.x][mineReplace.y] = MINE;
                                                    premierClic = false;
                                                }
                                            }
                                        }

                                    }
                                    premierClic = false;
                                }

                                if( decouvert.difficile[positionGrille.x][positionGrille.y] == INDECOUVERT)
                                {// si on a pas cliqué sur cette case ben on la decouvre
                                    decouvert.difficile[positionGrille.x][positionGrille.y] = DECOUVERT;
                                    if( carte.difficile[positionGrille.x][positionGrille.y] ==MINE)
                                    {//si c'est une mine, on explose et on la met en rouge
                                        explose = true;
                                        carte.difficile[positionGrille.x][positionGrille.y] = MINE_ROUGE;
                                    }
                                }
                                if ( carte.difficile[positionGrille.x][positionGrille.y] == VIDE)
                                {//on decouvre toutes les cases autour et ainsi de suite
                                        decouvert = decouvrirNiveau(carte, difficulte, positionGrille, decouvert);
                                }
                                break;
                        }//fin du switch left button

                    }
                    else if (event.button.button == SDL_BUTTON_RIGHT)
                    {
                        event.button.button = 0;
                        switch (difficulte)
                        {
                            case 1:
                                if( decouvert.facile[positionGrille.x][positionGrille.y] == INDECOUVERT)
                                {// si on a pas cliqué sur cette case ben on met un drapeau
                                    decouvert.facile[positionGrille.x][positionGrille.y] = CASE_MINEE;
                                }

                                else if( decouvert.facile[positionGrille.x][positionGrille.y] == CASE_MINEE)
                                {// si c'est un drapeau on la remet normal
                                    decouvert.facile[positionGrille.x][positionGrille.y] = INDECOUVERT;
                                }
                                break;

                            case 2:
                                if( decouvert.moyen[positionGrille.x][positionGrille.y] == INDECOUVERT)
                                {// si on a pas cliqué sur cette case ben on met un drapeau
                                    decouvert.moyen[positionGrille.x][positionGrille.y] = CASE_MINEE;
                                }

                                else if( decouvert.moyen[positionGrille.x][positionGrille.y] == CASE_MINEE)
                                {// si c'est un drapeau on la remet normal
                                    decouvert.moyen[positionGrille.x][positionGrille.y] = INDECOUVERT;
                                }
                                break;

                            case 3:
                                if( decouvert.difficile[positionGrille.x][positionGrille.y] == INDECOUVERT)
                                {// si on a pas cliqué sur cette case ben on met un drapeau
                                    decouvert.difficile[positionGrille.x][positionGrille.y] = CASE_MINEE;
                                }

                                else if( decouvert.difficile[positionGrille.x][positionGrille.y] == CASE_MINEE)
                                {// si c'est un drapeau on la remet normal
                                    decouvert.difficile[positionGrille.x][positionGrille.y] = INDECOUVERT;
                                }
                                break;
                        }//fin du switch sdl right button
                    }
                    break;



            }//fin du switch event


            if( explose == true)
            {// si on a perdu on montre les mines pas encore vues et on montre les erreurs
                smileyActuel = smiley[BOUM];
                continuer = false;
                for (i = 0; i < largeurChoisi; i ++)
                {
                    for (j = 0; j < hauteurChoisi; j++)
                    {
                        switch (difficulte)
                        {
                            case 1:
                                if( carte.facile[i][j] == MINE && decouvert.facile[i][j] == INDECOUVERT)
                                {
                                    decouvert.facile[i][j] = DECOUVERT;
                                }
                                else if( decouvert.facile[i][j] == CASE_MINEE && carte.facile[i][j] != MINE)
                                {
                                    decouvert.facile[i][j] = DECOUVERT;
                                    carte.facile[i][j] = DRAPEAU_BARRE;
                                }
                                break;

                            case 2:
                                if( carte.moyen[i][j] == MINE && decouvert.moyen[i][j] == INDECOUVERT)
                                {
                                    decouvert.moyen[i][j]= DECOUVERT;
                                }
                                else if( decouvert.moyen[i][j] == CASE_MINEE && carte.moyen[i][j] != MINE)
                                {
                                    decouvert.moyen[i][j] = DECOUVERT;
                                    carte.moyen[i][j]= DRAPEAU_BARRE;
                                }
                                break;

                            case 3:
                                if( carte.difficile[i][j] == MINE && decouvert.difficile[i][j] == INDECOUVERT)
                                {
                                    decouvert.difficile[i][j] = DECOUVERT;
                                }
                                else if( decouvert.difficile[i][j] == CASE_MINEE && carte.difficile[i][j] != MINE)
                                {
                                    decouvert.difficile[i][j] = DECOUVERT;
                                    carte.difficile[i][j] = DRAPEAU_BARRE;
                                }
                                break;
                        }
                    }
                }

            }
            mineActuel = mineChoisi;
            gagne = true;
            for (i = 0; i < largeurChoisi; i++)
            {//decompte des mines, check si gagne
                for (j =0; j <hauteurChoisi; j++)
                {
                    switch (difficulte)
                    {
                        case 1:
                            if( decouvert.facile[i][j] == CASE_MINEE)
                            {
                                mineActuel --;
                            }
                            if( decouvert.facile[i][j] == CASE_MINEE && carte.facile[i][j] != MINE
                            || carte.facile[i][j] == MINE && decouvert.facile[i][j] != CASE_MINEE)
                            {
                                gagne = false;
                            }

                        case 2:
                            if( decouvert.moyen[i][j] == CASE_MINEE)
                            {
                                mineActuel --;
                            }
                            if( decouvert.moyen[i][j] == CASE_MINEE && carte.moyen[i][j] != MINE
                            || carte.moyen[i][j] == MINE && decouvert.moyen[i][j] != CASE_MINEE)
                            {
                                gagne = false;
                            }

                        case 3:
                            if( decouvert.difficile[i][j] == CASE_MINEE)
                            {
                                mineActuel --;
                            }
                            if( decouvert.difficile[i][j] == CASE_MINEE && carte.difficile[i][j] != MINE
                            || carte.difficile[i][j] == MINE && decouvert.difficile[i][j] != CASE_MINEE)
                            {
                                gagne = false;
                            }
                    }
                }
            }

            if (gagne)
            {
                continuer = false;
                smileyActuel = smiley[HAPPY];
                for (i = 0 ; i < largeurChoisi; i++)
                {
                    for (j =0; j < hauteurChoisi; j ++)
                    {
                        switch (difficulte)
                        {
                            case 1:
                                if (decouvert.facile[i][j] == INDECOUVERT)
                                {
                                    decouvert.facile[i][j] = DECOUVERT;
                                }
                                break;

                            case 2:
                                if (decouvert.moyen[i][j] == INDECOUVERT)
                                {
                                    decouvert.moyen[i][j] = DECOUVERT;
                                }
                                break;

                            case 3:
                                if (decouvert.difficile[i][j] == INDECOUVERT)
                                {
                                    decouvert.difficile[i][j] = DECOUVERT;
                                }
                                break;
                        }
                    }
                }
            }
            if ( !premierClic)
            {
                tempsActuel = (SDL_GetTicks() - tempsDebut) / 1000;
            }

            sprintf(chaineMine, "mines : %ld", mineActuel);
            sprintf(chaineTemps, "temps : %lds", tempsActuel);

            SDL_FreeSurface(texteMine);
            SDL_FreeSurface(texteTemps);
            texteMine = TTF_RenderText_Solid( police, chaineMine, couleurRouge);
            texteTemps = TTF_RenderText_Solid( police, chaineTemps, couleurRouge);
            //création des surfaces textes puis calcul de leurs coordonées
            positionTexteMine.y = 45;
            positionTexteMine.x = (626/4) - (texteMine->w/2);
            positionTexteTemps.x = (626/4)*3 - (texteTemps->w/2);
            positionTexteTemps.y = 45;

            SDL_BlitSurface(fond, NULL, ecran, &positionFond);
            SDL_BlitSurface(texteMine, NULL, ecran, &positionTexteMine);
            SDL_BlitSurface(texteTemps, NULL, ecran, &positionTexteTemps);
            SDL_BlitSurface(smileyActuel, NULL, ecran, &positionSmiley);



            for (i = 0; i < largeurChoisi; i++)
            {//blit de la carte
                for (j = 0;j < hauteurChoisi; j++)
                {
                    positionCase.x = TAILLE_BORDURE + TAILLE_BLOC * i;
                    positionCase.y = 2* TAILLE_BORDURE + TAILLE_HAUT + TAILLE_BLOC * j;

                    switch (difficulte)
                    {// ce switch sert a blitter la bonne carte
                        case 1:
                            if( decouvert.facile[i][j] == INDECOUVERT)
                            {//si on a pas cliqué sur la case, on blitte un plein
                                SDL_BlitSurface(tile[PLEIN], NULL, ecran, &positionCase);
                            }
                            else if( decouvert.facile[i][j] == CASE_MINEE)
                            {//sinon on blitte un drapeau
                                SDL_BlitSurface(tile[DRAPEAU], NULL, ecran, &positionCase);
                            }
                            else
                            {//sinon on blitte un nombre ou un vide
                                SDL_BlitSurface(tile[carte.facile[i][j]], NULL, ecran, &positionCase);
                            }
                            break;

                        case 2:
                            if( decouvert.moyen[i][j] == INDECOUVERT)
                            {//si on a pas cliqué sur la case, on blitte un plein
                                SDL_BlitSurface(tile[PLEIN], NULL, ecran, &positionCase);
                            }
                            else if( decouvert.moyen[i][j] == CASE_MINEE)
                            {//sinon on blitte un drapeau
                                SDL_BlitSurface(tile[DRAPEAU], NULL, ecran, &positionCase);
                            }
                            else
                            {//sinon on blitte un nombre ou un vide
                                SDL_BlitSurface(tile[carte.moyen[i][j]], NULL, ecran, &positionCase);
                            }
                            break;

                        case 3:
                            if( decouvert.difficile[i][j] == INDECOUVERT)
                            {//si on a pas cliqué sur la case, on blitte un plein
                                SDL_BlitSurface(tile[PLEIN], NULL, ecran, &positionCase);
                            }
                            else if( decouvert.difficile[i][j] == CASE_MINEE)
                            {//sinon on blitte un drapeau
                                SDL_BlitSurface(tile[DRAPEAU], NULL, ecran, &positionCase);
                            }
                            else
                            {//sinon on blitte un nombre ou un vide
                                SDL_BlitSurface(tile[carte.difficile[i][j]], NULL, ecran, &positionCase);
                            }
                            break;
                    }

            }
        }// ça y est on a enfin tout blitté :)
        SDL_Flip(ecran);
        SDL_Delay(20);
        }

        while (pauseFin)
        {
            SDL_WaitEvent(&event);
            if ( event.type == SDL_QUIT)
            {
                exit(0);
            }
            else if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            {
                pauseFin = false;
                restart = false;
            }
            else if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
            {
                pauseFin = false;
                restart = true;
            }
            else if ( event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
            event.button.x >= positionSmiley.x && event.button.x <= positionSmiley.x + positionSmiley.w &&
            event.button.y >= positionSmiley.y && event.button.y <= positionSmiley.y + positionSmiley.h )
            {//si on clic sur le smiley
                if ( explose)
                {
                    smileyActuel = smiley[BOUM_CLIC];
                }
                else
                {
                    smileyActuel = smiley[CLIC];
                }
                pauseClic = true;
                while (pauseClic)
                {
                    SDL_BlitSurface( smileyActuel, NULL, ecran, &positionSmiley);
                    SDL_Flip(ecran);
                    SDL_WaitEvent(&event);
                    if ( event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
                    {
                        pauseClic = false;
                        pauseFin = false;
                        restart = true;
                    }
                }
            }
        }

        for (i = 0 ; i < DRAPEAU_BARRE ; i++)
        {
            SDL_FreeSurface( tile[i]);
        }
        for (i = 0 ; i < BOUM_CLIC ; i++)
        {
            SDL_FreeSurface( smiley[i]);
        }
        SDL_FreeSurface(fond);
        SDL_FreeSurface(smileyActuel);
        SDL_FreeSurface(texteMine);
        SDL_FreeSurface(texteTemps);

        TTF_CloseFont(police);
        TTF_Quit();
    }while (restart);
}

