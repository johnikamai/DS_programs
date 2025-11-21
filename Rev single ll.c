#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node* next; 
}; 
 
typedef struct node NODE; 
 
NODE* reverseLinkedList(NODE* head) { 
    NODE *prev = NULL, *curr = head, *next = NULL; 
    while (curr != NULL) { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
    return prev; 
} 
 
void display(NODE* head) { 
    NODE* temp = head; 
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 
 
NODE* insertAtEnd(NODE* head, int data) { 
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); 
    newNode->data = data; 
    newNode->next = NULL; 
    if (head == NULL) 
        return newNode; 
    NODE* temp = head; 
    while (temp->next != NULL) 
        temp = temp->next; 
    temp->next = newNode; 
    return head; 
} 
 
int main() { 
    NODE* head = NULL; 
    int n, value; 
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &value); 
        head = insertAtEnd(head, value); 
    } 
 head = reverseLinkedList(head); 
    display(head); 
    return 0; 
}
