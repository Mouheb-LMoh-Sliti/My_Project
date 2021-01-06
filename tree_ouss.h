#include <gtk/gtk.h>
  GtkWidget *acceuil;
  GtkWidget *gestion;
typedef struct troupeaux troupeaux ;
struct troupeaux{
char id[30];
char sexe[30];
char type[30];
char date[30];
};

void Affichertroupeaux(GtkWidget* treeview1,char*l);
int Cherchertroupeaux(GtkWidget* treeview1,char*l,char*id);

int cherchertroupeaux(GtkWidget* treeview1,char*l,char*type);
