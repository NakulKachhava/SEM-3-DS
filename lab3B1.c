#include<stdio.h>
int main(){
	int n,i,k,count=0;
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
        if(a[k] == a[k+1]){
            count++;
        }
    }
    if(count==0){
        printf("No duplicate elements in the array.");
    }
    else{
        printf("Duplicate elements found in the array.");
    }
	return 0;
}
