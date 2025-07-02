#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node *head = NULL;

void insertAtLast(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = x;
    if(head == NULL){        
        newnode->link = NULL;
        head = newnode;
        return;
    }
    else{
        struct Node *save = head;
        while(save->link != NULL){
            save = save->link;
        }
        save->link = newnode;
        newnode->link = NULL;
        return;
    }
}

void reverse(){
    struct Node *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = nextNode = head;
    while (nextNode != NULL)
    {
        nextNode = nextNode->link;
        currentNode->link = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d => ", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.Insert a node at the last of the linked list. \n2.Display all nodes.\n3.reverse a linked list\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtLast();
            break;
            case 2: LinkedListTraversal(head);
            break;
            case 3: 
            {   reverse();
                printf("Linked List After Reversing:\n");
                LinkedListTraversal(head);
            }
            break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
            break;
        }
    } 
}