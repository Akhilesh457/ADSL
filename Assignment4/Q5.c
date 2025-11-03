// 5. Write a C program to find the highest marks among n students using a structure array.

#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];
    for(int i = 0; i < n; i++) {
        printf("Enter name and marks of student %d: ", i+1);
        scanf("%s %d", s[i].name, &s[i].marks);
    }

    struct Student top = s[0];
    for(int i = 1; i < n; i++) {
        if(s[i].marks > top.marks) top = s[i];
    }

    printf("\nHighest Marks:\n%s with %d marks\n", top.name, top.marks);

    return 0;
}
