#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *first = NULL;

int gcdOfNodes(int a , int b){
    if (b == 0) {
        return a;
    }
    return gcdOfNodes(b, a % b);
}

void insertAtLast(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = x;
    if(first == NULL){        
        newNode->link = NULL;
        first = newNode;
        return;
    }
    else{
        struct Node *save = first;
        while(save->link != NULL){
            save = save->link;
        }
        save->link = newNode;
        newNode->link = NULL;
        return;
    }
}

void displayAllNodes(){
    struct Node *save = first;
    while(save != NULL){
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
    return;
}

void addGcdOfTwoNodes(){
    struct Node * save = first;
    while (save->link != NULL){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = gcdOfNodes(save->info,save->link->info);
        newNode->link = save->link;
        struct Node *temp = save->link;
        save->link = newNode;
        save = temp;
    }
}

void main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.Insert a node at the last of the linked list. \n2.Display all nodes.\n3.add a node whose info contains the gcd of two adjecent nodes\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtLast();
            break;
            case 2: displayAllNodes();
            break;
            case 3: addGcdOfTwoNodes();
            break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
            break;
        }
    }
}