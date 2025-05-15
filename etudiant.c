#include<stdio.h>
#include<string.h>
#include"etudiant.h"
void ajoutemembre(Etudiant L){
    FILE* f=fopen("etudiant.txt","a");
    FILE* f1=fopen("montant.txt","r");
    long m1;
    printf("entrer le nom du nouveau membre:");
    scanf("%s",L.nom);
    printf("entrer le prenom du nouveau membre:");
    scanf("%s",L.prenom);
    printf("entrer le matricule du nouveau membre:");
    scanf("%s",L.matricule);
    printf("entrer le role du nouveau membre:");
    scanf("%s",L.role);
    printf("entrer l'age du nouveau membre:");
    scanf("%d",&L.age);
    printf("entrer le numero de telephone du nouveau membre:");
    scanf("%s",L.numero);
    printf("entrer la somme d'aderation du nouveau membre:");
    scanf("%ld",&L.montant);
    fscanf(f1,"%ld",&m1);
    if(L.montant<(int)m1/3||(L.montant>(int)m1/3 && L.montant<(int)(2*(m1/3)+m1%3))||(L.montant>(int)m1/3+m1%3 && L.montant<(int)(3*(m1/3)+m1%3))){
        printf("le montant est incorrecte!!!!\n");
        printf("le montant est payable en 3 tranches %d XAF,%d XAF ou %d XAF\n",(int)m1/3,(int)(2*(m1/3)+m1%3),(int)(3*(m1/3)+m1%3));
        do{
            printf("entrer un nouveau montant qui soit %d XAF,%d XAF ou %d XAF",(int)m1/3,(int)(2*(m1/3)+m1%3),(int)(3*(m1/3)+m1%3));
            scanf("%ld",&L.montant);
        }while(L.montant!=(int)m1/3||L.montant!=(int)(2*(m1/3)+m1%3)||L.montant!=(int)(3*(m1/3)+m1%3));
    }
    printf("vous etez disponible quand:");
    scanf("%s %*s %d %s %d",L.t.date,&L.t.jour,L.t.mois,&L.t.annee);
    fprintf(f,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,L.age,L.numero,L.montant,L.t.date,L.t.jour,L.t.mois,L.t.annee);
    fclose(f);
    fclose(f1);
}
void supprimemembre(Etudiant L,char *m){
    FILE* f=fopen("etudiant.txt","r");
    FILE* f1=fopen("etud.txt","w");
    do{
         fscanf(f,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,&L.age,L.numero,&L.montant,L.t.date,&L.t.jour,L.t.mois,&L.t.annee);
         if(strcmp(L.matricule,m)!=0){
            fprintf(f1,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,L.age,L.numero,L.montant,L.t.date,L.t.jour,L.t.mois,L.t.annee);
         }
    }while(!feof(f));
    fclose(f);
    remove("etudiant.txt");
    fclose(f1);
    rename("etud.txt","etudiant.txt");
}
int recherchemembre(Etudiant L,char m[]){
    FILE* f=fopen("etudiant.txt","r");
    do{
         fscanf(f,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,&L.age,L.numero,&L.montant,L.t.date,&L.t.jour,L.t.mois,&L.t.annee);
         if(strcmp(L.matricule,m)==0){
            return 1;
         }else{
            return 0;
         }
    }while(!feof(f));
}
void modificationmembre(Etudiant L,char m){
      FILE* f=fopen("etudiant.txt","r");
      FILE* f1=fopen("etud.txt","w");
      long m1;
    do{
         fscanf(f,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,&L.age,L.numero,&L.montant,L.t.date,&L.t.jour,L.t.mois,&L.t.annee);
         if(strcmp(L.matricule,m)==0){
    printf("entrer le nom du nouveau membre:");
    scanf("%s",L.nom);
    printf("entrer le prenom du nouveau membre:");
    scanf("%s",L.prenom);
    printf("entrer le matricule du nouveau membre:");
    scanf("%s",L.matricule);
    printf("entrer le role du nouveau membre:");
    scanf("%s",L.role);
    printf("entrer l'age du nouveau membre:");
    scanf("%d",&L.age);
    printf("entrer le numero de telephone du nouveau membre:");
    scanf("%s",L.numero);
    printf("entrer la somme d'aderation du nouveau membre:");
    scanf("%ld",&L.montant);
    fscanf(f1,"%ld",&m1);
    if(L.montant<(int)m1/3||(L.montant>(int)m1/3 && L.montant<(int)(2*(m1/3)+m1%3))||(L.montant>(int)m1/3+m1%3 && L.montant<(int)(3*(m1/3)+m1%3))){
        printf("le montant est incorrecte!!!!\n");
        printf("le montant est payable en 3 tranches %d XAF,%d XAF ou %d XAF\n",(int)m1/3,(int)(2*(m1/3)+m1%3),(int)(3*(m1/3)+m1%3));
        do{
            printf("entrer un nouveau montant qui soit %d XAF,%d XAF ou %d XAF",(int)m1/3,(int)(2*(m1/3)+m1%3),(int)(3*(m1/3)+m1%3));
            scanf("%ld",&L.montant);
        }while(L.montant!=(int)m1/3||L.montant!=(int)(2*(m1/3)+m1%3)||L.montant!=(int)(3*(m1/3)+m1%3));
    }
    printf("vous etez disponible quand:");
    scanf("%s %*s %d %s %d",L.t.date,&L.t.jour,L.t.mois,&L.t.annee);
            fprintf(f1,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,L.age,L.numero,L.montant,L.t.date,L.t.jour,L.t.mois,L.t.annee);
         }else{
            fprintf(f1,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,L.age,L.numero,L.montant,L.t.date,L.t.jour,L.t.mois,L.t.annee);
         }
    }while(!feof(f));
    fclose(f);
    remove("etudiant.txt");
    fclose(f1);
    rename("etud.txt","etudiant.txt");
}
void affichage_membres(Etudiant L){
    FILE* f=fopen("etudiant.txt","r");
      do{
         fscanf(f,"%s %s %s %s %d %s %ld %s %d %s %d\n",L.nom,L.prenom,L.matricule,L.role,&L.age,L.numero,&L.montant,L.t.date,&L.t.jour,L.t.mois,&L.t.annee);
         printf("NOM:%s\n",L.nom);
         printf("PRENOM:%s\n",L.prenom);
         printf("MATRICULE:%s\n",L.matricule);
         printf("ROLE:%s\n",L.matricule);
         printf("AGE:%s",L.age);
         printf("NUMERO:%s\n",L.numero);
         printf("MONTANT:%s\n",L.montant);
         printf("DATE:%s,%d %s %d\n",L.t.date,L.t.jour,L.t.mois,L.t.annee);
    }while(!feof(f));   
    fclose(f);
}