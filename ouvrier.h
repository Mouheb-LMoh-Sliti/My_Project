#include <gtk/gtk.h>

struct ouvrier
{

	char nom[30];
	char prenom[30];
	char cin[15];
	char telephone[15];
	char tache[30];
	int jour;
	int mois;
	int annee;
	char sexe[30];



}; typedef struct ouvrier ouvrier;
struct absence
{

	char nom[30];
	char prenom[30];
	char cin[15];
	int taux;
	int nbabs;
	int nbpr;



}; typedef struct absence absence;

void ajouter_ouvrier(ouvrier o);
int controle(char cin[]);
void afficher_ouvrier(GtkWidget *liste);
void modifier_ouvrier(ouvrier o1);
ouvrier rechercher (char cin[15]);
int supprimer_ouvrier(ouvrier o,char cin[15]);
absence recherch (char cin[15]);
void modifier_abs(absence a1);
absence meilleur ();
