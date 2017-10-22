/*constantes.h

par Little Dragoon

définit des constantes communes à tout le programme
*/

#ifndef CONSTANTES
#define CONSTANTES

    #define TAILLE_BLOC             15
    #define TAILLE_BORDURE          13
    #define NB_BLOCS_HAUTEUR        40
    #define NB_BLOCS_LARGEUR        40
    #define TAILLE_HAUT             100 - TAILLE_BORDURE
    #define HAUTEUR_FENETRE         TAILLE_BLOC * NB_BLOCS_HAUTEUR + TAILLE_BORDURE * 3 + TAILLE_HAUT
    #define LARGEUR_FENETRE         TAILLE_BLOC * NB_BLOCS_LARGEUR + TAILLE_BORDURE * 2
    #define LARGEUR_FACILE          12
    #define HAUTEUR_FACILE          12
    #define MINES_FACILE            15
    #define LARGEUR_MOYEN           25
    #define HAUTEUR_MOYEN           20
    #define MINES_MOYEN             70
    #define LARGEUR_DIFFICILE       40
    #define HAUTEUR_DIFFICILE       40
    #define MINES_DIFFICILE         250

    enum {VIDE, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, MINE, MINE_ROUGE, PLEIN, DRAPEAU, DRAPEAU_BARRE};
    enum {NORMAL, HAPPY, BOUM, CLIC, BOUM_CLIC};
    enum {INDECOUVERT, DECOUVERT, CASE_MINEE};



#endif

