#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct node { 
    int data; 
    struct node* next; 
} node; 
 
node* front = NULL, * rear = NULL; 
 
// Function to enqueue (add an element to the queue) 
void enqueue(int data) { 
    node* newnode = (node*)malloc(sizeof(node)); 
    newnode->data = data; 
    newnode->next = NULL; 
 
    if (front == NULL && rear == NULL) { 
        front = rear = newnode; 
    } else { 
        rear->next = newnode; 
        rear = newnode; 
    } 
} 
 
// Function to dequeue (remove an element from the queue) 
void dequeue() { 
    if (front == NULL && rear == NULL) { 
        printf("Queue is empty\n"); 
    } else if (front == rear) { 
        free(front); 
        front = rear = NULL; 
    } else { 
        node* temp = front; 
        front = front->next; 
        free(temp); 
    } 
} 
 
// Function to display the elements of the queue 
void display() { 
    if (front == NULL && rear == NULL) { 
        printf("Queue is empty\n"); 
    } else { 
        node* temp = front; 
        while (temp != NULL) { 
            printf("->%d", temp->data); 
            temp = temp->next; 
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
        printf("4. Exit\n"); 
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
                exit(0); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
                break; 
        } 
    } while (ch != 4); 
 
    return 0
}
