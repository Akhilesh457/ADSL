/*1. Write a program to reverse a singly linked list (implement both iterative and recursive methods).*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Iterative method 
struct Node* reverseIterative(struct Node* head) {
    struct Node* p = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   
        curr->next = p;  
        p = curr;
        curr = next;
    }

    return p;
}

// Recursive method
struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List:\n");
    printList(head);

    head = reverseIterative(head);
    printf("\nReversed List (Iterative):\n");
    printList(head);

    head = reverseRecursive(head);
    printf("\nReversed List (Recursive):\n");
    printList(head);

    return 0;
}