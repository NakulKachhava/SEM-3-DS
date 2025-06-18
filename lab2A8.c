#include<stdio.h>
void main(){
   
    printf("Enter the number: ");
    int n,i;
    int fact;
    for(i=1;i=n+1;i++){
        fact=fact*i;
        if(n==0||n==1){
            return 1;
        }
        printf("factorial of given no: %d",fact);
    }
}