#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node *prev; 
    struct node *next; 
}; 
 
typedef struct node NODE; 
 
NODE* createNode() { 
    NODE *head = NULL, *newNode, *temp = NULL; 
    int choice = 1; 
    while (choice) { 
        newNode = (NODE *)malloc(sizeof(NODE)); 
        if (newNode == NULL) { 
            exit(1); 
        } 
        scanf("%d", &newNode->data); 
        newNode->prev = NULL; 
        newNode->next = NULL; 
 
        if (head == NULL) { 
            head = newNode; 
        } else { 
            temp->next = newNode; 
            newNode->prev = temp; 
        } 
 
        temp = newNode; 
        scanf("%d", &choice); 
    } 
    return head; 
} 
 
void display(NODE *head) { 
    NODE *temp = head; 
    while (temp != NULL) { 
        printf("->%d", temp->data); 
        temp = temp->next; 
    } 
} 
 
NODE* insertAtBeginning(NODE* head, int data) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
    newNode->data = data;
    newNode->prev = NULL; 
    newNode->next = head; 
    if (head != NULL) { 
        head->prev = newNode; 
    } 
    return newNode; 
} 
 
NODE* insertAtEnd(NODE* head, int data) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        exit(1); 
    } 
    newNode->data = data; 
    newNode->next = NULL; 
 
    if (head == NULL) { 
        newNode->prev = NULL; 
        return newNode; 
    } 
 
    NODE* temp = head; 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
    temp->next = newNode; 
    newNode->prev = temp; 
    return head; 
} 
 
NODE* insertAtPosition(NODE* head, int data, int position) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
    newNode->data = data; 
 
    if (position == 1) { 
        newNode->prev = NULL; 
        newNode->next = head; 
        if (head != NULL) { 
            head->prev = newNode; 
        } 
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
    newNode->prev = current; 
    if (current->next != NULL) { 
        current->next->prev = newNode; 
    } 
    current->next = newNode; 
    return head; 
} 
 
NODE* deleteNode(NODE* head, int key) { 
    NODE* temp = head; 
 
    while (temp != NULL && temp->data != key) { 
        temp = temp->next; 
    } 
 
    if (temp == NULL) { 
        return head; 
    } 
 
    if (temp->prev != NULL) { 
        temp->prev->next = temp->next; 
    } 
 
    if (temp->next != NULL) { 
        temp->next->prev = temp->prev; 
    } 
 
    if (temp == head) { 
        head = head->next; 
    } 
 
    free(temp); 
    return head; 
} 
 
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
 
NODE* reverseLinkedList(NODE* head) { 
    NODE *temp = NULL; 
    NODE *current = head; 
 
    while (current != NULL) { 
        temp = current->prev; 
        current->prev = current->next; 
        current->next = temp; 
        current = current->prev; 
    } 
 
    if (temp != NULL) { 
        head = temp->prev; 
    } 
 
    return head; 
} 
 
int main() { 
    NODE *head = NULL; 
    int choice, subChoice, data, position, key; 
 
    do { 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
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
 
            case 2: 
                scanf("%d", &key); 
                head = deleteNode(head, key); 
                if (head == NULL) { 
                    printf("NULL\n"); 
                } 
                break; 
 
            case 3: 
                display(head); 
                printf("\n"); 
                break; 
 
            case 4: 
                head = reverseLinkedList(head); 
                break; 
 
            case 5: 
                scanf("%d", &key); 
                if (searchLinkedList(head, key) != NULL) 
                    printf("YES\n"); 
                else 
                    printf("NO\n"); 
                break; 
 
            case 6: 
                break; 
 
            default: 
                printf("Invalid choice! Please enter again.\n"); 
                break; 
        } 
    } while (choice != 6); 
 
    NODE* temp; 
    while (head != NULL) { 
        temp = head; 
        head = head->next; 
        free(temp); 
    } 
 
    return 0; 
}
