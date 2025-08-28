#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    bubbleSort(a, n);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
