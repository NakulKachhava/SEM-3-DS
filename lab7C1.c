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

int peek(){
    if(top < 0){
        return -1;
    }
    else{
        return stack[top];
    }
}

void isSorted(){
    int n,expected = 1,i = 0,j = 0;
    printf("Enter length of the array - ");
    scanf("%d",&n);
    int a[n];
    for (int k = 0; k < n; k++)
    {
        printf("Enter an element - ");
        scanf("%d",&a[k]);
    }
    int b[n];
    while (i < n || (top >= 0 && expected == peek()))
    {
        if(expected == peek()){
            b[i++] = pop();
            expected++;
        }
        else if(i < n){
            push(a[j++]);
        }
        else{
            break;  
        }
    }
    if(top == -1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
}

int main(){
    int inputs;
    printf("Enter number of inputs - ");
    scanf("%d",&inputs);
    for(int i=1 ; i <= inputs; i++){
        isSorted();
    }
    return 0;
}