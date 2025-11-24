#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end of circular linked list
void insert(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Function to split the circular linked list
void splitList(struct Node *head, struct Node **head1, struct Node **head2)
{
    struct Node *slow_ptr = head, *fast_ptr = head;

    if (head == NULL)
        return;

    // Find the middle of the list using slow and fast pointer approach
    while (fast_ptr->next != head && fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    // If list has even elements
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    // Set the head of first half
    *head1 = head;

    // Set the head of second half
    if (head->next != head)
        *head2 = slow_ptr->next;

    // Make first half circular
    fast_ptr->next = slow_ptr->next;

    // Make second half circular
    slow_ptr->next = head;
}

// Function to display the circular linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    // Insert some elements
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original Circular Linked List: ");
    displayList(head);

    // Split the list
    splitList(head, &head1, &head2);

    printf("First Half: ");
    displayList(head1);

    printf("Second Half: ");
    displayList(head2);

    getch();
    return 0;
}