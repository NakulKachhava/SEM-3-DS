#include<stdio.h>
#include<string.h>

int top = -1;
int stack[100];
int max = 100;


void push(int x){
    if(top < max - 1){
        stack[++top] = x;
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
    return stack[top--];
}

void display(){
    int i;
    printf("Output String - ");
    for(i = 0 ; i <= top ; i++){
        printf("%c",stack[i]);
    }
    printf("\n");
    return;
}

void reverseStack(){
    int temp;
    for (int i = 0; i < (top + 1)/2; i++) {
        temp = stack[i]; 
        stack[i] = stack[top - i];
        stack[top - i] = temp;
    }
}

void vowelAnxiety(char s[],int n){
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            reverseStack();
            push(s[i]);
        }
        else{
            push(s[i]);
        }
    }
    display();
}

int main(){
    int inputs;
    printf("Enter number of inputs - ");
    scanf("%d",&inputs);
    for(int i=1 ; i <= inputs; i++){
        int n;
        char s[100];
        printf("Enter length of String - \n");
        scanf("%s",&n);
        printf("Enter a String - \n");
        scanf("%d",&s);
        vowelAnxiety(s,n);
    }
    return 0;
}