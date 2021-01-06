#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "equip.h"
#include <gtk/gtk.h>

enum   
{       REF,
	NOM,
	MARQUE,
        DATE,	
        DATEM,
	ETAT,
	COLUMNS,
};




void ajouter_equipement(equipement e)
{
  FILE *f;
  f=fopen("equip.txt","a+");
  if(f!=NULL) 
{
  fprintf(f,"%s %s %s %d %d %d %d %d %d %s\n",e.ref,e.nom,e.marque,e.jour,e.mois,e.annee,e.jourm,e.moism,e.anneem,e.etat);
  fclose(f);
}
  f=fopen("equip1.txt","a+");
  if(f!=NULL) 
{
  fprintf(f,"%s %s %s %d/ %d/ %d %d/ %d/ %d %s\n",e.ref,e.nom,e.marque,e.jour,e.mois,e.annee,e.jourm,e.moism,e.anneem,e.etat);
  fclose(f);
}
}
void afficher_equipement(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char ref[30];
	char nom[30];
	char marque[15];
	char jour[5];
	char mois[5];
	char annee[6];
	char jourm[5];
	char moism[5];
	char anneem[6];
	char date[30];
	char datem[20];
	char etat[30];

	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Reference",renderer, "text",REF, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Marque",renderer, "text",MARQUE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date_d_achat",renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date_de_maintenance",renderer, "text",DATEM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


 		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",ETAT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		



		

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("equip1.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("equip1.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",ref,nom,marque,jour,mois,annee,jourm,moism,anneem,etat)!=EOF)
			{strcpy(date, jour);
			 strcat(date, mois);
			 strcat(date, annee);

			 strcpy(datem, jourm);
			 strcat(datem, moism);
			 strcat(datem, anneem);
		gtk_list_store_append(store,&iter);
		gtk_list_store_set (store, &iter, REF, ref, NOM, nom, MARQUE, marque, DATE, date, DATEM, datem, ETAT, etat, -1 );
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 		g_object_unref(store);
}
}
}

void afficher_defectueux(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char ref[30];
	char nom[30];
	char marque[15];
	char jour[5];
	char mois[5];
	char annee[6];
	char jourm[5];
	char moism[5];
	char anneem[6];
	char date[40];
	char datem[40];
	char etat[30];

	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Reference",renderer, "text",REF, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Marque",renderer, "text",MARQUE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date_d_achat",renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date_de_maintenance",renderer, "text",DATEM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


 		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",ETAT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		



		

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("equip1.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("equip1.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",ref,nom,marque,jour,mois,annee,jourm,moism,anneem,etat)!=EOF)
			{strcpy(date, jour);
			 strcat(date, mois);*
			 strcat(date, annee);

			 strcpy(datem, jourm);
			 strcat(datem, moism);
			 strcat(datem, anneem);
			 if(strcmp(etat,"defectueux")==0)
				{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set (store, &iter, REF, ref, NOM, nom, MARQUE, marque, DATE, date, DATEM, datem, ETAT, etat, -1 );
				}
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 		g_object_unref(store);
}
}
}


void modifier_equipement(equipement e1)
{
    FILE*f;
    FILE*c;
    FILE*s;
    FILE*l;
    equipement e;
    char ref[9];
    f=fopen("equip.txt","r");
    c=fopen("tmp.txt","a+");
    s=fopen("tmp1.txt","a+");

    
    if(f!=NULL)
    { if(c!=NULL)
    { 
        while(fscanf(f,"%s %s %s %d %d %d %d %d %d %s\n",e.ref,e.nom,e.marque,&e.jour,&e.mois,&e.annee,&e.jourm,&e.moism,&e.anneem,e.etat)!=EOF)
        {
		printf("\n %s \n",e1.ref);
            if(strcmp(e.ref,e1.ref)!=0)
            {
                fprintf(c,"%s %s %s %d %d %d %d %d %d %s\n",e.ref,e.nom,e.marque,e.jour,e.mois,e.annee,e.jourm,e.moism,e.anneem,e.etat);
		fprintf(s,"%s %s %s %d/ %d/ %d %d/ %d/ %d %s\n",e.ref,e.nom,e.marque,e.jour,e.mois,e.annee,e.jourm,e.moism,e.anneem,e.etat);	
			printf("\n oki \n");

            }
            else
            { printf("\n oki1 \n");



                fprintf(c,"%s %s %s %d %d %d %d %d %d %s\n",e1.ref,e1.nom,e1.marque,e1.jour,e1.mois,e1.annee,e1.jourm,e1.moism,e1.anneem,e1.etat);
		fprintf(s,"%s %s %s %d/ %d/ %d %d/ %d/ %d %s\n",e1.ref,e1.nom,e1.marque,e1.jour,e1.mois,e1.annee,e1.jourm,e1.moism,e1.anneem,e1.etat);
            }
        }
        fclose(f);
        fclose(c);
        fclose(s);
remove("equip.txt");
rename("tmp.txt","equip.txt");
remove("equip1.txt");
rename("tmp1.txt","equip1.txt");
    }
    }

}
equipement rechercher (char ref[15])
{
    FILE*f;

equipement e;
    

    f=fopen("equip.txt","r");
if(f!=NULL){
    while(fscanf(f,"%s %s %s %d %d %d %d %d %d %s\n",e.ref,e.nom,e.marque,&e.jour,&e.mois,&e.annee,&e.jourm,&e.moism,&e.anneem,e.etat)!=EOF)
    {
        if((strcmp(e.ref,ref)==0))
        {
	 printf("ok \n");
	return e;
fclose(f);
	}
        
		strcpy(e.ref,"erreur");
		strcpy(e.nom,"erreur");
		strcpy(e.marque,"erreur");
                strcpy(e.etat,"erreur");
                
                

			    
    }
	
    fclose (f);}
    return e;

}

int supprimer_equipement(equipement e,char ref[15])
{
    FILE*f;
    FILE*c;
    FILE*s;
    int suppri=0;
    f=fopen("equip.txt","r+");
    c=fopen("tmp.txt","w+");
    s=fopen("tmp1.txt","w+");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %d %d %d %s\n",e.ref,e.nom,e.marque,&e.jour,&e.mois,&e.annee,&e.jourm,&e.moism,&e.anneem,e.etat)!=EOF)
        {

            if ((strcmp(e.ref,ref)!=0))
            {               
                fprintf(c,"%s %s %s %d %d %d %d %d %d %s\n",e.ref,e.nom,e.marque,e.jour,e.mois,e.annee,e.jourm,e.moism,e.anneem,e.etat);
		fprintf(s,"%s %s %s %d/ %d/ %d %d/ %d/ %d %s\n",e.ref,e.nom,e.marque,e.jour,e.mois,e.annee,e.jourm,e.moism,e.anneem,e.etat);              
            }
            else
            {
              suppri=1;
            }
        }
    }
fclose(f);
fclose(c);
fclose(s);
remove("equip.txt");
rename("tmp.txt","equip.txt");

remove("equip1.txt");
rename("tmp1.txt","equip1.txt");
return suppri;
}

/*absence meilleur ()
{
    FILE*f;

absence a;
absence a1;
    int t=101;

    f=fopen("abs.txt","r");
if(f!=NULL){
    while(fscanf(f,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,&a.taux,&a.nbabs,&a.nbpr)!=EOF)
    {
     if(a.taux < t)
        {
	 t=a.taux;
	 a1=a;
	}
                
    }
	
    fclose (f);}
    return a1;

}*/
