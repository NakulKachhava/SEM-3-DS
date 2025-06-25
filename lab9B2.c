#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i;
    printf("Enter size of an array - ");
    scanf("%d",&n);
    char *str = (char*)malloc(n * sizeof(int));
    printf("Enter string to check - ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",str + i);
    }
    char *first = str;
    char *last = str + (n * sizeof(int));
    while(first < last){
        if(*first == *last){
            first++;
            last--;
        }
        else{
            printf("Array is not palindrome\n");
            return 0;
        }
    }
    printf("Array is palindrome\n");
    return 0;
}
