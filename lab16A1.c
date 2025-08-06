#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node* insert(struct node *root){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    if(root == NULL){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = x;
        newnode->lptr = newnode->rptr = NULL;
        return newnode;
    }
    if(x < root->info) {
        root->lptr = insert(root->lptr);
    } else if(x > root->info) {
        root->rptr = insert(root->rptr);
    } else {
        printf("Duplicate value, not inserting.\n");
    }
    return root;
}

void search(struct node *root){
    int x;
    printf("Enter value you want to search - ");
    scanf("%d",&x);
    if(root == NULL){
        return;
    }
    else if(root->info == x){
        printf("%d is present in the tree",x);
        return;
    }
    else{
        printf("%d is not present in the tree",x);
        return;
    }
    search(root->lptr);
    search(root->rptr);
}

void preOrderTraversal(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d,",root->info);
    preOrderTraversal(root->lptr);
    preOrderTraversal(root->rptr);
}

void postOrderTraversal(struct node *root){
    if(root == NULL){
        return;
    }
    preOrderTraversal(root->lptr);
    preOrderTraversal(root->rptr);
    printf("%d,",root->info);
}

void inOrderTraversal(struct node *root){
    if(root == NULL){
        return;
    }
    preOrderTraversal(root->lptr);
    printf("%d,",root->info);
    preOrderTraversal(root->rptr);
}

int main(){
    struct node *root;
    int choice;
    while (1)
    {
        printf("Menu: \n");
        printf("1.Insert a node in the tree. \n2.Delete a node from the tree.\n3.Search a node in the tree.\n4.Perform Preorder Traversal in the tree.\n5.Perform Postorder Traversal in the tree.\n6.Perform Inorder Traversal in the tree.\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: root = insert(root);
        break;
        // case 2: delete(root);
        // break;
        case 3: search(root);
        break;
        case 4: preOrderTraversal(root);
        break;
        case 5: postOrderTraversal(root);
        break;
        case 6: inOrderTraversal(root);
        break;
        case 7: exit(0);
        }
    }
    return 0;
}