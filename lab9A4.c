#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,largest;
    printf("Enter size of an array - ");
    scanf("%d",&n);
    int *array = (int*)malloc(n * sizeof(int));
    for ( i = 0; i < n; i++)
    {
        printf("Enter element %d - ",i+1);
        scanf("%d",array + i);
    }
    int temp = *(array);
    for ( i = 0; i < n; i++)
    {
        if (*(array + i) > temp){
            largest = *(array + i);
        }
    }
    printf("Largest element in the array is %d\n",largest);
}
