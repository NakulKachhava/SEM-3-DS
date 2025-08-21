#include<stdio.h>

void search(int a[],int n){
    int x;
    printf("Enter element you want to search - ");
    scanf("%d",&x);
    for(int i=0; i < n; i++){
        if(a[i] == x){
            printf("Index of %d is %d",x,i);
        }
    }
}

int main(){
    int n,i;
    printf("Enter size of an array - ");
    scanf("%d",&n);
    int a[n];
    for(i=0; i < n; i++){
        printf("Enter an element - ");
        scanf("%d",&a[i]);
    }
    search(a,n);
    return 0;
} 