//
// Created by chano on 01/11/2023.
//

#ifndef ING1_2023_2024_11_5_PROJET1_H
#define ING1_2023_2024_11_5_PROJET1_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define LIGNES_PLATEAU 10
#define COLONNES_PLATEAU 20
#define SNOOPY 0x1 // le Snoopy est represente par un smiley de code ANSI 0x1 au centre meme du plateau
#define OISEAU 0xE //les oiseaux sont represente par des clés de Sol (code ANSI 0xE) à chaque coins du tableau
#define DELIMITATION 0x4

typedef struct monJEU{
    int snoopy_x, snoopy_y;
    char plateau[LIGNES_PLATEAU][COLONNES_PLATEAU];
    int oiseau ;
    int point ;
}JEU;




int choix(int option);
void Color(int couleurDuTexte,int couleurDeFond);
void initialisation_plateau( JEU *jeu);
void affichage_plateau( JEU *jeu);
void deplacement ( JEU *jeu, int deplacement_x, int deplacement_y);

#endif //ING1_2023_2024_11_5_PROJET1_H
