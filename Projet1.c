//
// Created by chano on 01/11/2023.
//
#include "Projet1.h"
int option;
int choix(int option){
    printf("taper un entier entre 1 et 5:");
    scanf("%d", &option);
    return option;
}
void clearScreen() {
    system("cls");
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


int verificationMotDePasse(char *MDP, int niveau) {
    switch (niveau) {
        case 1:
            return strcmp(MDP, "VERT") == 0;
        case 2:
            return strcmp(MDP, "ROUGE") == 0;
        case 3:
            return strcmp(MDP, "JAUNE") == 0;
        default:
            return 0;
    }
}
void MotsDePasses(char *MDP, int niveau) {
    int attempts = 3; // Allow 3 attempts
    int isPasswordCorrect = 0;

    while (attempts > 0) {
        printf("\nEntrez le mot de passe pour acceder au niveau %d : ", niveau);
        scanf("%s", MDP);

        // Call the verification function
        isPasswordCorrect = verificationMotDePasse(MDP, niveau);

        if (isPasswordCorrect) {
            printf("ACCES AUTORISE, snoopy luck ;) !\n");
            break; // Exit the loop if the password is correct
        } else {
            printf("\n MAUVAIS MOT DE PASSE \nVEUILLEZ REESSAYER\n");
            attempts--;

            if (attempts > 0) {
                printf("Il vous reste %d tentative(s).\n", attempts);
            } else {
                printf("Vous avez epuise toutes les tentatives. Retour au menu principal.\n");
                choix(option);

            }
        }
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
    for (int seconds = 120; seconds >= 0; seconds--)
    {
        clearScreen();
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














void initialisation_plateau(JEU *jeu) {
    int i, j;
    jeu->snoopy_x = LIGNES_PLATEAU / 2;
    jeu->snoopy_y = COLONNES_PLATEAU / 2;
    jeu->oiseau = 4;
    jeu->point = 0;

    for (i = 0; i < LIGNES_PLATEAU; i++) {
        for (j = 0; j < COLONNES_PLATEAU; j++) {

            if ((i == 1 && j == 1 )|| (i == 1 && j == COLONNES_PLATEAU - 2) || (i == LIGNES_PLATEAU - 2 && j == 1) || (i == LIGNES_PLATEAU - 2 && j == COLONNES_PLATEAU - 2)) {
                jeu->plateau[i][j] = OISEAU;}
            else if (i==0 || j== 0 || i == 0 || j == 0 || j == COLONNES_PLATEAU - 1 || i == LIGNES_PLATEAU- 1 ){ jeu->plateau[i][j] = DELIMITATION; }
            else if (i == jeu->snoopy_x && j == jeu->snoopy_y) {

                jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = SNOOPY; //SNOOPY est au centre du plateau
            } else {
                jeu->plateau[i][j] = 0x0;
            }

        }
    }

}

void affichage_plateau( JEU *jeu){
    for (int i = 0; i < LIGNES_PLATEAU; i++){
        for (int j = 0; j < COLONNES_PLATEAU; j++){
            printf("%c", jeu->plateau[i][j]);
        }
        printf("\n");
    }
}

void deplacement ( JEU *jeu,int deplacement_x, int deplacement_y){

    int x = jeu->snoopy_x + deplacement_x;
    int y = jeu->snoopy_y + deplacement_y;

    if (x >= 0 && x < LIGNES_PLATEAU && y >= 0 && y < COLONNES_PLATEAU && jeu->plateau[x][y] != DELIMITATION) {
        if (jeu->plateau[x][y] == OISEAU) {
            jeu->oiseau--;
            if (jeu->oiseau == 0) {
                jeu->point = 1;
                return;
            }
        }
        jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = 0x0;
        jeu->snoopy_x = x;
        jeu->snoopy_y = y;
        jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = SNOOPY;
    }}