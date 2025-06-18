#include<stdio.h>
int main(){
	int n,m=0,ans=0;
	printf("Enter a number: ");
    scanf("%d",&n);
    while (1)
    {
    	if (n == 0){
          break;  
        }
        m = n % 10;
        ans = ans*10+m;
        n/=10;
    }
    printf("ans = %d",ans);
	return 0;
}
