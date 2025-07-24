#include<stdio.h>

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
    printf("Output Intervals - ");
    printf("{");
    for(i = 0 ; i <= top ;i+=2){
        printf("{%d,%d}",stack[i],stack[i+1]);
    }
    printf("}\n");
    return;
}

void mergeIntervals(char s[],int n){
    for (int i = 0; i < n; i++){
        if(s[i] != '{' || s[i] != '}' || s[i] != ','){
            push(s[i]);
            push(s[i+2]);
        }
    }
    for(int i = 0; i <= top; i++){
        for (int i = s[i]; i <= s[i+1]; i++)
        {
            
        }
        
    }
}

int main(){
    char s[500];
    printf("Enter a String - ");
    scanf("%s",&s);
    int n = strlen(s);
    mergeIntervals(s,n);         
    return 0;
}