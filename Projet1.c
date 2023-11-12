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




















