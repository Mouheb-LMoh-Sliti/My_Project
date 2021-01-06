#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "equip.h"
#include "support.h"
#include <string.h>


GtkWidget *eqag;
GtkWidget *treeaff;
GtkWidget *eg;
GtkWidget *output;




void
on_actaff_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
eqag=lookup_widget(objet, "equipement");
gtk_widget_destroy(eqag);
eqag=create_equipement();
gtk_widget_show(eqag);
}


void
on_marq_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_aff_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
eqag=lookup_widget(objet_graphique,"equipement");
eg=lookup_widget(eqag,"eg");
treeaff=lookup_widget(eqag,"treeaff");
afficher_equipement(treeaff);
}


void
on_ajact_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
eqag=lookup_widget(objet, "equipement");
gtk_widget_destroy(eqag);
eqag=create_equipement();
gtk_widget_show(eqag);
}


void
on_ajaj_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
equipement e;

GtkWidget *ref, *nom, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *bon, *def;

eqag=lookup_widget(objet, "equipement");

ref=lookup_widget(objet, "eajref");
nom=lookup_widget(objet, "eajn");
marque=lookup_widget(objet, "combobox4");
jour=lookup_widget(objet, "spinbuttonajaj");
mois=lookup_widget(objet, "spinbuttonajam");
annee=lookup_widget(objet, "spinbuttonajaa");
jour=lookup_widget(objet, "spinbuttonajmj");
mois=lookup_widget(objet, "spinbuttonajmm");
annee=lookup_widget(objet, "spinbuttonajma");
bon=lookup_widget(objet, "radiobuttonajeb");
def=lookup_widget(objet, "radiobuttonajed");

strcpy(e.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(e.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(marque) ) );

e.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
e.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
e.jourm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourm));
e.moism=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moism));
e.anneem=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneem));

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bon)))
	{strcpy(e.etat,"bonne_etat");}
else	{strcpy(e.etat,"defectueux");}

ajouter_equipement(e);
}


void
on_mschr_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *emsref, *nom, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *etat;
  equipement e;
  char ref[9] ;
 

  
  emsref=lookup_widget(objet, "emsref");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
  
  e=rechercher(ref);

  FILE* f;
  f=fopen("equip.txt","r");
 
  nom=lookup_widget (objet,"emsn");
  marque=lookup_widget (objet,"emsmar");
  jour=lookup_widget (objet,"spinbuttonmsaj");
  mois=lookup_widget (objet,"spinbuttonmsam");
  annee=lookup_widget (objet,"spinbuttonmsaa");
  jourm=lookup_widget (objet,"spinbuttonmsmj");
  moism=lookup_widget (objet,"spinbuttonmsmm");
  anneem=lookup_widget (objet,"spinbuttonmsma");
  etat=lookup_widget (objet,"emse");
  gtk_entry_set_text (GTK_ENTRY(emsref),e.ref);
  gtk_entry_set_text (GTK_ENTRY(nom),e.nom);
  gtk_combo_box_set_active(GTK_COMBO_BOX(marque),e.marque);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),e.jour);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),e.mois);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),e.annee);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(jourm),e.jourm);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(moism),e.moism);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(anneem),e.anneem);
  gtk_entry_set_text (GTK_ENTRY(etat),e.etat);
  
  
  fclose(f);
}


void
on_msmod_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *emsref, *nom, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *etat ,*message;
  equipement e1;
  char ref[9] ;
 

  
  emsref=lookup_widget(objet, "emsref");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
  
  e1=rechercher(ref);

 message=lookup_widget(objet,"label26");
 gtk_widget_show (message);

  FILE* f;
  f=fopen("equip.txt","r");
 
  nom=lookup_widget (objet,"emsn");
  marque=lookup_widget (objet,"emsmar");
  jour=lookup_widget (objet,"spinbuttonmsaj");
  mois=lookup_widget (objet,"spinbuttonmsam");
  annee=lookup_widget (objet,"spinbuttonmsaa");
  jourm=lookup_widget (objet,"spinbuttonmsmj");
  moism=lookup_widget (objet,"spinbuttonmsmm");
  anneem=lookup_widget (objet,"spinbuttonmsma");
  etat=lookup_widget (objet,"emse");
  
strcpy(e1.ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
strcpy(e1.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(e1.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(e1.etat,gtk_entry_get_text(GTK_ENTRY(etat)));



e1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
e1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
e1.jourm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourm));
e1.moism=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moism));
e1.anneem=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneem));

	


  modifier_equipement(e1);
  fclose(f);
}


void
on_mssup_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nom, *emsref, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *etat, *outpout, *message;
  equipement e;
char ref[9];
int suppri;
  FILE* f;

  emsref=lookup_widget(objet, "emsref");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
   
   outpout=lookup_widget (objet,"err");
   suppri=supprimer_equipement(e,ref);
  if (suppri==1)
   {
  gtk_label_set_text (GTK_LABEL(outpout),"equipement supprimé");
	/*printf("equipement supprimé");*/
	message=lookup_widget(objet,"label27");
 	gtk_widget_show (message);
   }

}


void
on_msact_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
eqag=lookup_widget(objet, "equipement");
gtk_widget_destroy(eqag);
eqag=create_equipement();
gtk_widget_show(eqag);
}

