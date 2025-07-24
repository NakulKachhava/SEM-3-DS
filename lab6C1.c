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

void removeStar(char s[],int n){
    for(int i = 0; i < n; i++){
        if(s[i] == '*'){
            pop();
        }
        else{
            push(s[i]);
        }
    }
    display();
}

int main(){
    char s[100];
    printf("Enter a String - ");
    scanf("%s",&s);
    int n = strlen(s);
    removeStar(s,n);
    return 0;
}