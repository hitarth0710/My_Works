#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ; 
    struct node* next ; 
} ;

struct stack{
    struct node* top ; 
}  ;

void push(struct stack* stack , int num) ; 
void display(struct stack* stack) ; 
void pop(struct stack* stack) ; 
void peek(struct stack* stack) ;

int main() {
    struct stack* Stack = malloc(sizeof(struct stack)) ; 
    Stack->top = NULL ; 
    int ch =1 ; 
    while(ch!=0) {
        printf("1.PUSH\n") ; 
        printf("2.POP\n") ; 
        printf("3.PEEK\n") ; 
        printf("4.DISPLAY\n") ; 
        printf("0.Exit\n") ; 
        printf("Enter your choice : ") ; 
        scanf("%d" , &ch) ; 
        if(ch==1) {
            int n ; 
            printf("Enter the data you want to push on the stack: ") ; 
            scanf("%d" , &n) ; 
            push(Stack , n) ; 
            printf("%d pushed!!\n" , n) ; 
        }
        else if(ch==2) {
            pop(Stack) ; 
        }
        else if(ch==3) {
            peek(Stack) ; 
        }
        else if(ch==4) {
            display(Stack) ; 
        }
        else if(ch==0) {
            continue;
        }else {
            printf("Enter the valid choice!!") ;
        }
    }
    return 0 ; 
}

void push(struct stack* stack , int num)  {
    struct node* ptr = malloc(sizeof(struct node)) ; 
    ptr->data = num ; 
    ptr->next = stack->top ; 
    stack->top = ptr ; 
}
void pop(struct stack* stack) {
    if(stack->top == NULL) {
        printf("Stack is Empty!!\n") ;
    }else {
        struct node* temp ; 
        temp = stack->top ;
        printf("%d Popped!!\n" , temp->data) ;
        stack->top = temp->next ; 
        free(temp) ; 
    }
}
void display(struct stack* stack) {
    if(stack->top == NULL) {
        printf("Stack is Empty!!\n") ;
    }else{
        struct node* temp = stack->top ; 
        while(temp != NULL) {
            printf("%d\n" , temp->data) ; 
            temp = temp->next ; 
        }
    } 
}
void peek(struct stack* stack) { 
    if(stack->top == NULL) {
        printf("Stack is Empty!!\n") ;
    }else{
        printf("%d \n" , stack->top->data) ; 
    }
}
