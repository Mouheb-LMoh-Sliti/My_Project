#include <gtk/gtk.h>

struct equipement
{

	char ref[30];
	char nom[30];
	char marque[15];
	int jour;
	int mois;
	int annee;
	int jourm;
	int moism;
	int anneem;
	char etat[30];



}; typedef struct equipement equipement;

void ajouter_equipement(equipement e);
void afficher_equipement(GtkWidget *liste);
void afficher_defectueux(GtkWidget *liste);
void modifier_equipement(equipement e1);
equipement rechercher (char ref[15]);
int supprimer_equipement(equipement,char ref[15]);
//absence recherch (char cin[15]);
//void modifier_marque(marque m1);
//marque mauvaise ();
