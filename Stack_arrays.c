#include <stdio.h> 
#define N 100 
int stack[N]; 
int top = -1; 
 
// Function to push an element onto the stack 
void push(int data) { 
    if (top == N - 1) { 
        printf("Stack overflow!\n"); 
        return; 
    } 
    top++; 
    stack[top] = data; 
    printf("Pushed element: %d\n", data); 
} 
 
// Function to pop an element from the stack 
int pop() { 
    if (top == -1) { 
        printf("Stack is empty!\n"); 
        return -1; 
    } 
    int item = stack[top]; 
    top--; 
    return item; 
} 
 
// Function to peek the top element of the stack 
int peek() { 
    if (top == -1) { 
        printf("Stack is empty!\n"); 
        return -1; 
    } 
    return stack[top]; 
} 
 
// Function to display the elements of the stack 
void display() { 
    if (top == -1) { 
        printf("Stack is empty!\n"); 
        return; 
    } 
    printf("Stack elements:\n"); 
    for (int i = top; i >= 0; i--) { 
        printf("%d\n", stack[i]); 
    } 
} 
 
int main() { 
    int choice, data;
     do { 
        printf("\n1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Peek\n"); 
        printf("4. Display\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to push: "); 
                scanf("%d", &data); 
                push(data); 
                break; 
            case 2: 
                printf("Popped element: %d\n", pop()); 
                break; 
            case 3: 
                printf("Top element: %d\n", peek()); 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                printf("Exiting program.\n"); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } while (choice != 5); 
 
    return 0; 
}
