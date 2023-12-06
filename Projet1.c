//
// Created by chano on 01/11/2023.
//
#include "Projet1.h"
int TRestant = 120;
int option;
int niveau;
int vies = 3;
double elapsed_time = 0;

void sauvegarderMeilleursScores(JEU* jeu, int niveau) {
    FILE* fichier = fopen("SCORES.txt", "a");
    if (fichier != NULL) {
        fprintf(fichier, "%d %d\n", niveau, jeu->scores[niveau - 1]);
        fclose(fichier);
    }
}
int calculerScoreTotal(JEU* jeu)
{
    int ScoreTotal = 0;
    for (int i = 0; i < MAX_SCORES; ++i)
    {
        ScoreTotal = jeu->scores[i];
    }
    return ScoreTotal;
}
void chargerMeilleursScores(JEU* jeu)
{
    SCORES(&jeu, 1, elapsed_time);
    SCORES(&jeu, 2, elapsed_time);
}
void SCORES(JEU* jeu, int niveau, double elapsed_time) {
    int tempsLimite = 120;
    int ScoreNiveau=0;

    // Adjust scoring calculation based on the level
    if (niveau == 1)
    {
        ScoreNiveau = (tempsLimite - (int)elapsed_time) * 100;
    }
    else if (niveau == 2)
    {
        ScoreNiveau = (tempsLimite - (int)elapsed_time) * 100;
    }
    else
    {
        ScoreNiveau = 0;
    }

    jeu->scores[niveau - 1] += ScoreNiveau;

    printf("Score du niveau %d : %d\n", niveau, ScoreNiveau);
    //printf("Scores enregistres :\n");
    //for (int i = 0; i < MAX_SCORES; ++i) {
     //   printf("Niveau %d : %d\n", i + 1, jeu->scores[i]);
   // }
    int ScoreTotal = calculerScoreTotal(jeu);
    printf("Score total : %d\n", ScoreTotal);
}
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
    printf("                                              4.Instructions Jeu\n");
    printf("                                              5.Scores\n");
    printf("                                              6.Quitter\n");



}
int choix(int option) {
    printf("Tapez un entier entre 1 et 6 : ");
    scanf("%d", &option);
    return option;
}
int choix1(JEU* jeu, int niveau)
{
    double elapsed_time = 0;
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
            int niveau = ChargerNiveau1();
            initialisation_plateau(&jeu);
            lancerPartie1(&jeu);
            SCORES(&jeu, 1, elapsed_time);
        }
        else if (CHOIX == 3)
        {
            printf("Voulez-vous charger le niveau 1 ou niveau 2 ?\n");
            printf("1. Niveau1\n");
            printf("2. Niveau2\n");
            int choixNiveau;
            scanf("%d", &choixNiveau);

            if (choixNiveau == 1) {
                int niveau = ChargerNiveau1();
                initialisation_plateau(&jeu);
                lancerPartie1(&jeu);
                SCORES(&jeu, 1, elapsed_time);
            } else if (choixNiveau == 2) {
                int niveau = ChargerNiveau2();
                initialisation_plateau2(&jeu);
                lancerPartie2(&jeu);
                SCORES(&jeu, 2, elapsed_time);
            } else {
                printf("Choix invalide. Veuillez choisir 1 ou 2.\n");
            }
        }
        else if (CHOIX == 6)
        {
            return 0;
        }
        else if (CHOIX == 5)
        {
            chargerMeilleursScores(jeu);
            printf("Scores enregistres :\n");
            for (int i = 0; i < MAX_SCORES; ++i) {
                printf("Niveau %d : %d\n", i + 1, jeu->scores[i]);
            }

            // Calculer et afficher le score total
            int ScoreTotal = calculerScoreTotal(jeu);
            printf("Score total : %d\n", ScoreTotal);
        }
        else if (CHOIX == 4)
        {
            printf("Touches du jeu:\n"
                   "-Appuyer 'D' pour aller en bas;\n"
                   "-Appuyer 'Q' pour aller en Haut;\n"
                   "-Appuyer 'S' pour aller a gauche;\n"
                   "-Appuyer 'Z' pour aller a droite;\n"
                   "-Appuyer 'P' a tout moment pour mettre pause                                                      ");
        }

    }

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
    FILE* fichier = fopen("sauvegarde2.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier, "%d", &niveau);
        fclose(fichier);
    }
    return niveau;
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
void sauvegarderTempsRestant(int temps) {
    TRestant = temps;
}
void afficherTempsRestant(int tempsRestant) {
    printf("Temps restant : %d secondes", tempsRestant);
}
void initialisation_plateau(JEU* jeu)
{
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
void initialisation_plateau2(JEU* jeu) {
    int i, j;
    jeu->snoopy_x = LIGNES_PLATEAU / 2;
    jeu->snoopy_y = COLONNES_PLATEAU / 2;
    jeu->oiseau = 4;
    jeu->point = 0;

    // Réinitialisation du plateau
    for (i = 0; i < LIGNES_PLATEAU; i++) {
        for (j = 0; j < COLONNES_PLATEAU; j++) {

            if ((i == 1 && j == 1) || (i == 1 && j == COLONNES_PLATEAU - 2) ||
                (i == LIGNES_PLATEAU - 2 && j == 1) || (i == LIGNES_PLATEAU - 2 && j == COLONNES_PLATEAU - 2)) {
                jeu->plateau[i][j] = 0x0;  // Supprime les anciens emplacements d'oiseaux
            } else if (i == 0 || j == 0 || i == LIGNES_PLATEAU - 1 || j == COLONNES_PLATEAU - 1) {
                jeu->plateau[i][j] = DELIMITATION;
            } else if (i == jeu->snoopy_x && j == jeu->snoopy_y) {
                jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = SNOOPY;
            } else {
                jeu->plateau[i][j] = 0x0;
            }
        }
    }
    srand((unsigned)time(NULL));

    // Remplit le plateau avec des murs
    for (int i = 0; i < LIGNES_PLATEAU; i++) {
        for (int j = 0; j < COLONNES_PLATEAU; j++) {
            jeu->plateau[i][j] = MUR;
        }
    }
    srand((unsigned)time(NULL));

    // Remplit le plateau avec des murs
    for (int i = 0; i < LIGNES_PLATEAU; i++) {
        for (int j = 0; j < COLONNES_PLATEAU; j++) {
            jeu->plateau[i][j] = MUR;
        }
    }

    // Crée un point de départ et ajoute-le au labyrinthe
    int startX = 1;
    int startY = 1;
    jeu->plateau[startX][startY] = PASSAGE;

    // Génère le labyrinthe en utilisant une méthode simple de creusement aléatoire
    for (int i = 0; i < 1000; i++) {
        int direction = rand() % 4; // Choix aléatoire d'une direction (0: haut, 1: droite, 2: bas, 3: gauche)

        switch (direction) {
            case 0: // Haut
                if (startX - 2 > 0) {
                    jeu->plateau[startX - 2][startY] = PASSAGE;
                    jeu->plateau[startX - 1][startY] = PASSAGE;
                    startX -= 2;
                }
                break;
            case 1: // Droite
                if (startY + 2 < COLONNES_PLATEAU - 1) {
                    jeu->plateau[startX][startY + 2] = PASSAGE;
                    jeu->plateau[startX][startY + 1] = PASSAGE;
                    startY += 2;
                }
                break;
            case 2: // Bas
                if (startX + 2 < LIGNES_PLATEAU - 1) {
                    jeu->plateau[startX + 2][startY] = PASSAGE;
                    jeu->plateau[startX + 1][startY] = PASSAGE;
                    startX += 2;
                }
                break;
            case 3: // Gauche
                if (startY - 2 > 0) {
                    jeu->plateau[startX][startY - 2] = PASSAGE;
                    jeu->plateau[startX][startY - 1] = PASSAGE;
                    startY -= 2;
                }
                break;
        }
    }
    // Place les oiseaux à de nouveaux emplacements
    jeu->plateau[2][2] = OISEAU;
    jeu->plateau[2][COLONNES_PLATEAU - 3] = OISEAU;
    jeu->plateau[LIGNES_PLATEAU - 3][2] = OISEAU;
    jeu->plateau[LIGNES_PLATEAU - 3][COLONNES_PLATEAU - 3] = OISEAU;
}
void deplacement2(JEU* jeu, int deplacement_x, int deplacement_y) {
    int x = jeu->snoopy_x + deplacement_x;
    int y = jeu->snoopy_y + deplacement_y;

    if (x >= 0 && x < LIGNES_PLATEAU && y >= 0 && y < COLONNES_PLATEAU && jeu->plateau[x][y] != MUR) {
        if (jeu->plateau[x][y] == OISEAU) {
            jeu->oiseau--;
            if (jeu->oiseau == 0) {
                jeu->point = 1;
                return;
            }
        }
        jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = PASSAGE;  // Utilisez le code pour le passage au lieu de 0x0
        jeu->snoopy_x = x;
        jeu->snoopy_y = y;
        jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] = SNOOPY;
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
void sauvegarde_plateau(JEU *jeu,const char *JeuSnoopy) {
//ecriture dans le fichier parent
    FILE *pf = fopen("../JeuSnoopy.txt", "w");

    if (pf == NULL) {
        perror("Erreur d'ouverture de fichier.");
        return;
    }
    fprintf(pf, "%d %d %d %d\n", jeu->snoopy_x, jeu->snoopy_y, jeu->oiseau, jeu->point);

    for (int i = 0; i < LIGNES_PLATEAU; i++) {
        for (int j = 0; j < COLONNES_PLATEAU; j++) {
            int Nombre;
            if (jeu->plateau[i][j] == SNOOPY) {
                Nombre = 4;
            } else if (jeu->plateau[i][j] == OISEAU) {
                Nombre = 6;
            } else {
                Nombre = 0;
            }
            fprintf(pf, "%d", Nombre);

        }
        fprintf(pf, "\n");

    }
    fclose(pf);
}
int chargement_du_plateau (JEU *jeu, const char *JeuSnoopy){
    FILE *pf = fopen ("JeuSnoopy.txt","r");

    if (pf == NULL){
        perror("fichier non ouvrable");
        return 0;
    }

    fscanf(pf, "%d %d %d %d", &jeu->snoopy_x, &jeu->snoopy_y, &jeu->oiseau, &jeu->point);

    for (int i = 0; i < LIGNES_PLATEAU; i++) {
        for (int j = 0; j < COLONNES_PLATEAU; j++) {
            int Nombre;
            fscanf(pf, "%d", &Nombre);
            if ( Nombre == 4) {
                jeu->plateau[i][j] = SNOOPY;
            } else if (  Nombre = 6) {
                jeu->plateau[i][j] = OISEAU;
            } else {
                jeu->plateau[i][j] = 0;
            }
        }}
    fclose(pf);
    return 1;
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
void lancerPartie2(JEU* jeu)
{
    clock_t start_time = clock();
    bool prochainNiveau = false;
    int tempsLimite = 120;
    MotsDePasses(jeu->motDePasse, 2);
    if (verificationMotDePasse(jeu->motDePasse, 2))
    {
        fflush(stdout);
        printf("\nLe jeu commence!\n");
        lancement();
        double elapsed_time = 0;

        while (1) {
            int seconds;

            while (1) {
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
                        printf("Vous avez quitte le jeu\n");
                        SCORES(&jeu, 2, elapsed_time);
                        return;
                }

                deplacement2(jeu, deplacement_x, deplacement_y);
                if (jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] == OISEAU) {
                    jeu->oiseau--;
                    if (jeu->oiseau == 0) {
                        jeu->point = 1;
                        printf("Vous avez collecte tous les oiseaux! Vous passez au niveau suivant.\n");
                        clock_t current_time = clock();
                        double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;
                        int ScoreNiveau = tempsLimite - (int) elapsed_time * 100;
                        jeu->scores[niveau - 1] = ScoreNiveau;
                        // Affichage des scores
                        SCORES(&jeu, 2, elapsed_time);
                        // Sauvegarde des meilleurs scores
                        sauvegarderMeilleursScores(jeu, niveau);

                        break;
                    }
                }

                affichage_plateau(jeu);
                sauvegarde_plateau(&jeu,"JeuSnoopy.text");
                chargement_du_plateau (&jeu, "JeuSnoopy.text");
                fflush(stdout);

                if (jeu->point == 1) //si tous les oiseaux récupérés
                {
                    printf("Victoire! Vous avez termine le deuxième niveau.\n");
                    clock_t current_time = clock();
                    double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;
                    int ScoreNiveau = tempsLimite - (int) elapsed_time * 100;
                    jeu->scores[1] = ScoreNiveau; // Mise à jour du score du deuxième niveau
                    // Affichage des scores
                    SCORES(&jeu, 2, elapsed_time);
                    // Sauvegarde des meilleurs scores
                    sauvegarderMeilleursScores(jeu, 2);
                    printf("Que souhaitez vous faire\n");
                    printf("1. Retourner au menu principal\n");
                    printf("2. Passer au niveau suivant\n");
                    int choi;
                    scanf("%d", &choi);

                    if (choi == 2)
                    {
                        prochainNiveau = true;
                        break;
                    } else if (choi == 1)
                    {
                        lancement1();
                        while(1) {
                            int option=1;
                            menu();
                            choix(option);
                            choix1(jeu, option);

                        }
                        break;
                    } else {
                        printf("Choix invalide. Veuillez choisir 1 ou 2.\n");
                    }

                }


                clock_t current_time = clock();
                double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;

                if (elapsed_time > tempsLimite) //Si temps écoulé--> game over
                {
                    VIES(jeu);
                    lancement();
                    start_time = clock();
                    break;
                }

                seconds = tempsLimite - (int) elapsed_time;
                printf("\rTemps restant : %d secondes   ", seconds);
                fflush(stdout);
            }
        }
    }
    else
    {
            printf("Mot de passe incorrect. Retour au menu principal.\n");
            choix(option);
    }
}
void lancerPartie1(JEU *jeu)
{
    int niveau = ChargerNiveau1();
    clock_t start_time = clock();
    bool prochainNiveau = false;
    int tempsLimite = 120;
    int vies = 3;
    MotsDePasses(jeu->motDePasse, 1);
    if (verificationMotDePasse(jeu->motDePasse, 1)) {
        lancement();
        affichage_plateau(jeu);
        fflush(stdout);
        printf("\nLe jeu commence!\n");
        double elapsed_time = 0;

        while (1) {
            int seconds;

            while (1) {
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
                        SCORES(&jeu, 1, elapsed_time); // Affichage des scores
                        return;
                }

                deplacement(jeu, deplacement_x, deplacement_y);
                if (jeu->plateau[jeu->snoopy_x][jeu->snoopy_y] == OISEAU) {
                    jeu->oiseau--;
                    if (jeu->oiseau == 0) {
                        jeu->point = 1;
                        printf("Vous avez collecté tous les oiseaux! Vous passez au niveau suivant.\n");
                        clock_t current_time = clock();
                        double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;
                        int ScoreNiveau = tempsLimite - (int) elapsed_time * 100;
                        jeu->scores[niveau - 1] = ScoreNiveau;
                        // Affichage des scores
                        SCORES(&jeu, 1, elapsed_time);
                        // Sauvegarde des meilleurs scores
                        sauvegarderMeilleursScores(jeu, niveau);

                        break;
                    }
                }

                affichage_plateau(jeu);
                sauvegarde_plateau(&jeu,"JeuSnoopy.text");
                chargement_du_plateau (&jeu, "JeuSnoopy.text");
                fflush(stdout);

                if (jeu->point == 1) //si tous les oiseaux récupérés
                {
                    printf("Victoire! Vous passez au niveau suivant.\n");
                    clock_t current_time = clock();
                    double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;
                    int ScoreNiveau = tempsLimite - (int) elapsed_time * 100;
                    jeu->scores[niveau - 1] = ScoreNiveau;
                    // Affichage des scores
                    SCORES(&jeu, 1, elapsed_time);
                    // Sauvegarde des meilleurs scores
                    sauvegarderMeilleursScores(jeu, niveau);
                    printf("Que souhaitez vous faire\n");
                    printf("1. Retourner au menu principal\n");
                    printf("2. Passer au niveau suivant\n");
                    int choi;
                    scanf("%d", &choi);

                    if (choi == 2) {
                        prochainNiveau = true;
                        break;
                    } else if (choi == 1) {
                        lancement1();
                        while(1) {
                            int option=1;
                            menu();
                            choix(option);
                            choix1(jeu, option);

                        }
                        break; // Retourner au menu principal
                    } else {
                        printf("Choix invalide. Veuillez choisir 1 ou 2.\n");
                    }
                    // break;
                }

                clock_t current_time = clock();
                double elapsed_time = (double) (current_time - start_time) / CLOCKS_PER_SEC;

                if (elapsed_time > tempsLimite) //Si temps écoulé--> game over
                {
                    VIES(jeu);
                    lancement();
                    start_time = clock();
                    break;
                }

                seconds = tempsLimite - (int) elapsed_time;
                printf("\rTemps restant : %d secondes   ", seconds);
                fflush(stdout);
            }
            if (prochainNiveau) {

                int niveau2 = ChargerNiveau2();
                initialisation_plateau2(jeu);
                lancement();
                lancerPartie2(jeu);
                break;
            } else {
                lancement1();
                menu();
                choix1(jeu, option);
                choix(option);

            }
        }
    }
            else
            {
            printf("Mot de passe incorrect. Retour au menu principal.\n");
            choix(option);
            }

        }

