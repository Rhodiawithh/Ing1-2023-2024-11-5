//
// Created by chano on 01/11/2023.
//
#include "Projet1.h"

int choix(int option){
    printf("taper un entier entre 1 et 5:");
    scanf("%d", &option);
    printf("taper un entier entre 1 et 5:");
    scanf("%d", &option);
    if (option==1){
        printf("REGLES DU JEU :\n le joueur possede trois vies. Chaque niveau doit etre resolu en moins de 120 secondes.\nLe but est de recuperer les quatres oiseaux du niveau sans se faire toucher par la balle et/ou les ennemis (si present)");
    }
    return option;
}


















