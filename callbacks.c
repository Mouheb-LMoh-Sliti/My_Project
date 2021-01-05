#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "client.h"
#include "commande.h"
client selected_client;
commande selected_commande;
//---Ajout Client--//
void
on_inscription_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
client e;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;
int b=1;

GtkWidget *label61_nom;
label61_nom=lookup_widget(objet_graphique,"label61_nom");

GtkWidget *label62_pr;
label62_pr=lookup_widget(objet_graphique,"label62_pr");

GtkWidget *label63_se;
label63_se=lookup_widget(objet_graphique,"label63_se");

GtkWidget *label64_dte;
label64_dte=lookup_widget(objet_graphique,"label64_dte");

GtkWidget *label65_tel;
label65_tel=lookup_widget(objet_graphique,"label65_tel");

GtkWidget *label66_cin;
label66_cin=lookup_widget(objet_graphique,"label66_cin");

GtkWidget *label67_mail;
label67_mail=lookup_widget(objet_graphique,"label67_mail");

GtkWidget *label68_ad;
label68_ad=lookup_widget(objet_graphique,"label68_ad");

GtkWidget *existe;
GtkWidget* success;
existe=lookup_widget(objet_graphique,"label70_ex");
success=lookup_widget(objet_graphique,"label71_su");


input1=lookup_widget(objet_graphique,"entry1_C");
//input2=lookup_widget(objet_graphique,"entry2");
input3=lookup_widget(objet_graphique,"entry3_C");
input4=lookup_widget(objet_graphique,"entry4_C");

input5=lookup_widget(objet_graphique,"combobox1_C");

input6=lookup_widget(objet_graphique, "entry5_C");
input7=lookup_widget(objet_graphique, "spinbutton1_C");
input8=lookup_widget(objet_graphique, "entry6_C");

input9=lookup_widget(objet_graphique, "entry7_C");
input10=lookup_widget(objet_graphique, "entry8_C");

strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
//strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));

strcpy(e.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));


strcpy(e.dateNaiss,gtk_entry_get_text(GTK_ENTRY(input6)));
e.inscri=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input7));
strcpy(e.tel,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(e.mail,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(input10)));

if(strcmp(e.nom,"")==0){
		  gtk_widget_show (label61_nom);
b=0;
}
else {
		  gtk_widget_hide(label61_nom);
}

if(strcmp(e.prenom,"")==0){
		  gtk_widget_show (label62_pr);
b=0;
}
else {
		  gtk_widget_hide(label62_pr);
}
if(strcmp(e.sexe,"")==0){
		  gtk_widget_show (label63_se);
b=0;
}
else {
		  gtk_widget_hide(label63_se);
}

if(strcmp(e.dateNaiss,"")==0){
		  gtk_widget_show (label64_dte);
b=0;
}
else {
		  gtk_widget_hide(label64_dte);
}

if(strcmp(e.tel,"")==0){
		  gtk_widget_show (label65_tel);
b=0;
}
else {
		  gtk_widget_hide(label65_tel);
}

if(strcmp(e.cin,"")==0){
		  gtk_widget_show (label66_cin);
b=0;
}
else {
		  gtk_widget_hide(label66_cin);
}

if(strcmp(e.mail,"")==0){
		  gtk_widget_show (label67_mail);
b=0;
}
else {
		  gtk_widget_hide(label67_mail);
}

if(strcmp(e.adresse,"")==0){
		  gtk_widget_show (label68_ad);
b=0;
}
else {
		  gtk_widget_hide(label68_ad);
}

if(b==1){

        if(exist_client(e.cin)==1)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (existe);
                ajouter_client(e);

						  gtk_widget_show (success);
        }
}

}





void
on_affichage1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *inscrip;
GtkWidget *treeview2;

inscrip=lookup_widget(objet,"inscrip");
treeview2=lookup_widget(inscrip,"treeview2");
afficher_client(treeview2);

}

//----Treeview----//
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_data,-1);

}
strcpy(selected_client.cin,str_data);

FILE *f;
client e;
f=fopen("client.bin","rb");
while(!feof(f))
	{
	fread(&e,sizeof(client),1,f);
	if(strcmp(selected_client.cin,e.cin)==0){selected_client=e;}
	}
