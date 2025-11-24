#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int val)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = val;
    n->next = NULL;
    return n;
}

/* Append value to end of list; returns new head (unchanged unless head was NULL) */
Node *append(Node *head, int val)
{
    Node *n = createNode(val);
    if (head == NULL)
        return n;
    Node *p = head;
    while (p->next)
        p = p->next;
    p->next = n;
    return head;
}

/* Check whether list is circular: traverse; if you hit NULL -> not circular;
    if you return to head -> circular. By convention, empty list (NULL) is considered circular here. */
int isCircular(Node *head)
{
    if (head == NULL)
        return 1; /* treat empty list as circular */
    Node *p = head->next;
    while (p != NULL && p != head)
        p = p->next;
    return (p == head);
}

/* Print a linear list (stops at NULL) */
void printListLinear(Node *head)
{
    Node *p = head;
    while (p)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

/* Print a circular list (stops when returns to head) */
void printListCircular(Node *head)
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }
    Node *p = head;
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != NULL && p != head);
    if (p == head)
        printf("(back to head)\n");
    else
        printf("NULL (broken circularity)\n");
}

int main(void)
{
    Node *head = NULL;

    /* Example 1: linear list */
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);

    printf("Example 1: linear list:\n");
    printListLinear(head);
    printf("Is circular? %s\n\n", isCircular(head) ? "Yes" : "No");

    /* Example 2: make the same list circular by linking last->next = head */
    Node *tail = head;
    while (tail->next)
        tail = tail->next;
    tail->next = head; /* create circular link */

    printf("Example 2: after making it circular (tail->next = head):\n");
    printListCircular(head);
    printf("Is circular? %s\n\n", isCircular(head) ? "Yes" : "No");

    /* Cleanup: Break the cycle and free list */
    tail->next = NULL;
    while (head)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }

    printf("Press any key to exit...\n");
    getch();
    return 0;
}