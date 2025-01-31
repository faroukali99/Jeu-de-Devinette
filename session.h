#ifndef SESSION_H
#define SESSION_H

#define MAX_TENTATIVES 10

typedef struct {
    char pseudo[50];
    char date_heure[20];
    int tentatives[MAX_TENTATIVES];
    double ecart_type;
} Session;

void enregistrer_session(const Session *session);
void afficher_archives();

#endif
