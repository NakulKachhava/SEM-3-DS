#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

void insertAtFirst(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if(first == NULL){
        newnode->link = newnode;
        first = last = newnode;
    }
    else{
        newnode->link = first;
        last->link = newnode;
        first = newnode;
    }
    return;
}

void displayAllNodes(){
    struct node *save = first;
    do{
        printf("%d -> ", save->info);
        save = save->link;
    }while(save != first);
    printf("%d\n",first->info);
    return;
}

void insertAtLast(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if(first == NULL){        
        newnode->link = newnode;
        first = last = newnode;
    }
    else{
        newnode->link = first;
        last->link = newnode;
        last = newnode;
    }
    return;
}

void deleteAtSpecifiedPosition(){
    int x;
    printf("Enter data/info of the node which you want to delete - ");
    scanf("%d",&x);
    if (first == NULL) {
        printf("Linked List is Empty"); 
        return;
    }
    struct node *save = first, *prev = NULL;
    if(save->info == x) { 
        first = save->link;
        last->link = first; 
        free(save);
        return;
    }
    while (save != NULL && save->info != x) { 
        prev = save;
        save = save->link;
    }
    if (save == NULL) { 
        printf("Node not found");
        return;
    }
    else{
        prev->link = save->link;
        free(save);
    } 
    return;
}

void main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.Insert a node at the front of the circular linked list. \n2.Display all nodes.\n3.Insert a node at the end of the circular linked list.\n4.Delete a node from specified position in circular linked list.\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtFirst();
            break;
            case 2: displayAllNodes();
            break;
            case 3: insertAtLast();
            break;
            case 4: deleteAtSpecifiedPosition();
            break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}