#include<stdio.h>
int main(){
	int n,i,y,ans=0;
	printf("Enter a number: ");
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        for ( y = 1; y <= i; y++)
        {
            ans+=y;
        }
    }
    printf("Sum of the given series = %d",ans);
	return 0;
}
