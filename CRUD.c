#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>

//Ajouter un plante 

void ajouter_plante( plante t){
FILE*f=NULL; //flot de donnée
f=fopen("plante.txt","a+");// creation du fichier plante .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s %s\n",t.id,t.saison,t.type,t.date,t.prix); //f variable de type file 
fclose(f);
 //retour NULL si operation fini 
}
//********************************************************





//verifier l'existance 

int exist_plante(char*id){
FILE*f=NULL;
plante t;
f=fopen("plante.txt","r");// ouverture du fichier plante en  mode lecture 
while(fscanf(f,"%s %s %s %s %s\n",t.id,t.saison,t.type,t.date,t.prix)!=EOF){
if(strcmp(t.id,id)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//*****************************************************************




//supprimer tr
void supprimer_plante(char*id){
FILE*f=NULL;
FILE*f1=NULL;
plante t ;
f=fopen("plante.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s\n",t.id,t.saison,t.type,t.date,t.prix)!=EOF){
if(strcmp(id,t.id)!=0)fprintf(f1,"%s %s %s %s %s\n",t.id,t.saison,t.type,t.date,t.prix);
}
fclose(f);
fclose(f1);
remove("plante.txt");
rename("ancien.txt","plante.txt");
}

//******************************************************************


















