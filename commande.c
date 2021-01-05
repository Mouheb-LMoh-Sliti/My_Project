#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "commande.h"

enum
{
	CIN,
	REF,
	TYPEE,
        SEXEE,
        QUANT,
	PRIX,
	
	COL
};

/////////////2eme Fonctiion AJOUTER/////////
void ajouter_commande(commande c)
{FILE *f=NULL;
f=fopen("commande.bin","a+b");
if (f!=NULL)
{fwrite(&c,sizeof(commande),1,f);
fclose(f);
}
}
/////////////////Fonction Afficher///////////
void afficher_commande(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
commande e;
char prix[20];
char ref[20];
char cin[20];
char type[25];
char sexe[10];
int quantite;


 store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer, "text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Ref",renderer, "text",REF,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);




renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("type",renderer, "text",TYPEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer, "text",SEXEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("quantite",renderer, "text",QUANT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Prix",renderer, "text",PRIX,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


}

store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
f = fopen("commande.bin","rb");
if(f==NULL)
{
return;
}
else
{
 f=fopen("commande.bin","rb");
	while(fread(&e,sizeof(commande),1,f)!=0)
	{
        gtk_list_store_append(store,&iter);
	 gtk_list_store_set(store,&iter ,CIN,e.cin,REF,e.ref,TYPEE,e.type,SEXEE,e.sexe,QUANT,e.quantite,PRIX,e.prix,-1);
	}
	fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}
//----------Fonction supprimer------------/
void supprimer_commande(commande e)
{
char cin [20];
char ref[20];
char type[25];
char sexe[10];
int quantite;
char prix[30];

FILE *f;
FILE *f1;

commande E;
f=fopen("commande.bin","rb");
f1=fopen("tempo.bin","ab");


    if (f==NULL || f1==NULL )
    {
	return;
    }
    else{
    	while (fread(&E,sizeof(commande),1,f)!=0)
    {
	if(strcmp(e.cin,E.cin)!=0 )
        fwrite(&E,sizeof(commande),1,f1);

}
fclose(f);
fclose(f1);
remove("commande.bin");
rename("tempo.bin","commande.bin");
}
}

//------------------Fonction Modifier--------------//
void modifier_commande(commande e)

{

FILE *f;
FILE *f1;

commande E;
f=fopen("commande.bin","rb");

f1=fopen("tempo.bin","ab");


    if (f==NULL || f1==NULL )
    {
	return;
    }
    else{

    while (fread(&e,sizeof(commande),1,f)!=0)
    {
	if(strcmp(E.cin,e.cin)==0)
        {


	fwrite(&E,sizeof(commande),1,f1);
	}
	else
	fwrite(&e,sizeof(commande),1,f1);

    }

fclose(f);
fclose(f1);
remove("commande.bin");
rename("tempo.bin","commande.bin");
}

}
