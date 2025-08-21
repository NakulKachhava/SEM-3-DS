#include <stdio.h>
#define MAX 100

struct priorityQueue{
    int data;
    int priority;
}; 

struct priorityQueue pQueue[MAX];
int front = -1, rear = -1;

void enqueue(int x,int y) {
    if (rear == MAX - 1)
        printf("Priority Queue Overflow!\n");
    else {
        if (front == -1) front = 0;
        rear++;
        pQueue[rear].data = x;
        pQueue[rear].priority = y;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Priority Queue Underflow!\n");
    else if (front == rear) {
        front = rear = -1;
    }
    else {
        int max_i = front;
        for(int i=front+1 ; i <= rear ; i++){
            if(pQueue[i].priority > pQueue[max_i].priority){
                max_i = i;
            }
        }
        for(int i=max_i ; i < rear ; i++){
            pQueue[i] = pQueue[i+1];
        }
        rear--;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Priority Queue is empty!\n");
    else {
        printf("Priority Queue elements: \n");
        for (int i = front; i <= rear; i++)
            printf("{%d : %d}\n", pQueue[i].data, pQueue[i].priority);
    }
}

int main() {
    int choice, x, y;
    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to ENQUEUE: ");
                scanf("%d", &x);
                printf("Enter priority to ENQUEUE: ");
                scanf("%d", &y);
                enqueue(x,y);         
                break;
            case 2:
                dequeue();
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