fclose(f);

}

//----Bouton Supprimer--///
void
on_sup_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscrip;

inscrip=lookup_widget(button,"inscrip");
supprimer_client(selected_client);
GtkWidget *tree;
tree=lookup_widget(inscrip,"treeview2");
afficher_client(tree);

}

//---Bouton Chercher----//
void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *inscrip;
GtkWidget *cin;
cin= lookup_widget (objet,"entry9_C");
char NOME[25];

strcpy(NOME,gtk_entry_get_text(GTK_ENTRY(cin)));


GtkWidget *treeview2;
inscrip=lookup_widget (objet,"inscrip");


treeview2=lookup_widget (inscrip,"treeview2");

rechercher_client(NOME,treeview2);

}


//-----Bouton Modifier---///
void
on_mod_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif;
GtkWidget *window;
window= create_modif ();
  gtk_widget_show (window);

client e;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;


input1=lookup_widget(window,"entry10_C");
input2=lookup_widget(window,"entry11_C");
input3=lookup_widget(window,"entry12_C");
input4=lookup_widget(window,"entry13_C");
input5=lookup_widget(window,"combobox2_C");
input6=lookup_widget(window, "entry14_C");
input7=lookup_widget(window, "spinbutton2_C");
input8=lookup_widget(window, "entry15_C");
input9=lookup_widget(window, "entry16_C");
input10=lookup_widget(window, "entry17_C");

gtk_entry_set_text(input1,selected_client.cin);
gtk_entry_set_text(input2,selected_client.password);
gtk_entry_set_text(input3,selected_client.nom);
gtk_entry_set_text(input4,selected_client.prenom);
//gtk_combo_box_set_entry_text(input5,selected_client.sexe);
gtk_entry_set_text(input6,selected_client.dateNaiss);
gtk_spin_button_set_value(input7,selected_client.inscri);
gtk_entry_set_text(input8,selected_client.tel);
gtk_entry_set_text(input9,selected_client.mail);
gtk_entry_set_text(input10,selected_client.adresse);

}

//--bouton confirmer--//

void
on_conf_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
client e;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;


input1=lookup_widget(objet_graphique,"entry10_C");
input2=lookup_widget(objet_graphique,"entry11_C");
input3=lookup_widget(objet_graphique,"entry12_C");
input4=lookup_widget(objet_graphique,"entry13_C");

input5=lookup_widget(objet_graphique,"combobox2_C");

input6=lookup_widget(objet_graphique, "entry14_C");
input7=lookup_widget(objet_graphique, "spinbutton2_C");
input8=lookup_widget(objet_graphique, "entry15_C");

input9=lookup_widget(objet_graphique, "entry16_C");
input10=lookup_widget(objet_graphique, "entry17_C");

strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
//strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(e.dateNaiss,gtk_entry_get_text(GTK_ENTRY(input6)));
e.inscri=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input7));
strcpy(e.tel,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(e.mail,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(input10)));
supprimer_client(e);
ajouter_client(e);

}

//--bouton Retour--//
void
on_ret_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modif;
modif=lookup_widget(objet,"modif");
gtk_widget_destroy(modif);
}


void
on_recemment_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscrip;
GtkWidget *treeview2;

inscrip=lookup_widget(button,"inscrip");
treeview2=lookup_widget(inscrip,"treeview2");
rechercher_recemment(treeview2);

}

//bouton ajouter2
void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
commande c;

GtkWidget *input1,*input2,*input3,*input4,*input8,*input9,*input10;



input1=lookup_widget(objet_graphique,"combobox3_C");
input2=lookup_widget(objet_graphique, "spinbutton3_C");
input3=lookup_widget(objet_graphique,"femmelle");
input4=lookup_widget(objet_graphique,"male");

input8=lookup_widget(objet_graphique, "entry18_cin");
input9=lookup_widget(objet_graphique, "entry19_ref");
input10=lookup_widget(objet_graphique, "entry20_prix");

strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(c.ref,gtk_entry_get_text(GTK_ENTRY(input9)));

strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input3)))
{
strcpy(c.sexe,"Femmelle");}
else
{
strcpy(c.sexe,"Male");}
c.quantite=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input2));

strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(input10)));

ajouter_commande(c);
}




//////Afficher 2////////


void
on_afficher2_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *inscrip;
GtkWidget *treeview3;

inscrip=lookup_widget(objet,"inscrip");
treeview3=lookup_widget(inscrip,"treeview3");
afficher_commande(treeview3);
}




void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_data,-1);

}
strcpy(selected_commande.cin,str_data);

FILE *f;
commande e;
f=fopen("commande.bin","rb");
while(!feof(f))
	{
	fread(&e,sizeof(commande),1,f);
	if(strcmp(selected_commande.cin,e.cin)==0){selected_commande=e;}
	}
fclose(f);
}




void
on_buttonsupp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscrip;

inscrip=lookup_widget(button,"inscrip");
supprimer_commande(selected_commande);
GtkWidget *tree;
tree=lookup_widget(inscrip,"treeview3");
afficher_commande(tree);
}


void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button_modifier2_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif_Com;
GtkWidget *window;
window= create_modif_Com ();
  gtk_widget_show (window);
commande c;

GtkWidget *input1,*input2,*input3,*input4,*input8,*input9,*input10;



input1=lookup_widget(window,"combobox4_C");
//input2=lookup_widget(window "spinbutton4");
input3=lookup_widget(window,"femmelle");
input4=lookup_widget(window,"male");

input8=lookup_widget(window, "entry19_C");
input9=lookup_widget(window, "entry20_C");
input10=lookup_widget(window, "entry18_C");


gtk_entry_set_text(input1,selected_commande.cin);
gtk_entry_set_text(input9,selected_commande.ref);
gtk_entry_set_text(input10,selected_commande.prix);

gtk_spin_button_set_value(input2,selected_commande.quantite);



}


void
on_confirmer2_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
commande c;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input8,*input9,*input10;



input1=lookup_widget(objet_graphique,"combobox4_C");
input2=lookup_widget(objet_graphique, "spinbutton4_C");

input5=lookup_widget(objet_graphique,"combobox5_C");
input8=lookup_widget(objet_graphique, "entry19_C");
input9=lookup_widget(objet_graphique, "entry20_C");
input10=lookup_widget(objet_graphique, "entry18_C");

strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(c.ref,gtk_entry_get_text(GTK_ENTRY(input9)));

strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));

strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));

c.quantite=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input2));

strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(input10)));

supprimer_commande(c);
ajouter_commande(c);
}


void
on_retour2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modif_Com;
modif_Com=lookup_widget(objet,"modif_Com");
gtk_widget_destroy(modif_Com);
}






/////////Authentification



void
on_gest_client_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscrip;
GtkWidget *window;
window= create_inscrip ();
  gtk_widget_show (window);
}


void
on_connecter_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acc;
GtkWidget *window;
window= create_acc ();
  gtk_widget_show (window);
}


void
on_inscr_authen_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gest_auth;
GtkWidget *window;
window= create_gest_auth ();
  gtk_widget_show (window);
}


void
on_ajouter_auth_clicked                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
auth y;


GtkWidget *input1,*input2;



input1=lookup_widget(objet_graphique,"entry1_auth");
input2=lookup_widget(objet_graphique,"entry2_auth");

strcpy(y.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(y.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input2)));


ajouter_auth(y);
}


void
on_afficher_auth_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gest_auth;
GtkWidget *treeview4_auth;

gest_auth=lookup_widget(objet,"gest_auth");
treeview4_auth=lookup_widget(gest_auth,"treeview4_auth");
afficher_auth(treeview4_auth);
}


void
on_treeview4_auth_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_data,-1);

}
//strcpy(selected_client.cin,str_data);

FILE *f;
auth y;
f=fopen("auth.bin","rb");
while(!feof(f))
	{
	fread(&y,sizeof(auth),1,f);
	//if(strcmp(selected_client.cin,e.cin)==0){selected_client=e;}
	}
fclose(f);
}


void
on_retour_auth_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gest_auth;
gest_auth=lookup_widget(objet,"gest_auth");
gtk_widget_destroy(gest_auth);
}

