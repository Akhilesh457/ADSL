#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 50

struct Book
{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
};

int main()
{
    struct Book books[MAX_BOOKS];
    int n, i;
    float min_price;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for book %d:\n", i + 1);
        printf("Title: ");
        fflush(stdin);
        gets(books[i].title);
        printf("Author: ");
        gets(books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    printf("\nEnter minimum price to filter: ");
    scanf("%f", &min_price);

    printf("\nBooks with price above %.2f:\n", min_price);
    for (i = 0; i < n; i++)
    {
        if (books[i].price > min_price)
        {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n\n", books[i].price);
        }
    }

    getch();
    return 0;
}