#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node *next; 
}; 
 
typedef struct node NODE; 
 
// Function to create a linked list 
NODE* createNode() { 
    NODE *head = NULL, *newNode, *temp = NULL; 
    int choice = 1; 
     
    while (choice) { 
        newNode = (NODE *)malloc(sizeof(NODE)); 
        if (newNode == NULL) { 
            exit(1); 
        } 
 		scanf("%d", &newNode->data); 
        newNode->next = NULL; 
 		if (head == NULL) { 
            head = newNode; 
        }
		else { 
            if (temp == NULL) { 
                head->next = newNode; 
            }
			else { 
                temp->next = newNode; 
            } 
        } 
 		temp = newNode; 
        scanf("%d", &choice); 
    } 
 
    return head; 
} 
 
// Function to display the linked list 
void display(NODE *head) { 
    NODE *temp = head; 
    while (temp != NULL) { 
        printf("->%d", temp->data); 
        temp = temp->next; 
    } 
} 
// Function to insert a node at the beginning 
NODE* insertAtBeginning(NODE* head, int data) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
 	newNode->data = data; 
    newNode->next = head; 
    return newNode; 
} 
 
// Function to insert a node at the end 
NODE* insertAtEnd(NODE* head, int data) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        exit(1); 
    } 
 
    newNode->data = data; 
    newNode->next = NULL; 
 
    if (head == NULL) { 
        return newNode; 
    } 
 
    NODE* temp = head; 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
 
    temp->next = newNode; 
    return head; 
} 
 
// Function to insert a node at a given position 
NODE* insertAtPosition(NODE* head, int data, int position) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
 
    newNode->data = data; 
 
    if (position == 1) { 
        newNode->next = head; 
        return newNode; 
    }
    NODE* current = head; 
    int count = 1; 
 
    while (count < position - 1 && current != NULL) { 
        current = current->next; 
        count++; 
    } 
 
    if (current == NULL) { 
        printf("Invalid position.\n"); 
        return head; 
    } 
 
    newNode->next = current->next; 
    current->next = newNode; 
 
    return head; 
} 
 
// Function to delete the first occurrence of a given value 
NODE* deleteNode(NODE* head, int key) { 
    NODE* temp = head; 
    NODE* prev = NULL; 
 
    if (temp != NULL && temp->data == key) { 
        head = temp->next; 
        free(temp); 
        return head; 
    } 
 
    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    if (temp == NULL) { 
        return head; 
    } 
 
    prev->next = temp->next; 
    free(temp); 
    return head; 
} 
 
// Function to search for a value in the linked list 
NODE* searchLinkedList(NODE* head, int key) { 
    NODE* current = head; 
    while (current != NULL) { 
        if (current->data == key) { 
            return current; 
        } 
        current = current->next;
} 
    return NULL; 
} 
 
// Function to reverse the linked list 
NODE* reverseLinkedList(NODE* head) { 
    NODE *prevNode = NULL, *currentNode = head, *nextNode = NULL; 
 
    while (currentNode != NULL) { 
        nextNode = currentNode->next; 
        currentNode->next = prevNode; 
        prevNode = currentNode; 
        currentNode = nextNode; 
    } 
 
    return prevNode; 
} 
 
// Function to sort the linked list in ascending order 
NODE* sortLinkedList(NODE* head) { 
    if (head == NULL || head->next == NULL) { 
        return head; 
    } 
 
    int swapped; 
    NODE *ptr1; 
    NODE *lptr = NULL; 
 
    do { 
        swapped = 0; 
        ptr1 = head; 
 
        while (ptr1->next != lptr) { 
            if (ptr1->data > ptr1->next->data) { 
                int temp = ptr1->data; 
                ptr1->data = ptr1->next->data; 
                ptr1->next->data = temp; 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
 
        lptr = ptr1; 
    } while (swapped); 
 
    return head; 
} 
 
int main() { 
    NODE *head = NULL; 
    int choice, subChoice, data, position, key;
 do { 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: // Insertion 
                scanf("%d", &data); 
                if (head == NULL) { 
                    head = insertAtBeginning(head, data); 
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
                        if (position < 1) { 
                            printf("Invalid position.\n"); 
                            break; 
                        } 
                        head = insertAtPosition(head, data, position); 
                        break; 
                    default: 
                        printf("Invalid choice for Insertion Operations\n"); 
                        break; 
                } 
                break; 
 
            case 2: // Deletion 
                scanf("%d", &key); 
                head = deleteNode(head, key); 
                if (searchLinkedList(head, key) == NULL) { 
                    printf("NULL\n"); 
                } 
                break; 
 
            case 3: // Display 
                display(head); 
                printf("\n"); 
                break; 
 
            case 4: // Reverse 
                head = reverseLinkedList(head); 
                break; 
 
            case 5: // Search 
                scanf("%d", &key);
				if (searchLinkedList(head, key) != NULL) 
                    printf("YES\n"); 
                else 
                    printf("NO\n"); 
                break; 
 
            case 6: // Sort 
                head = sortLinkedList(head); 
                break; 
 
            case 7: // Exit 
                break; 
 
            default: 
                printf("Invalid choice! Please enter again.\n"); 
                break; 
        } 
 
    } while (choice != 7); 
 
    // Free allocated memory 
    NODE* temp; 
    while (head != NULL) { 
        temp = head; 
        head = head->next; 
        free(temp); 
    } 
 
    return 0; 
}  

 
