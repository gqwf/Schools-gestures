#include <stdio.h>
#include <string.h>
#include "etudiant.h"
#include "filiere.h"
#include "etablissement.h"

#define MAX_ETUDIANTS 100
#define MAX_FILIERES 10
#define MAX_ETABLISSEMENTS 10

int main() {
    Etudiant etudiants[MAX_ETUDIANTS];
    Filiere filieres[MAX_FILIERES];
    Etablissement etablissements[MAX_ETABLISSEMENTS];
    float budget = 0.0;
    int nombre_etudiants = 0;
    int nombre_filieres = 0;
    int nombre_etablissements = 0;

    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter étudiant\n");
        printf("2. Afficher étudiants\n");
        printf("3. Mettre à jour étudiant\n");
        printf("4. Supprimer étudiant\n");
        printf("5. Ajouter filière\n");
        printf("6. Afficher filières\n");
        printf("7. Ajouter établissement\n");
        printf("8. Afficher établissements\n");
        printf("9. Mettre à jour budget\n");
        printf("10. Afficher budget\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                // ajout etudiant
                Etudiant e;
                printf("Ajouter un étudiant:\n");
                printf("Nom: ");
                scanf("%s", e.nom);
                printf("Prénom: ");
                scanf("%s", e.prenom);
                printf("Matricule: ");
                scanf("%s", e.matricule);
                printf("Âge: ");
                scanf("%d", &e.age);
                printf("Montant: ");
                scanf("%ld", &e.montant);
                etudiants[nombre_etudiants++] = e;
                ajoutemembre(e); // Save to file
                break;
            }

            case 2: {
                // affichage etudiant
                printf("Liste des étudiants:\n");
                for (int i = 0; i < nombre_etudiants; i++) {
                    printf("%s %s, Matricule: %s\n", etudiants[i].nom, etudiants[i].prenom, etudiants[i].matricule);
                }
                break;
            }

            case 3: {
                // Modifie etudiant
                char matricule[16];
                printf("Entrer le matricule de l'étudiant à mettre à jour: ");
                scanf("%s", matricule);
                
                int found = 0;
                for (int i = 0; i < nombre_etudiants; i++) {
                    if (strcmp(etudiants[i].matricule, matricule) == 0) {
                        found = 1;
                        printf("Mettre à jour les informations de l'étudiant:\n");
                        printf("Nom (actuel: %s): ", etudiants[i].nom);
                        scanf("%s", etudiants[i].nom);
                        printf("Prénom (actuel: %s): ", etudiants[i].prenom);
                        scanf("%s", etudiants[i].prenom);
                        printf("Âge (actuel: %d): ", etudiants[i].age);
                        scanf("%d", &etudiants[i].age);
                        printf("Montant (actuel: %ld): ", etudiants[i].montant);
                        scanf("%ld", &etudiants[i].montant);
                        // Sauvegarde
                        printf("Informations mises à jour.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Étudiant avec matricule %s non trouvé.\n", matricule);
                }
                break;
            }

            case 4: {
                // suprime etudiant
                char matricule[16];
                printf("Entrer le matricule de l'étudiant à supprimer: ");
                scanf("%s", matricule);
                
                int found = 0;
                for (int i = 0; i < nombre_etudiants; i++) {
                    if (strcmp(etudiants[i].matricule, matricule) == 0) {
                        found = 1;
                        
                        for (int j = i; j < nombre_etudiants - 1; j++) {
                            etudiants[j] = etudiants[j + 1];
                        }
                        nombre_etudiants--;
                        printf("Étudiant avec matricule %s supprimé.\n", matricule);
                        break;
                    }
                }
                if (!found) {
                    printf("Étudiant avec matricule %s non trouvé.\n", matricule);
                }
                break;
            }

            case 5: {
                // ajoutfilière
                Filiere f;
                ajouter_filiere(&f);
                filieres[nombre_filieres++] = f;
                break;
            }

            case 6: {
                // montrer filières
                printf("Liste des filières:\n");
                for (int i = 0; i < nombre_filieres; i++) {
                    afficher_filiere(filieres[i]);
                }
                break;
            }

            case 7: {
                // ajout etablissement
                Etablissement eTab;
                ajouter_etablissement(&eTab);
                etablissements[nombre_etablissements++] = eTab;
                break;
            }

            case 8: {
                // montrer etablissement
                printf("Liste des établissements:\n");
                for (int i = 0; i < nombre_etablissements; i++) {
                    afficher_etablissement(etablissements[i]);
                }
                break;
            }

            case 9: {
                float montant;
                int type;
                printf("Entrer le montant: ");
                scanf("%f", &montant);
                printf("Type (1 pour ajouter, 2 pour déduire): ");
                scanf("%d", &type);
                if (type == 1) {
                    budget += montant;
                } else if (type == 2) {
                    budget -= montant;
                }
                break;
            }

            case 10:
                // Montre budget
                printf("Budget actuel: %.2f\n", budget);
                break;

            case 0:
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}