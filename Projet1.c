//
// Created by chano on 01/11/2023.
//
#include "Projet1.h"

int choix(int option){
    printf("taper un entier entre 1 et 5:");
    scanf("%d", &option);
    return option;
}
    void Color(int couleurDuTexte,int couleurDeFond){// fonction d'affichage de couleurs
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
    }
// initialisons le plateau de jeu
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
// Sauvegarde du plateau dans un fichier texte (JeuSnoopy)
void sauvegarde_plateau(JEU *jeu,const char *JeuSnoopy) {
//ecriture dans le fichier parent
    FILE *pf = fopen("../JeuSnoopy.txt", "w");

    if (pf == NULL) {
        perror("Erreur d'ouverture de fichier.");
        return;
    }
    fprintf(pf, "%d %d %d %d\n", jeu->snoopy_x, jeu->snoopy_y, jeu->oiseau, jeu->point);

    for (int i = 0; i < LIGNES_PLATEAU; i++) {
        for (int j = 0; j < COLONNES_PLATEAU; j++) {
            int Nombre;
            if (jeu->plateau[i][j] == SNOOPY) {
               Nombre = 4;
            } else if (jeu->plateau[i][j] == OISEAU) {
                Nombre = 6;
            } else {
                Nombre = 0;
            }
            fprintf(pf, "%d", Nombre);

        }
        fprintf(pf, "\n");

    }
    fclose(pf);
}



int chargement_du_plateau (JEU *jeu, const char *JeuSnoopy){
    FILE *pf = fopen ("JeuSnoopy.txt","r");

    if (pf == NULL){
        perror("fichier non ouvrable");
        return 0;
    }

    fscanf(pf, "%d %d %d %d", &jeu->snoopy_x, &jeu->snoopy_y, &jeu->oiseau, &jeu->point);

    for (int i = 0; i < LIGNES_PLATEAU; i++) {
        for (int j = 0; j < COLONNES_PLATEAU; j++) {
            int Nombre;
            fscanf(pf, "%d", &Nombre);
            if ( Nombre == 4) {
                jeu->plateau[i][j] = SNOOPY;
            } else if (  Nombre = 6) {
                jeu->plateau[i][j] = OISEAU;
            } else {
                jeu->plateau[i][j] = 0;
            }
        }}
    fclose(pf);
    return 1;
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


















