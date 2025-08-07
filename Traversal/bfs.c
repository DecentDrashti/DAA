#include<stdio.h>
//breadth first search algorithm
#define V 8
int queue[V]; // Queue array
int front = -1; // Index of the front element
int rear = -1;  // Index of the rear element

int is_empty() {
    return front == -1 || front > rear;
}
int is_full() {
    return rear == V - 1;
}
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

void bfs(int graph[V][V])
{
    int visited[V]={0};
    visited[0]=1;
    enqueue(0);
    while (!is_empty())
    {
        int u =dequeue();
        printf("%d",u);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0 && graph[u][i]!=0)
            {
                visited[i]=1;
                enqueue(i);
            }
        }
    }
    
}
void main()
{
    int graph[V][V]={
        {0,1,1,1,0,0,0,0},
        {1,0,1,0,1,1,0,0},
        {1,1,0,0,0,1,0,0},
        {1,0,0,0,0,0,1,1},
        {0,1,0,0,0,1,0,0},
        {0,1,1,0,1,0,0,0},
        {0,0,0,1,0,0,0,1},
        {0,0,0,1,0,0,1,0}
    };

    bfs(graph);
}
