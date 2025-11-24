#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (!node)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = node; /* self-loop for single-node circular list */
    return node;
}

/* Insert a new node with value 'data' after 'prev_node' in a circular list */
void insertAfter(struct Node *prev_node, int data)
{
    if (prev_node == NULL)
    {
        printf("Error: given node is NULL\n");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/* Print circular list starting from head once around */
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *p = head;
    do
    {
        printf("%d", p->data);
        printf("-> ");
        p = p->next;
    } while (p != head);
    printf("\n");
}

int main(void)
{
    /* Create a circular list with three nodes: 10 -> 20 -> 30 -> back to 10 */
    struct Node *n1 = createNode(10);
    struct Node *n2 = createNode(20);
    struct Node *n3 = createNode(30);

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    struct Node *head = n1;

    printf("Original circular list:\n");
    printList(head);

    /* Insert 25 after node n2 (after value 20) */
    insertAfter(n2, 25);

    printf("After inserting 25 after node with value 20:\n");
    printList(head);

    /* Insert 5 after head (after 10) */
    insertAfter(head, 5);
    printf("After inserting 5 after head (10):\n");
    printList(head);

    printf("Press any key to exit...\n");
    getch();
    return 0;
}
