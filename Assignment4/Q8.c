// 8. Explain how calloc differs from malloc while allocating memory for an array of structures.

// calloc initializes the allocated memory to zero, while malloc leaves it uninitialized.

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n = 3;
    struct Student *s1 = (struct Student *)malloc(n * sizeof(struct Student)); // uninitialized
    struct Student *s2 = (struct Student *)calloc(n, sizeof(struct Student)); // initialized to 0

    printf("malloc first student's marks: %d (may be garbage)\n", s1[0].marks);
    printf("calloc first student's marks: %d (initialized to 0)\n", s2[0].marks);

    free(s1);
    free(s2);
    return 0;
}
