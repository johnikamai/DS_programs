#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
 
// Structure for a node 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
// Queue for Level Order Traversal 
struct Queue { 
    struct Node* items[MAX]; 
    int front, rear; 
}; 
 
void initQueue(struct Queue* q) { 
    q->front = q->rear = -1; 
} 
 
int isEmpty(struct Queue* q) { 
    return q->front == -1; 
} 
 
void enqueue(struct Queue* q, struct Node* value) { 
    if ((q->rear + 1) % MAX == q->front) { 
        printf("Queue Overflow\n"); 
        return; 
    } 
    if (isEmpty(q)) 
        q->front = 0; 
    q->rear = (q->rear + 1) % MAX; 
    q->items[q->rear] = value; 
} 
 
struct Node* dequeue(struct Queue* q) { 
    if (isEmpty(q)) { 
        return NULL; 
    } 
    struct Node* temp = q->items[q->front]; 
    if (q->front == q->rear) 
        q->front = q->rear = -1; 
    else 
        q->front = (q->front + 1) % MAX; 
    return temp; 
} 
 
// BST utility functions 
struct Node* newNode(int data) {
	   struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
 
struct Node* insert(struct Node* node, int data) { 
    if (node == NULL) 
        return newNode(data); 
    if (data < node->data) 
        node->left = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data); 
    return node; 
} 
 
struct Node* inorderPredecessor(struct Node* node) { 
    struct Node* current = node->left; 
    while (current && current->right != NULL) 
        current = current->right; 
    return current; 
} 
 
struct Node* deleteNode(struct Node* root, int data) { 
    if (root == NULL) 
        return root; 
 
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
    else { 
        if (root->left == NULL) { 
            struct Node* temp = root->right; 
            free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            struct Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
 
        struct Node* temp = inorderPredecessor(root); 
        root->data = temp->data; 
        root->left = deleteNode(root->left, temp->data); 
    } 
    return root; 
} 
 
// Traversals 
void inorder(struct Node* root) { 
    if (root != NULL) {
    	    inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
 
void preorder(struct Node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
 
void postorder(struct Node* root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    } 
} 
 
void levelOrder(struct Node* root) { 
    if (root == NULL) { 
        printf("Tree is empty.\n"); 
        return; 
    } 
 
    struct Queue q; 
    initQueue(&q); 
    enqueue(&q, root); 
 
    while (!isEmpty(&q)) { 
        struct Node* current = dequeue(&q); 
        printf("%d ", current->data); 
 
        if (current->left != NULL) 
            enqueue(&q, current->left); 
        if (current->right != NULL) 
            enqueue(&q, current->right); 
    } 
} 
 
// Main function 
int main() { 
    struct Node* root = NULL; 
    int choice, data; 
 
    printf("Binary Search Tree Menu:\n"); 
    printf("1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Level Order\n7. Exit\n"); 
 
    do {
    	  printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &data); 
                root = insert(root, data); 
                break; 
 
            case 2: 
                printf("Enter value to delete: "); 
                scanf("%d", &data); 
                root = deleteNode(root, data); 
                break; 
 
            case 3: 
                printf("Inorder Traversal: "); 
                inorder(root); 
                printf("\n"); 
                break; 
 
            case 4: 
                printf("Preorder Traversal: "); 
                preorder(root); 
                printf("\n"); 
                break; 
 
            case 5: 
                printf("Postorder Traversal: "); 
                postorder(root); 
                printf("\n"); 
                break; 
 
            case 6: 
                printf("Level Order Traversal: "); 
                levelOrder(root); 
                printf("\n"); 
                break; 
 
            case 7: 
                printf("Exiting...\n"); 
                break; 
 
            default: 
                printf("Invalid choice. Try again.\n"); 
        } 
    } while (choice != 7); 
 
    return 0; 
}
