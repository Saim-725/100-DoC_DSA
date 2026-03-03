// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* temp = createNode(value);

    if (head == NULL)
        return temp;

    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct Node* temp;

        if (l1->data < l2->data) {
            temp = createNode(l1->data);
            l1 = l1->next;
        } else {
            temp = createNode(l2->data);
            l2 = l2->next;
        }

        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    while (l1 != NULL) {
        tail->next = createNode(l1->data);
        tail = tail->next;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        tail->next = createNode(l2->data);
        tail = tail->next;
        l2 = l2->next;
    }

    return result;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n, m, x;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* merged = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    merged = mergeLists(list1, list2);

    printList(merged);

    return 0;
}