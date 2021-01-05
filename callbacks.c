#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ouvrier.h"
#include<string.h>

GtkWidget *Ouvrier;
GtkWidget *aj;
GtkWidget *ms;
GtkWidget *abse;
GtkWidget *treeAFF;
GtkWidget *output;

/*********Bouton afficher treeview**************/
void
on_BF_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Ouvrier=lookup_widget(objet_graphique,"Ouvrier");
treeAFF=lookup_widget(Ouvrier,"treeAFF");
afficher_ouvrier(treeAFF);
}

/*********Bouton Actualiser************/
void
on_AFAC_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
Ouvrier=lookup_widget(objet, "Ouvrier");
gtk_widget_destroy(Ouvrier);
Ouvrier=create_Ouvrier();
gtk_widget_show(Ouvrier);
}

/**************Bouton Modifier_Supprimer***************/
void
on_buttonfms_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Ouvrier=lookup_widget(objet_graphique,"Ouvrier");
ms=create_ms();
gtk_widget_destroy(Ouvrier);
gtk_widget_show(ms);
}

/****************Bouton Gestion d'absence********/
void
on_buttonfabs_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Ouvrier=lookup_widget(objet_graphique,"Ouvrier");
abse=create_abse();
gtk_widget_destroy(Ouvrier);
gtk_widget_show(abse);
}

/*******************Bouton Ajouter informmations**************/
void
on_buttonAJ_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
ouvrier o;

GtkWidget *nom, *prenom, *cin, *telephone,*tache, *jour, *mois, *annee, *sexeh, *sexef;
GtkWidget *admin;

Ouvrier=lookup_widget(objet, "Ouvrier");

nom=lookup_widget(objet, "EN");
prenom=lookup_widget(objet, "EP");
cin=lookup_widget(objet, "ECI");
telephone=lookup_widget(objet, "entry4");
tache=lookup_widget(objet, "combobox1");
jour=lookup_widget(objet, "spinbuttonJA");
mois=lookup_widget(objet, "spinbuttonMA");
annee=lookup_widget(objet, "spinbuttonAA");
sexeh=lookup_widget(objet, "radiobuttonH");
sexef=lookup_widget(objet, "radiobuttonF");

strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(o.telephone,gtk_entry_get_text(GTK_ENTRY(telephone)));
strcpy(o.tache,gtk_combo_box_get_active_text(GTK_COMBO_BOX(tache)));

o.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sexeh)))
	{strcpy(o.sexe,"Homme");}
else	{strcpy(o.sexe,"Femme");}

ajouter_ouvrier(o);
aj=lookup_widget(objet,"aj");
Ouvrier=create_Ouvrier();
gtk_widget_destroy(aj);
gtk_widget_show(Ouvrier);
}

/*****************Bouton Modifier***************/
void
on_buttonMOD_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *prenom, *nom, *cin, *telephone, *tache, *jour, *mois, *annee, *sexe;
  
  ouvrier o1;

  char cine[9];
  
  
  FILE* f;
  f=fopen("utilisateurs.txt","r");

  prenom=lookup_widget (objet,"ePRM");
  nom=lookup_widget (objet,"eNOMM");
  cin=lookup_widget (objet,"eCHR");
  telephone=lookup_widget (objet,"eTELM");
  tache=lookup_widget (objet,"eTAFM");;
  jour=lookup_widget (objet,"spinbuttonJM");
  mois=lookup_widget (objet,"spinbuttonMM");
  annee=lookup_widget (objet,"spinbuttonAM");
  sexe=lookup_widget (objet,"radiobuttonS");
  
