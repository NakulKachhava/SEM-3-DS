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
    while(save != NULL){
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
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
    struct node *pred = NULL;
    while(save->link != NULL){
        pred = save;
        save = save->link;
    }
    pred->link = NULL;
    free(save);
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
    if(save->info==x) { 
        first = save->link; free(save);
        return;
    }
    while (save != null && save->info != x) { 
        prev = save;
        save = save->link;
    }
    if (save == null) { 
        printf("Node not found");
        return;
    }
    prev->link = save->link;
    free(save); 
    return;
}

void countNodes(){
    struct node *save = first;
    int count = 0;
    if(first == NULL){
        printf("The total number of nodes = %d\n",count);
        return;
    }
    else{
        while(save != NULL){
            count++;
            save = save->link;
        }
        printf("The total number of nodes = %d\n",count);
        return;
    }
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
            case 2: displayAllNodes();
            break;
            case 3: deleteAtFirst();
            break;
            case 4: insertAtLast();
            break;
            case 5: deleteAtLast();
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
