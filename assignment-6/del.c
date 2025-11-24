#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to delete first occurrence of a given value
void deleteFirstOccurrence(struct Node **head, int value)
{
    struct Node *current = *head;

    // If list is empty
    if (*head == NULL)
        return;

    // If value is found at head
    if ((*head)->data == value)
    {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return;
    }

    // Search for the value in the list
    while (current != NULL && current->data != value)
        current = current->next;

    // If value not found
    if (current == NULL)
        return;

    // Update the links
    if (current->next != NULL)
        current->next->prev = current->prev;
    current->prev->next = current->next;

    free(current);
}

// Function to print the list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Creating a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    printf("Original List: ");
    printList(head);

    // Delete first occurrence of 3
    deleteFirstOccurrence(&head, 3);

    printf("List after deleting 3: ");
    printList(head);

    getch();
    return 0;
}