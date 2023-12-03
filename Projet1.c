//
// Created by chano on 01/11/2023.
//
#include "Projet1.h"

int T=120;
int option;
int niveau;
int vies = 3;
void menu()
{

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
    printf("                                                      MENU:\n");
    printf("                                                                                                        ");
    printf("                                                                                                        \n");
    printf("                                              1.Regles du jeu\n");
    printf("                                              2.Lancer un nouveau Jeu a partir du niveau 1\n");
    printf("                                              3.Charger une partie\n");
    printf("                                              4.Mot de passe\n");
    printf("                                              5.Scores\n");
    printf("                                              6.Quitter\n");



}
int choix(int option) {
    printf("Tapez un entier entre 1 et 5 : ");
    scanf("%d", &option);
    return option;
}
int choix1(JEU* jeu, int niveau)
{
    while(1) {
        int CHOIX, a;
        a = 0;
        CHOIX = choix(a);
        if (CHOIX == 1)
        {
            printf("REGLES DU JEU :\n le joueur possede trois vies. \nChaque niveau doit etre resolu en moins de 120 secondes.\nLe but est de recuperer les quatres oiseaux(notes de musiques dans notre cas) du niveau sans se faire toucher par la balle et/ou les ennemis (si present)");
        }
        else if (CHOIX == 2)
        {
            initialisation_plateau(&jeu);
            char MDP[20];
            scanf("%s", MDP);
            MotsDePasses(MDP, 1);
            lancerPartie1(&jeu);
        }
        else if (CHOIX == 3)
        {
            int niveau = ChargerNiveau1();
            char MDP[20];
            MotsDePasses(MDP, niveau);
            initialisation_plateau(&jeu);
            lancerPartie1(&jeu);
            SCORES(&jeu, niveau);


        }
        else if (CHOIX == 6)
        {
            int n = quitter(n);
            return 0;
        }
        else if (CHOIX == 5)
        {
            SCORES(jeu, niveau);
        }

    }

}
void clearreen() {
    system("cls");
}

void Color(int couleurDuTexte, int couleurDeFond) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

int ChargerNiveau1() {
    int niveau = 1;
    FILE* fichier = fopen("sauvegarde.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier, "%d", &niveau);
        fclose(fichier);
    }
    return niveau;
}
int ChargerNiveau2() {
    int niveau = 2;
    FILE* fichier = fopen("sauvegarde.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier, "%d", &niveau);
        fclose(fichier);
    }
    return niveau;
}

int quitter(int) {
    printf("Au Revoir :)\n");
    return 0;
}

int verificationMotDePasse(char* MDP, int niveau) {
    switch (niveau) {
        case 1:
            return strcmp(MDP, "VERT") == 0;
        case 2:
            return strcmp(MDP, "ROUGE") == 0;
        case 3:
            return strcmp(MDP, "JAUNE") == 0;
        default:
            return 0;
    }
}

void MotsDePasses(char* MDP, int niveau) {
    int attempts = 3;
    int isPasswordCorrect = 0;

    while (attempts > 0) {
        printf("\nEntrez le mot de passe pour acceder au niveau %d : ", niveau);
        scanf("%s", MDP);

        isPasswordCorrect = verificationMotDePasse(MDP, niveau);

        if (isPasswordCorrect) {
            printf("ACCES AUTORISE, snoopy luck ;) !\n");
            break;
        } else {
            printf("\n MAUVAIS MOT DE PASSE \nVEUILLEZ REESSAYER\n");
            attempts--;

            if (attempts > 0) {
                printf("Il vous reste %d tentative(s).\n", attempts);
            } else {
                printf("Vous avez epuise toutes les tentatives. Retour au menu principal.\n");
                choix(option);
            }
        }
    }
}

int TRestant = 120;
void sauvegarderTempsRestant(int temps) {
    TRestant = temps;
}

