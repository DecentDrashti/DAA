#include<stdio.h>
//implementing stack using array
#define max 100
int stack[max]; // Stack array
int top = -1;
// Function to check if the stack is empty
int is_empty(int *top) {
    return *top == -1;
}
// Function to check if the stack is full
int is_full(int *top) {
    return *top == max - 1;
}
// Function to pop an element from the stack
int pop(int stack[], int *top) {
    if (is_empty(top)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 or an error code
    }
    return stack[(*top)--];
}
void push(int value) {
    // Check if the stack is full before pushing
    if(top<(max - 1)){
    stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
    
}
void display() {
    if (is_empty(&top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}
void peek(){
    if (is_empty(&top)) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}
void size(){
    if (is_empty(&top)) {
        printf("Stack is empty\n");
    }
    else{
        printf("Size of stack: %d\n", top + 1);
    } 
}
void change(int*top,int value){
    if(is_empty(top)){
        printf("Stack is empty\n");
    } else {
        stack[*top] = value; // Change the top element to the new value
        printf("Top element changed to %d\n", value);
    }
}
void main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Size\n6. change\n 7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 7) {
        printf("Exiting the program...\n");
        break; // Exit the loop if user chooses to exit
    }
    switch(choice){
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            printf("Pushed %d onto the stack\n", value);
            break;
        case 2:
            value = pop(stack, &top);
            if (value != -1) {
                printf("Popped %d from the stack\n", value);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            size();
            break;
        case 6:
            printf("Enter new value for the top element: ");
            scanf("%d", &value);
            change(&top, value);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
  }
  
 }
}
