//
// Created by loris on 10/11/2023.
//

#include "SP.h"
int choix(int option){
    printf("taper un entier entre 1 et 6:");
    scanf("%d", &option);
    while (option < 1 || option > 6);
    return option;
}

int ChargerNiveau()
{
    int niveau = 1;
    FILE *fichier = fopen("sauvegarde.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier, "%d", &niveau);
        fclose(fichier);
    }
    return niveau;
}

int quitter(int ){
    printf("Au Revoir :)\n");
}

char MotsDePasses (char MotDePasse)
{
    int niveau;
    printf("Entrez le mot de passe pour acceder au niveau %d : ", niveau);
    scanf("%s", MotDePasse);
    if (niveau == 1 && strcmp(&MotDePasse, "motdepasse1") == 0)
    {//pas sure pour le &motdepasse
        printf("Acces au niveau 1 autorise !\n");
    }
    else if (niveau == 2 && strcmp(&MotDePasse, "motdepasse2") == 0)
    {//pas sure pour le &motdepasse
        printf("Acces au niveau 2 autorise !\n");
    }
    else if (niveau == 3 && strcmp(&MotDePasse, "motdepasse3") == 0)
    {//pas sure pour le &motdepasse
        printf("Acces au niveau 3 autorise !\n");
    }
    else if (niveau == 4 && strcmp(&MotDePasse, "motdepasse4") == 0)
    {//pas sure pour le &motdepasse
        printf("Acces au niveau 4 autorise !\n");
    }
    else {
        printf("Mot de passe incorrect. Acces refuse.\n");
    }
}
// while avc fonction kabit ou cabit pour deplacer snoopy.