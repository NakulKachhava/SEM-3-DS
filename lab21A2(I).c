#include <stdio.h>

int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;  
        else
            right = mid - 1; 
    }
    return -1; 
}

int main() {
    int i,n,x;
    printf("Enter size of an array - ");
    scanf("%d",&n);
    int a[n];
    for(i=0; i < n; i++){
        printf("Enter an element - ");
        scanf("%d",&a[i]);
    }
    printf("Enter element you want to search - ");
    scanf("%d", &x);
    int index = binarySearchIterative(a, n, x);
    if (index != -1)
        printf("Iterative: Element %d found at index %d\n", x, index);
    else
        printf("Iterative: Element %d not found\n", x);

    return 0;
}
