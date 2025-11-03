// 3. Explain how nested structures work. Write a program where a struct for date is nested inside a struct for student.

#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char name[50];
    int roll;
    struct Date dob;
};

int main() {
    struct Student s;

    printf("Enter name and roll number: ");
    scanf("%s %d", s.name, &s.roll);

    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &s.dob.day, &s.dob.month, &s.dob.year);

    printf("\nStudent Details:\n");
    printf("Name: %s\nRoll: %d\nDOB: %d-%d-%d\n", s.name, s.roll, s.dob.day, s.dob.month, s.dob.year);

    return 0;
}
