#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,sum=0;
    printf("Enter size of an array - ");
    scanf("%d",&n);
    int *array = (int*)malloc(n * sizeof(int));
    for ( i = 0; i < n; i++)
    {
        printf("Enter element %d - ",i+1);
        scanf("%d",array + i);
        sum += *(array + i);
    }
    printf("Sum of elements in array is %d\n",sum);
    return 0;
}
