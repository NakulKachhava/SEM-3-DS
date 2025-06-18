#include<stdio.h>
#include<math.h>
int noOfDigits(int m){
    int count = 0;
    while(m != 0){
        m = m / 10;
        count++;
    }
    return count;
}
int pow(int base, int exp){
    int i,ans=1;
    for(i = 1; i <= exp; i++){
        ans *= base;
    }
    return ans;
}
int main(){
	int n,i,k,sum=0;
    for ( k = 1; k <= 1000; k++)
    {
	    int temp = k;
	    int m = noOfDigits(k);
	    for (i = 1; i <= m; i++)
	    {
	        sum += pow(k % 10,m);
	        k/=10;
	    }
	    if(sum==temp){
	        printf("%d is an armstrong number",temp);
	    }
    }
	return 0;
}
