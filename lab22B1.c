#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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

    selectionSort(a, n);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
