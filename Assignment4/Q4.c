// 4. Can a struct contain a pointer to itself? Give an example.

#include <stdio.h>

struct Node {
    int data;
    struct Node *next; // Pointer to itself
};

int main() {
    struct Node n1, n2;
    n1.data = 10;
    n2.data = 20;
    n1.next = &n2;
    n2.next = NULL;

    printf("Node1: %d, Node2: %d\n", n1.data, n1.next->data);

    return 0;
}