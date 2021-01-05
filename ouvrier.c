#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <string.h>
#include "ouvrier.h"
#include <gtk/gtk.h>

enum   
{       NOM,
        PRENOM,
	CIN,
	TELEPHONE,
	TACHE,
        JOUR,
	MOIS,
	ANNEE,
	SEXE,
	NBABS,
	NBPR,
	TAUX,
	COLUMNS,
};



/**************Ajouter ****************/
void ajouter_ouvrier(ouvrier o)
{
  FILE *f;
  FILE *e;
  f=fopen("utilisateurs.txt","a+");
  if(f!=NULL) 
{
  fprintf(f,"%s %s %s %s %s %d %d %d %s\n",o.nom,o.prenom,o.cin,o.telephone,o.tache,o.jour,o.mois,o.annee,o.sexe);
  fclose(f);
}
  e=fopen("absence.txt","a+");
  if(e!=NULL) 
{
  fprintf(e,"%s %s %s 0 0 0\n",o.nom,o.prenom,o.cin);
  fclose(e);
}

}
/*
int controle(char cin[])
{int r=-1;
FILE *f;
ouvrier c;
f=fopen("utilisateurs.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s\n",c.nom,c.prenom,c.cin,c.telephone,c.tache,&c.jour,&c.mois,&c.annee,c.sexe)!=EOF)
{
if (strcmp(cin,c.cin)==0) r=0;
return r;
}
}
}*/

/**************Afficher***************/
void afficher_ouvrier(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char nom[30];
	char prenom[30];
	char cin[15];
	char telephone[15];
	char tache[30];
	char jour[5];
	char mois[5];
	char annee[6];
	char sexe[30];
	char nbabs[5];
	char nbpr[5];
	char taux[5];
	char a[30];
	char b[30];
	char e[30];

	store=NULL;

	FILE *f;
	FILE *c;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prénom",renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Cin",renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Téléphone",renderer, "text",TELEPHONE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Tâche",renderer, "text",TACHE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


 		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Année",renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Sexe",renderer, "text",SEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nombre d'absences",renderer, "text",NBABS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nombre de présence",renderer, "text",NBPR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Taux d'absentéisme",renderer, "text",TAUX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("utilisateurs.txt","r");
		
		c = fopen("absence.txt","r");
		if((f==NULL)&&(c==NULL))
		{
			return;
		}
		else
		{
			f = fopen("utilisateurs.txt","a+");
			c = fopen("absence.txt","a+");
			while((fscanf(f,"%s %s %s %s %s %s %s %s %s\n",nom,prenom,cin,telephone,tache,jour,mois,annee,sexe)!=EOF)&&(fscanf(c,"%s %s %s %s %s %s\n",a,b,e,taux,nbabs,nbpr)!=EOF))
			{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, CIN, cin, TELEPHONE, telephone, TACHE, tache, JOUR, jour, MOIS, mois, ANNEE, annee, SEXE, 	sexe, NBABS, nbabs, NBPR, nbpr, TAUX, taux, -1 );
			}
			fclose(f);
			fclose(c);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 		g_object_unref(store);
}
}
}

/************Modifier***********/
void modifier_ouvrier(ouvrier o1)
{
    FILE*f;
    FILE*e;
    ouvrier o;
    absence a;
    char cin[9];
    f=fopen("utilisateurs.txt","r");
    e=fopen("tmp.txt","a+");

    
    if(f!=NULL)
    { if(e!=NULL)
    { 
        while(fscanf(f,"%s %s %s %s %s %d %d %d %s\n",o.nom,o.prenom,o.cin,o.telephone,o.tache,&o.jour,&o.mois,&o.annee,o.sexe)!=EOF)
        {
		printf("\n %s \n",o1.cin);
            if(strcmp(o.cin,o1.cin)!=0)
            {
                fprintf(e,"%s %s %s %s %s %d %d %d %s\n",o.nom,o.prenom,o.cin,o.telephone,o.tache,o.jour,o.mois,o.annee,o.sexe);	
			printf("\n OK \n");

            }
            else
            { printf("\n OKK \n");



                fprintf(e,"%s %s %s %s %s %d %d %d %s\n",o1.nom,o1.prenom,o1.cin,o1.telephone,o1.tache,o1.jour,o1.mois,o1.annee,o1.sexe);
            }
        }
        fclose(f);
        fclose(e);
remove("utilisateurs.txt");
rename("tmp.txt","utilisateurs.txt");
    }
    }
    
    f=fopen("absence.txt","r");
    e=fopen("tmp.txt","a+");

    
    if(f!=NULL)
    { if(e!=NULL)
    { 
        while(fscanf(f,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,&a.taux,&a.nbabs,&a.nbpr)!=EOF)
        {
		printf("\n %s \n",o1.cin);
            if(strcmp(a.cin,o1.cin)!=0)
            {
                fprintf(e,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,a.taux,a.nbabs,a.nbpr);	
			printf("\n OK \n");

            }
            else
            { printf("\n OKK \n");



                fprintf(e,"%s %s %s %d %d %d\n",o1.nom,o1.prenom,o1.cin,a.taux,a.nbabs,a.nbpr);
            }
        }
        fclose(f);
        fclose(e);
remove("absence.txt");
rename("tmp.txt","absence.txt");

    }}

}

