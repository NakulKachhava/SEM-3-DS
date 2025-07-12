#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

int countAllNodes(){
    int count = 0;
    struct node *save = first;
    do{
        count++;
        save = save->link;
    }while(save != first);
    return count;
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

void displayAfterSplit(){
    struct node *save = first;
    while(save != NULL){
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
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

void splitInHalfCLL(){
    int count = 0;
    int totalNodes = countAllNodes();
    struct node *save = first;
    if(totalNodes == 1){
        printf("insufficient nodes.At least 2 nodes is needed.");
        return;
    }
    else{
        while(save->link != first){
            count++;
            if(count == (totalNodes + 1)/2){
                first = save->link;
                save->link = NULL;
                last = NULL;
                displayAfterSplit();
                return;
            }
            else{
                save = save->link;
            }
        }
    }
    return;
}

void main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.Insert a node at the end of the circular linked list. \n2.Display all nodes.\n3.Split a circular linked list in half.\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtLast();
            break;
            case 2: displayAllNodes();
            break;
            case 3: splitInHalfCLL();
            break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}