#include<stdio.h>
#include<string.h>
int main(){
	int n,i,k;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    char name[n][10];
    for ( i = 0; i < n; i++){
        for (k = 0; k < 10;k++){
            printf("Enter a name - ");
            scanf("%c",name[i][k]);
        }   
    }
    for ( i = 0; i < n; i++){
        for (k = 0; k < 10;k++){
            printf("%d",name[i][k]);
        }   
    }
	return 0;
}
