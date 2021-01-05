#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "employe.h"

employe selected_employe;


void
on_annuler_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier;
GtkWidget *Formulaire;
modifier=lookup_widget(objet,"modifier");
gtk_widget_destroy(modifier);
Formulaire=create_Formulaire();
gtk_widget_show(Formulaire);
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
on_SUPEM_clicked                       (GtkWidget      *objet,
                                        gpointer         user_data)
{
employe e;
GtkWidget *modifier,*Formulaire,*cinE,*nomE,*prenomE,*sexeE,*date_naissanceE,*adresseE,*telephoneE,*date_recrutementE,*mailE,*profilE;


  char CinE[9];
  int suppri;
  FILE* f;
 cinE=lookup_widget(objet,"CINRECHM");
nomE=lookup_widget(objet,"nomEM");
prenomE=lookup_widget(objet,"prenomEM");
sexeE=lookup_widget(objet,"sexeEM");
date_naissanceE=lookup_widget(objet,"datenaissanceEM");
adresseE=lookup_widget(objet,"adresseEM");
telephoneE=lookup_widget(objet, "telephoneEM");
mailE=lookup_widget(objet, "mailEM");
date_recrutementE=lookup_widget(objet, "recrutementEM");
profilE=lookup_widget(objet,"profilEM");

strcpy (CinE,gtk_entry_get_text(GTK_ENTRY(cinE)));
   suppri=supprimer_employe(e,CinE);
  if (suppri==1)
   {
  
	printf("ouvrier supprimé");
   }
modifier=lookup_widget(objet,"modifier");
Formulaire=create_Formulaire();
gtk_widget_destroy(modifier);
gtk_widget_show(Formulaire);
}


void
on_ajouterEM_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
employe e;

GtkWidget *input1,*input2,*input3,*femme,*homme,*input4,*input5,*input6,*input7,*input8,*input9;


input1=lookup_widget(objet_graphique,"nomm");
input2=lookup_widget(objet_graphique,"prenomm");
input3=lookup_widget(objet_graphique,"cinn");
femme=lookup_widget(objet_graphique,"femme");
homme=lookup_widget(objet_graphique,"homme");

input4=lookup_widget(objet_graphique,"datenaissancee");

input5=lookup_widget(objet_graphique, "adressee");
input6=lookup_widget(objet_graphique, "telephonee");

input7=lookup_widget(objet_graphique, "maill");
input8=lookup_widget(objet_graphique, "recrutementt");

input9=lookup_widget(objet_graphique,"combobox1EM");

strcpy(e.nomE,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenomE,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.cinE,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.date_naissanceE,gtk_entry_get_text(GTK_ENTRY(input4)));

strcpy(e.adresseE,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(e.telephoneE,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(e.mailE,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(e.date_recrutementE,gtk_entry_get_text(GTK_ENTRY(input8)));

strcpy(e.profilE,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input9)));

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
{
strcpy(e.sexeE,"Femme");}
else
{
strcpy(e.sexeE,"Homme");}

ajouter_employe(e);
}


void
on_rechercherEM_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Formulaire;
GtkWidget *cinE;
employe e;
cinE= lookup_widget (objet,"CINFEM");
char Cinn[20];

strcpy(Cinn,gtk_entry_get_text(GTK_ENTRY(cinE)));


GtkWidget *treeview1EM;
Formulaire=lookup_widget (objet,"Formulaire");


treeview1EM=lookup_widget (Formulaire,"treeview1EM");
rechercher_employe(Cinn,treeview1EM);
}


void
on_MODSUPEM_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Formulaire;
GtkWidget *modifier;
Formulaire=lookup_widget(objet_graphique,"Formulaire");
modifier=create_modifier();
gtk_widget_destroy(Formulaire);
gtk_widget_show(modifier);
}


void
on_afficherEM_enter                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Formulaire;
GtkWidget *treeview1EM;

Formulaire=lookup_widget(objet,"Formulaire");
treeview1EM=lookup_widget(Formulaire,"treeview1EM");
afficher_employe(treeview1EM);
}


