#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *first = NULL;

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

void sortElementsOfNode() {
    struct Node *i, *j;
    int temp;
    if (first == NULL)
        return;
    for (i = first; i->link != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

void main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.Insert a node at the last of the linked list. \n2.Display all nodes.\n3.sort the elements of the node\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertAtLast();
            break;
            case 2: displayAllNodes();
            break;
            case 3: sortElementsOfNode();
            break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
            break;
        }
    }
}