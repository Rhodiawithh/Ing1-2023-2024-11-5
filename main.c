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
       if (CHOIX == 2){
           JEU jeu;
           initialisation_plateau(&jeu);
           char mvmt;
           while (1){
               affichage_plateau(&jeu);
               if (jeu.point == 1){

                   printf("Victoire! Vous passez au niveau suivant");
                  break;
               }
               mvmt = getch();
               switch (mvmt) {
                   case 's' :
                       deplacement(&jeu,0, -1);
                       break;
                   case 'z' :
                       deplacement(&jeu,0, 1);
                       break;
                   case 'd' :
                       deplacement(&jeu,1, 0);
                       break;
                   case 'q' :
                       deplacement(&jeu,-1,0);
                       break;
                   case 'l':
                       printf("Vous avez quitter le jeu");
                       return 0;
               }

           }
       }
else if  (CHOIX==6){
        printf("Vous avez quitter le jeu");
        return 0;
}}

}
