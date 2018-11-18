#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


static int compare (void const*a,void const*b);


int printfBis(char* nom);

void main(int argc, char *argv[]){

    if (argc<2){
        printf("missing argument\n");
        exit(1);
        //cas où on n'a pas d'argument
    }


  DIR *dirp=opendir(argv[1]); // il faut mettre le chemin si c'est un dossier antérieur, le nom suffit si c'est un descendant

  if (dirp==NULL){
        printf("rsfind: %s: No such file or directory\n",argv[1]); //doit renvoyer rsfind: ou find:  ???
        exit(2);
  }

  struct dirent *dp;
  char *table[1000];
  int i=0;

  while ((dp=readdir(dirp))!=NULL){
    if (strcmp(dp->d_name,".") && strcmp(dp->d_name,"..")){
        table[i]=dp->d_name;
        i+=1;
    }

  }
  closedir(dirp);

  if (i==0){ //le directory est vide
    printf("%s\n",argv[1]);
    exit(2);
  }


  qsort(&table[0],i,sizeof(char*),compare);

  int j=0;
  while(j<=i){
    if (fork()==0){
      printfBis(table[j]);
      exit(1);
    }
    else {
      wait(NULL);
      j+=1;
    }
  }
}

static int compare (void const*a,void const*b){

  char const *const *pa=a;
  char const *const *pb=b;
  return strcmp(*pa,*pb);
}

int printfBis(char* nom){
  int i=0;
  while(nom[i]!='\0'){
    write(1,&nom[i],1);
    i=i+1;
  }
  write(1,"\n",sizeof("\n"));
}
