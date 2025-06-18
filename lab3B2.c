#include<stdio.h>
int main(){
	int n,m,l,i,k,index,count=0;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter a number: ");
        scanf("%d",&a[i]);
    }
    printf("Enter 1st number: ");
    scanf("%d",&m);
    printf("Enter 2nd number: ");
    scanf("%d",&l);
    for (i = 0; i < n;i++)
    {
        if (a[i] == m){
            a[i] = l;
            index = i;
        }
    }
    printf("index of replaced number is: %d\n",index);
    for (k = 0; k < n;k++)
    {
        printf("%d",a[k]);
    }
	return 0;
}
