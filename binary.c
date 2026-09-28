#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data[20];
    int top;
};
typedef struct stack STACK;
void push(STACK *s, int item){
    s->data[++(s->top)]=item;
}
int pop(STACK *s){
    return s->data[(s->top)--];
}
int main(){
    int n,remainder;
    STACK s;
    s.top=-1;
    printf("Enter a decimal number: ");
    scanf("%d",&n);
    while(n>0){
        remainder=n%2;
        push(&s,remainder);
        n=n/2;
    }
    printf("Binary number: ");
    while(s.top>=0){
        printf("%d",pop(&s));
    }
    return 0;
}