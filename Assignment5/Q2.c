/*2. Write a program to search for a given element in a linked list and print its position.*/
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
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void searchElement(struct Node* head, int key) {
    int position = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element %d not found in the list\n", key);
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Linked List:\n");
    printList(head);

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    searchElement(head, key);

    return 0;
}