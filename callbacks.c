#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif



#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree_ouss.h"
#include"CRUD_OUSS.h"
GtkTreeSelection *selection1;

void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
gtk_widget_hide (acceuil);
gestion = create_gestion ();
p=lookup_widget(gestion,"treeviewho2");
Affichertroupeaux(p,"troupeaux.txt");
gtk_widget_show (gestion);
}


void
on_Ajoutertroupeaux_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 troupeaux t;
GtkWidget *ousssexe;
GtkWidget *oussId;
GtkWidget *ousstype;
GtkWidget *oussjour;
GtkWidget *oussmois;
GtkWidget *oussannee;
GtkWidget *labelId;
GtkWidget *labelsexe;
GtkWidget *labelType;
GtkWidget *labelDate;
GtkWidget *existe;
GtkWidget* success;
int b=1;
char str[100];


oussId=lookup_widget(gestion,"entryho5");
ousssexe=lookup_widget(gestion,"comboboxho2");
ousstype=lookup_widget(gestion,"comboboxho1");
oussjour=lookup_widget(gestion,"spinbuttonho1");
oussmois=lookup_widget(gestion,"spinbuttonho2");
oussannee=lookup_widget(gestion,"spinbuttonho3");


labelId=lookup_widget(gestion,"labelho13");
labelsexe=lookup_widget(gestion,"labelho7");
labelType=lookup_widget(gestion,"labelho8");
labelDate=lookup_widget(gestion,"labelho9");

existe=lookup_widget(gestion,"labelho34");
success=lookup_widget(gestion,"labelho35");
        strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(oussId) ) );
        strcpy(t.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ousssexe) ) );
        strcpy(t.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ousstype) ) );
strcpy(str,gtk_entry_get_text(GTK_ENTRY(oussjour)));strcat(str,"/");strcat(str,gtk_entry_get_text(GTK_ENTRY(oussmois)));strcat(str,"/");strcat(str,gtk_entry_get_text(GTK_ENTRY(oussannee)));
strcpy(t.date,str);
       

 gtk_widget_hide (success);
// controle saisie
if(strcmp(t.id,"")==0){
		  gtk_widget_show (labelId);
b=0;
}
else {
		  gtk_widget_hide(labelId);
}

if(strcmp(t.sexe,"")==0){
		  gtk_widget_show (labelsexe);
b=0;
}
else {
		  gtk_widget_hide(labelsexe);
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



if(b==1){

        if(exist_troupeaux(t.id)==1)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (existe);
                ajouter_troupeaux(t);

						  gtk_widget_show (success);
        }
//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestion,"treeviewho2");

        Affichertroupeaux(p,"troupeaux.txt");
}

}




void
on_Modifiertroupeaux_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
       	 troupeaux t;
    gchar *Id;
    gchar *sexe;
    gchar *Type;
    gchar *date;
   GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&Id,1,&sexe,2,&Type,3,&date,-1);//recuperer les information de la ligne selectionneé
            supprimer_troupeaux(Id);
}

        strcpy(t.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"labelho20"))));
        strcpy(t.sexe,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entryho6"))));
        strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entryho7"))));
        strcpy(t.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entryho9"))));
ajouter_troupeaux(t);
//mise ajour du tree view 
        Affichertroupeaux(lookup_widget(gestion,"treeview1"),"troupeaux.txt");
	gtk_widget_show(lookup_widget(gestion,"labelho37"));
        GtkWidget *p=lookup_widget(gestion,"treeviewho2");
        Affichertroupeaux(p,"troupeaux.txt");
}





void
on_cherchertroupeaux_clicked              (GtkButton       *button,
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
entry=lookup_widget(gestion,"entryho10");
labelid=lookup_widget(gestion,"labelho28");
p1=lookup_widget(gestion,"treeviewho2");
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

nb=Cherchertroupeaux(p1,"troupeaux.txt",id);
// afficher le sexebre de resultats obtenue par la recherche
 

sprintf(chnb,"%d",nb);        //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(gestion,"labelho27");
message=lookup_widget(gestion,"labelho26");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);
}

}


void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
gtk_widget_destroy (gestion);

}




void
on_bmodifier_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *id;
        gchar *sexe;
        gchar *type;
        gchar *date;
  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestion,"labelho37"));//cacher label modifier avec succees
                gtk_tree_model_get (model,&iter,0,&id,1,&sexe,2,&type,3,&date,-1);//recuperer les information de la ligne selectionneé
        // //remplir les champs de entry
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entryho6")),sexe);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entryho7")),type);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entryho9")),date);



                GtkWidget* msgId=lookup_widget(gestion,"labelho20");
                GtkWidget* msg1=lookup_widget(gestion,"labelho36");
                gtk_label_set_text(GTK_LABEL(msgId),id);
                gtk_widget_show(msgId);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestion,"button4"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestion,"notebook1")));//redirection vers la page precedente
       
        }

}


void
on_bsupprimer_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    gchar *Id;
    gchar *sexe;
    gchar *Type;
    gchar *date;
troupeaux t;
  
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&Id,1,&sexe,2,&Type,3,&date,-1);//recuperer les information de la ligne selectionneé
            supprimer_troupeaux(Id);
            Affichertroupeaux(lookup_widget(gestion,"treeviewho2"),"troupeaux.txt");        
        }
}


void
on_bafficher12_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestion,"treeviewho2");
        Affichertroupeaux(p,"troupeaux.txt");
}


void
on_treeviewho2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
    gchar *id;
        gchar *sexe;
        gchar *type;
        gchar *date;
      
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion,"treeviewho2");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       


}




void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *P;
GtkWidget *Entry;
GtkWidget *labeltyp;
GtkWidget *typResultat;
GtkWidget *Message;
char type[30];
char chtyp[30];
int b=0,typ; //b=0  entry  cherche vide 
Entry=lookup_widget(gestion,"entryho11");
labeltyp=lookup_widget(gestion,"labelho65");
P=lookup_widget(gestion,"treeviewho2");
strcpy(type,gtk_entry_get_text(GTK_ENTRY(Entry)));

if(strcmp(type,"")==0){
  gtk_widget_show (labeltyp);b=0;
}else{
b=1;
gtk_widget_hide (labeltyp);}

if(b==0)
    {return;
    }
    else
    {

typ=cherchertroupeaux(P,"troupeaux.txt",type);
// afficher le sexebre de resultats obtenue par la recherche
 

sprintf(chtyp,"%d",typ);        //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
typResultat=lookup_widget(gestion,"labelho64");
Message=lookup_widget(gestion,"labelho63");
gtk_label_set_text(GTK_LABEL(typResultat),chtyp);

gtk_widget_show (typResultat);
gtk_widget_show (Message);
}
}


