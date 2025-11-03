/*7. Write a program to merge two sorted linked lists into one sorted linked list.*/
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

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* merged = NULL; // head of merged list
    struct Node* temp = NULL;

    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // Initialize merged head
    if (list1->data <= list2->data) {
        merged = list1;
        list1 = list1->next;
    } else {
        merged = list2;
        list2 = list2->next;
    }

    temp = merged;

    // Merge remaining nodes
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // Attach remaining nodes
    if (list1 != NULL) temp->next = list1;
    if (list2 != NULL) temp->next = list2;

    return merged;
}

int main() {
    struct Node* list1 = createNode(3);
    list1->next = createNode(4);
    list1->next->next = createNode(15);

    struct Node* list2 = createNode(2);
    list2->next = createNode(7);
    list2->next->next = createNode(66);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("\nMerged Sorted List: ");
    displayList(mergedList);

    return 0;
}
