#include <stdio.h>
#include <conio.h>

int containsDuplicate(int nums[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] == nums[j])
            {
                return 1; // true
            }
        }
    }
    return 0; // false
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    if (containsDuplicate(nums, n))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    getch();
    return 0;
}