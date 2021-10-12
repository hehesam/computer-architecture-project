#ifndef EXE_H
#define EXE_H
#endif // EXE_H
#include<stdio.h>
#include"Decode.h"

extern int R[16] ;
extern int PC;

int res;
int componant2;

void Mux2() // choose "rt" or "extention of offset"
{
   int signal = get_signal2();
   if(signal == 0){
       componant2 = R[RT()];
   }
   else{
       componant2 = get_extention();
   }
}

int AND() // make a selector for Mux4
{
    int s1 = get_Branch_signal();
    int s2 = res;
    if((s1 & s2) == 1)
        return 1;
    return 0;
}

int Adder() // add the pc and extention of offset
{
   return PC + get_extention();
}

int Mux4(int signal , int PC2) // return "the offset of Branch" or "PC"
{
    if(signal == 1) //Branch Instruction
        return PC2;
    else
        return PC;
}

int Mux5(int res_Mux4) // return "the offset of Jump" or "PC"
{
   int signal5 = get_Jump_siganl();
   if(signal5)
       return componant2;
   else
       return res_Mux4;
}

void Mux6(int res_Mux5 , int rs) //set the PC with "RS" for jal or "res of MUX5"
{
    int signal6 = get_jal_siganl();
    if(signal6)
        PC = R[rs];
    else
        PC = res_Mux5;
}

void  ALU(){

    Mux2();
    int opcode = get_opcode();
    int rs=RS();

    switch (opcode) {
            case 0 :
                res = R[rs] + componant2;
                break;
            case 1:
                res = R[rs] - componant2;
                break;

            case 2:
                res = R[rs] - componant2;
                if(res<0)
                    res = 1;
                else
                    res = 0;
                break;

            case 3:
                res = R[rs] | componant2;
                break;

            case 4:
                res = R[rs] & componant2;
                break;

            case 5:
                res = R[rs] + componant2;
                break;

            case 6:
                res = R[rs] - componant2;
                if(res<0)
                    res = 1;
                else
                    res = 0;
                break;

            case 7:
                res = R[rs] | componant2;
                break;

            case 8:
                res = componant2 << 16;
                break;

            case 9:
                res = R[rs] + componant2;
                break;

            case 10:
                res = R[rs] + componant2;
                break;

            case 11:
                if(R[rs] == componant2)
                    res = 1;
                    //PC += offset;
                else
                    res = 0;
                break;




    }
    int PC2 = Adder();

    int signal4 = AND();
    int res_MUX4 = Mux4(signal4 , PC2); // for Branch Instruction

    int res_Mux5 = Mux5(res_MUX4); // for Jump Instruction

    Mux6(res_Mux5 , rs); // for jal Instruction
}

int get_ALU_res(){
    return res;
}
