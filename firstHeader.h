#ifndef FIRSTHEADER_H
#define FIRSTHEADER_H
#endif // FIRSTHEADER_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

 char * print_h(){

//    char * arr =  (char*)calloc(6,1);
//    arr = "hesam";

     char * arr = "hesam";

     printf("this is arr: ");
     for(unsigned  int i=0;i<=sizeof (arr);i++){
         printf("%c  ", arr[i]);
     }
     printf("\n");

    return arr;

}
