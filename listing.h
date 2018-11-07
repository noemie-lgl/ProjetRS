//listing contenu d'un répertoire

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


static int compare (void const*a,void const*b){

  char const *const *pa=a;
  char const *const *pb=b;
  return strcmp(*pa,*pb);
}

  
// doit afficher sur deux colonnes et dans l'ordre alphabétique
void listing(){

    DIR *dirp=opendir(".");
    struct dirent *dp;
    char *table[1000];
    int i=0;

    while ((dp=readdir(dirp))!=NULL){
        table[i]=dp->d_name;
        i+=1;
    }
    closedir(dirp);

    qsort(&table[0],i,sizeof(char*),compare);
    
    int j=0;
    while(table[j]!=NULL){
        printf("%s\n",table[j]);
	j+=1;
    }
}
