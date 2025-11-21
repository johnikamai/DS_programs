#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node *left, *right; 
}; 
 
// Function to create a new node 
struct node *createNode(int value) { 
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
    newNode->data = value; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
// Function to insert a new node into BST 
struct node *insert(struct node *root, int value) { 
    if (root == NULL) 
        return createNode(value); 
 
    if (value < root->data) 
        root->left = insert(root->left, value); 
    else if (value > root->data) 
        root->right = insert(root->right, value); 
 
    return root; 
} 
 
// Function to search for a key in BST 
struct node *search(struct node *root, int key) { 
    if (root == NULL || root->data == key) 
        return root; 
 
    if (key < root->data) 
        return search(root->left, key); 
    else 
        return search(root->right, key); 
} 
 
// Function to find the node with the minimum value in BST 
struct node *findMin(struct node *root) { 
    if (root == NULL || root->left == NULL) 
        return root; 
    return findMin(root->left); 
} 
 
// Function to find the node with the maximum value in BST 
struct node *findMax(struct node *root) { 
    if (root == NULL || root->right == NULL)
           return root; 
    return findMax(root->right); 
} 
 
// Main function 
int main() { 
    struct node *root = NULL; 
    int choice, value; 
 
    printf("Binary Search Tree Menu:\n"); 
    printf("1. Search\n2. Find Max\n3. Find Min\n4. Insert\n5. Exit\n"); 
 
    while (1) { 
        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to search: "); 
                scanf("%d", &value); 
                if (search(root, value)) 
                    printf("Found: %d\n", value); 
                else 
                    printf("NULL\n"); 
                break; 
 
            case 2: 
                if (root) 
                    printf("Max: %d\n", findMax(root)->data); 
                else 
                    printf("Tree is empty.\n"); 
                break; 
 
            case 3: 
                if (root) 
                    printf("Min: %d\n", findMin(root)->data); 
                else 
                    printf("Tree is empty.\n"); 
                break; 
 
            case 4: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                root = insert(root, value); 
                printf("Inserted: %d\n", value); 
                break; 
 
            case 5: 
                exit(0); 
 
            default: 
                printf("Invalid choice.\n");
        } 
    } 
 
    return 0; 
}
