/*2. Write a program to store and display information of n employees using an array of
structures.*/

#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for(int i = 0; i < n; i++) {
        printf("Enter ID, Name, Salary for employee %d: ", i+1);
        scanf("%d %s %f", &emp[i].id, emp[i].name, &emp[i].salary);
    }

    printf("\nEmployee Details:\n");
    for(int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }

    return 0;
}
