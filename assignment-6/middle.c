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
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->data = value;
    n->prev = n->next = NULL;
    return n;
}

/* Append node at end of doubly linked list */
void append(Node **head_ref, int value)
{
    Node *new_node = createNode(value);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    Node *cur = *head_ref;
    while (cur->next)
        cur = cur->next;
    cur->next = new_node;
    new_node->prev = cur;
}

/* Print list forward */
void printList(Node *head)
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

/* Return length of doubly linked list */
int getLength(Node *head)
{
    int count = 0;
    Node *cur = head;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

/* Find middle node using slow-fast pointers.
    For even number of nodes this returns the second middle node.
*/
Node *findMiddle(Node *head)
{
    if (!head)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/* Free list */
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

int main(void)
{
    Node *head = NULL;

    /* Example 1: odd number of nodes */
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printf("Doubly linked list (odd count):\n");
    printList(head);
    printf("Length: %d\n", getLength(head));
    Node *mid = findMiddle(head);
    if (mid)
        printf("Middle node data: %d\n\n", mid->data);

    freeList(head);
    head = NULL;

    /* Example 2: even number of nodes */
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Doubly linked list (even count):\n");
    printList(head);
    printf("Length: %d\n", getLength(head));
    mid = findMiddle(head);
    if (mid)
        printf("Middle node data (second middle in even case): %d\n", mid->data);

    freeList(head);

    printf("\nPress any key to exit...");
    getch();
    return 0;
}