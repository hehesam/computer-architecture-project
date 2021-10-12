#ifndef DECODE_H
#define DECODE_H
#endif // DECODE_H
#include<stdio.h>
#include"load_fetch.h"

extern int R_usage[16] ;


int a,b,c;
int offset = 65535;

void extender(){

    int signal = extend_signal();
    int neg = 32768;
    neg = neg & offset;

    if(signal==1 && neg>0){
        int neg2 = -65536;
        offset = neg2 | offset;
    }
}

void find_register(int dec){


    offset = 65535;


    int rs = 15728640;
    int rt = 983040;
    int rd = 61440;
    int type = typeFinder();
    if(type==0){
        printf("this is R type : \n");

        a = dec & rs;
        b = dec & rt;
        c = dec & rd;

        a = a >> 20;
        b = b >> 16;
        c = c >> 12;

        R_usage[a]++;
        R_usage[b]++;
        R_usage[c]++;


        printf("rs: %d  rt: %d  rd: %d\n", a,b,c);

    }
    else if(type==1){
        printf("this is I type: \n");

        a = dec & rs;
        b = dec & rt;
        offset = dec & offset;
        int neg = 32768;
        neg = neg & offset;
        int opcode = get_opcode();

        if(neg != 0 && (opcode !=7 && opcode != 8)){
            // 1111 000
            int neg2 = -65536;
            offset = neg2 | offset;
        }
        a = a >> 20;
        b = b >> 16;

        R_usage[a]++;
        R_usage[b]++;


         printf("rs: %d  rt: %d offset: %d\n ", a,b,offset);


    }
    else if(type == 2){
        printf("this is J type : \n");

        offset = dec & offset;
          printf("offset: %d \n",offset);
    }


}


// made change     ---------------------------
int * Mux1(){
    int type2 = typeFinder();
     int * destination = 0;
    if(type2 == 0){
            destination =  & R[c];
    }

    else if(type2 == 1){
        destination = & R[b];
    }
    return destination;
}



int RS(){
    return a;
}

int RT(){
    return b;
}

int RD(){
    return c;
}

int get_extention(){
    return offset;
}
