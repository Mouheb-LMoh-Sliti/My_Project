#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "tree_ouss.h"
#include<string.h>

//Ajouter un troupeaux 

void ajouter_troupeaux( troupeaux t){
FILE*f=NULL; //flot de donnée
f=fopen("troupeaux.txt","a+");// creation du fichier troupeaux .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s\n",t.id,t.sexe,t.type,t.date); //f variable de type file 
fclose(f);
 //retour NULL si operation fini 
}
//********************************************************





//verifier l'existance 

int exist_troupeaux(char*id){
FILE*f=NULL;
troupeaux t;
f=fopen("troupeaux.txt","r");// ouverture du fichier troupeaux en  mode lecture 
while(fscanf(f,"%s %s %s %s\n",t.id,t.sexe,t.type,t.date)!=EOF){
if(strcmp(t.id,id)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//*****************************************************************




//supprimer tr
void supprimer_troupeaux(char*id){
FILE*f=NULL;
FILE*f1=NULL;
troupeaux t ;
f=fopen("troupeaux.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s\n",t.id,t.sexe,t.type,t.date)!=EOF){
if(strcmp(id,t.id)!=0)fprintf(f1,"%s %s %s %s\n",t.id,t.sexe,t.type,t.date);
}
fclose(f);
fclose(f1);
remove("troupeaux.txt");
rename("ancien.txt","troupeaux.txt");
}

//******************************************************************


















