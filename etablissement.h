#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include "filiere.h"

typedef struct Etablissement {
    int numero;
    char intitule[50];
    char date_creation[10];
    Filiere filieres[10]; // Liste de filières
    int nb_filieres;
} Etablissement;

void ajouter_etablissement(Etablissement *e);
void ajouter_filiere_etablissement(Etablissement *e);
void afficher_etablissement(Etablissement e);
int rechercher_filiere_etablissement(Etablissement e, char code[]);

#endif