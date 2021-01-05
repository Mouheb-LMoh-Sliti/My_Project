#include <gtk/gtk.h>

typedef struct {
char cinE[50];
char nomE[50];
char prenomE[50];
char sexeE[50];
char date_naissanceE[50];
char adresseE[50];
char telephoneE[50];
char profilE[50];
char mailE[50];
char date_recrutementE[50];
} employe;

void ajouter_employe(employe e);
void afficher_employe(GtkWidget *liste);
int supprimer_employe(employe e,char cinE[15]);
void rechercher_employe(char CinE[50],GtkWidget *liste);
void modifier_employe(employe e);
employe rechercher (char cinE[15]);


