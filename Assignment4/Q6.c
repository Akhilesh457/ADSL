// 6. How can you compare two structures in C? Illustrate with an example comparing two student structures.

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    struct Student s1 = {"Alice", 80};
    struct Student s2 = {"Bob", 90};

    if(strcmp(s1.name, s2.name) == 0 && s1.marks == s2.marks)
        printf("Students are equal\n");
    else
        printf("Students are not equal\n");

    return 0;
}