#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_MOT 10
#define NUM_MOTS 13
#define NUM_GUESSES_MAX 6

int high_score = 0;

void print_high_score() {
    printf("High score: %d\n", high_score);
}

void jouer_pendu() {
    // Créer un dictionnaire de mots
    char mots[][MAX_LEN_MOT] = {"rouge", "tableau", "vert", "maison", "arbre", "voiture", "ordinateur", "chat", "chien", "oiseau", "pomme", "banane", "orange"};

    int mode;
    printf("\nChoisissez le mode de jeu:\n1. Solo\n2. Duo\n\n");
    scanf("%d", &mode);

    char mot_correct[MAX_LEN_MOT];
    if (mode == 1) {
        // Choisir un mot au hasard dans le dictionnaire
        strcpy(mot_correct, mots[rand() % NUM_MOTS]);
    } else if (mode == 2) {
        printf("\nJoueur 1, entrez un mot: ");
        scanf("%s", mot_correct);
    } else {
        printf("Mode de jeu non valide.\n");
        return;
    }

    // Créer une copie du mot correct avec tous les caractères cachés
    char mot_cache[MAX_LEN_MOT];
    for (int i = 0; i < strlen(mot_correct); i++) {
        mot_cache[i] = '*';
    }
    mot_cache[strlen(mot_correct)] = '\0';

    char devine;
    int devines_correctes = 0;
    int num_guesses = NUM_GUESSES_MAX;
    while (devines_correctes < strlen(mot_correct) && num_guesses > 0) {
        printf("\nDevinez une lettre: ");
        scanf(" %c", &devine);

        int lettre_trouvee = 0;
        for (int i = 0; i < strlen(mot_correct); i++) {
            if (devine == mot_correct[i]) {
                mot_cache[i] = devine;
                devines_correctes++;
                lettre_trouvee = 1;
            }
        }

        if (lettre_trouvee) {
    printf("La lettre %c est dans le mot.\n", devine);
} else {
    printf("La lettre %c n'est pas dans le mot.\n", devine);
    num_guesses--;
}

printf("Etat actuel: %s\n", mot_cache);
}

if (devines_correctes == strlen(mot_correct)) {
    printf("\n\nVous avez gagné!\n");

    // Update the high score if necessary
    if (num_guesses > high_score) {
        high_score = num_guesses;
    }
} else {
    printf("\n\nVous avez perdu. Le mot correct était %s.\n", mot_correct);
}
}

int main() {
print_high_score();
jouer_pendu();
print_high_score();
return 0;
}

