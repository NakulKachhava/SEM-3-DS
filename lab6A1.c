#include<stdio.h>
#include<stdlib.h>

int top = -1;
int s[10];
int max = 10;


void push(){
    int x;
    printf("Enter value of x - ");
    scanf("%d",&x);
    if(top < max - 1){
        s[++top] = x;
    }
    else{
        printf("Stack Overflow\n");
    }
    return;   
}

int pop(){
    if(top == -1){
        return -1;
    }
    return s[top--];
}

int peep(){
    int i;
    printf("Enter the number of element from the top - ");
    scanf("%d",&i);
    if(top-i+1 < 0){
        return -1;
    }
    else{
        return s[top-i+1];
    }
}

void change(){
    int i,x;
    printf("Enter the number of element from the top - ");
    scanf("%d",&i);
    printf("Enter value of x - ");
    scanf("%d",&x);
    if(top-i+1 < 0){
        printf("No such element exists\n");
    }
    else{
        s[top-i+1] = x;
    }
    return;
}

void display(){
    int i;
    printf("Stack Elements - ");
    for(i = top ; i >= 0 ; i--){
        printf("%d ",s[i]);
    }
    printf("\n");
    return;
}

void main(){
    int choice;
    while(1) {
        printf("Menu: \n");
        printf("1.PUSH.\n2.POP.\n3.PEEP.\n4.CHANGE.\n5.DISPLAY.\n6.EXIT.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: push();
            break;
            case 2: {
                int temp = pop();
                if(temp == -1) {
                    printf("Stack Underflow\n");
                }
                else{
                    printf("Element popped from stack is %d\n",temp);
                }
            }
            break;
            case 3: {
                int temp = peep();
                if(temp == -1) {
                    printf("No such element exists\n");
                }
                else{
                    printf("Element at given index of stack is %d\n",temp);
                }
            }
            break;
            case 4: change();
            break;
            case 5: display();
            break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
            break;
        }
    }
}