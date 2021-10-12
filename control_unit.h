#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H
#endif // CONTROL_UNIT_H
#include<stdio.h>
extern int R[16] ;
int opCode ;
int opcodeFinder(int dec){
    opCode = 251658240;
    opCode = opCode & dec;
    opCode = opCode>>24;
    return opCode;
}
int get_opcode(){
    return opCode;
}
int typeFinder(){
    if(opCode>=0 && opCode<=4){
        return 0;
    }
    else if(opCode>=5 && opCode<=12){
        return 1;
    }
    else if (opCode>=13 && opCode<=14){
        return 2;
    }
    return 0;
}

int get_signal3(){
    if( opCode>= 0 && opCode<=9){
        return 1;
    }
    else
        return 0;
}

int get_signal2(){
    if((opCode >=0 && opCode<=4)||opCode==11 || opCode==12){
        return 0; //rt
    }
    return 1; //extention of offset
}

int get_Branch_signal()
{
    if(opCode == 11)
        return 1;
    return 0;
}

int get_Jump_siganl()
{
    if(opCode==13)
        return 1;
    return 0;
}

int extend_signal(){
    if(opCode == 5 || opCode ==6 || opCode ==9 || opCode ==10 || opCode ==11){
        return 1;
    }
    if(opCode ==7 || opCode ==8)
        return 2;

    return 0;
}

int get_jal_siganl()
{
    if(opCode == 12)
        return 1;
    else
        return 0;

}