void
on_MODEM_clicked                       (GtkWidget      *objet,
                                        gpointer         user_data)
{
employe e1;
GtkWidget *cinE,*nomE,*prenomE,*sexeE,*date_naissanceE,*adresseE,*telephoneE,*mailE,*date_recrutementE,*profilE;

GtkWidget *Formulaire,*modifier;
  char CinE[9];
  
  
  FILE* f;
  f=fopen("employe.txt","r");
cinE=lookup_widget(objet,"CINRECHM");
nomE=lookup_widget(objet,"nomEM");
prenomE=lookup_widget(objet,"prenomEM");
sexeE=lookup_widget(objet,"sexeEM");
date_naissanceE=lookup_widget(objet,"datenaissanceEM");
adresseE=lookup_widget(objet,"adresseEM");
telephoneE=lookup_widget(objet, "telephoneEM");
mailE=lookup_widget(objet, "mailEM");
date_recrutementE=lookup_widget(objet, "recrutementEM");
profilE=lookup_widget(objet,"profilEM");

strcpy(e1.cinE,gtk_entry_get_text(GTK_ENTRY(cinE)));
strcpy(e1.nomE,gtk_entry_get_text(GTK_ENTRY(nomE)));
strcpy(e1.prenomE,gtk_entry_get_text(GTK_ENTRY(prenomE)));
strcpy(e1.sexeE,gtk_entry_get_text(GTK_ENTRY(sexeE)));
strcpy(e1.date_naissanceE,gtk_entry_get_text(GTK_ENTRY(date_naissanceE)));
strcpy(e1.adresseE,gtk_entry_get_text(GTK_ENTRY(adresseE)));
strcpy(e1.telephoneE,gtk_entry_get_text(GTK_ENTRY(telephoneE)));
strcpy(e1.mailE,gtk_entry_get_text(GTK_ENTRY(mailE)));
strcpy(e1.date_recrutementE,gtk_entry_get_text(GTK_ENTRY(date_recrutementE)));
strcpy(e1.profilE,gtk_entry_get_text(GTK_ENTRY(profilE)));

modifier_employe(e1);
  fclose(f);
modifier=lookup_widget(objet,"modifier");
Formulaire=create_Formulaire();
gtk_widget_destroy(modifier);
gtk_widget_show(Formulaire);
}


void
on_RECHEM_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *CINRECHM, *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9,*input0;
  employe e;
  char CinE[9] ;
 

  
  CINRECHM=lookup_widget(objet_graphique, "CINRECHM");
  strcpy(CinE,gtk_entry_get_text(GTK_ENTRY(CINRECHM)));
  
  e=rechercher(CinE);
FILE* f;
  f=fopen("employe.txt","r");
input0=lookup_widget (objet_graphique,"CINRECHM");
input1=lookup_widget(objet_graphique,"nomEM");
input2=lookup_widget(objet_graphique,"prenomEM");
input3=lookup_widget(objet_graphique,"sexeEM");
input4=lookup_widget(objet_graphique,"datenaissanceEM");
input5=lookup_widget(objet_graphique,"adresseEM");
input6=lookup_widget(objet_graphique, "telephoneEM");
input7=lookup_widget(objet_graphique, "mailEM");
input8=lookup_widget(objet_graphique, "recrutementEM");
input9=lookup_widget(objet_graphique,"profilEM");

  gtk_entry_set_text (GTK_ENTRY(input0),e.cinE);
  gtk_entry_set_text (GTK_ENTRY(input1),e.nomE);
  gtk_entry_set_text (GTK_ENTRY(input2),e.prenomE);
  gtk_entry_set_text (GTK_ENTRY(input3),e.sexeE);
  gtk_entry_set_text (GTK_ENTRY(input4),e.date_naissanceE);
  gtk_entry_set_text (GTK_ENTRY(input5),e.adresseE);
  gtk_entry_set_text (GTK_ENTRY(input6),e.telephoneE);
  gtk_entry_set_text (GTK_ENTRY(input7),e.mailE);
  gtk_entry_set_text (GTK_ENTRY(input8),e.date_recrutementE);
  gtk_entry_set_text (GTK_ENTRY(input9),e.profilE);
  

fclose(f);
}

