#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node* insert(struct node *root, int key){
    if(root == NULL){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = key;
        newnode->lptr = newnode->rptr = NULL;
        return newnode;
    }
    if(key < root->info) {
        root->lptr = insert(root->lptr, key);
    } else if(key > root->info) {
        root->rptr = insert(root->rptr, key);
    } else {
        printf("Duplicate value, not inserting.\n");
    }
    return root;
}

void search(struct node *root, int x) {
    if (root == NULL) {
        printf("%d is not present in the tree\n", x);
        return;
    } else if (root->info == x) {
        printf("%d is present in the tree\n", x);
        return;
    } else if (x < root->info) {
        search(root->lptr, x);
    } else {
        search(root->rptr, x);
    }
}

struct node* minValueNode(struct node* node) {
    struct node* temp = node;
    
    while (temp && temp->lptr != NULL)
        temp = temp->lptr;
    
    return temp;
}


struct node* delete(struct node* root, int key) {
    if (root == NULL) return root;
    
    if (key < root->info)
        root->lptr = delete(root->lptr, key);
    else if (key > root->info)
        root->rptr = delete(root->rptr, key);
    else {
        if (root->lptr == NULL) {
            struct node* temp = root->rptr;
            free(root);
            return temp;    
        }
        else if (root->rptr == NULL) {
            struct node* temp = root->lptr;
            free(root);
            return temp;
        }
        
        struct node* temp = minValueNode(root->rptr);  
        
        root->info = temp->info;
        
        root->rptr = delete(root->rptr, temp->info);
    }
    return root;
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
    postOrderTraversal(root->lptr);
    postOrderTraversal(root->rptr);
    printf("%d,",root->info);
}

void inOrderTraversal(struct node *root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->lptr);
    printf("%d,",root->info);
    inOrderTraversal(root->rptr);
}

int main(){
    struct node *root = NULL;
    int choice;
    while (1)
    {
        printf("\nMenu: \n");
        printf("1.Insert a node in the tree. \n2.Delete a node from the tree.\n3.Search a node in the tree.\n4.Perform Preorder Traversal in the tree.\n5.Perform Postorder Traversal in the tree.\n6.Perform Inorder Traversal in the tree.\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: {
            int key;
            printf("Enter node you want to insert - ");
            scanf("%d",&key);
            root = insert(root,key);
        }
        break;
        case 2: {
            int key;
            printf("Enter node you want to delete - ");
            scanf("%d",&key);
            root = delete(root,key);
        }
        break;
        case 3: {
            int key;
            printf("Enter value you want to search: ");
            scanf("%d", &key);
            search(root, key);
        }
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
