/*4. Write a program to detect whether a linked list contains a loop using Floyd’s Cycle Detection
Algorithm.*/
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

// Function to detect loop using Floyd’s Cycle Detection
int detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // loop detected
            return 1;
        }
    }

    return 0; // no loop
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    head->next->next->next->next = head->next;

    if (detectLoop(head)) {
        printf("Loop detected in the linked list\n");
    } else {
        printf("No loop in the linked list\n");
    }

    return 0;
}
