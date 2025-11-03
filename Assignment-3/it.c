#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee
{
    int id;
    char name[50];
    float salary;
    char department[20];
};

void increaseITSalary(struct Employee emp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(emp[i].department, "IT") == 0)
        {
            emp[i].salary *= 1.10f;
        }
    }
}

void displayEmployees(struct Employee emp[], int n)
{
    printf("\nEmployee Details:\n");
    printf("ID\tName\t\tSalary\t\tDepartment\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.2f\t\t%s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

int main()
{
    struct Employee emp[MAX_EMPLOYEES];
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        printf("Department: ");
        scanf("%s", emp[i].department);
    }

    increaseITSalary(emp, n);

    displayEmployees(emp, n);

    getch();
    return 0;
}