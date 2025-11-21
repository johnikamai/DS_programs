#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node *prev; 
    struct node *next; 
}; 
 
typedef struct node NODE; 
 
// Function to create a doubly circular linked list 
NODE* createNode() { 
    NODE *head = NULL, *newNode, *temp = NULL; 
    int choice = 1; 
 
    while (choice) { 
        newNode = (NODE *)malloc(sizeof(NODE)); 
        if (newNode == NULL) { 
            exit(1); 
        } 
 
        scanf("%d", &newNode->data); 
        newNode->prev = newNode->next = NULL; 
 
        if (head == NULL) { 
            head = newNode; 
            head->next = head; 
            head->prev = head; 
        } else { 
            temp->next = newNode; 
            newNode->prev = temp; 
            newNode->next = head; 
            head->prev = newNode; 
        } 
 
        temp = newNode; 
        scanf("%d", &choice); 
    } 
 
    return head; 
} 
 
// Function to display the doubly circular linked list 
void display(NODE *head) { 
    if (head == NULL) { 
        printf("NULL\n"); 
        return; 
    } 
 
    NODE *temp = head; 
 do { 
        printf("->%d", temp->data); 
        temp = temp->next; 
    } while (temp != head); 
    printf("\n"); 
} 
 
// Function to insert a node at the beginning 
NODE* insertAtBeginning(NODE* head, int data) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        exit(1); 
    } 
 
    newNode->data = data; 
    newNode->prev = head->prev; 
    newNode->next = head; 
    head->prev->next = newNode; 
    head->prev = newNode; 
 
    return newNode;  // New head 
} 
 
// Function to insert a node at the end 
NODE* insertAtEnd(NODE* head, int data) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        exit(1); 
    } 
 
    newNode->data = data; 
    newNode->prev = head->prev; 
    newNode->next = head; 
    head->prev->next = newNode; 
    head->prev = newNode; 
 
    return head; 
} 
 
// Function to insert at a given position 
NODE* insertAtPosition(NODE* head, int data, int position) { 
    if (position <= 0) { 
        printf("Invalid position.\n"); 
        return head; 
    } 
 
    if (position == 1) { 
        return insertAtBeginning(head, data); 
    } 
 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) {
    	   printf("Memory allocation failed\n"); 
        exit(1); 
    } 
 
    newNode->data = data; 
 
    NODE* current = head; 
    int count = 1; 
 
    while (count < position - 1 && current->next != head) { 
        current = current->next; 
        count++; 
    } 
 
    if (count != position - 1) { 
        printf("Position out of range.\n"); 
        free(newNode); 
        return head; 
    } 
 
    newNode->next = current->next; 
    newNode->prev = current; 
    current->next->prev = newNode; 
    current->next = newNode; 
 
    return head; 
} 
 
// Function to delete a node by value 
NODE* deleteNode(NODE* head, int key) { 
    if (head == NULL) { 
        printf("NULL\n"); 
        return NULL; 
    } 
 
    NODE* temp = head; 
 
    do { 
        if (temp->data == key) { 
            if (temp->prev == temp) {  // Only one node 
                free(temp); 
                return NULL; 
            } else { 
                temp->prev->next = temp->next; 
                temp->next->prev = temp->prev; 
                if (temp == head) { 
                    head = head->next; 
                } 
                free(temp); 
                return head; 
            } 
        } 
       temp = temp->next; 
    } while (temp != head); 
 
    printf("NULL\n"); 
    return head; 
} 
 
int main() { 
    NODE *head = NULL; 
    int choice, subChoice, position, data, key; 
 
    do { 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1:  // Insertion 
                scanf("%d", &data); 
                if (head == NULL) { 
                    head = (NODE*)malloc(sizeof(NODE)); 
                    if (head == NULL) { 
                        exit(1); 
                    } 
                    head->data = data; 
                    head->prev = head; 
                    head->next = head; 
                    break; 
                } 
 
                scanf("%d", &subChoice); 
                switch (subChoice) { 
                    case 1: 
                        head = insertAtBeginning(head, data); 
                        break; 
                    case 2: 
                        head = insertAtEnd(head, data); 
                        break; 
                    case 3: 
                        scanf("%d", &position); 
                        head = insertAtPosition(head, data, position); 
                        break; 
                    default: 
                        printf("Invalid choice for Insertion Operations\n"); 
                        break; 
                } 
                break; 
 
            case 2:  // Deletion 
                scanf("%d", &key); 
                head = deleteNode(head, key); 
                break; 
 
            case 3:  // Display
              display(head); 
                break; 
 
            case 4:  // Exit 
                break; 
 
            default: 
                printf("Invalid choice! Please enter again.\n"); 
                break; 
        } 
 
    } while (choice != 4); 
 
    // Free allocated memory before exiting 
    if (head != NULL) { 
        NODE* temp = head->next; 
        while (temp != head) { 
            NODE* nextNode = temp->next; 
            free(temp); 
            temp = nextNode; 
        } 
        free(head); 
    } 
 
    return 0; 
}
