#include<stdio.h>
int main(){
	int n,i,total=0;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    for (i = 0; i < n ;i++)
    {
        printf("Enter element : ");
        scanf("%d",&a[i]);
    }
    int min = a[0];
    int max = a[0];
    int minIndex = 0;
    int maxIndex = 0;
    for (i = 0; i < n ;i++)
    {
        if (a[i]<min){
            int temp = a[i];
            a[i] = min;
            min = temp;
            int minIndex = i;
        }
        if (a[i]>max){
            int temp1 = a[i];
            a[i] = max;
            max = temp1;
            maxIndex = i;
        }
    }
    printf("position of the smallest number = %d \n position of the largest number = %d",minIndex+1,maxIndex+1);
	return 0;
}
