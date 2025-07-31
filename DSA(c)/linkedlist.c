#include<stdio.h>
//implementing linked list
#include<stdlib.h>

//define a node structure
struct Node{
    int data;
    struct Node* next;
};

//function to create a new node
struct Node* head=NULL;
struct Node* createNode(int data)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//insert a node
struct Node* insertNode(struct Node*head,int data)
{
    struct Node* newNode=createNode(data);
    if(head==NULL)
     return newNode;
    struct Node* current = head;
    while(current->next!=NULL)
    {
        current=current->next;

    }
    current->next=newNode;
    return head;

}

//remove a node
struct Node* removeNode(struct Node*head,int data)
{
    struct Node* current=head;
    struct Node* previous=NULL;
    while(current!=NULL && current->data!=data)
    {
        previous=current;
        current=current->next;
    }
    if (current == NULL) 
    {
        // Data not found
        return head;
    }
    if (previous == NULL) {
        // The node to be removed is the head
        head = current->next;
    } else {
        // Bypass the node to be removed
        previous->next = current->next;
    }

    free(current);
    return head;
}

//traversal the linkedlist
struct Node* display(struct Node*head)
{
    struct Node* current=head;
    while (current->next!=NULL)
    {
        printf("\n%d -> ", current->data);
        current = current->next;
    }
    printf("%d -> NULL\n", current->data);
    return head;
    
}

void main() {
    int choice, value;
    while (1) {
        printf("\n1. add\n2. remove\n3. Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 4) {
        printf("Exiting the program...\n");
        break; // Exit the loop if user chooses to exit
    }
    switch(choice){
        case 1:
            printf("Enter value to enter: ");
            scanf("%d", &value);
            insertNode(&head,value);
            printf("Pushed %d onto the stack\n", value);
            break;
        case 2:
            value = removeNode(&head, value);
            // if (value != -1) {
            //     printf("Popped %d from the stack\n", value);
            // }
            break;
        case 3:
            displayNode();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
  }
  
 }
}
