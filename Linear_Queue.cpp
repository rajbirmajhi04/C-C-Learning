#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    q->arr = (int *)malloc(size * sizeof(int));
    if(!q->arr){
        printf("\nMemory allocation failed!\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    q->capacity = size;
    printf("\nQueue Initialized...\n");
}

int isEmpty(Queue *q){
    return q->front > q->rear;
}

int isFull(Queue *q){
    return q->rear == q->capacity - 1;
}

void resizeQueue(Queue *q){
    q->capacity *= 2;
    q->arr = (int *)realloc(q->arr, q->capacity * sizeof(int));
    if(!q->arr){
        printf("\nReallocation failed!\n");
        exit(1);
    }
    printf("\nRellocation successfull!\n");
}

void enqueue(Queue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow! Resizing queue...\n");
        resizeQueue(q);
    }
    if(q->front == -1){q->front = 0;}
    q->arr[++q->rear] = value;
    printf("Inserted --> %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1; 
    }
    int removed = q->arr[q->front++];
    printf("%d dequeued from queue.\n", removed);
    
    if(q->front > q->rear){
        q->front = -1;
        q->rear = -1;
    }
    return removed;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    printf("Front element: %d\n", q->arr[q->front]);
    return q->arr[q->front];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void freeQueue(Queue *q) {
    free(q->arr);
}

int main() {

    Queue q1;
    initQueue(&q1);

    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q1, 40);
    enqueue(&q1, 50);

    display(&q1);


    return 0;
}