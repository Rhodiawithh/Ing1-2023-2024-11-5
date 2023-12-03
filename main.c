#include "Projet1.h"

int main() {
    JEU jeu;
    sauvegarde_plateau(&jeu, "JeuSnoopy.txt");
    chargement_du_plateau(&jeu, "JeuSnoopy.txt");

    printf("                                              SSSS  N   N  OOO   OOO  PPPP   Y   Y\n");
    printf("                                              S     NN  N O   O O   O P   P   Y Y \n");
    printf("                                              SSSS  N N N O   O O   O PPPP     Y  \n");
    printf("                                                  S N  NN O   O O   O P        Y  \n");
    printf("                                              SSSS  N   N  OOO   OOO  P        Y \n");
    printf("                                                                                                        ");
    printf("                                                                                                        ");
    printf("                                                                                                        ");
    printf("                                                                                                        ");
    printf("                                                                                                        ");
    printf("                                                                                                        ");
    printf("                                                                                                        ");
    Color(3,0);
    printf("                                                      MENU:\n");
    printf("                                                                                                        ");
    Color(15,0);
    printf("                                                                                                        \n");
    printf("                                              1.Regles du jeu\n");
    printf("                                              2.Lancer un nouveau Jeu a partir du niveau 1\n");
    printf("                                              3.Charger une partie\n");
    printf("                                              4.Mot de passe\n");
    printf("                                              5.Scores\n");
    printf("                                              6.Quitter\n");



    while(1){
           int CHOIX, a = 0;
           CHOIX = choix(a);
           while (getchar() != '\n');
       if (CHOIX==1){
        printf("REGLES DU JEU :\n le joueur possede trois vies. Chaque niveau doit etre resolu en moins de 120 secondes.\nLe but est de recuperer les quatres oiseaux du niveau sans se faire toucher par la balle et/ou les ennemis (si present)");
    }
       if (CHOIX == 2){

           initialisation_plateau(&jeu);
           char mvmt;
           while (1){
               affichage_plateau(&jeu);
               sauvegarde_plateau(&jeu, "JeuSnoopy.txt");
               chargement_du_plateau(&jeu, "JeuSnoopy.txt");
               if (jeu.point == 1){
                   printf("Victoire! Vous passez au niveau suivant");
                 break;
               }
               mvmt = getchar();
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
               system("cls");
           }

       }
else if  (CHOIX==6){
        printf("Vous avez quitter le jeu");
        return 0;
}}

}
