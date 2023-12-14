/*
Write a program to implement circular queue using arrays
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int array[MAX_SIZE];
};

void initializeQueue(struct CircularQueue* queue) {
    queue->front = queue->rear = -1;
}

int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = value;

    printf("%d enqueued to the queue.\n", value);
}

int dequeue(struct CircularQueue* queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    value = queue->array[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return value;
}

void display(struct CircularQueue* queue) {
    int i;

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    i = queue->front;
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;

            case 3:
                display(&queue);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}


// / o/utput

/*
Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter a value to enqueue: 10
10 enqueued to the queue.

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter a value to enqueue: 20
20 enqueued to the queue.

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Elements in the queue: 10 20 

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter a value to enqueue: 30
30 enqueued to the queue.

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Dequeued element: 10

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Elements in the queue: 20 30 

Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting program.

*/
