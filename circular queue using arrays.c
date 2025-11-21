#include <stdio.h> 
#include <stdlib.h> 
 
#define N 5 
 
int queue[N]; 
int front = -1; 
int rear = -1; 
 
void enqueue(int data) { 
    if ((rear + 1) % N == front) { 
        printf("Queue Overflow\n"); 
    } else if (front == -1 && rear == -1) { 
        front = rear = 0; 
        queue[rear] = data; 
    } else { 
        rear = (rear + 1) % N; 
        queue[rear] = data; 
    } 
} 
 
void deque() { 
    if (front == -1 && rear == -1) { 
        printf("Queue Underflow\n"); 
    } else if (front == rear) { 
        front = rear = -1; 
    } else { 
        front = (front + 1) % N; 
    } 
} 
 
void display() { 
    if (front == -1 && rear == -1) { 
        printf("NULL\n"); 
    } else { 
        int i = front; 
        while (i != rear) { 
            printf("%d ", queue[i]); 
            i = (i + 1) % N; 
        } 
        printf("%d\n", queue[rear]); 
    } 
} 
 
int main() { 
    int data, ch; 
 
    do { 
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: "); 
        scanf("%d", &ch);
         switch (ch) { 
            case 1: 
                printf("Enter data to enqueue: "); 
                scanf("%d", &data); 
                enqueue(data); 
                break; 
            case 2: 
                deque(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } while (ch != 0); 
 
    return 0; 
}
