#include <stdio.h>
#include <string.h>
#include "etablissement.h"

void ajouter_etablissement(Etablissement *e) {
    printf("Entrer le numéro de l'établissement: ");
    scanf("%d", &e->numero);
    printf("Entrer l'intitulé de l'établissement: ");
    scanf("%s", e->intitule);
    printf("Entrer la date de création (JJ-MM-AAAA): ");
    scanf("%s", e->date_creation);
    e->nb_filieres = 0;
}

void ajouter_filiere_etablissement(Etablissement *e) {
    Filiere f;
    ajouter_filiere(&f);
    e->filieres[e->nb_filieres++] = f;
}

void afficher_etablissement(Etablissement e) {
    printf("Etablissement: %s, Date de création: %s\n", e.intitule, e.date_creation);
    for (int i = 0; i < e.nb_filieres; i++) {
        afficher_filiere(e.filieres[i]);
    }
}

int rechercher_filiere_etablissement(Etablissement e, char code[]) {
    for (int i = 0; i < e.nb_filieres; i++) {
        if (strcmp(e.filieres[i].code, code) == 0) {
            return i; // Retourne l'indexe de la filiere
        }
    }
    return -1; // Filière pas trouve
}