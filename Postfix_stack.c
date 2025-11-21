 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>  // Include ctype.h for isdigit function 
 
#define MAX_SIZE 100 
 
// Function to evaluate postfix expression 
int evaluatePostfix(char* postfix) { 
    int stack[MAX_SIZE]; 
    int top = -1; 
    char* token = strtok(postfix, " "); 
 
    while (token != NULL) { 
        if (isdigit((unsigned char)token[0])) {  // Use isdigit properly 
            stack[++top] = atoi(token); 
        } else { 
            int operand2 = stack[top--]; 
            int operand1 = stack[top--]; 
            switch (token[0]) { 
                case '+': 
                    stack[++top] = operand1 + operand2; 
                    break; 
                case '-': 
                    stack[++top] = operand1 - operand2; 
                    break; 
                case '*': 
                    stack[++top] = operand1 * operand2; 
                    break; 
                case '/': 
                    stack[++top] = operand1 / operand2; 
                    break; 
                default: 
                    printf("Invalid operator\n"); 
                    exit(1); 
            } 
        } 
        token = strtok(NULL, " "); 
    } 
    return stack[top]; 
} 
 
int main() { 
    int N; 
    scanf("%d", &N); 
    getchar();  // Consume newline character after the number of test cases 
 
    for (int t = 0; t < N; t++) { 
        char postfix[MAX_SIZE]; 
        fgets(postfix, MAX_SIZE, stdin);
            *strchr(postfix, '?') = '\0';  // Replace '?' with '\0' 
        printf("%d\n", evaluatePostfix(postfix)); 
    } 
 
    return 0; 
} 