/**************Rechercher**************/
ouvrier rechercher (char cin[15])
{
    FILE*f;

ouvrier o;
    

    f=fopen("utilisateurs.txt","r");
if(f!=NULL){
    while(fscanf(f,"%s %s %s %s %s %d %d %d %s\n",o.nom,o.prenom,o.cin,o.telephone,o.tache,&o.jour,&o.mois,&o.annee,o.sexe)!=EOF)
    {
        if((strcmp(o.cin,cin)==0))
        {
	 printf(" OK \n");
	return o;
fclose(f);
	}
        
		strcpy(o.nom,"Erreur!");
		strcpy(o.prenom,"Erreur!");
		strcpy(o.cin,"Erreur!");
		strcpy(o.telephone,"Erreur!");
		strcpy(o.tache,"Erreur!");
		strcpy(o.sexe,"Erreur!");
 		    
    }
	
    fclose (f);}
    return o;

}

/************Supprimer*****************/
int supprimer_ouvrier(ouvrier o,char cin[15])
{
    FILE*f;
    FILE*c;
    absence a;
    int suppri=0;
    f=fopen("utilisateurs.txt","r+");
    c=fopen("tmp.txt","w+");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d %d %s\n",o.nom,o.prenom,o.cin,o.telephone,o.tache,&o.jour,&o.mois,&o.annee,o.sexe)!=EOF)
        {

            if ((strcmp(o.cin,cin)!=0))
            {               
               fprintf(c,"%s %s %s %s %s %d %d %d %s\n",o.nom,o.prenom,o.cin,o.telephone,o.tache,o.jour,o.mois,o.annee,o.sexe);              
            }
            else
            {
              suppri=1;
            }
        }
    }
fclose(f);
fclose(c);
remove("utilisateurs.txt");
rename("tmp.txt","utilisateurs.txt");
    f=fopen("absence.txt","r+");
    c=fopen("tmp.txt","w+");
if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,&a.taux,&a.nbabs,&a.nbpr)!=EOF)
        {

            if ((strcmp(a.cin,cin)!=0))
            {               
               fprintf(c,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,a.taux,a.nbabs,a.nbpr);              
            }
        }
    }
fclose(f);
fclose(c);
remove("absence.txt");
rename("tmp.txt","absence.txt");
return suppri;
}
/*************Rechercher absence************/
absence recherch (char cin[15])
{
    FILE*f;

absence a;
    

    f=fopen("absence.txt","r");
if(f!=NULL){
    while(fscanf(f,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,&a.taux,&a.nbabs,&a.nbpr)!=EOF)
    {
        if((strcmp(a.cin,cin)==0))
        {
	 printf(" OK \n");
	
	fclose(f);
	return a;
	}
        
		a.taux=-99;
                
        }
	
    fclose (f);}
    return a;

}

/**************Modifier absence***********/
void modifier_abs(absence a1)
{
    FILE*f;
    FILE*e;
    absence a;
    char cin[9];
    f=fopen("absence.txt","r");
    e=fopen("tmp.txt","a+");

    
    if(f!=NULL)
    { if(e!=NULL)
    { 
        while(fscanf(f,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,&a.taux,&a.nbabs,&a.nbpr)!=EOF)
        {
		printf("\n %s \n",a1.cin);
            if(strcmp(a.cin,a1.cin)!=0)
            {
                fprintf(e,"%s %s %s %d %d %d\n",a.nom,a.prenom,a.cin,a.taux,a.nbabs,a.nbpr);	
			printf("\n OK \n");

            }
            else
            { printf("\n OKK \n");

                fprintf(e,"%s %s %s %d %d %d\n",a1.nom,a1.prenom,a1.cin,a1.taux,a1.nbabs,a1.nbpr);
            }
        }
        fclose(f);
        fclose(e);
remove("absence.txt");
rename("tmp.txt","absence.txt");

    }}
}

/************Meilleur ouvrier********/
absence meilleur ()
{
    FILE*f;

absence a;
absence a1;
    int t=101;

    f=fopen("absence.txt","r");
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

}
