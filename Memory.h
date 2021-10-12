#ifndef MEMORY_H
#define MEMORY_H
#endif // MEMORY_H

#include<stdio.h>
#include"EXE.h"
#include"Print.h"

extern int Memory[65536];
extern int R[16] ;
extern int PC;

void Mux3(int res_Mux7){
    int flag = get_signal3(); // need to write to register or what?
    int *destination =  Mux1();

    if(flag){
        *destination = res_Mux7;
    }
}

int Mux7(int res)
{
    int signal7 = get_jal_siganl();

    if(signal7)
        return PC;
    else
        return res;
}

void MEM(){
    int opcode = get_opcode();
    int res = get_ALU_res();
    int rt=RT();

    if(opcode == 9){
        // LW
       res = Memory[res];
    }

    else if(opcode == 10){
        // SW
        Memory[res] = R[rt];
    }

    //int res_Mux3 = Mux3(res);
    //Mux7(res_Mux3);

    int res_Mux7 = Mux7(res);
    Mux3(res_Mux7);

    print_PC();
    print_R();
//    print_M();

}

