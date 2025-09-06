#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue {
    int *arr;
    int front, rear, size;
} cq;

void createQueue(cq *q, int size){
    q->arr = (int *)malloc(size * sizeof(int));
    if(!q->arr){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

int isFull(cq *q){
    return (q->rear + 1) % q->size == q->front || (q->front == 0 && q->rear == q->size - 1);
}

int isEmpty(cq *q){
    return (q->front == -1);
}

void enqueue(cq *q, int value){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }
    if(isEmpty(q)){
        q->front = q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(cq *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->arr[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }else {
        q->front = (q->front + 1) % q->size;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

void display(cq *q){
    printf("Displaying queue elements: \n");
    for(int i = q->front; i <= q->rear; i++){
        printf("%d -> ", q->arr[i]);
    }
    printf("NULL\n");
}

int main() {

    cq q1;
    createQueue(&q1, 5);

    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q1, 40);
    enqueue(&q1, 50);
    display(&q1);
    enqueue(&q1, 60);


    return 0;
}