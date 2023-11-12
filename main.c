#include "Projet1.h"

int main() {
    Color(3,0);
    printf("\tMENU:\n");
    Color(15,0);
    printf("1.Regles du jeu\n");
    printf("2.Lancer un nouveau Jeu a partir du niveau 1\n");
    printf("3.Charger une partie\n");
    printf("4.Mot de passe\n");
    printf("5.Scores\n");
    printf("6.Quitter\n");


   while(1){
           int CHOIX,a=0;
           CHOIX = choix(a);
       if (CHOIX==1){
        printf("REGLES DU JEU :\n le joueur possede trois vies. Chaque niveau doit etre resolu en moins de 120 secondes.\nLe but est de recuperer les quatres oiseaux du niveau sans se faire toucher par la balle et/ou les ennemis (si present)");
    }
else if  (CHOIX==6){
        printf("Vous avez quitter le jeu");
        return 0;
}}

}
