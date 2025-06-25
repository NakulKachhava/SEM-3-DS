#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i;
    printf("Enter size of an array - ");
    scanf("%d",&n);
    int *array = (int*)malloc(n * sizeof(int));
    for ( i = 0; i < n; i++)
    {
        printf("Enter element %d - ",i+1);
        scanf("%d",array + i);
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d ",*(array + i));    
    }
    return 0;
}
