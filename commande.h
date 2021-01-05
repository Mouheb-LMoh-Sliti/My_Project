typedef struct
{
   char cin[20];
  char ref[20] ;
    char type[20];
    char sexe[20];
    int quantite ;
  char prix[20];
}commande;

void ajouter_commande(commande c);
void afficher_commande(GtkWidget *liste);
void supprimer_commande(commande e);
void modifier_commande(commande e);
