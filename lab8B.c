#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(int value) {
    if ((front == 0 && rear == MAX-1) || ((rear+1) == front)) {
        printf("Queue Overflow!\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX-1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    if (front == rear) {
        front = -1; rear = -1;
    } else if (front == MAX-1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}