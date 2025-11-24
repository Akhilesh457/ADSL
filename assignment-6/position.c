#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

/* Create a new node */
Node *createNode(int value)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = value;
    n->prev = n->next = NULL;
    return n;
}

/* Append node at the end */
void append(Node **headRef, int value)
{
    Node *newn = createNode(value);
    if (*headRef == NULL)
    {
        *headRef = newn;
        return;
    }
    Node *cur = *headRef;
    while (cur->next)
        cur = cur->next;
    cur->next = newn;
    newn->prev = cur;
}

/* Insert a new node with value at 1-based position pos.
   If pos is 1, inserts at head. If pos is length+1, inserts at tail.
   Returns 1 on success, 0 on invalid position. */
int insertAtPosition(Node **headRef, int value, int pos)
{
    if (pos <= 0)
        return 0;
    Node *newn = createNode(value);

    if (pos == 1)
    {
        newn->next = *headRef;
        if (*headRef)
            (*headRef)->prev = newn;
        *headRef = newn;
        return 1;
    }

    Node *cur = *headRef;
    int idx = 1;
    while (cur && idx < pos - 1)
    {
        cur = cur->next;
        idx++;
    }
    if (!cur)
    {
        free(newn);
        return 0; /* position out of bounds */
    }

    /* insert after cur */
    newn->next = cur->next;
    newn->prev = cur;
    if (cur->next)
        cur->next->prev = newn;
    cur->next = newn;
    return 1;
}

/* Display list forward using "->" to show links between nodes */
void displayForward(Node *head)
{
    Node *cur = head;
    while (cur)
    {
        printf("%d", cur->data);
        if (cur->next)
            printf(" <-> ");
        cur = cur->next;
    }
    printf("\n");
}

/* Free whole list */
void freeList(Node *head)
{
    Node *cur = head;
    while (cur)
    {
        Node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

int main()
{
    Node *head = NULL;

    /* Example list: 10 -> 20 -> 30 */
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("Initial list:\n");
    displayForward(head);

    printf("\nInsert 5 at position 1 (head):\n");
    if (insertAtPosition(&head, 5, 1))
        displayForward(head);
    else
        printf("Invalid position\n");

    printf("\nInsert 25 at position 4 (between 20 and 30):\n");
    if (insertAtPosition(&head, 25, 4))
        displayForward(head);
    else
        printf("Invalid position\n");

    printf("\nInsert 40 at position 6 (tail append):\n");
    if (insertAtPosition(&head, 40, 6))
        displayForward(head);
    else
        printf("Invalid position\n");

    printf("\nTry insert 999 at invalid position 10:\n");
    if (insertAtPosition(&head, 999, 10))
        displayForward(head);
    else
        printf("Invalid position (10)\n");

    freeList(head);
    printf("\nDone. Press any key to exit...\n");
    getch();
    return 0;
}