#include <stdio.h>
#include <conio.h>

struct Date
{
    int day;
    int month;
    int year;
};

int compareDates(struct Date d1, struct Date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;
    else
    {
        if (d1.month < d2.month)
            return -1;
        else if (d1.month > d2.month)
            return 1;
        else
        {
            if (d1.day < d2.day)
                return -1;
            else if (d1.day > d2.day)
                return 1;
            else
                return 0;
        }
    }
}

int main()
{
    struct Date date1, date2;

    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    int result = compareDates(date1, date2);

    if (result == -1)
        printf("First date is earlier.\n");
    else if (result == 1)
        printf("Second date is earlier.\n");
    else
        printf("Both dates are the same.\n");

    getch();
    return 0;
}