#ifndef INPUT_H
#define INPUT_H
#endif // INPUT_H
#include<stdio.h>
#include<string>


extern int Lines[100];
void take_input(char path[]){
    printf("%c",path[0]);
    FILE * mf = fopen(path,"r");
    if (mf == NULL)
        {
            printf("worng file or path ");
            exit(1);
        }
    char mat[100];
    int j = 0;
    while(fgets(mat, sizeof(mat),mf)){
        printf("%s\n", mat);
        Lines[j] = atoi(mat);
        j++;
    }
    j =0;
    while(Lines[j]){
        printf("%d\n", Lines[j]);
        j++;
    }
    fclose(mf);

}
