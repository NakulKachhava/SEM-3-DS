#include<stdio.h>
int isPrime(int a){
    int i,count=0;
    for (i = 1; i <= a; i++)
    {
        if(a%i==0){
        	count++; 
        }
    }
    if(count==2){
    	return 1;
	}
	else{
        return 0;
    }
}
int main(){
	int n,i,m;
	printf("Enter an interval: ");
    scanf("%d",&n);
    printf("Enter an interval: ");
    scanf("%d",&m);
    for (i = n; i < m; i++)
    {
        if(isPrime(i)==1){
            printf("%d is a prime number\n",i);
        }
    }
	return 0;
}