#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to find the longest common prefix
void longestCommonPrefix(char strs[][MAX_LENGTH], int n, char result[])
{
    if (n == 0)
    {
        result[0] = '\0';
        return;
    }
    int i, j;
    for (i = 0; strs[0][i]; i++)
    {
        char c = strs[0][i];
        for (j = 1; j < n; j++)
        {
            if (strs[j][i] != c || strs[j][i] == '\0')
            {
                result[i] = '\0';
                return;
            }
        }
        result[i] = c;
    }
    result[i] = '\0';
}

int main()
{
    int n, i;
    char strs[MAX_STRINGS][MAX_LENGTH];
    char result[MAX_LENGTH];

    printf("Enter number of strings: ");
    scanf("%d", &n);
    printf("Enter the strings:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", strs[i]);
    }

    longestCommonPrefix(strs, n, result);

    if (strlen(result) == 0)
        printf("No common prefix found.\n");
    else
        printf("Longest common prefix: %s\n", result);

    getch();
    return 0;
}