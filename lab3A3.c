#include<stdio.h>
int main(){
	int n,m,i,total=0;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter m: ");
    scanf("%d",&m);
    int p = m-n+1;
    int a[p];
    for (i = n; i <= m;i++)
    {
        a[i-n] = i;
        total += a[i-n];
    }
    float avg = (float)total/p;
    printf("avg = %f",avg);
	return 0;
}
