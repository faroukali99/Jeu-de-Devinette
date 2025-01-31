 #include <math.h>
#include "statistiques.h"

double calculer_ecart_type(const int tentatives[], int n) {
    double somme = 0, moyenne, variance = 0;

    for (int i = 0; i < n; i++) {
        somme += tentatives[i];
    }
    moyenne = somme / n;

    for (int i = 0; i < n; i++) {
        variance += pow(tentatives[i] - moyenne, 2);
    }
    variance /= n;

    return sqrt(variance);
}
