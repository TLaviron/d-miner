/* genererNiveau.h

Par Little Dragoon

contient le générateur de niveau*/

#ifndef GENERER_NIVEAU
#define GENERER_NIVEAU


typedef struct Grille Grille;
struct Grille
{
    char facile[LARGEUR_FACILE][HAUTEUR_FACILE];
    char moyen[LARGEUR_MOYEN][HAUTEUR_MOYEN];
    char difficile[LARGEUR_DIFFICILE][HAUTEUR_DIFFICILE];
};

Grille genererNiveau (Grille carte, long difficulte);

Grille remplirNiveau (Grille carte, long difficulte);

Grille decouvrirNiveau (Grille carte, long difficulte, SDL_Rect positionGrille, Grille decouvert);




#endif



