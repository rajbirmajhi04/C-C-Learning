#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} stack;

void initStack(stack *s, int capacity){
    s->arr = (int *)malloc(capacity * sizeof(int));
    if(!s->arr){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = capacity;
}

int isEmpty(stack *s){
    return s->top == -1;
}

int isFull(stack *s){
    return s->top == s->capacity - 1;
}

void resizeStack(stack *s){
    s->capacity *= 2;
    s->arr = (int *)realloc(s->arr, s->capacity * sizeof(int));
    if(!s->arr){
        printf("Stack reallocation failed!\n");
        exit(1);
    }
    printf("Stack capacity is doubled to %d!\n", s->capacity);
}

void push(stack *s, int value){
    if(isFull(s)){
        printf("Stack overflow! Resizing stack...!!!\n");
        resizeStack(s);
    }
    s->arr[++s->top] = value;
    printf("\n%d pushed into the stack.\n", value);

    // feature
    if(!isFull(s)){
        int spaceLeft = s->capacity - (s->top + 1);
        printf("Space left: %d\n", spaceLeft);
    }
    else {
        printf("Stack is now full.\n");
    }
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

void display(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        exit(1);
    }
    printf("\nStack Items: \n");
    for(int i = s->top; i >= 0; i--){
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void free(stack *s){
    free(s->arr);
}

int main(){
    
    stack s1;
    initStack(&s1, 5);

    push(&s1, 10);
    push(&s1, 7);
    push(&s1, 65);
    push(&s1, 97);
    push(&s1, 3);

    display(&s1);

    pop(&s1);
    pop(&s1);
    pop(&s1);

    display(&s1);

    push(&s1, 10);
    push(&s1, 7);
    push(&s1, 65);
    push(&s1, 97);
    push(&s1, 3);

    display(&s1);

    return 0;
}