void SCORES(JEU* jeu, int niveau) {
    sauvegarderTempsRestant(TRestant);
    int ScoreNiveau = TRestant * 100;
    jeu->scores[niveau - 1] = ScoreNiveau;  //faire score avec structure c'est beaucoup plus simple et ca fonctionne.

    int ScoreTotal = 0;
    for (int i = 0; i < MAX_SCORES; ++i) {
        ScoreTotal += jeu->scores[i];//(le score total += au score du niveau)
    }

    printf("Score du niveau %d : %d\n", niveau, ScoreNiveau);
    printf("Score total : %d\n", ScoreTotal);
}
void sauvegarderMeilleursScores(JEU* jeu, int niveau) {
    FILE* fichier = fopen("meilleurs_scores.txt", "a");
    if (fichier != NULL) {
        fprintf(fichier, "%d %d\n", niveau, jeu->scores[niveau - 1]);
        fclose(fichier);
    }
}

void chargerMeilleursScores(JEU* jeu) {
    FILE* fichier = fopen("meilleurs_scores.txt", "r");
    if (fichier != NULL) {
        int niveau, score;
        while (fscanf(fichier, "%d %d", &niveau, &score) == 2) {
            jeu->scores[niveau - 1] = score;
        }
        fclose(fichier);
    }
}
void chronometre(int tempsLimite) {
    for (int seconds = tempsLimite; seconds >= 0; seconds--) {
        printf("\rTemps restant : %d secondes   ", seconds);
        fflush(stdout);
        Sleep(1000);
    }
    printf("\nDEATH\n");
}
void initialisation_plateau(JEU* jeu) {
    int i, j;
    jeu->snoopy_x = LIGNES_PLATEAU / 2;
    jeu->snoopy_y = COLONNES_PLATEAU / 2;
    jeu->oiseau = 4;
    jeu->point = 0;

    for (i = 0; i < LIGNES_PLATEAU; i++) {
        for (j = 0; j < COLONNES_PLATEAU; j++) {

            if ((i == 1 && j == 1) || (i == 1 && j == COLONNES_PLATEAU - 2) ||
                (i == LIGNES_PLATEAU - 2 && j == 1) || (i == LIGNES_PLATEAU - 2 && j == COLONNES_PLATEAU - 2)) {
                jeu->plateau[i][j] = OISEAU;
            } else if (i == 0 || j == 0 || i == LIGNES_PLATEAU - 1 || j == COLONNES_PLATEAU - 1) {
                jeu->plateau[i][j] = DELIMITATION;
            } else if (i == jeu->snoopy_x && j == jeu->snoopy_y) {
                jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = SNOOPY;
            } else {
                jeu->plateau[i][j] = 0x0;
            }
        }
    }
}

void affichage_plateau(JEU* jeu) {
    for (int i = 0; i < LIGNES_PLATEAU; i++) {
        for (int j = 0; j < COLONNES_PLATEAU; j++) {
            printf("%c", jeu->plateau[i][j]);
        }
        printf("\n");
    }
}

