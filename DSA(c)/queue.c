#include<stdio.h>
//implementing queue using array
#include<stdlib.h>
#define MAX 100
int queue[MAX]; // Queue array
int front = -1; // Index of the front element
int rear = -1;  // Index of the rear element
// Function to check if the queue is empty
int is_empty() {
    return front == -1 || front > rear;
}
// Function to check if the queue is full
int is_full() {
    return rear == MAX - 1;
}
// Function to enqueue an element
void enqueue(int value) {
    // Check if the queue is full before enqueuing
    if (is_full()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0; // Initialize front if it's the first element
    }
    queue[++rear] = value; // Increment rear and add the new element
}
// Function to dequeue an element
int dequeue() {
    // Check if the queue is empty before dequeuing
    if (is_empty()) {
        printf("Queue Underflow\n");
        return -1; // Return -1 or an error code
    }
    int dequeued_value = queue[front++]; // Get the front element and increment front
    if (front > rear) {
        front = -1; // Reset front and rear if the queue becomes empty
        rear = -1;
    }
    return dequeued_value;
}
// Function to display the queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d \n", queue[i]);
        }
       
    }
}

//function for peeking the front element
void peek(){
    if (is_empty(&front)) {
        printf("Queue is empty\n");
    } else {
        printf("Top element: %d\n", queue[front]);
    }
}

void main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 7) {
        printf("Exiting the program...\n");
        break; // Exit the loop if user chooses to exit
    }
    switch(choice){
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            printf(" enqueue%d onto the queue\n", value);
            break;
        case 2:
            value = dequeue();
            if (value != -1) {
                printf("dequeued %d from the queue\n", value);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
  }
  
 }
}

// struct Queue {
//     int items[MAX];
//     int front;
//     int rear;
// };
// // Function to create a queue
// struct Queue* createQueue() {
//     struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
//     q->front = -1;
//     q->rear = -1;
//     return q;
// }
