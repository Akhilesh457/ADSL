#include <stdio.h>
#include <conio.h>

void findTwoSum(int nums[], int n, int target, int *index1, int *index2)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                *index1 = i;
                *index2 = j;
                return;
            }
        }
    }
}

int main()
{
    int nums[100], n, target, idx1 = -1, idx2 = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    findTwoSum(nums, n, target, &idx1, &idx2);

    if (idx1 != -1 && idx2 != -1)
    {
        printf("Indices: %d and %d\n", idx1, idx2);
        printf("Numbers: %d and %d\n", nums[idx1], nums[idx2]);
    }
    else
    {
        printf("No solution found.\n");
    }

    getch();
    return 0;
}