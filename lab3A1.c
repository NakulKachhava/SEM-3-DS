#include<stdio.h>
int main(){
	int n,i,k;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter a number: ");
        scanf("%d",&a[i]);
    }
    for (k = 0; k < n;k++)
    {
        printf("%d",a[k]);
    }
	return 0;
}
