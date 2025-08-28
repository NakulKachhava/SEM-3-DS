#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;  
    
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid; 
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
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
    int index = binarySearchRecursive(a, 0, n - 1, x);
    if (index != -1)
        printf("Recursive: Element %d found at index %d\n", x, index);
    else
        printf("Recursive: Element %d not found\n", x);

    return 0;
}
