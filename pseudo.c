#include <stdio.h>
#include <string.h>
#include "pseudo.h"

int verifier_pseudo(const char *pseudo) {
    FILE *file = fopen("pseudos.txt", "r");
    if (file == NULL) {
        return 0; // Le fichier n'existe pas, donc le pseudo n'existe pas
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Supprimer le saut de ligne
        if (strcmp(line, pseudo) == 0) {
            fclose(file);
            return 1; // Le pseudo existe déjà
        }
    }

    fclose(file);
    return 0; // Le pseudo n'existe pas
}

void enregistrer_pseudo(const char *pseudo) {
    FILE *file = fopen("pseudos.txt", "a");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "%s\n", pseudo);
    fclose(file);
}
