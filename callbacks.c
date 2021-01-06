#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif



#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"CRUD.h"
GtkTreeSelection *selection1;

void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
gtk_widget_hide (acceuilp);
gestionp = create_gestionp ();
p=lookup_widget(gestionp,"treeview2p");
Afficherplante(p,"plante.txt");
gtk_widget_show (gestionp);
}


void
on_Ajouterplante_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 plante t;
GtkWidget *entrysaison;
GtkWidget *entryId;
GtkWidget *entrytype;
GtkWidget *entryMois;
GtkWidget *entryJour;
GtkWidget *entryAnnee;
GtkWidget *entryPrix;
GtkWidget *labelId;
GtkWidget *labelsaison;
GtkWidget *labelType;
GtkWidget *labelDate;
GtkWidget *labelPrix;
GtkWidget *existe;
GtkWidget* success;
int b=1;
char str[100];



entryId=lookup_widget(gestionp,"entry5p");
entrysaison=lookup_widget(gestionp,"comboboxentry1p");
entrytype=lookup_widget(gestionp,"entry2p");


entryJour=lookup_widget(gestionp,"spinbutton1p");
entryMois=lookup_widget(gestionp,"spinbutton2p");
entryAnnee=lookup_widget(gestionp,"spinbutton3p");


entryPrix=lookup_widget(gestionp,"entry3p");
labelId=lookup_widget(gestionp,"label13p");
labelsaison=lookup_widget(gestionp,"label7p");
labelType=lookup_widget(gestionp,"label8p");
labelDate=lookup_widget(gestionp,"label9p");
labelPrix=lookup_widget(gestionp,"label10p");
existe=lookup_widget(gestionp,"label34p");
success=lookup_widget(gestionp,"label35p");
        strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(entryId) ) );
strcpy(t.saison,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysaison) ) );
        strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(entrytype) ) );
strcpy(str,gtk_entry_get_text(GTK_ENTRY(entryJour)));strcat(str,"/");strcat(str,gtk_entry_get_text(GTK_ENTRY(entryMois)));strcat(str,"/");strcat(str,gtk_entry_get_text(GTK_ENTRY(entryAnnee)));
strcpy(t.date,str);
        strcpy(t.prix,gtk_entry_get_text(GTK_ENTRY(entryPrix) ) );

 gtk_widget_hide (success);
// controle saisie
if(strcmp(t.id,"")==0){
		  gtk_widget_show (labelId);
b=0;
}
else {
		  gtk_widget_hide(labelId);
}

if(strcmp(t.saison,"")==0){
		  gtk_widget_show (labelsaison);
b=0;
}
else {
		  gtk_widget_hide(labelsaison);
}
if(strcmp(t.type,"")==0){
		  gtk_widget_show (labelType);
b=0;
}
else {
		  gtk_widget_hide(labelType);
}
if(strcmp(t.date,"")==0){
		  gtk_widget_show (labelDate);
b=0;
}
else {
		  gtk_widget_hide(labelDate);
}
if(strcmp(t.prix,"")==0){
		  gtk_widget_show (labelPrix);
b=0;
}
else {
		  gtk_widget_hide(labelPrix);
}



if(b==1){

        if(exist_plante(t.id)==1)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (existe);
                ajouter_plante(t);

						  gtk_widget_show (success);
        }
//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestionp,"treeview2p");

        Afficherplante(p,"plante.txt");
}

}




void
on_Modifierplante_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
       	 plante t;




	
	gchar *id;
    gchar *saison;
    gchar *type;
    gchar *date;
    gchar *prix;
   GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&id,1,&saison,2,&type,3,&date,4,&prix,-1);//recuperer les information de la ligne selectionneé
            supprimer_plante(id);
}




        strcpy(t.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionp,"label20p"))));
        strcpy(t.saison,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionp,"entry6p"))));
        strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionp,"entry7p"))));
        strcpy(t.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionp,"entry9p"))));
        strcpy(t.prix,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionp,"entry8p"))));
        ajouter_plante(t);
//mise ajour du tree view 
        Afficherplante(lookup_widget(gestionp,"treeview1p"),"plante.txt");
	gtk_widget_show(lookup_widget(gestionp,"label37p"));
        GtkWidget *p=lookup_widget(gestionp,"treeview2p");
        Afficherplante(p,"plante.txt");
}





void
on_chercherplante_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelid;
GtkWidget *nbResultat;
GtkWidget *message;
char id[30];
char chnb[30];
int b=0,nb; //b=0  entry  cherche vide 
entry=lookup_widget(gestionp,"entry10p");
labelid=lookup_widget(gestionp,"label28p");
p1=lookup_widget(gestionp,"treeview2p");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(id,"")==0){
  gtk_widget_show (labelid);b=0;
}else{
b=1;
gtk_widget_hide (labelid);}

if(b==0)
    {return;
    }
    else
    {

nb=Chercherplante(p1,"plante.txt",id);
// afficher le saisonbre de resultats obtenue par la recherche
 

sprintf(chnb,"%d",nb);        //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(gestionp,"labelp");
message=lookup_widget(gestionp,"label26p");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);
}

}


void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuilp);
gtk_widget_destroy (gestionp);

}




void
on_bmodifier_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *id;
        gchar *saison;
        gchar *type;
        gchar *date;
        gchar *prix;
  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestionp,"label37p"));//cacher label modifier avec succees
                gtk_tree_model_get (model,&iter,0,&id,1,&saison,2,&type,3,&date,4,&prix,-1);//recuperer les information de la ligne selectionneé
        // //remplir les champs de entry
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionp,"entry6p")),saison);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionp,"entry7p")),type);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionp,"entry9p")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionp,"entry8p")),prix);



                GtkWidget* msgId=lookup_widget(gestionp,"label20p");
                GtkWidget* msg1=lookup_widget(gestionp,"label36p");
                gtk_label_set_text(GTK_LABEL(msgId),id);
                gtk_widget_show(msgId);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestionp,"button4p"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionp,"notebook1")));//redirection vers la page precedente
       
        }

}


void
on_bsupprimer_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    gchar *Id;
    gchar *saison;
    gchar *Type;
    gchar *date;
    gchar *prix;
  
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&Id,1,&saison,2,&Type,3,&date,4,&prix,-1);//recuperer les information de la ligne selectionneé
            supprimer_plante(Id);
            Afficherplante(lookup_widget(gestionp,"treeview2p"),"plante.txt");        
        }
}


void
on_bafficher12_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestionp,"treeview2p");
        Afficherplante(p,"plante.txt");
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
    gchar *id;
        gchar *saison;
        gchar *type;
        gchar *date;
        gchar *prix;
      
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionp,"treeview2p");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       


}








