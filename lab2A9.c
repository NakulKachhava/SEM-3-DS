#include<stdio.h>
int main(){
	int n,p,i;
    float ans=1;
	printf("Enter a number: ");
    scanf("%d",&n);
    printf("Enter power of that number: ");
    scanf("%d",&p);
    for(i = 1; i <= p; i++){
        ans *= n;
    }
    printf("%d^%d = %f",n,p,ans);
	return 0;
}
