#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

typedef struct CircularQueue {
    int front;
    int rear;
    int size;
    int array[MAX];
} CircularQueue;

void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

int isFull(CircularQueue* queue) {
    return queue->size == MAX;
}

void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot add more elements.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; 
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Enqueued: %d\n", item);
}

void dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", queue->array[queue->front]);
    queue->front = (queue->front + 1) % MAX; // Circular increment
    queue->size--;

    if (queue->size == 0) {
        queue->front = -1;
        queue->rear = -1;
    }
}

void printQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
