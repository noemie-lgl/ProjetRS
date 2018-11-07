#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "listing.h"


int main(int argc, char *argv[])
{
    if (argc<2){
        printf("missing argument");
        return 0;
        //cas où on n'a pas d'argument
    }

    int i;
    static struct option long_options[]={{"name",1,NULL,0},{"exec",1,NULL,0}}; //0: no argument , 1: an argument is required , 2: the argument is optional
    int option_index;

    while(i=getopt_long(argc, argv, "lit:",long_options, &option_index )){

       if (i==-1){
        printf("ERROR");
        return 0;
       }
       switch(i){
       case 'l':
            listing();
            break;

       case 'i':

           printf("option i");
           break;

       case 't':

           printf("option t with argument %s",optarg);
           break;

        }
    }
}
