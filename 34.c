// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if (top == NULL) {
        return 0; // underflow (not expected here)
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluate(char* exp) {
    int i = 0;

    while (exp[i] != '\0') {
        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand (digit)
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        else {
            // Operator
            int b = pop();
            int a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
            i++;
        }
    }

    return pop();
}

int main() {
    char exp[100];

    // Read full line input
    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);

    printf("%d", result);

    return 0;
}