typedef struct
{
char login[50];
char mot_de_passe[50];

}auth;


typedef struct
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

}client;

void ajouter_auth(auth y);
void afficher_auth(GtkWidget *liste);
//int exist_authen(char*login);



void ajouter_client(client e);
void afficher_client(GtkWidget *liste);
void supprimer_client(client e);
void rechercher_client(char NOMC[25],GtkWidget *liste);
void modifier_client(client e);
void rechercher_recemment(GtkWidget *liste);

int exist_client(char*cin);



