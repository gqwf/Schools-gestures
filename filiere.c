#include <stdio.h>
#include <string.h>
#include "filiere.h"

void ajouter_filiere(Filiere *f) {
    printf("Entrer le code de la filière: ");
    scanf("%s", f->code);
    printf("Entrer l'intitulé de la filière: ");
    scanf("%s", f->intitule);
    printf("Entrer le niveau de la filière (Licence/Master): ");
    scanf("%s", f->niveau);
    f->nb_etudiants = 0;
}

void ajouter_etudiant_filiere(Filiere *f, Etudiant e) {
    f->etudiants[f->nb_etudiants++] = e;
    ajoutemembre(e); // Save to file
}

void afficher_filiere(Filiere f) {
    printf("Filière: %s (%s)\n", f.intitule, f.niveau);
    for (int i = 0; i < f.nb_etudiants; i++) {
        printf("Etudiant: %s %s, Matricule: %s\n", f.etudiants[i].nom, f.etudiants[i].prenom, f.etudiants[i].matricule);
    }
}

int rechercher_etudiant_filiere(Filiere f, char matricule[]) {
    for (int i = 0; i < f.nb_etudiants; i++) {
        if (strcmp(f.etudiants[i].matricule, matricule) == 0) {
            return i; // Retourne l'indexe de l'etudiant
        }
    }
    return -1; // Etudiant pas trouve
}