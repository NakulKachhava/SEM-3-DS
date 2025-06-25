#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtFirst(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
    return;
}

void displayAllNodes(){
    struct node *save = first;
    while(save->link != NULL){
        printf("%d ", save->info);
        save = save->link;
    }
    return;
}

void deleteAtFirst(){
    struct node *temp = first;
    first = first->link;
    free(temp);
    return;
}

void insertAtLast(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if(first == NULL){        
        newnode->link = NULL;
        first = newnode;
        return;
    }
    else{
        struct node *save = first;
        while(save->link != NULL){
            save = save->link;
        }
        save->link = newnode;
        newnode->link = NULL;
        return;
    }
}

void deleteAtLast(){
    struct node *save = first;
    struct node *pred = first;
    while(save->link != NULL){
        pred = save;
        save = save->link;
    }
    pred->link = NULL;
    free(save);
    return;
}

void deleteAtSpecifiedPosition(){

}

void main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.Insert a node at the front of the linked list. \n2.Display all nodes.\n3.Delete a first node of the linked list.\n4.Insert a node at the end of the linked list.\n5.Delete a last node of the linked list.\n6.Delete a node from specified position.\n7.count the number of nodes\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtFirst();
            break;
            case 2: display();
            break;
            case 3: deleteFirst();
            break;
            case 4: insertAtEnd();
            break;
            case 5: deleteLast();
            break;
            case 6: deleteAtSpecifiedPosition();
            break;
            case 7: countNodes();
            break;
            case 8: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}