#include<stdio.h>
int main(){
	int n,i,j,k;
    printf("Enter a number: ");
    scanf("%d",&n);
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < n-1-i;j++)
        {
            printf(" ");
        }
        int value = 1;
        for (k = 0; k <= i;k++)
        {
            printf("%d ",value);
            value = value * (i-k)/(k+1);
        }
        printf("\n");
    }
	return 0;
}
