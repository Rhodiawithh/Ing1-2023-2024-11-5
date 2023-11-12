//
// Created by loris on 10/11/2023.
//

#ifndef RSNOOPY_SP_H
#define RSNOOPY_SP_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int choix(int option);
int ChargerNiveau();
int quitter(int );
void MotsDePasses(char *MDP, int niveau);
void CHRONOMETRE();
void SauvegardeTemps(int temps);
void SCORES();
void VIES();
#endif //RSNOOPY_SP_H
