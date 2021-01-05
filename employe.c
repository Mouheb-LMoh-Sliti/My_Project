#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "employe.h"


enum
{	
	NOME,
	PRENOME,
	CINE,
	DATENAISSE,
	SEXEE,
	TELEPHONEE,
	ADRESSEE,
	MAILE,
	DATERECRUTE,
	PROFILE,
        COLUMNS,
};

/////////////AJOUTER un employe/////////
void ajouter_employe(employe e)
{
  FILE *f;
  f=fopen("employe.txt","a+");
  if(f!=NULL) 
{
  fprintf(f,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE);
  fclose(f);
}
}

////////////Afficher les employes/////////
void afficher_employe(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char cinE[50];
	char nomE[50];
	char prenomE[50];
	char sexeE[50];
	char adresseE[50];
	char telephoneE[50];
	char date_recrutementE[50];
	char mailE[50];
	char profilE[50];
	store=NULL;
	employe e;
char date_naissanceE[50];

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Cin",renderer,"text",CINE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prénom",renderer,"text",PRENOME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",SEXEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date naissance",renderer,"text",DATENAISSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Adresse",renderer,"text",ADRESSEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Telephone",renderer,"text",TELEPHONEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Mail",renderer,"text",MAILE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Date recrutement",renderer,"text",DATERECRUTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Profil",renderer,"text",PROFILE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("employe.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("employe.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE)!=EOF)
	{
        gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CINE, e.cinE, NOME, e.nomE, PRENOME, e.prenomE, SEXEE, e.sexeE, DATENAISSE, e.date_naissanceE, ADRESSEE, e.adresseE, TELEPHONEE, e.telephoneE, MAILE, e.mailE, DATERECRUTE, e.date_recrutementE, PROFILE, e.profilE, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

////////////////Supprimer un compte employe///////////////
int supprimer_employe(employe e,char cinE[15])
{

	
int suppri=0;
FILE *f;
FILE *f1;

employe E;

f=fopen("employe.txt","r+");
f1=fopen("tempo.txt","w+");


 if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE)!=EOF)
        {

            if ((strcmp(e.cinE,cinE)!=0))
            {               
               fprintf(f1,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE);              
            }
            else
            {
              suppri=1;
            }
        }
    }
fclose(f);
fclose(f1);
remove("employe.txt");
rename("tempo.txt","employe.txt");
   
return (suppri);
}

///////////////////Chercher un employe////////////////
void rechercher_employe(char CinE[50],GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	employe e;

	GtkListStore *store;

	char cinE[50];
	char nomE[50];
	char prenomE[50];
	char sexeE[50];
	char date_naissanceE[50];
	char adresseE[50];
	char telephoneE[50];
	char date_recrutementE[50];
	char mailE[50];
	char profilE[50];
	store=NULL;


FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CINE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Date_naissance",renderer,"text",DATENAISSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",ADRESSEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" telephone",renderer,"text",TELEPHONEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" mail",renderer,"text",MAILE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" date_recrutement",renderer,"text",DATERECRUTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" profil",renderer,"text",PROFILE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("employe.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("employe.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE)!=EOF)
{if((strcmp(e.cinE,CinE)==0)){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CINE, e.cinE, NOME, e.nomE, PRENOME, e.prenomE, SEXEE, e.sexeE, DATENAISSE, e.date_naissanceE, ADRESSEE, e.adresseE, TELEPHONEE, e.telephoneE, DATERECRUTE, e.date_recrutementE, PROFILE, e.profilE, -1);
}}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
////////////////////////Modifier employe///////////////////////////////// 
void modifier_employe(employe e1)

{

FILE *f;
FILE *f1;
char CinE[9];
employe e;
f=fopen("employe.txt","r");

f1=fopen("tempo.txt","a+");


     if(f!=NULL)
    { if(f1!=NULL)
    { 
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE)!=EOF)
        {
		printf("\n %s \n",e1.cinE);
            if(strcmp(e.cinE,e1.cinE)!=0)
            {
                fprintf(f1,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE);	
			printf("\n OK \n");

            }
            else
            { printf("\n OKK \n");



                fprintf(f1,"%s %s %s %s %s %s %s %s %s %s\n",e1.nomE,e1.prenomE,e1.cinE,e1.date_naissanceE,e1.sexeE,e1.telephoneE,e1.adresseE,e1.mailE,e1.date_recrutementE,e1.profilE);
            }
        }
        fclose(f);
        fclose(f1);
remove("employe.txt");
rename("tempo.txt","employe.txt");
    }
    }
}
///////////////////////recherche employe (fenetre mod/sup) ////////////////////////////
employe rechercher (char cinE[15])
{
    FILE*f;

employe e;
    

    f=fopen("employe.txt","r");
if(f!=NULL){
    while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",e.nomE,e.prenomE,e.cinE,e.date_naissanceE,e.sexeE,e.telephoneE,e.adresseE,e.mailE,e.date_recrutementE,e.profilE)!=EOF)
    {
        if((strcmp(e.cinE,cinE)==0))
        {
	 printf(" OK \n");
	return (e);
fclose(f);
	}
        
		strcpy(e.nomE,"Erreur!");
		strcpy(e.prenomE,"Erreur!");
		strcpy(e.sexeE,"Erreur!");
		strcpy(e.mailE,"Erreur!");
		strcpy(e.date_naissanceE,"Erreur!");
		strcpy(e.adresseE,"Erreur!");
		strcpy(e.telephoneE,"Erreur!");
		strcpy(e.date_recrutementE,"Erreur!");
		strcpy(e.profilE,"Erreur!");
		
    }
	
    fclose (f);}
    return (e);
}
