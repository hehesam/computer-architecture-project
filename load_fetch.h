#ifndef LOAD_FETCH_H
#define LOAD_FETCH_H
#endif // LOAD_FETCH_H

#include<stdio.h>
#include"control_unit.h"

 extern int R[16] ;
 extern int PC;


void PC_Adder()
{
    PC++;
}

void load_fetch(int dec){
    PC_Adder();
    int op_code = opcodeFinder(dec);
    printf("op code : %d \n", op_code);
}

