#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int lb, int ub) {
    int flag = 1;
    if (lb < ub) {
        int i = lb;
        int j = ub + 1;
        int key = arr[lb];
        while (flag == 1)
        {
            i++;
            while (arr[i] < key)
            {
                i++;
            }
            j--;
            while (arr[j] > key)
            {
                j--;
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
            else
            {
                flag = 0;
            }
        }
        swap(&arr[lb], &arr[j]);
        quickSort(arr, lb, j - 1);
        quickSort(arr, j + 1, ub);
    }
}

int main() {
    int i,n;
    printf("Enter size of an array - ");
    scanf("%d",&n);
    int a[n];
    for(i=0; i < n; i++){
        printf("Enter an element - ");
        scanf("%d",&a[i]);
    }

    quickSort(a, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
