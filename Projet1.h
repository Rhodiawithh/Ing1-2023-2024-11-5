
#ifndef ING1_2023_2024_11_5_PROJET1_H
#define ING1_2023_2024_11_5_PROJET1_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "time.h"

#define TAILLE_MDP 20
#define LIGNES_PLATEAU 10
#define COLONNES_PLATEAU 20
#define SNOOPY 0x1 // le Snoopy est represente par un smiley de code ANSI 0x1 au centre meme du plateau
#define OISEAU 0xE //les oiseaux sont represente par des clés de Sol (code ANSI 0xE) à chaque coins du tableau
#define DELIMITATION 0x4
#define MAX_SCORES 5
#define MUR 3    // Bloc plein
#define PASSAGE 176  // Bloc ombré

//double TRestant = 0;
typedef struct monJEU{
    char motDePasse[TAILLE_MDP];
    int snoopy_x, snoopy_y;
    char plateau[LIGNES_PLATEAU][COLONNES_PLATEAU];
    int oiseau ;
    int point ;
    int scores[MAX_SCORES];
    int tempsRestant;
}JEU;



int ChargerNiveau1();
int ChargerNiveau2();
int quitter(int );
void MotsDePasses(char *MDP, int niveau);
void afficherTempsRestant(int tempsRestant);
void sauvegarderTempsRestant(int temps);
void VIES(JEU* jeu);
int choix(int option);
void initialisation_plateau( JEU *jeu);
void initialisation_plateau2(JEU* jeu);
void affichage_plateau( JEU *jeu);
void deplacement ( JEU *jeu, int deplacement_x, int deplacement_y);
void deplacement2(JEU* jeu, int deplacement_x, int deplacement_y);
int verificationMotDePasse(char *MDP, int niveau);
void lancerPartie2(JEU* jeu);
void lancerPartie1(JEU* jeu);
void lancement();
void reinitialiserPositionSnoopy(JEU* jeu);
void GameOver();
void lancement1();
void SCORES(JEU* jeu, int niveau, double elapsed_time);
void menu();
int choix1(JEU* jeu, int niveau);


#endif //ING1_2023_2024_11_5_PROJET1_H
