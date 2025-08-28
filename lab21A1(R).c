#include <stdio.h>

int MAX = 100;
int a[MAX];

int search(int x, int i)
{
    if (a[i] == x)
    {
        return i;
    }
    else
    {
        search(x, i + 1);
    }
}

int main()
{
    int i, x;
    for (i = 0; i < MAX; i++)
    {
        printf("Enter an element - ");
        scanf("%d", &a[i]);
    }
    printf("Enter element you want to search - ");
    scanf("%d", &x);
    int result = search(x, 0);
    printf("Index of the element = %d", result);
    return 0;
}


