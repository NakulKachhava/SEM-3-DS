#include<stdio.h>
#include<stdlib.h>

struct node {
    int c;
    int e;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;
struct node *first3 = NULL;

void insertAtLast(int cl){
    if(cl == 1){
        while (1)
        {
            int cho;
            printf("\n1.For inserting x.\n2.For exit.\n");
            printf("Enter your choice: ");
            scanf("%d", &cho);
            switch(cho) {
                case 1: {
                    int co,ex;
                    printf("Enter Coefficient of x - ");
                    scanf("%d",&co);
                    printf("Enter Exponent of x - ");
                    scanf("%d",&ex);
                    struct node *newnode = (struct node *)malloc(sizeof(struct node));
                    newnode->c = co;
                    newnode->e = ex;
                    if(first1 == NULL){        
                        newnode->link = NULL;
                        first1 = newnode;
                    }
                    else{
                        struct node *save = first1;
                        while(save->link != NULL){
                            save = save->link;
                        }
                        save->link = newnode;
                        newnode->link = NULL;
                    }
                }
                break;
                case 2: return;
                default: printf("Invalid choice.\n");
            }
        }
    }
    else if(cl == 2){
        while (1)
        {
            int cho;
            printf("\n1.For inserting x.\n2.For exit.\n");
            printf("Enter your choice: ");
            scanf("%d", &cho);
            switch(cho) {
                case 1: {
                    int co,ex;
                    printf("Enter Coefficient of x - ");
                    scanf("%d",&co);
                    printf("Enter Exponent of x - ");
                    scanf("%d",&ex);
                    struct node *newnode = (struct node *)malloc(sizeof(struct node));
                    newnode->c = co;
                    newnode->e = ex;
                    if(first2 == NULL){        
                        newnode->link = NULL;
                        first2 = newnode;
                    }
                    else{
                        struct node *save = first2;
                        while(save->link != NULL){
                            save = save->link;
                        }
                        save->link = newnode;
                        newnode->link = NULL;
                    }
                }
                break;
                case 2: return;
                default: printf("Invalid choice.\n");
            }
        }
    }
}

void displaySumOfTwoPolynomials(){
    struct node *save = first3;
    while(save != NULL){
        if(save->c > 0){
            printf("+%dx^%d", save->c,save->e);
        }
        else{
            printf("%dx^%d", save->c,save->e);
        }
        save = save->link;
    }
    return;
}

void insertionOfFinalNode(int sum,int expo){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->c = sum;
    newNode->e = expo;
    if(first3 == NULL){
        newNode->link = NULL;
        first3 =  newNode;
    }
    else{
        struct node *save = first3;
        while(save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
        newNode->link = NULL;
    }
}

void additionOfTwoPolynomial(){
    struct node *save1 = first1;
    struct node *save2 = first2;
    while (save1 != NULL && save2 != NULL)
    {
        if(save1->e == save2->e){
            insertionOfFinalNode(save1->c + save2->c,save1->e);
            save1 = save1->link;
            save2 = save2->link; 
        }
        else if(save1->e > save2->e){
            insertionOfFinalNode(save1->c,save1->e);
            save1 = save1->link;
        }
        else if(save1->e < save2->e){
            insertionOfFinalNode(save2->c,save2->e);
            save2 = save2->link;
        }
    }
}
 
int main(){
    int cho;
    while (1)
    {
        printf("Menu: \n");
        printf("1.For inserting polynomial.\n2.For addition of polynomials.\n3.For displaying the result of sum of two polynomials.\n4.Exit\n");
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
            case 3: displaySumOfTwoPolynomials();
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
