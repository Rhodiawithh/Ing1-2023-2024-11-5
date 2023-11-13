#include "Projet1.h"

int main() {
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
    printf("                                                     MENU:\n");
    printf("                                                                                                        ");
    printf("                                                                                                        \n");
    printf("                                              1.Regles du jeu\n");
    printf("                                              2.Lancer un nouveau Jeu a partir du niveau 1\n");
    printf("                                              3.Charger une partie\n");
    printf("                                              4.Mot de passe\n");
    printf("                                              5.Scores\n");
    printf("                                              6.Quitter\n");





    while(1) {
        int CHOIX, a;
        a = 0;
        CHOIX = choix(a);
        if (CHOIX == 1) {
            printf("REGLES DU JEU :\n le joueur possede trois vies. \nChaque niveau doit etre resolu en moins de 120 secondes.\nLe but est de recuperer les quatres oiseaux du niveau sans se faire toucher par la balle et/ou les ennemis (si present)");
        } else if (CHOIX == 3) {
            int niveau = ChargerNiveau();
            printf("Niveau charge : %d\n", niveau);
        } else if (CHOIX == 4) {
            int niveau;
            char MDP[50];// voire pq 50
            printf("Choix du Niveau (1, 2, 3): ");
            if (niveau<1 && niveau>3)
            {
                printf("veuillez choisir un niveau éxistant%d", niveau);
            }
            else
            {
                scanf("%d", &niveau);
                MotsDePasses(MDP, niveau);
            }


        } else if (CHOIX == 6) {
            int n = quitter(n);
            return 0;
        }
        else if (CHOIX == 5)
        {
            SCORES();
            CHRONOMETRE();
        }

    }

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

