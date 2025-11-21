#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* prev; 
}; 
 
// Function to push an element onto the stack 
struct Node* push(struct Node* top, int data) { 
    struct Node* newNode = malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed!\n"); 
        exit(1); 
    } 
    newNode->data = data; 
    newNode->prev = top; 
    return newNode; 
} 
 
// Function to pop an element from the stack 
struct Node* pop(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is Empty\n"); 
        return NULL; 
    } 
    struct Node* temp = top; 
    top = top->prev; 
    free(temp); 
    return top; 
} 
 
// Function to display the top element of the stack 
void display(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is Empty\n"); 
    } else { 
        printf("-> %d\n", top->data); 
    } 
} 
 
int main() { 
    struct Node* top = NULL; 
    int choice, data; 
 
    do { 
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) {
        	 case 1: 
                printf("Enter value to push: "); 
                scanf("%d", &data); 
                top = push(top, data); 
                break; 
            case 2: 
                top = pop(top); 
                break; 
            case 3: 
                display(top); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } while (choice != 4); 
 
    return 0; 
}
