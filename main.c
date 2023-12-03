#include "Projet1.h"

int main() {
    int niveau1=1;
    JEU *jeu;
    menu();
    choix1(jeu, niveau1);
    return 0;
}




//FONCTION SCORES(tempsRestant)
//ScoreNiveau ← tempsRestant * 100
//ScoreTotal ← ScoreTotal + ScoreNiveau

//        AFFICHER "Score du niveau :", ScoreNiveau
//        AFFICHER "Score total :", ScoreTotal
//        FIN FONCTION


//FONCTION CHRONOMETRE()
//POUR chaque seconde DE 120 À 0
//AFFICHER "\rTemps restant : ", seconde, " secondes   "
//VIDAGE DU TAMBOUR DE SORTIE
//        PAUSE DE 1 SECONDE
//sauvegarderTempsRestant(seconde)
//FIN POUR
//FIN FONCTION

