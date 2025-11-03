#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Student
{
    char name[50];
    int rollNumber;
    float marks;
};

int main()
{
    int n, i, highestIndex = 0;
    struct Student students[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        fflush(stdin);
        gets(students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    for (i = 1; i < n; i++)
    {
        if (students[i].marks > students[highestIndex].marks)
        {
            highestIndex = i;
        }
    }

    printf("\nStudent with highest marks:\n");
    printf("Name: %s\n", students[highestIndex].name);
    printf("Roll Number: %d\n", students[highestIndex].rollNumber);
    printf("Marks: %.2f\n", students[highestIndex].marks);

    getch();
    return 0;
}