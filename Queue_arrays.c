#include <stdio.h> 
#define N 5 
 
int queue[N]; 
int front = -1; 
int rear = -1; 
 
// Function to enqueue (add an element to the queue) 
void enqueue(int data) { 
    if (rear == N - 1) { 
        printf("Overflow\n"); 
    } else if (front == -1 && rear == -1) { 
        front = rear = 0; 
        queue[rear] = data; 
    } else { 
        rear++; 
        queue[rear] = data; 
    } 
} 
 
// Function to dequeue (remove an element from the queue) 
void dequeue() { 
    if (front == -1 && rear == -1) { 
        printf("Underflow\n"); 
    } else if (front == rear) { 
        front = rear = -1; 
    } else { 
        printf("%d\n", queue[front]); 
        front++; 
    } 
} 
 
// Function to peek (view the front element of the queue) 
void peek() { 
    if (front == -1 && rear == -1) { 
        printf("Queue is empty\n"); 
    } else { 
        printf("%d\n", queue[front]); 
    } 
} 
 
// Function to display the elements of the queue 
void display() { 
    if (front == -1 && rear == -1) { 
        printf("Queue is empty\n"); 
    } else { 
        printf("Queue elements: "); 
        for (int i = front; i <= rear; i++) { 
            printf("%d ", queue[i]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int data, ch; 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Enqueue\n"); 
        printf("2. Dequeue\n"); 
        printf("3. Display\n"); 
        printf("4. Peek\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &ch); 
 
        switch (ch) { 
            case 1: 
                printf("Enter data to enqueue: "); 
                scanf("%d", &data); 
                enqueue(data); 
                break; 
            case 2: 
                dequeue(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                peek(); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
                break; 
        } 
    } while (ch != 0); 
 
    return 0; 
} 
 
