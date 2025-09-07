#include <stdio.h>
#include <stdlib.h>

/*
 Insertion and deletion takes place from both end of the queue.
*/

#define SIZE 5

int deque[SIZE];

/*
    front (points to the current first eleemnt)
    rear (points to the current last eleemnt)
*/

int front = -1, rear = -1;

/*
 Make circular:
 After SIZE - 1, the next index is 0 (wrap - around)
 Before 0, the previous index is SIZE - 1 (wrap around backward)

 Moving forward: rear = (rear + 1) % size
 Moving backward: (if front == 0) then front = SIZE - 1 else front --
*/

void insertRear(int value){
    // check if full
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
        printf("Deque is full\n");
        return;
    }
    // if empty
    if(front == -1){
        front = rear = 0;
    }
    else if(rear == SIZE - 1){ // rear is the last index (wrap around)
        rear = 0;
    }
    else {
        rear ++;
    }
    deque[rear] = value;
}

void insertFront(int value){
    // check if full
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
        printf("Deque is full!\n");
        return;
    }
    // if empty
    if(front == -1){
        front = rear = 0;
    }
    else if(front = 0){ // wrap backward
        front = SIZE - 1;
    }
    else {
        front --;
    }
    deque[front] = value;
}

void deleteFront(){
    // check if empty
    if(front == -1){
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted: %d\n", deque[front]);
    // if there is only one element
    if(front == rear){
        front = rear = -1; // reset both pointers
    }
    else if (front == SIZE - 1){ // wrap forward
        front = 0;
    }
    else {
        front ++;
    }
}

void deleteRear(){
    // check if empty
    if(front == -1){
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted: %d\n", deque[rear]);
    // if there is only one element
    if(front == rear){
        front = rear = -1; // reset both pointers
    }
    else if (rear == 0){
        rear = SIZE - 1;
    }
    else {
        rear --;
    }
}

void display(){
    if(front == -1){
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    for(int i = front; ;i = (i + 1) % SIZE){ // modulo keeps its circular
        printf("%d ", deque[i]);
        if(i == rear){
            break;
        }
    }
    printf("\n");
}

int main() {

    insertRear(10);
    insertRear(20);
    insertRear(30);
    insertRear(40);
    insertRear(50);
    display();
    insertRear(60); // cant insert

    deleteRear();
    deleteRear();
    display();
    deleteFront();
    deleteFront();
    display();
    return 0;
}