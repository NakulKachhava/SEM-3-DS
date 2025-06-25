#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

void main(){
    int x;
    printf("Enter a value for info - ");
    scanf("%d", &x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
    printf("Data in a node = %d",newnode->info);
}
