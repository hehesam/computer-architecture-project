#ifndef PRINT_H
#define PRINT_H
#endif // PRINT_H
#include<stdio.h>
extern int Memory[65536];
extern int R[16] ;
extern int PC;

void print_R(){
    printf("Registers: \n");
    int i=0;
    for(i=0;i<16;i++)
        printf("R[%d] = %d \t", i, R[i]);
    printf("\n");
}
void print_M(){
    printf("Memory: \n");
    for(int i=0;i<10;i++)
        printf("M[%d] = %d\t", i, Memory[i]);
    printf("\n");

}
void print_PC(){
    printf("the PC is :     %d\n", PC);
}

void sep_Line(){
    printf("--------------------------------------------------------------------------\n");
}
