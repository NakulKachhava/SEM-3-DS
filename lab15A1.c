#include<stdio.h>
#include<stdlib.h>

struct node {   
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *L = NULL;
struct node *R = NULL;

void insertAtFirst(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if(L == NULL){
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        L = R = newnode;
    }
    else{
        newnode->rptr = L;
        L->lptr = newnode;
        L = newnode;
    }
    return;
}
 
void insertAtLast(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if(R == NULL){
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        L = R = newnode;
    }
    else{
        newnode->lptr = R;
        R->rptr = newnode;
        R = newnode;
    }
    return;
}

void deleteAtSpecifiedPosition(){
    int x;
    printf("Enter data/info of the node which you want to delete - ");
    scanf("%d",&x);
    if (L == NULL) {
        printf("Linked List is Empty"); 
        return;
    }
    struct node *save = L;
    if(L == R){
        L = R = NULL;
        free(save);
    }
    else if(L->info == x) { 
        L = L->rptr;
        if(L != NULL){
            L->lptr = NULL;
        }
        free(save);
    }
    else if(R->info == x){
        save = R;
        R = R->lptr;
        R->rptr = NULL;
        free(save);
    }
    else{
        while (save != NULL && save->info != x) { 
            save = save->rptr;
        }
        if(save == NULL){
            printf("Node not found");
        }
        else{
            save->lptr->rptr = save->rptr;
            save->rptr->lptr = save->lptr;
            free(save);
        }
    } 
    return;
}

void displayAllNodes(){
    struct node *save = L;
    while (save != NULL) {
        printf("%d <-> ", save->info);
        save = save->rptr;
    }
    printf("NULL\n");
}

int main(){
    int choice;
    while(1){
        printf("Menu: \n");
        printf("1.Insert a node at the front of the doubly linked list. \n2.Delete a node from specified position in doubly linked list.\n3.Insert a node at the end of the doubly linked list.\n4.Display all nodes.\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtFirst();
            break;
            case 2: deleteAtSpecifiedPosition();
            break;
            case 3: insertAtLast();
            break;
            case 4: displayAllNodes();
            break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}