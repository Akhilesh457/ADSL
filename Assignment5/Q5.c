/*5. Implement insertion operations in a singly linked list to insert a node:
• At the beginning
• At the end
• At a given position*/

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

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;  // new head
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)  // empty list
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insert at given position (1-based)
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position == 1)
        return insertAtBeginning(head, data);

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    // Move to the node before the position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original List:\n");
    displayList(head);

    head = insertAtBeginning(head, 5);
    printf("\nAfter inserting 5 at beginning:\n");
    displayList(head);

    head = insertAtEnd(head, 40);
    printf("\nAfter inserting 40 at end:\n");
    displayList(head);

    head = insertAtPosition(head, 25, 4);
    printf("\nAfter inserting 25 at position 4:\n");
    displayList(head);

    return 0;
}