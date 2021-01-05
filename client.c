#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "client.h"


enum
{	    CIN,
	    PW,
        NOM,
	    PRENOM,
        SEXE,
        DATE,
        INSCRI,
        TEL,
        MAIL,
        ADRE,
	

        COLUMNS
};



/////////////Fonctiion AJOUTER/////////
void ajouter_client(client e)
{FILE *f=NULL;
f=fopen("client.bin","a+b");
if (f!=NULL)
{fwrite(&e,sizeof(client),1,f);
fclose(f);
}
}
/////////////////Fonction Afficher///////////
void afficher_client(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
client e;

char cin[60];
char password[60];
char nom[25];
char prenom[35];
char sexe[10];
char dateNaiss[20];
int inscri;
char tel[20];
char mail[35];
char adresse[60];

 store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("cin",renderer, "text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

/*
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("password",renderer, "text",PW,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);*/


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer, "text",SEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("dateNaiss",renderer, "text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("inscri",renderer, "text",INSCRI,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("tel",renderer, "text",TEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("mail",renderer, "text",MAIL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",ADRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("client.bin","rb");
if(f==NULL)
{
return;
}
else
{
 f=fopen("client.bin","rb");
	while(fread(&e,sizeof(client),1,f)!=0)
	{
        gtk_list_store_append(store,&iter);
	 gtk_list_store_set(store,&iter ,CIN,e.cin,PW,e.password,NOM,e.nom,PRENOM,e.prenom,SEXE,e.sexe,DATE,e.dateNaiss,INSCRI,e.inscri,TEL,e.tel,MAIL,e.mail,ADRE,e.adresse,-1);
	}
	fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}

//----------Fonction supprimer------------/
void supprimer_client(client e)
{
char cin[60];
char password[60];
char nom[25];
char prenom[35];
char sexe[10];
char dateNaiss[20];
int inscri;
char tel[20];
char mail[35];
char adresse[60];

FILE *f;
FILE *f1;

client E;
f=fopen("client.bin","rb");
f1=fopen("tempo.bin","ab");


    if (f==NULL || f1==NULL )
    {
	return;
    }
    else{
    	while (fread(&E,sizeof(client),1,f)!=0)
    {
	if(strcmp(e.cin,E.cin)!=0 )
        fwrite(&E,sizeof(client),1,f1);

}
fclose(f);
fclose(f1);
remove("client.bin");
rename("tempo.bin","client.bin");
}
}
//-----------Fonction Chercher---------------//
void rechercher_client(char NOMC[25],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
client e;

char cin[60];
char password[60];
char nom[25];
char prenom[35];
char sexe[10];
char dateNaiss[20];
int inscri;
char tel[20];
char mail[35];
char adresse[60];

 store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("cin",renderer, "text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("password",renderer, "text",PW,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer, "text",SEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("dateNaiss",renderer, "text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("inscri",renderer, "text",INSCRI,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("tel",renderer, "text",TEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("mail",renderer, "text",MAIL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",ADRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("client.bin","rb");
if(f==NULL)
{
return;
}
else
{
 f=fopen("client.bin","rb");
	while(fread(&e,sizeof(client),1,f)!=0)
	{if((strcmp(e.cin,NOMC)==0)){
        gtk_list_store_append(store,&iter);
	 gtk_list_store_set(store,&iter,CIN,e.cin,PW,e.password,NOM,e.nom,PRENOM,e.prenom,SEXE,e.sexe,DATE,e.dateNaiss,INSCRI,e.inscri,TEL,e.tel,MAIL,e.mail,ADRE,e.adresse,-1);
	}}
	fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}
//------------------Fonction Modifier--------------//
void modifier_client(client e)

{

FILE *f;
FILE *f1;

client E;
f=fopen("client.bin","rb");

f1=fopen("tempo.bin","ab");


    if (f==NULL || f1==NULL )
    {
	return;
    }
    else{

    while (fread(&e,sizeof(client),1,f)!=0)
    {




	if(strcmp(E.cin,e.cin)==0)
        {


	fwrite(&E,sizeof(client),1,f1);
	}
	else
	fwrite(&e,sizeof(client),1,f1);

    }

fclose(f);
fclose(f1);
remove("client.bin");
rename("tempo.bin","client.bin");
}

}

void rechercher_recemment(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
client e;

char cin[60];
char password[60];
char nom[25];
char prenom[35];
char sexe[10];
char dateNaiss[20];
int inscri;
char tel[20];
char mail[35];
char adresse[60];

 store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("cin",renderer, "text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("password",renderer, "text",PW,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer, "text",SEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("dateNaiss",renderer, "text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("inscri",renderer, "text",INSCRI,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("tel",renderer, "text",TEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("mail",renderer, "text",MAIL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",ADRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("client.bin","rb");
if(f==NULL)
{
return;
}
else
{int i=0;
int j=0;
 f=fopen("client.bin","rb");
	while(fread(&e,sizeof(client),1,f)!=0)
		{i++;
	if(i <=2)
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CIN,e.cin,PW,e.password,NOM,e.nom,PRENOM,e.prenom,SEXE,e.sexe,DATE,e.dateNaiss,INSCRI,e.inscri,TEL,e.tel,MAIL,e.mail,ADRE,e.adresse,-1);
}
}

	fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}
}

//verifier l'existance 

int exist_client(char*cin){
FILE*f=NULL;
client e;
f=fopen("client.bin","rb"); 
	while(fread(&e,sizeof(client),1,f)!=0){
if(strcmp(e.cin,cin)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//********************************Authentification*********************************

enum {
LOGIN,
MDP,

COL};

void ajouter_auth(auth y)
{FILE *f=NULL;
f=fopen("auth.bin","a+b");
if (f!=NULL)
{fwrite(&y,sizeof(auth),1,f);
fclose(f);
}
}
////////////affficher
void afficher_auth(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
auth y;

char login[60];
char mot_de_passe[60];

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Login",renderer, "text",LOGIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Mot_de_passe",renderer, "text",MDP,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("auth.bin","rb");
if(f==NULL)
{
return;
}
else
{
 f=fopen("auth.bin","rb");
	while(fread(&y,sizeof(auth),1,f)!=0)
	{
        gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter ,LOGIN,y.login,MDP,y.mot_de_passe,-1);
}
	fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}


