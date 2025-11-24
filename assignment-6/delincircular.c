#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to delete a node with specific value
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
        return;

    // If head is to be deleted
    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *curr = *head, *prev = NULL;

    // Find the node to be deleted
    while (curr->data != key)
    {
        // If node not found
        if (curr->next == *head)
        {
            printf("\nNode with value %d not found\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // If node to be deleted is head
    if (curr == *head)
    {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        *head = curr->next;
        prev->next = *head;
        free(curr);
    }
    // For other nodes
    else
    {
        prev->next = curr->next;
        free(curr);
    }
}

// Function to display the list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main()
{
    struct Node *head = NULL;

    // Create a circular linked list: 1->2->3->4->5->1
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = head;

    printf("Original Circular Linked List:\n");
    displayList(head);

    // Delete node with value 3
    printf("\nDeleting node with value 3...\n");
    deleteNode(&head, 3);
    printf("List after deletion:\n");
    displayList(head);

    // Delete node with value 1 (head)
    printf("\nDeleting node with value 1 (head)...\n");
    deleteNode(&head, 1);
    printf("List after deletion:\n");
    displayList(head);

    getch();
    return 0;
}