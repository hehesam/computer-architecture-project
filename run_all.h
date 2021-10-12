#ifndef RUN_ALL_H
#define RUN_ALL_H
#endif // RUN_ALL_H
#include<stdio.h>
#include"input.h"
#include"Memory.h"


#include"Pulse_refresh.h"

int Lines[100] = {0};
int R [16] = {0};
int Memory[65536] = {0};
int R_usage[16] = {0};

int M_usage = 0;
int PC=0;

int instructionCounter = 0;


int main(){
//    take_input();
    int i=0;
    while(Lines[i]){
        if( Lines[i] == 234881024){
            i++;
            while(Lines[i]){
                Memory[i] = Lines[i];
                M_usage++;
//                printf("%d\n", Memory[i]);
                i++;
            }
        }
        i++;
    }
    print_PC();
//    print_M();


    return 0;
}

void process(){

       instructionCounter ++;

        int decimal = Lines[PC];

        printf("Line %d: %d \n", PC, decimal);

        // load_fetch header:
        load_fetch(decimal);

        // Decoade header:
        find_register(decimal);

        // EXE header:
        ALU();

        // Memory header:
        MEM();
        sep_Line();

}

// adding comments
