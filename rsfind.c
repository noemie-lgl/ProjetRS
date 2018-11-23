#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <getopt.h>

void listing(char *arg);

static int compare (void const*a,void const*b);

int printfBis(char* nom);

int main(int argc, char *argv[]){

    if (argc<2){
        listing(".");
        return 0;
        //cas où on n'a pas d'argument
    }

    int i;
    static struct option long_options[]={{"name",1,NULL,'n'},{"exec",1,NULL,'e'}}; //0: no argument , 1: an argument is required , 2: the argument is optional

    int option_index;

    while(i=getopt_long(argc, argv, "lit:",long_options, &option_index )){

       if (i==-1){
        break;
       }
       switch(i){
       case 'l':
            printf("option l");
            break;

       case 'i':

           printf("option i");
           break;

       case 't':

           printf("option t with argument %s",optarg);
           break;

        case 'n': //option --name
            printf("option name with argument %s",optarg);
            break;

        case 'e': //option --exec
            printf("option exec");
            break;

        }
    }

  
}


void listing( char * arg){
    
    DIR *dirp=opendir(arg); // il faut mettre le chemin si c'est un dossier antérieur, le nom suffit si c'est un descendant

    if (dirp==NULL){
        printf("rsfind: %s: No such file or directory\n",arg); //doit renvoyer rsfind: ou find:  ???
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
        printf("%s\n",arg);
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
