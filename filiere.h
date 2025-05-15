#ifndef FILIERE_H
#define FILIERE_H

#include "etudiant.h"

typedef struct Filiere {
    char code[10];
    char intitule[50];
    char niveau[20]; // Licence, Master
    Etudiant etudiants[100]; // Liste d'étudiants
    int nb_etudiants;
} Filiere;

void ajouter_filiere(Filiere *f);
void ajouter_etudiant_filiere(Filiere *f, Etudiant e);
void afficher_filiere(Filiere f);
int rechercher_etudiant_filiere(Filiere f, char matricule[]);

#endif