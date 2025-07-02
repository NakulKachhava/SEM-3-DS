#include<stdio.h>
#include<stdlib.h>

struct Node {
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

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d => ", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

struct Node * copyLinkedList(struct Node *head)
{
    struct Node *new;
    struct Node *begin;
    struct Node *save;
    struct Node *pred;

    if (head == NULL)
    {
        return NULL;
    }

    
    new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("Underflow");
        return NULL;
    }

    new->info = head->info;  
    begin = new;            

    save = head;           
    
    while (save->link != NULL)
    {
        pred = new;         
        save = save->link;  
        
        new = (struct Node *)malloc(sizeof(struct Node));
        if (new == NULL)
        {
            printf("Underflow\n");
            return NULL;
        }
        new->info = save->info; 
        pred->link = new;       
    }
    new->link = NULL;           
    return begin;               
}

void main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.Insert a node at the last of the linked list. \n2.Display all nodes.\n3.Copy a linked list\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtLast();
            break;
            case 2: LinkedListTraversal(head);
            break;
            case 3: 
            {   struct Node *copiedList = copyLinkedList(head);
                if (copiedList != NULL)
                {
                    printf("Copied Linked List:\n");
                    LinkedListTraversal(copiedList);
                }
                else
                {
                    printf("Failed to copy the linked list.\n");
                }
            }
            break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
            break;
        }
    }
}