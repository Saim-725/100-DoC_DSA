// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    int n,k;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*newnode;

    for(int i=0;i<n;i++){
        newnode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    scanf("%d",&k);

    if(head==NULL || k==0){
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return 0;
    }

    int len=1;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }

    temp->next=head;

    k=k%len;
    int steps=len-k;

    struct Node *newtail=head;
    for(int i=1;i<steps;i++){
        newtail=newtail->next;
    }

    head=newtail->next;
    newtail->next=NULL;

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}