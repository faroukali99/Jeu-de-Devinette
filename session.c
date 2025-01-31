#include <stdio.h>
#include <time.h>
#include "session.h"

void enregistrer_session(const Session *session) {
    FILE *file = fopen("sessions.bin", "ab");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fwrite(session, sizeof(Session), 1, file);
    fclose(file);
}

void afficher_archives() {
    FILE *file = fopen("sessions.bin", "rb");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    Session session;
    while (fread(&session, sizeof(Session), 1, file)) {
        printf("Pseudo : %s\n", session.pseudo);
        printf("Date et heure : %s\n", session.date_heure);
        printf("Tentatives : ");
        for (int i = 0; i < MAX_TENTATIVES; i++) {
            printf("%d ", session.tentatives[i]);
        }
        printf("\nEcart-type : %.2f\n\n", session.ecart_type);
    }

    fclose(file);
}
