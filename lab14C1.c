#include<stdio.h>
#include<stdlib.h>

struct node {
    int c;
    int e;
    struct node *link;
};

struct node *first1 = NULL;
struct node *last1 = NULL;
struct node *first2 = NULL;
struct node *last2 = NULL;
struct node *first3 = NULL;
struct node *last3 = NULL;

void insertAtLast(int cl){
    if(cl == 1){
        int co,ex;
        printf("Enter Coefficient of x - ");
        scanf("%d",&co);
        printf("Enter Exponent of x - ");
        scanf("%d",&ex);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->c = co;
        newnode->e = ex;
        if(first1 == NULL){        
            newnode->link = newnode;
            first1 = last1 = newnode;
        }
        else{
            newnode->link = first1;
            last1->link = newnode;
            last1 = newnode;
        }
        return;
    }
    else if(cl == 2){
        int co,ex;
        printf("Enter Coefficient of x - ");
        scanf("%d",&co);
        printf("Enter Exponent of x - ");
        scanf("%d",&ex);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->c = co;
        newnode->e = ex;
        if(first2 == NULL){        
            newnode->link = newnode;
            first2 = last2 = newnode;
        }
        else{
            newnode->link = first2;
            last2->link = newnode;
            last2 = newnode;
        }
        return;
    }
}

void additionOfTwoPolynomial(){
    struct node *save1 = first1;
    struct node *save2 = first2;
    while (save1 != first1 && save2 != first2)
    {
        
    }
    
}

int main(){
    int cho;
    while (1)
    {
        printf("Menu: \n");
        printf("1.For inserting polynomial.\n2.For addition of polynomials.\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &cho);
        switch(cho) {
            case 1: {
                int cl;
                printf("\nEnter 1 for first polynomial.\nEnter 2 for second polynomial.\nEnter choice for polynomial - ");
                scanf("%d",&cl);
                insertAtLast(cl);
            }
            break;
            case 2: additionOfTwoPolynomial();
            break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}