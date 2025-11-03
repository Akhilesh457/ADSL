// 10. Using realloc, write a program to increase the number of students in a dynamically allocated array of structures and input the new student details.

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n, new_n;
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    struct Student *s = (struct Student *)malloc(n * sizeof(struct Student));
    for(int i = 0; i < n; i++)
        scanf("%s %d", s[i].name, &s[i].marks);

    printf("Enter new total number of students: ");
    scanf("%d", &new_n);

    s = (struct Student *)realloc(s, new_n * sizeof(struct Student));
    for(int i = n; i < new_n; i++) {
        printf("Enter name and marks for student %d: ", i+1);
        scanf("%s %d", s[i].name, &s[i].marks);
    }

    printf("\nAll students:\n");
    for(int i = 0; i < new_n; i++)
        printf("%s %d\n", s[i].name, s[i].marks);

    free(s);
    return 0;
}