strcpy(o1.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(o1.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(o1.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(o1.telephone,gtk_entry_get_text(GTK_ENTRY(telephone)));
strcpy(o1.tache,gtk_entry_get_text(GTK_ENTRY(tache)));


o1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(o1.sexe,gtk_entry_get_text(GTK_ENTRY(sexe)));

  modifier_ouvrier(o1);
  fclose(f);
ms=lookup_widget(objet,"ms");
Ouvrier=create_Ouvrier();
gtk_widget_destroy(ms);
gtk_widget_show(Ouvrier);
}

/***************Bouton chercher*************/
void
on_buttonCHR_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *eCHR, *prenom, *nom, *cin, *telephone, *tache, *jour, *mois, *annee, *sexe;
  ouvrier o;
  char cine[9] ;
 

  
  eCHR=lookup_widget(objet, "eCHR");
  strcpy(cine,gtk_entry_get_text(GTK_ENTRY(eCHR)));
  
  o=rechercher(cine);

  FILE* f;
  f=fopen("utilisateurs.txt","r");
 
  prenom=lookup_widget (objet,"ePRM");
  nom=lookup_widget (objet,"eNOMM");
  cin=lookup_widget (objet,"eCHR");
  telephone=lookup_widget (objet,"eTELM");
  tache=lookup_widget (objet,"eTAFM");;
  jour=lookup_widget (objet,"spinbuttonJM");
  mois=lookup_widget (objet,"spinbuttonMM");
  annee=lookup_widget (objet,"spinbuttonAM");
  sexe=lookup_widget (objet,"radiobuttonS");
  gtk_entry_set_text (GTK_ENTRY(prenom),o.prenom);
  gtk_entry_set_text (GTK_ENTRY(nom),o.nom);
  gtk_entry_set_text (GTK_ENTRY(cin),o.cin);
  gtk_entry_set_text (GTK_ENTRY(telephone),o.telephone);
  gtk_entry_set_text (GTK_ENTRY(tache),o.tache);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),o.jour);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),o.mois);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),o.annee);
  gtk_entry_set_text (GTK_ENTRY(sexe),o.sexe);

  fclose(f);
}


/********************Bouton Supprimer******************/
void
on_SUP_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nom, *prenom, *cin, *telephone, *tache, *jour, *mois, *annee, *sexe, *outpout;
  ouvrier o;
char cine[9];
int suppri;
  FILE* f;

  prenom=lookup_widget (objet,"ePRM");
  nom=lookup_widget (objet,"eNOMM");
  cin=lookup_widget (objet,"eCHR");
  telephone=lookup_widget (objet,"eTELM");
  tache=lookup_widget (objet,"eTAFM");;
  jour=lookup_widget (objet,"spinbuttonJM");
  mois=lookup_widget (objet,"spinbuttonMM");
  annee=lookup_widget (objet,"spinbuttonAM");
  sexe=lookup_widget (objet,"radiobuttonS");
   
   outpout=lookup_widget (objet,"ERR");
   strcpy (cine,gtk_entry_get_text(GTK_ENTRY(cin)));
   suppri=supprimer_ouvrier(o,cine);
  if (suppri==1)
   {
  gtk_label_set_text (GTK_LABEL(outpout),"ouvrier supprimé");
	printf("ouvrier supprimé");
   }
ms=lookup_widget(objet,"ms");
Ouvrier=create_Ouvrier();
gtk_widget_destroy(ms);
gtk_widget_show(Ouvrier);
}

/**************Bouton chercher taux d'absence**************/
void
on_CHAB_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *eABCH, *taux;
  absence a;
  char cine[9] ;
 

  
  eABCH=lookup_widget(objet, "eABCH");
  strcpy(cine,gtk_entry_get_text(GTK_ENTRY(eABCH)));
  
  a=recherch(cine);
  taux=lookup_widget (objet,"spinbuttonT");
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(taux),a.taux);

}

/***************Bouton Marquer absence*******************/
void
on_MQAB_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *cin, *taux, *nbabs, *nbpr;
  
  absence a1;
  absence a2;

  char cine[9];
  
  
  FILE* f;
  f=fopen("absence.txt","r");

  cin=lookup_widget (objet,"eABCH");
  nbabs=lookup_widget (objet,"radiobuttonAB");

strcpy(a1.cin,gtk_entry_get_text(GTK_ENTRY(cin)));

a2=recherch(a1.cin);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(nbabs)))
	{a2.nbabs++;
	 a2.taux=(100/(a2.nbabs+a2.nbpr))*a2.nbabs;
	}
	
else	{a2.nbpr++;
	 a2.taux=(100/(a2.nbabs+a2.nbpr))*a2.nbabs;
	}

  modifier_abs(a2);
  fclose(f);
}

/**************Bouton meilleur ouvrier*************/
void
on_mei_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *eNAB;
  absence a;
  a=meilleur ();
  eNAB=lookup_widget (objet,"eNAB");
  gtk_entry_set_text (GTK_ENTRY(eNAB),a.cin);
}

/************** Ajouter treeview ***********/
void
on_buttonfaj_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Ouvrier=lookup_widget(objet_graphique,"Ouvrier");
aj=create_aj();
gtk_widget_destroy(Ouvrier);
gtk_widget_show(aj);
}

/**************Bouton retour**********/
void
on_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
abse=lookup_widget(objet_graphique,"abse");
Ouvrier=create_Ouvrier();
gtk_widget_destroy(abse);
gtk_widget_show(Ouvrier);
}

