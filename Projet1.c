//
// Created by chano on 01/11/2023.
//
#include "Projet1.h"

int choix(int option){
    printf("\ntaper un entier entre 1 et 6:");
    scanf("%d", &option);
    return option;
}
    void Color(int couleurDuTexte,int couleurDeFond){// fonction d'affichage de couleurs
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
    }



int ChargerNiveau()
{
    int niveau = 1;
    FILE *fichier = fopen("sauvegarde.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier, "%d", &niveau);
        fclose(fichier);
        //il faut mettre le sous programme mdp a mon avis ici pcque
        //on est pas sensé avoir mdp dans le menu, c'est quand on charge une partie ou en general quand on veut jouer un niveau qu'il faut
    }
    return niveau;
}

int quitter(int ){
    printf("Au Revoir :)\n");
    return 0;
}
void MotsDePasses(char *MDP, int niveau) {// *MDP pointe vers le tableau char declare en main
    printf("\nEntrez le mot de passe pour acceder au niveau %d : ", niveau);
    scanf("%s", MDP);// c'est un tableau char donc %s (TD7)
    if (niveau == 1 && strcmp(MDP, "VERT") == 0) {
        printf("ACCES AUTORISE, snoopy luck ;) !\n");
    } else if (niveau == 2 && strcmp(MDP, "ROUGE") == 0) {
        printf("ACCES AUTORISE, snoopy luck ;) !\n");
    } else if (niveau == 3 && strcmp(MDP, "JAUNE") == 0) {
        printf("ACCES AUTORISE, snoopy luck ;) !\n");
    } else {
        printf("\n MAUVAIS MOT DE PASSE \nVEUILLEZ REESSAYER");
    }
}
int TRestant = 120;
void sauvegarderTempsRestant(int temps) {
    TRestant = temps;
}
void SCORES()
{
    int ScoreNiveau = TRestant * 100;
    int ScoreTotal=0;
    ScoreTotal += ScoreNiveau;
    printf("Score du niveau : %d\n", ScoreNiveau);
    printf("Score total : %d\n", ScoreTotal);
}
void CHRONOMETRE() {
    for (int seconds = 120; seconds >= 0; seconds--) {
        printf("\rTemps restant : %d secondes   ", seconds);
        fflush(stdout);
        sleep(1);
        sauvegarderTempsRestant(seconds);

    }

    printf("\nDEATH\n");
}
// while avc fonction kabit ou cabit pour deplacer snoopy.
int vies=3;
void VIES()
{
    vies--;
    if (vies > 0)
    {
        printf("Vous avez perdu une vie. Il vous reste %d vies.\n", vies);
    } else
    {
        printf("Vous avez perdu toutes vos vies. Game Over.\n");
    }
}


















