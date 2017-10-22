/* genererNiveau.cpp

Par Little Dragoon

contient le générateur de niveau*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>

#include "constantes.h"
#include "genererNiveau.h"
#include "jouer.h"

Grille genererNiveau( Grille carte, long difficulte)
{
    SDL_Rect positionMine;
    long nombreDeMines = 0;



    switch (difficulte)
    {
        case 1:
            while (nombreDeMines < MINES_FACILE)
            {
                positionMine.x = (rand() % LARGEUR_FACILE);
                positionMine.y = (rand() % HAUTEUR_FACILE);
                //génération d'une coordonée aléatoire

                if( carte.facile[positionMine.x][positionMine.y] != MINE)
                {//placement de mine a cette coordonée
                    carte.facile[positionMine.x][positionMine.y] = MINE;
                    nombreDeMines ++;
                }
            }
            break;

        case 2:
            while (nombreDeMines < MINES_MOYEN)
            {
                positionMine.x = rand() % LARGEUR_MOYEN;
                positionMine.y = rand() % HAUTEUR_MOYEN;

                if( carte.moyen[positionMine.x][positionMine.y] != MINE)
                {
                    carte.moyen[positionMine.x][positionMine.y] = MINE;
                    nombreDeMines ++;
                }
            }
            break;

        case 3:
            while (nombreDeMines < MINES_DIFFICILE)
            {
                positionMine.x = rand() % LARGEUR_DIFFICILE;
                positionMine.y = rand() % HAUTEUR_DIFFICILE;

                if( carte.difficile[positionMine.x][positionMine.y] != MINE)
                {
                    carte.difficile[positionMine.x][positionMine.y] = MINE;
                    nombreDeMines ++;
                }
            }
            break;
    }
    carte = remplirNiveau( carte, difficulte);
    return carte;

}

Grille remplirNiveau (Grille carte, long difficulte)
{
    long i = 0, j = 0, mineActuel;

    switch (difficulte)
    {
        case 1:
            for (i = 0; i <LARGEUR_FACILE; i++)
            {//parcourir le tableau
                for (j = 0; j < HAUTEUR_FACILE; j++)
                {
                    if ( carte.facile[i][j] != MINE)
                    {//si cette case ne contient pas deja une mine
                        mineActuel = 0;
                        if ( i != 0 && i != LARGEUR_FACILE -1 && j != 0 && j != HAUTEUR_FACILE -1 )
                        {//si on est au centre
                            if( carte.facile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }

                        }

                        else if( i == 0 && j == 0)
                        {//si on est en haut a gauche
                            if( carte.facile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.facile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_FACILE -1 && j == HAUTEUR_FACILE -1)
                        {//si on est en bas a droite
                            if( carte.facile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.facile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == 0 && j == HAUTEUR_FACILE -1)
                        {//si on est en bas a gauche
                            if( carte.facile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.facile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_FACILE -1 && j == 0)
                        {//si on est en haut a droite
                            if( carte.facile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.facile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }

                        }

                        else if( i == 0 && j != 0 && j != HAUTEUR_FACILE -1)
                        {//si on est a gauche
                            if( carte.facile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.facile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i != 0 && i != LARGEUR_FACILE -1 && j == 0)
                        {//si on est en haut
                            if( carte.facile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i != 0 && i != LARGEUR_FACILE -1 && j == HAUTEUR_FACILE -1)
                        {//si on est en bas
                            if( carte.facile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_FACILE -1 && j != 0 && j != HAUTEUR_FACILE -1)
                        {//si on est a droite
                             if( carte.facile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.facile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        switch (mineActuel)
                        {//changer la case vide en nombre
                            case 0:
                                carte.facile[i][j] = VIDE;
                                break;

                            case 1:
                                carte.facile[i][j] = UN;
                                break;

                            case 2:
                                carte.facile[i][j] = DEUX;
                                break;

                            case 3:
                                carte.facile[i][j] = TROIS;
                                break;

                            case 4:
                                carte.facile[i][j] = QUATRE;
                                break;

                            case 5:
                                carte.facile[i][j] = CINQ;
                                break;

                            case 6:
                                carte.facile[i][j] = SIX;
                                break;

                            case 7:
                                carte.facile[i][j] = SEPT;
                                break;

                            case 8:
                                carte.facile[i][j] = HUIT;
                                break;
                        }
                    }
                }
            }
            break;

        case 2:
            for (i = 0; i <LARGEUR_MOYEN; i++)
            {//parcourir le tableau
                for (j = 0; j < HAUTEUR_MOYEN; j++)
                {
                    if ( carte.moyen[i][j] != MINE)
                    {//si cette case ne contient pas deja une mine
                        mineActuel = 0;
                        if ( i != 0 && i != LARGEUR_MOYEN -1 && j != 0 && j != HAUTEUR_MOYEN -1 )
                        {//si on est au centre
                            if( carte.moyen[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }

                        }

                        else if( i == 0 && j == 0)
                        {//si on est en haut a gauche
                            if( carte.moyen[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.moyen[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_MOYEN -1 && j == HAUTEUR_MOYEN -1)
                        {//si on est en bas a droite
                            if( carte.moyen[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.moyen[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == 0 && j == HAUTEUR_MOYEN -1)
                        {//si on est en bas a gauche
                            if( carte.moyen[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.moyen[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_MOYEN -1 && j == 0)
                        {//si on est en haut a droite
                            if( carte.moyen[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.moyen[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }

                        }

                        else if( i == 0 && j != 0 && j != HAUTEUR_MOYEN -1)
                        {//si on est a gauche
                            if( carte.moyen[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.moyen[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i != 0 && i != LARGEUR_MOYEN -1 && j == 0)
                        {//si on est en haut
                            if( carte.moyen[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i != 0 && i != LARGEUR_MOYEN -1 && j == HAUTEUR_MOYEN -1)
                        {//si on est en bas
                            if( carte.moyen[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_MOYEN -1 && j != 0 && j != HAUTEUR_MOYEN -1)
                        {//si on est a droite
                             if( carte.moyen[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.moyen[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        switch (mineActuel)
                        {//changer la case vide en nombre
                            case 0:
                                carte.moyen[i][j] = VIDE;
                                break;

                            case 1:
                                carte.moyen[i][j] = UN;
                                break;

                            case 2:
                                carte.moyen[i][j] = DEUX;
                                break;

                            case 3:
                                carte.moyen[i][j] = TROIS;
                                break;

                            case 4:
                                carte.moyen[i][j] = QUATRE;
                                break;

                            case 5:
                                carte.moyen[i][j] = CINQ;
                                break;

                            case 6:
                                carte.moyen[i][j] = SIX;
                                break;

                            case 7:
                                carte.moyen[i][j] = SEPT;
                                break;

                            case 8:
                                carte.moyen[i][j] = HUIT;
                                break;
                        }
                    }
                }
            }
            break;

        case 3:
            for (i = 0; i <LARGEUR_DIFFICILE; i++)
            {//parcourir le tableau
                for (j = 0; j < HAUTEUR_DIFFICILE; j++)
                {
                    if ( carte.difficile[i][j] != MINE)
                    {//si cette case ne contient pas deja une mine
                        mineActuel = 0;
                        if ( i != 0 && i != LARGEUR_DIFFICILE -1 && j != 0 && j != HAUTEUR_DIFFICILE -1 )
                        {//si on est au centre
                            if( carte.difficile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }

                        }

                        else if( i == 0 && j == 0)
                        {//si on est en haut a gauche
                            if( carte.difficile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.difficile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_DIFFICILE -1 && j == HAUTEUR_DIFFICILE -1)
                        {//si on est en bas a droite
                            if( carte.difficile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.difficile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == 0 && j == HAUTEUR_DIFFICILE -1)
                        {//si on est en bas a gauche
                            if( carte.difficile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.difficile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_DIFFICILE -1 && j == 0)
                        {//si on est en haut a droite
                            if( carte.difficile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.difficile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }

                        }

                        else if( i == 0 && j != 0 && j != HAUTEUR_DIFFICILE -1)
                        {//si on est a gauche
                            if( carte.difficile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                             if( carte.difficile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i != 0 && i != LARGEUR_DIFFICILE -1 && j == 0)
                        {//si on est en haut
                            if( carte.difficile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i != 0 && i != LARGEUR_DIFFICILE -1 && j == HAUTEUR_DIFFICILE -1)
                        {//si on est en bas
                            if( carte.difficile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i+1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        else if( i == LARGEUR_DIFFICILE -1 && j != 0 && j != HAUTEUR_DIFFICILE -1)
                        {//si on est a droite
                             if( carte.difficile[i-1][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j-1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i-1][j] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i-1][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                            if( carte.difficile[i][j+1] == MINE)
                            {
                                mineActuel ++;
                            }
                        }

                        switch (mineActuel)
                        {//changer la case vide en nombre
                            case 0:
                                carte.difficile[i][j] = VIDE;
                                break;

                            case 1:
                                carte.difficile[i][j] = UN;
                                break;

                            case 2:
                                carte.difficile[i][j] = DEUX;
                                break;

                            case 3:
                                carte.difficile[i][j] = TROIS;
                                break;

                            case 4:
                                carte.difficile[i][j] = QUATRE;
                                break;

                            case 5:
                                carte.difficile[i][j] = CINQ;
                                break;

                            case 6:
                                carte.difficile[i][j] = SIX;
                                break;

                            case 7:
                                carte.difficile[i][j] = SEPT;
                                break;

                            case 8:
                                carte.difficile[i][j] = HUIT;
                                break;
                        }
                    }
                }
            }
            break;
    }

    return carte;


}

Grille decouvrirNiveau(Grille carte, long difficulte, SDL_Rect positionGrille, Grille decouvert)
{
    bool resteCase = false;
    long i = 0, j = 0;

    switch ( difficulte)
    {
        case 1:
            if ( positionGrille.x != 0 && positionGrille.x != LARGEUR_FACILE -1 &&
            positionGrille.y != 0 && positionGrille.y != HAUTEUR_FACILE -1 )
            {// si on est au centre
                 if ( carte.facile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.facile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.facile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.facile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.facile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.facile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.facile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.facile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.facile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.facile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.facile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.facile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.facile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.facile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.facile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
            }

            else if( positionGrille.x == 0 && positionGrille.y == 0)
            {//si on est en haut a gauche
                 if ( carte.facile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.facile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.facile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y+1] == INDECOUVERT )//v
                {
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.facile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.facile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v


            }

            else if( positionGrille.x == LARGEUR_FACILE -1 && positionGrille.y == HAUTEUR_FACILE -1)
            {//si on est en bas a droite
                 if ( carte.facile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.facile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.facile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y-1] == INDECOUVERT )//^
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.facile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.facile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^


            }

            else if( positionGrille.x == 0 && positionGrille.y == HAUTEUR_FACILE -1)
            {//si on est en bas a gauche
                if ( carte.facile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.facile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.facile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y] == INDECOUVERT )//>
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.facile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.facile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>

            }

            else if( positionGrille.x == LARGEUR_FACILE -1 && positionGrille.y == 0)
            {//si on est en haut a droite
                if (carte.facile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.facile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.facile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.facile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.facile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<

            }

            else if( positionGrille.x == 0 && positionGrille.y != 0 && positionGrille.y != HAUTEUR_FACILE -1)
            {//si on est a gauche
                if ( carte.facile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.facile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.facile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.facile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.facile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y+1] == INDECOUVERT )//v
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.facile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.facile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.facile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.facile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
            }

            else if( positionGrille.x != 0 && positionGrille.x != LARGEUR_FACILE -1 && positionGrille.y == 0)
            {//si on est en haut
                if ( carte.facile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.facile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.facile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.facile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.facile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.facile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.facile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.facile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.facile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
            }

            else if( positionGrille.x != 0 && positionGrille.x != LARGEUR_FACILE -1 && positionGrille.y == HAUTEUR_FACILE -1)
            {//si on est en bas
                if (carte.facile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.facile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.facile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.facile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.facile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x+1][positionGrille.y] == INDECOUVERT )//>
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.facile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.facile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.facile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.facile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
            }

            else if( positionGrille.x == LARGEUR_FACILE -1 && positionGrille.y != 0 && positionGrille.y != HAUTEUR_FACILE -1)
            {//si on est a droite
                if (carte.facile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.facile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.facile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.facile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.facile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.facile[positionGrille.x][positionGrille.y-1] == INDECOUVERT)//^
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.facile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.facile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.facile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.facile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.facile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
            }

            while (resteCase == true)
            {
                resteCase = false;
                for (i = 0; i < LARGEUR_FACILE; i++)
                {
                    for (j = 0; j < HAUTEUR_FACILE; j++)
                    {
                        if (carte.facile[i][j] == VIDE && decouvert.facile[i][j] == DECOUVERT)
                        {
                            if ( i != 0 && i != LARGEUR_FACILE -1 &&
                            j != 0 && j != HAUTEUR_FACILE -1 )
                            {// si on est au centre
                                 if ( carte.facile[i-1][j-1] == VIDE && decouvert.facile[i-1][j-1] == INDECOUVERT || // <^
                                carte.facile[i][j-1] == VIDE && decouvert.facile[i][j-1] == INDECOUVERT ||//^
                                carte.facile[i+1][j-1] == VIDE && decouvert.facile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.facile[i+1][j] == VIDE && decouvert.facile[i+1][j] == INDECOUVERT ||//>
                                carte.facile[i+1][j+1] == VIDE && decouvert.facile[i+1][j+1] == INDECOUVERT || //>v
                                carte.facile[i][j+1] == VIDE && decouvert.facile[i][j+1] == INDECOUVERT ||//v
                                carte.facile[i-1][j+1] == VIDE && decouvert.facile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.facile[i-1][j] == VIDE && decouvert.facile[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.facile[i][j-1] = DECOUVERT;//^
                                decouvert.facile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.facile[i+1][j] = DECOUVERT;//>
                                decouvert.facile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.facile[i][j+1] = DECOUVERT;//v
                                decouvert.facile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.facile[i-1][j] = DECOUVERT;//<
                            }

                            else if( i == 0 && j == 0)
                            {//si on est en haut a gauche
                                 if ( carte.facile[i+1][j] == VIDE && decouvert.facile[i+1][j] == INDECOUVERT ||//>
                                carte.facile[i+1][j+1] == VIDE && decouvert.facile[i+1][j+1] == INDECOUVERT || //>v
                                carte.facile[i][j+1] == VIDE && decouvert.facile[i][j+1] == INDECOUVERT )//v
                                {
                                    resteCase = true;
                                }

                                decouvert.facile[i+1][j] = DECOUVERT;//>
                                decouvert.facile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.facile[i][j+1] = DECOUVERT;//v


                            }

                            else if( i == LARGEUR_FACILE -1 && j == HAUTEUR_FACILE -1)
                            {//si on est en bas a droite
                                 if ( carte.facile[i-1][j] == VIDE && decouvert.facile[i-1][j] == INDECOUVERT || //<
                                carte.facile[i-1][j-1] == VIDE && decouvert.facile[i-1][j-1] == INDECOUVERT || // <^
                                carte.facile[i][j-1] == VIDE && decouvert.facile[i][j-1] == INDECOUVERT )//^
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i-1][j] = DECOUVERT;//<
                                decouvert.facile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.facile[i][j-1] = DECOUVERT;//^


                            }

                            else if( i == 0 && j == HAUTEUR_FACILE -1)
                            {//si on est en bas a gauche
                                if ( carte.facile[i][j-1] == VIDE && decouvert.facile[i][j-1] == INDECOUVERT ||//^
                                carte.facile[i+1][j-1] == VIDE && decouvert.facile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.facile[i+1][j] == VIDE && decouvert.facile[i+1][j] == INDECOUVERT )//>
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i][j-1] = DECOUVERT;//^
                                decouvert.facile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.facile[i+1][j] = DECOUVERT;//>

                            }

                            else if( i == LARGEUR_FACILE -1 && j == 0)
                            {//si on est en haut a droite
                                if (carte.facile[i][j+1] == VIDE && decouvert.facile[i][j+1] == INDECOUVERT ||//v
                                carte.facile[i-1][j+1] == VIDE && decouvert.facile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.facile[i-1][j] == VIDE && decouvert.facile[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i][j+1] = DECOUVERT;//v
                                decouvert.facile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.facile[i-1][j] = DECOUVERT;//<

                            }

                            else if( i == 0 && j != 0 && j != HAUTEUR_FACILE -1)
                            {//si on est a gauche
                                if ( carte.facile[i][j-1] == VIDE && decouvert.facile[i][j-1] == INDECOUVERT ||//^
                                carte.facile[i+1][j-1] == VIDE && decouvert.facile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.facile[i+1][j] == VIDE && decouvert.facile[i+1][j] == INDECOUVERT ||//>
                                carte.facile[i+1][j+1] == VIDE && decouvert.facile[i+1][j+1] == INDECOUVERT || //>v
                                carte.facile[i][j+1] == VIDE && decouvert.facile[i][j+1] == INDECOUVERT )//v
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i][j-1] = DECOUVERT;//^
                                decouvert.facile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.facile[i+1][j] = DECOUVERT;//>
                                decouvert.facile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.facile[i][j+1] = DECOUVERT;//v
                            }

                            else if( i != 0 && i != LARGEUR_FACILE -1 && j == 0)
                            {//si on est en haut
                                if ( carte.facile[i+1][j] == VIDE && decouvert.facile[i+1][j] == INDECOUVERT ||//>
                                carte.facile[i+1][j+1] == VIDE && decouvert.facile[i+1][j+1] == INDECOUVERT || //>v
                                carte.facile[i][j+1] == VIDE && decouvert.facile[i][j+1] == INDECOUVERT ||//v
                                carte.facile[i-1][j+1] == VIDE && decouvert.facile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.facile[i-1][j] == VIDE && decouvert.facile[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i+1][j] = DECOUVERT;//>
                                decouvert.facile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.facile[i][j+1] = DECOUVERT;//v
                                decouvert.facile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.facile[i-1][j] = DECOUVERT;//<
                            }

                            else if( i != 0 && i != LARGEUR_FACILE -1 && j == HAUTEUR_FACILE -1)
                            {//si on est en bas
                                if (carte.facile[i-1][j] == VIDE && decouvert.facile[i-1][j] == INDECOUVERT || //<
                                carte.facile[i-1][j-1] == VIDE && decouvert.facile[i-1][j-1] == INDECOUVERT || // <^
                                carte.facile[i][j-1] == VIDE && decouvert.facile[i][j-1] == INDECOUVERT ||//^
                                carte.facile[i+1][j-1] == VIDE && decouvert.facile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.facile[i+1][j] == VIDE && decouvert.facile[i+1][j] == INDECOUVERT )//>
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i-1][j] = DECOUVERT;//<
                                decouvert.facile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.facile[i][j-1] = DECOUVERT;//^
                                decouvert.facile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.facile[i+1][j] = DECOUVERT;//>
                            }

                            else if( i == LARGEUR_FACILE -1 && j != 0 && j != HAUTEUR_FACILE -1)
                            {//si on est a droite
                                if (carte.facile[i][j+1] == VIDE && decouvert.facile[i][j+1] == INDECOUVERT ||//v
                                carte.facile[i-1][j+1] == VIDE && decouvert.facile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.facile[i-1][j] == VIDE && decouvert.facile[i-1][j] == INDECOUVERT || //<
                                carte.facile[i-1][j-1] == VIDE && decouvert.facile[i-1][j-1] == INDECOUVERT || // <^
                                carte.facile[i][j-1] == VIDE && decouvert.facile[i][j-1] == INDECOUVERT)//^
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.facile[i][j+1] = DECOUVERT;//v
                                decouvert.facile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.facile[i-1][j] = DECOUVERT;//<
                                decouvert.facile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.facile[i][j-1] = DECOUVERT;//^
                            }
                        }
                    }
                }
            }
            break;


        case 2:
            if ( positionGrille.x != 0 && positionGrille.x != LARGEUR_MOYEN -1 &&
            positionGrille.y != 0 && positionGrille.y != HAUTEUR_MOYEN -1 )
            {// si on est au centre
                 if ( carte.moyen[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.moyen[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.moyen[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.moyen[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.moyen[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.moyen[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.moyen[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.moyen[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.moyen[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.moyen[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.moyen[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.moyen[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.moyen[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.moyen[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.moyen[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
            }

            else if( positionGrille.x == 0 && positionGrille.y == 0)
            {//si on est en haut a gauche
                 if ( carte.moyen[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.moyen[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.moyen[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y+1] == INDECOUVERT )//v
                {
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.moyen[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.moyen[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v


            }

            else if( positionGrille.x == LARGEUR_MOYEN -1 && positionGrille.y == HAUTEUR_MOYEN -1)
            {//si on est en bas a droite
                 if ( carte.moyen[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.moyen[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.moyen[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y-1] == INDECOUVERT )//^
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.moyen[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.moyen[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^


            }

            else if( positionGrille.x == 0 && positionGrille.y == HAUTEUR_MOYEN -1)
            {//si on est en bas a gauche
                if ( carte.moyen[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.moyen[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.moyen[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y] == INDECOUVERT )//>
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.moyen[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.moyen[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>

            }

            else if( positionGrille.x == LARGEUR_MOYEN -1 && positionGrille.y == 0)
            {//si on est en haut a droite
                if (carte.moyen[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.moyen[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.moyen[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.moyen[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.moyen[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<

            }

            else if( positionGrille.x == 0 && positionGrille.y != 0 && positionGrille.y != HAUTEUR_MOYEN -1)
            {//si on est a gauche
                if ( carte.moyen[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.moyen[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.moyen[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.moyen[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.moyen[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y+1] == INDECOUVERT )//v
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.moyen[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.moyen[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.moyen[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.moyen[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
            }

            else if( positionGrille.x != 0 && positionGrille.x != LARGEUR_MOYEN -1 && positionGrille.y == 0)
            {//si on est en haut
                if ( carte.moyen[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.moyen[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.moyen[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.moyen[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.moyen[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.moyen[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.moyen[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.moyen[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.moyen[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
            }

            else if( positionGrille.x != 0 && positionGrille.x != LARGEUR_MOYEN -1 && positionGrille.y == HAUTEUR_MOYEN -1)
            {//si on est en bas
                if (carte.moyen[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.moyen[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.moyen[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.moyen[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.moyen[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x+1][positionGrille.y] == INDECOUVERT )//>
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.moyen[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.moyen[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.moyen[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.moyen[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
            }

            else if( positionGrille.x == LARGEUR_MOYEN -1 && positionGrille.y != 0 && positionGrille.y != HAUTEUR_MOYEN -1)
            {//si on est a droite
                if (carte.moyen[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.moyen[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.moyen[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.moyen[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.moyen[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.moyen[positionGrille.x][positionGrille.y-1] == INDECOUVERT)//^
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.moyen[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.moyen[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.moyen[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.moyen[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.moyen[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
            }

            while (resteCase == true)
            {
                resteCase = false;
                for (i = 0; i < LARGEUR_MOYEN; i++)
                {
                    for (j = 0; j < HAUTEUR_MOYEN; j++)
                    {
                        if (carte.moyen[i][j] == VIDE && decouvert.moyen[i][j] == DECOUVERT)
                        {
                            if ( i != 0 && i != LARGEUR_MOYEN -1 &&
                            j != 0 && j != HAUTEUR_MOYEN -1 )
                            {// si on est au centre
                                 if ( carte.moyen[i-1][j-1] == VIDE && decouvert.moyen[i-1][j-1] == INDECOUVERT || // <^
                                carte.moyen[i][j-1] == VIDE && decouvert.moyen[i][j-1] == INDECOUVERT ||//^
                                carte.moyen[i+1][j-1] == VIDE && decouvert.moyen[i+1][j-1] == INDECOUVERT ||//>^
                                carte.moyen[i+1][j] == VIDE && decouvert.moyen[i+1][j] == INDECOUVERT ||//>
                                carte.moyen[i+1][j+1] == VIDE && decouvert.moyen[i+1][j+1] == INDECOUVERT || //>v
                                carte.moyen[i][j+1] == VIDE && decouvert.moyen[i][j+1] == INDECOUVERT ||//v
                                carte.moyen[i-1][j+1] == VIDE && decouvert.moyen[i-1][j+1] == INDECOUVERT ||//<v
                                carte.moyen[i-1][j] == VIDE && decouvert.moyen[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i-1][j-1] = DECOUVERT;// <^
                                decouvert.moyen[i][j-1] = DECOUVERT;//^
                                decouvert.moyen[i+1][j-1] = DECOUVERT;//>^
                                decouvert.moyen[i+1][j] = DECOUVERT;//>
                                decouvert.moyen[i+1][j+1] = DECOUVERT;//>v
                                decouvert.moyen[i][j+1] = DECOUVERT;//v
                                decouvert.moyen[i-1][j+1] = DECOUVERT;//<v
                                decouvert.moyen[i-1][j] = DECOUVERT;//<
                            }

                            else if( i == 0 && j == 0)
                            {//si on est en haut a gauche
                                 if ( carte.moyen[i+1][j] == VIDE && decouvert.moyen[i+1][j] == INDECOUVERT ||//>
                                carte.moyen[i+1][j+1] == VIDE && decouvert.moyen[i+1][j+1] == INDECOUVERT || //>v
                                carte.moyen[i][j+1] == VIDE && decouvert.moyen[i][j+1] == INDECOUVERT )//v
                                {
                                    resteCase = true;
                                }

                                decouvert.moyen[i+1][j] = DECOUVERT;//>
                                decouvert.moyen[i+1][j+1] = DECOUVERT;//>v
                                decouvert.moyen[i][j+1] = DECOUVERT;//v


                            }

                            else if( i == LARGEUR_MOYEN -1 && j == HAUTEUR_MOYEN -1)
                            {//si on est en bas a droite
                                 if ( carte.moyen[i-1][j] == VIDE && decouvert.moyen[i-1][j] == INDECOUVERT || //<
                                carte.moyen[i-1][j-1] == VIDE && decouvert.moyen[i-1][j-1] == INDECOUVERT || // <^
                                carte.moyen[i][j-1] == VIDE && decouvert.moyen[i][j-1] == INDECOUVERT )//^
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i-1][j] = DECOUVERT;//<
                                decouvert.moyen[i-1][j-1] = DECOUVERT;// <^
                                decouvert.moyen[i][j-1] = DECOUVERT;//^


                            }

                            else if( i == 0 && j == HAUTEUR_MOYEN -1)
                            {//si on est en bas a gauche
                                if ( carte.moyen[i][j-1] == VIDE && decouvert.moyen[i][j-1] == INDECOUVERT ||//^
                                carte.moyen[i+1][j-1] == VIDE && decouvert.moyen[i+1][j-1] == INDECOUVERT ||//>^
                                carte.moyen[i+1][j] == VIDE && decouvert.moyen[i+1][j] == INDECOUVERT )//>
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i][j-1] = DECOUVERT;//^
                                decouvert.moyen[i+1][j-1] = DECOUVERT;//>^
                                decouvert.moyen[i+1][j] = DECOUVERT;//>

                            }

                            else if( i == LARGEUR_MOYEN -1 && j == 0)
                            {//si on est en haut a droite
                                if (carte.moyen[i][j+1] == VIDE && decouvert.moyen[i][j+1] == INDECOUVERT ||//v
                                carte.moyen[i-1][j+1] == VIDE && decouvert.moyen[i-1][j+1] == INDECOUVERT ||//<v
                                carte.moyen[i-1][j] == VIDE && decouvert.moyen[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i][j+1] = DECOUVERT;//v
                                decouvert.moyen[i-1][j+1] = DECOUVERT;//<v
                                decouvert.moyen[i-1][j] = DECOUVERT;//<

                            }

                            else if( i == 0 && j != 0 && j != HAUTEUR_MOYEN -1)
                            {//si on est a gauche
                                if ( carte.moyen[i][j-1] == VIDE && decouvert.moyen[i][j-1] == INDECOUVERT ||//^
                                carte.moyen[i+1][j-1] == VIDE && decouvert.moyen[i+1][j-1] == INDECOUVERT ||//>^
                                carte.moyen[i+1][j] == VIDE && decouvert.moyen[i+1][j] == INDECOUVERT ||//>
                                carte.moyen[i+1][j+1] == VIDE && decouvert.moyen[i+1][j+1] == INDECOUVERT || //>v
                                carte.moyen[i][j+1] == VIDE && decouvert.moyen[i][j+1] == INDECOUVERT )//v
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i][j-1] = DECOUVERT;//^
                                decouvert.moyen[i+1][j-1] = DECOUVERT;//>^
                                decouvert.moyen[i+1][j] = DECOUVERT;//>
                                decouvert.moyen[i+1][j+1] = DECOUVERT;//>v
                                decouvert.moyen[i][j+1] = DECOUVERT;//v
                            }

                            else if( i != 0 && i != LARGEUR_MOYEN -1 && j == 0)
                            {//si on est en haut
                                if ( carte.moyen[i+1][j] == VIDE && decouvert.moyen[i+1][j] == INDECOUVERT ||//>
                                carte.moyen[i+1][j+1] == VIDE && decouvert.moyen[i+1][j+1] == INDECOUVERT || //>v
                                carte.moyen[i][j+1] == VIDE && decouvert.moyen[i][j+1] == INDECOUVERT ||//v
                                carte.moyen[i-1][j+1] == VIDE && decouvert.moyen[i-1][j+1] == INDECOUVERT ||//<v
                                carte.moyen[i-1][j] == VIDE && decouvert.moyen[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i+1][j] = DECOUVERT;//>
                                decouvert.moyen[i+1][j+1] = DECOUVERT;//>v
                                decouvert.moyen[i][j+1] = DECOUVERT;//v
                                decouvert.moyen[i-1][j+1] = DECOUVERT;//<v
                                decouvert.moyen[i-1][j] = DECOUVERT;//<
                            }

                            else if( i != 0 && i != LARGEUR_MOYEN -1 && j == HAUTEUR_MOYEN -1)
                            {//si on est en bas
                                if (carte.moyen[i-1][j] == VIDE && decouvert.moyen[i-1][j] == INDECOUVERT || //<
                                carte.moyen[i-1][j-1] == VIDE && decouvert.moyen[i-1][j-1] == INDECOUVERT || // <^
                                carte.moyen[i][j-1] == VIDE && decouvert.moyen[i][j-1] == INDECOUVERT ||//^
                                carte.moyen[i+1][j-1] == VIDE && decouvert.moyen[i+1][j-1] == INDECOUVERT ||//>^
                                carte.moyen[i+1][j] == VIDE && decouvert.moyen[i+1][j] == INDECOUVERT )//>
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i-1][j] = DECOUVERT;//<
                                decouvert.moyen[i-1][j-1] = DECOUVERT;// <^
                                decouvert.moyen[i][j-1] = DECOUVERT;//^
                                decouvert.moyen[i+1][j-1] = DECOUVERT;//>^
                                decouvert.moyen[i+1][j] = DECOUVERT;//>
                            }

                            else if( i == LARGEUR_MOYEN -1 && j != 0 && j != HAUTEUR_MOYEN -1)
                            {//si on est a droite
                                if (carte.moyen[i][j+1] == VIDE && decouvert.moyen[i][j+1] == INDECOUVERT ||//v
                                carte.moyen[i-1][j+1] == VIDE && decouvert.moyen[i-1][j+1] == INDECOUVERT ||//<v
                                carte.moyen[i-1][j] == VIDE && decouvert.moyen[i-1][j] == INDECOUVERT || //<
                                carte.moyen[i-1][j-1] == VIDE && decouvert.moyen[i-1][j-1] == INDECOUVERT || // <^
                                carte.moyen[i][j-1] == VIDE && decouvert.moyen[i][j-1] == INDECOUVERT)//^
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.moyen[i][j+1] = DECOUVERT;//v
                                decouvert.moyen[i-1][j+1] = DECOUVERT;//<v
                                decouvert.moyen[i-1][j] = DECOUVERT;//<
                                decouvert.moyen[i-1][j-1] = DECOUVERT;// <^
                                decouvert.moyen[i][j-1] = DECOUVERT;//^
                            }
                        }
                    }
                }
            }
            break;

        case 3:
            if ( positionGrille.x != 0 && positionGrille.x != LARGEUR_DIFFICILE -1 &&
            positionGrille.y != 0 && positionGrille.y != HAUTEUR_DIFFICILE -1 )
            {// si on est au centre
                 if ( carte.difficile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.difficile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.difficile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.difficile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.difficile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.difficile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.difficile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.difficile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.difficile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.difficile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.difficile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.difficile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.difficile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.difficile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.difficile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
            }

            else if( positionGrille.x == 0 && positionGrille.y == 0)
            {//si on est en haut a gauche
                 if ( carte.difficile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.difficile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.difficile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y+1] == INDECOUVERT )//v
                {
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.difficile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.difficile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v


            }

            else if( positionGrille.x == LARGEUR_DIFFICILE -1 && positionGrille.y == HAUTEUR_DIFFICILE -1)
            {//si on est en bas a droite
                 if ( carte.difficile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.difficile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.difficile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y-1] == INDECOUVERT )//^
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.difficile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.difficile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^


            }

            else if( positionGrille.x == 0 && positionGrille.y == HAUTEUR_DIFFICILE -1)
            {//si on est en bas a gauche
                if ( carte.difficile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.difficile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.difficile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y] == INDECOUVERT )//>
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.difficile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.difficile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>

            }

            else if( positionGrille.x == LARGEUR_DIFFICILE -1 && positionGrille.y == 0)
            {//si on est en haut a droite
                if (carte.difficile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.difficile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.difficile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.difficile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.difficile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<

            }

            else if( positionGrille.x == 0 && positionGrille.y != 0 && positionGrille.y != HAUTEUR_DIFFICILE -1)
            {//si on est a gauche
                if ( carte.difficile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.difficile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.difficile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.difficile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.difficile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y+1] == INDECOUVERT )//v
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.difficile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.difficile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.difficile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.difficile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
            }

            else if( positionGrille.x != 0 && positionGrille.x != LARGEUR_DIFFICILE -1 && positionGrille.y == 0)
            {//si on est en haut
                if ( carte.difficile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y] == INDECOUVERT ||//>
                carte.difficile[positionGrille.x+1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y+1] == INDECOUVERT || //>v
                carte.difficile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.difficile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.difficile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y] == INDECOUVERT) //<
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
                decouvert.difficile[positionGrille.x+1][positionGrille.y+1] = DECOUVERT;//>v
                decouvert.difficile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.difficile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.difficile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
            }

            else if( positionGrille.x != 0 && positionGrille.x != LARGEUR_DIFFICILE -1 && positionGrille.y == HAUTEUR_DIFFICILE -1)
            {//si on est en bas
                if (carte.difficile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.difficile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.difficile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y-1] == INDECOUVERT ||//^
                carte.difficile[positionGrille.x+1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y-1] == INDECOUVERT ||//>^
                carte.difficile[positionGrille.x+1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x+1][positionGrille.y] == INDECOUVERT )//>
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.difficile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.difficile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
                decouvert.difficile[positionGrille.x+1][positionGrille.y-1] = DECOUVERT;//>^
                decouvert.difficile[positionGrille.x+1][positionGrille.y] = DECOUVERT;//>
            }

            else if( positionGrille.x == LARGEUR_DIFFICILE -1 && positionGrille.y != 0 && positionGrille.y != HAUTEUR_DIFFICILE -1)
            {//si on est a droite
                if (carte.difficile[positionGrille.x][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y+1] == INDECOUVERT ||//v
                carte.difficile[positionGrille.x-1][positionGrille.y+1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y+1] == INDECOUVERT ||//<v
                carte.difficile[positionGrille.x-1][positionGrille.y] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y] == INDECOUVERT || //<
                carte.difficile[positionGrille.x-1][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x-1][positionGrille.y-1] == INDECOUVERT || // <^
                carte.difficile[positionGrille.x][positionGrille.y-1] == VIDE && decouvert.difficile[positionGrille.x][positionGrille.y-1] == INDECOUVERT)//^
                {//si une des cases autour est vide, on continue
                    resteCase = true;
                }

                decouvert.difficile[positionGrille.x][positionGrille.y+1] = DECOUVERT;//v
                decouvert.difficile[positionGrille.x-1][positionGrille.y+1] = DECOUVERT;//<v
                decouvert.difficile[positionGrille.x-1][positionGrille.y] = DECOUVERT;//<
                decouvert.difficile[positionGrille.x-1][positionGrille.y-1] = DECOUVERT;// <^
                decouvert.difficile[positionGrille.x][positionGrille.y-1] = DECOUVERT;//^
            }

            while (resteCase == true)
            {
                resteCase = false;
                for (i = 0; i < LARGEUR_DIFFICILE; i++)
                {
                    for (j = 0; j < HAUTEUR_DIFFICILE; j++)
                    {
                        if (carte.difficile[i][j] == VIDE && decouvert.difficile[i][j] == DECOUVERT)
                        {
                            if ( i != 0 && i != LARGEUR_DIFFICILE -1 &&
                            j != 0 && j != HAUTEUR_DIFFICILE -1 )
                            {// si on est au centre
                                 if ( carte.difficile[i-1][j-1] == VIDE && decouvert.difficile[i-1][j-1] == INDECOUVERT || // <^
                                carte.difficile[i][j-1] == VIDE && decouvert.difficile[i][j-1] == INDECOUVERT ||//^
                                carte.difficile[i+1][j-1] == VIDE && decouvert.difficile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.difficile[i+1][j] == VIDE && decouvert.difficile[i+1][j] == INDECOUVERT ||//>
                                carte.difficile[i+1][j+1] == VIDE && decouvert.difficile[i+1][j+1] == INDECOUVERT || //>v
                                carte.difficile[i][j+1] == VIDE && decouvert.difficile[i][j+1] == INDECOUVERT ||//v
                                carte.difficile[i-1][j+1] == VIDE && decouvert.difficile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.difficile[i-1][j] == VIDE && decouvert.difficile[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.difficile[i][j-1] = DECOUVERT;//^
                                decouvert.difficile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.difficile[i+1][j] = DECOUVERT;//>
                                decouvert.difficile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.difficile[i][j+1] = DECOUVERT;//v
                                decouvert.difficile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.difficile[i-1][j] = DECOUVERT;//<
                            }

                            else if( i == 0 && j == 0)
                            {//si on est en haut a gauche
                                 if ( carte.difficile[i+1][j] == VIDE && decouvert.difficile[i+1][j] == INDECOUVERT ||//>
                                carte.difficile[i+1][j+1] == VIDE && decouvert.difficile[i+1][j+1] == INDECOUVERT || //>v
                                carte.difficile[i][j+1] == VIDE && decouvert.difficile[i][j+1] == INDECOUVERT )//v
                                {
                                    resteCase = true;
                                }

                                decouvert.difficile[i+1][j] = DECOUVERT;//>
                                decouvert.difficile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.difficile[i][j+1] = DECOUVERT;//v


                            }

                            else if( i == LARGEUR_DIFFICILE -1 && j == HAUTEUR_DIFFICILE -1)
                            {//si on est en bas a droite
                                 if ( carte.difficile[i-1][j] == VIDE && decouvert.difficile[i-1][j] == INDECOUVERT || //<
                                carte.difficile[i-1][j-1] == VIDE && decouvert.difficile[i-1][j-1] == INDECOUVERT || // <^
                                carte.difficile[i][j-1] == VIDE && decouvert.difficile[i][j-1] == INDECOUVERT )//^
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i-1][j] = DECOUVERT;//<
                                decouvert.difficile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.difficile[i][j-1] = DECOUVERT;//^


                            }

                            else if( i == 0 && j == HAUTEUR_DIFFICILE -1)
                            {//si on est en bas a gauche
                                if ( carte.difficile[i][j-1] == VIDE && decouvert.difficile[i][j-1] == INDECOUVERT ||//^
                                carte.difficile[i+1][j-1] == VIDE && decouvert.difficile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.difficile[i+1][j] == VIDE && decouvert.difficile[i+1][j] == INDECOUVERT )//>
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i][j-1] = DECOUVERT;//^
                                decouvert.difficile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.difficile[i+1][j] = DECOUVERT;//>

                            }

                            else if( i == LARGEUR_DIFFICILE -1 && j == 0)
                            {//si on est en haut a droite
                                if (carte.difficile[i][j+1] == VIDE && decouvert.difficile[i][j+1] == INDECOUVERT ||//v
                                carte.difficile[i-1][j+1] == VIDE && decouvert.difficile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.difficile[i-1][j] == VIDE && decouvert.difficile[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i][j+1] = DECOUVERT;//v
                                decouvert.difficile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.difficile[i-1][j] = DECOUVERT;//<

                            }

                            else if( i == 0 && j != 0 && j != HAUTEUR_DIFFICILE -1)
                            {//si on est a gauche
                                if ( carte.difficile[i][j-1] == VIDE && decouvert.difficile[i][j-1] == INDECOUVERT ||//^
                                carte.difficile[i+1][j-1] == VIDE && decouvert.difficile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.difficile[i+1][j] == VIDE && decouvert.difficile[i+1][j] == INDECOUVERT ||//>
                                carte.difficile[i+1][j+1] == VIDE && decouvert.difficile[i+1][j+1] == INDECOUVERT || //>v
                                carte.difficile[i][j+1] == VIDE && decouvert.difficile[i][j+1] == INDECOUVERT )//v
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i][j-1] = DECOUVERT;//^
                                decouvert.difficile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.difficile[i+1][j] = DECOUVERT;//>
                                decouvert.difficile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.difficile[i][j+1] = DECOUVERT;//v
                            }

                            else if( i != 0 && i != LARGEUR_DIFFICILE -1 && j == 0)
                            {//si on est en haut
                                if ( carte.difficile[i+1][j] == VIDE && decouvert.difficile[i+1][j] == INDECOUVERT ||//>
                                carte.difficile[i+1][j+1] == VIDE && decouvert.difficile[i+1][j+1] == INDECOUVERT || //>v
                                carte.difficile[i][j+1] == VIDE && decouvert.difficile[i][j+1] == INDECOUVERT ||//v
                                carte.difficile[i-1][j+1] == VIDE && decouvert.difficile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.difficile[i-1][j] == VIDE && decouvert.difficile[i-1][j] == INDECOUVERT) //<
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i+1][j] = DECOUVERT;//>
                                decouvert.difficile[i+1][j+1] = DECOUVERT;//>v
                                decouvert.difficile[i][j+1] = DECOUVERT;//v
                                decouvert.difficile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.difficile[i-1][j] = DECOUVERT;//<
                            }

                            else if( i != 0 && i != LARGEUR_DIFFICILE -1 && j == HAUTEUR_DIFFICILE -1)
                            {//si on est en bas
                                if (carte.difficile[i-1][j] == VIDE && decouvert.difficile[i-1][j] == INDECOUVERT || //<
                                carte.difficile[i-1][j-1] == VIDE && decouvert.difficile[i-1][j-1] == INDECOUVERT || // <^
                                carte.difficile[i][j-1] == VIDE && decouvert.difficile[i][j-1] == INDECOUVERT ||//^
                                carte.difficile[i+1][j-1] == VIDE && decouvert.difficile[i+1][j-1] == INDECOUVERT ||//>^
                                carte.difficile[i+1][j] == VIDE && decouvert.difficile[i+1][j] == INDECOUVERT )//>
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i-1][j] = DECOUVERT;//<
                                decouvert.difficile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.difficile[i][j-1] = DECOUVERT;//^
                                decouvert.difficile[i+1][j-1] = DECOUVERT;//>^
                                decouvert.difficile[i+1][j] = DECOUVERT;//>
                            }

                            else if( i == LARGEUR_DIFFICILE -1 && j != 0 && j != HAUTEUR_DIFFICILE -1)
                            {//si on est a droite
                                if (carte.difficile[i][j+1] == VIDE && decouvert.difficile[i][j+1] == INDECOUVERT ||//v
                                carte.difficile[i-1][j+1] == VIDE && decouvert.difficile[i-1][j+1] == INDECOUVERT ||//<v
                                carte.difficile[i-1][j] == VIDE && decouvert.difficile[i-1][j] == INDECOUVERT || //<
                                carte.difficile[i-1][j-1] == VIDE && decouvert.difficile[i-1][j-1] == INDECOUVERT || // <^
                                carte.difficile[i][j-1] == VIDE && decouvert.difficile[i][j-1] == INDECOUVERT)//^
                                {//si une des cases autour est vide, on continue
                                    resteCase = true;
                                }

                                decouvert.difficile[i][j+1] = DECOUVERT;//v
                                decouvert.difficile[i-1][j+1] = DECOUVERT;//<v
                                decouvert.difficile[i-1][j] = DECOUVERT;//<
                                decouvert.difficile[i-1][j-1] = DECOUVERT;// <^
                                decouvert.difficile[i][j-1] = DECOUVERT;//^
                            }
                        }
                    }
                }
            }
            break;

    }
    return decouvert;
}




