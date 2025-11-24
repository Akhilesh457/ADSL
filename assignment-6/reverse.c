#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

/* Append new node at the end */
void append(Node **head_ref, int data)
{
    Node *new_node = createNode(data);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    Node *tail = *head_ref;
    while (tail->next)
        tail = tail->next;
    tail->next = new_node;
    new_node->prev = tail;
}

/* Print list from head to tail */
void printForward(Node *head)
{
    printf("Forward: ");
    for (Node *p = head; p; p = p->next)
    {
        printf("%d", p->data);
        if (p->next)
            printf(" <-> ");
    }
    printf("\n");
}

/* Print list from tail to head */
void printBackward(Node *head)
{
    if (!head)
    {
        printf("Backward: (empty)\n");
        return;
    }
    Node *tail = head;
    while (tail->next)
        tail = tail->next;
    printf("Backward: ");
    for (Node *p = tail; p; p = p->prev)
    {
        printf("%d", p->data);
        if (p->prev)
            printf(" <-> ");
    }
    printf("\n");
}

/* Reverse doubly linked list in place */
void reverseDoubly(Node **head_ref)
{
    if (!head_ref || !(*head_ref))
        return;
    Node *current = *head_ref;
    Node *temp = NULL;
    while (current)
    {
        /* swap prev and next */
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        /* move to next node in original order, which is current->prev after swap */
        current = current->prev;
    }
    /* temp now points to the old head's prev (i.e. new head->next) so set head */
    if (temp)
        *head_ref = temp->prev;
}

/* Example usage */
int main(void)
{
    Node *head = NULL;
    /* build example list: 1 <-> 2 <-> 3 <-> 4 <-> 5 */
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original list:\n");
    printForward(head);
    printBackward(head);

    reverseDoubly(&head);

    printf("\nAfter reversing in place:\n");
    printForward(head);
    printBackward(head);

    printf("\nPress any key to exit...\n");
    getch();
    return 0;
}