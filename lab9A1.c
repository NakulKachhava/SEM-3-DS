#include<stdio.h>
#include<stdlib.h>
int main(){
    int *iptr = (int *)malloc(sizeof(int));
    char *cptr = (char *)malloc(sizeof(char));
    float *fptr = (float *)malloc(sizeof(float));
    
    int *iptr1 = (int *)calloc(1,sizeof(int));
    char *cptr1 = (char *)calloc(1,sizeof(char));
    float *fptr1 = (float *)calloc(1,sizeof(float));
    
    if(iptr && cptr && fptr && iptr1 && cptr1 && fptr1){
        *iptr = 10;
        *cptr = 'A';
        *fptr = 10.5;
        *iptr1 = 11;
        *cptr1 = 'B';
        *fptr1 = 11.5;
        printf("Integer value using malloc: %d\n", *iptr);
        printf("Character value using malloc: %c\n", *cptr);
        printf("Float value using malloc: %f\n", *fptr);
        printf("Integer value using calloc: %d\n", *iptr1);
        printf("Character value using calloc: %c\n", *cptr1);
        printf("Float value using calloc: %f\n", *fptr1);
    }
    return 0;
}
