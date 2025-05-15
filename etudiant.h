#ifndef ETUDIANT_H
#define ETUDIANT_H
typedef struct Horaire{
    int heure,annee,jour;
    char date[10],mois[10];
} Horaire;
typedef struct Etudiant
{ 
    char nom[17],prenom[17],matricule[16],numero[17],role[20];
    int age;
    Horaire t;
    long montant;
} Etudiant;
void ajoutemembre(Etudiant L);
void supprimemembre(Etudiant L,char m);
int recherchemembre(Etudiant L,char m);
void modificationmembre(Etudiant L,char m);
void affichage_membres(Etudiant L);
#endif