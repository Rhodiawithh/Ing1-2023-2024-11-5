//
// Created by loris on 10/11/2023.
//
#include "SP.h"
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