void deplacement(JEU* jeu, int deplacement_x, int deplacement_y) {
    int x = jeu->snoopy_x + deplacement_x;
    int y = jeu->snoopy_y + deplacement_y;

    if (x >= 0 && x < LIGNES_PLATEAU && y >= 0 && y < COLONNES_PLATEAU && jeu->plateau[x][y] != DELIMITATION) {
        if (jeu->plateau[x][y] == OISEAU) {
            jeu->oiseau--;
            if (jeu->oiseau == 0) {
                jeu->point = 1;
                return;
            }
        }
        jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = 0x0;
        jeu->snoopy_x = x;
        jeu->snoopy_y = y;
        jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = SNOOPY;
    }
}
void reinitialiserPositionSnoopy(JEU* jeu) {
    jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = 0x0;
    jeu->snoopy_x = LIGNES_PLATEAU / 2;
    jeu->snoopy_y = COLONNES_PLATEAU / 2;
    jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = SNOOPY;
}
void GameOver()
{


    printf("\n\n\n\n");
    printf("   GGG    AAAAA  M     M EEEEE  \n");
    printf("  G   G  A     A MM   MM E      \n");
    printf(" G      AAAAAAA M M M M EEEE   \n");
    printf(" G   GG A     A M  M  M E      \n");
    printf("  GGGG  A     A M     M EEEEE  \n");
    printf("\n");
    printf("   OOO  V     V EEEEE  RRRR  \n");
    printf("  O   O  V   V  E      R   R \n");
    printf(" O     O  V V   EEEE   RRRR  \n");
    printf("  O   O    V    E      R  R  \n");
    printf("   OOO     V    EEEEE  R   RR\n");
    printf("\n\n\n");

}
void VIES(JEU* jeu) {
    vies--;
    if (vies > 0) {
        printf("Vous avez perdu une vie. Il vous reste %d vie(s).\n", vies);
        reinitialiserPositionSnoopy(jeu);  // Réinitialiser la position de Snoopy
    } else {
        GameOver();
        printf("Vous avez perdu toutes vos vies. Game Over.\n");
        lancement1();
        menu();
        choix1(jeu, option);
        choix(option);

    }
}
void lancement()
{
    printf("Appuyez 2 fois sur Entree pour commencer la partie...");
    while (1) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 13) {  // 13 est le code ASCII pour la touche "Entrée"
                break;  // Sortir de la boucle si la touche "Entrée" est pressée
            }
        }
    }
}
void lancement1()
{
    printf("Appuyez sur Entree pour aller au menu principal");
    while (1) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 13) {  // 13 est le code ASCII pour la touche "Entrée"
                break;  // Sortir de la boucle si la touche "Entrée" est pressée
            }
        }
    }
}
void lancerPartie1(JEU* jeu)
{
    int niveau = ChargerNiveau1();
    clock_t start_time = clock();
    int tempsLimite = 120;  // Temps limite en secondes
    int vies = 3;  // Nombre initial de vies
    lancement();

    affichage_plateau(jeu);
    fflush(stdout);
    printf("\nLe jeu commence!\n");

    while (1) {
        // ... (votre code pour la boucle de jeu)

        while (1) {

            // Gestion des mouvements
            char mvmt = getch();
            int deplacement_x = 0, deplacement_y = 0;

            switch (mvmt) {
                case 's':
                    deplacement_x = 0;
                    deplacement_y = -1;
                    break;
                case 'z':
                    deplacement_x = 0;
                    deplacement_y = 1;
                    break;
                case 'd':
                    deplacement_x = 1;
                    deplacement_y = 0;
                    break;
                case 'q':
                    deplacement_x = -1;
                    deplacement_y = 0;
                    break;
                case 'l':
                    printf("Vous avez quitté le jeu\n");
                    SCORES(jeu, niveau); // Affichage des scores
                    return;
            }

            // Déplace le snoopy et vérifie les collisions
            deplacement(jeu, deplacement_x, deplacement_y);

            // Gestion des objets collectables (oiseaux)
            if (jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] == OISEAU) {
                jeu->oiseau--;
                if (jeu->oiseau == 0) {
                    jeu->point = 1;
                    printf("Vous avez collecté tous les oiseaux! Vous passez au niveau suivant.\n");
                    // Code pour passer au niveau suivant, mettre à jour les scores, etc.
                }
            }

            // Gestion des collisions avec d'autres éléments (ennemis, bords du plateau, etc.)
            //if (jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] == ENNEMI) {
            // VIES();  // Le joueur perd une vie en cas de collision avec un ennemi
            //  printf("Attention! Vous avez été touché par un ennemi. Il vous reste %d vies.\n", vies);
            //   }

            // Mise à jour de l'affichage après les déplacements et collisions
            affichage_plateau(jeu);
            fflush(stdout);

            // Vérification de la condition de victoire
            if (jeu->point == 1)
            {
                printf("Victoire! Vous passez au niveau suivant.\n");
                sauvegarderTempsRestant(T);
                SCORES(jeu, niveau);  // Affichage des scores
                // Code pour passer au niveau suivant, mettre à jour les scores, etc.
                break;
            }
            //start_time = clock();
            //chronometre(tempsLimite);

            // Vérification de la condition de défaite (temps écoulé > 120 secondes)
            clock_t current_time = clock();//modify all this shit
            double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;

            if (elapsed_time > tempsLimite)
            {
                VIES(jeu);
                lancement();
                start_time = clock();
                //start_time = clock();
                break;
            }

            // Affichage du temps écoulé
            printf("\rTemps ecoule : %.2f secondes", elapsed_time);
            fflush(stdout);
        }
    }

}
