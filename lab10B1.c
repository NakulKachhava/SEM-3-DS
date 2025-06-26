#include<stdio.h>
#include<stdlib.h>

struct node{
     int info;
     struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void insertAtLast(int c){
    if(c == 1){
          int x;
          printf("Enter value of x - ");
          scanf("%d",&x);
          struct node *newnode = (struct node *)malloc(sizeof(struct node));
          newnode->info = x;
          if(first1 == NULL){        
               newnode->link = NULL;
               first1 = newnode;
               return;
          }
          else{
               struct node *save = first1;
               while(save->link != NULL){
                    save = save->link;
               }
               save->link = newnode;
               newnode->link = NULL;
               return;
          }
    }
    else{
          int y;
          printf("Enter value of x - ");
          scanf("%d",&y);
          struct node *newnode = (struct node *)malloc(sizeof(struct node));
          newnode->info = y;
          if(first2 == NULL){        
               newnode->link = NULL;
               first2 = newnode;
               return;
          }
          else{
               struct node *save = first2;
               while(save->link != NULL){
                    save = save->link;
               }
               save->link = newnode;
               newnode->link = NULL;
               return;
          }
    }
}

void displayAllNodes(int c){
     if(c == 1){
          struct node *save = first1;
          while(save != NULL){
               printf("%d -> ", save->info);
               save = save->link;
          }
          printf("NULL\n");
          return;
     }
     else{
          struct node *save = first2;
          while(save != NULL){
               printf("%d -> ", save->info);
               save = save->link;
          }
          printf("NULL\n");
          return;
     }
}

int linkedListCompare(){
     int n,m;
     struct node *save1 = first1;
     struct node *save2 = first2;
     while (save1 != NULL && save2 != NULL)
     {
          n = save1->info;
          m = save2->info;
          if(n!=m){
               return 0;
          }
          save1 = save1->link;
          save2 = save2->link;
     }
     return 1;
}

void main(){
     int choice;
     while(1) {
          printf("Menu: \n");
          printf("1.Insert a node at the last of the linked list. \n2.Display all nodes.\n3.To check if the linked lists are same or not.\n4.Exit\n");
          printf("Enter your choice: ");
          scanf("%d", &choice);
          switch(choice) {
               case 1: 
               {
                    int n;
                    printf("Enter 1 for 1st linked list and 2 for 2nd linked list: ");
                    scanf("%d",&n);
                    insertAtLast(n);
                    break;
               }
               case 2: 
               {
                    int n;
                    printf("Enter 1 for 1st linked list and 2 for 2nd linked list: ");
                    scanf("%d",&n);
                    displayAllNodes(n);
                    break;
               }
               case 3:
               {
                    if(linkedListCompare() == 1){
                         printf("Linked list are same");
                    }
                    else{
                         printf("Linked list are not same");
                    }   
               } 
               case 4: exit(0);
               default: printf("Invalid choice.\n");
          }
     }
}