// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        return; // stack overflow (ignored for this problem)
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        return; // stack underflow (ignored)
    }
    top--;
}

int main() {
    int n, m, i, x;

    // Input
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // Pop m elements
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print stack from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}