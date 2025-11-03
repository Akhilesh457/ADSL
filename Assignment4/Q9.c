// 9. Write a program to dynamically allocate memory for a 2D array inside a structure and store integers in it.

#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int **arr;
};

int main() {
    struct Matrix m;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m.rows, &m.cols);

    m.arr = (int **)malloc(m.rows * sizeof(int *));
    for(int i = 0; i < m.rows; i++)
        m.arr[i] = (int *)malloc(m.cols * sizeof(int));

    printf("Enter elements:\n");
    for(int i = 0; i < m.rows; i++)
        for(int j = 0; j < m.cols; j++)
            scanf("%d", &m.arr[i][j]);

    printf("Matrix:\n");
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++)
            printf("%d ", m.arr[i][j]);
        printf("\n");
    }

    for(int i = 0; i < m.rows; i++)
        free(m.arr[i]);
    free(m.arr);

    return 0;
}
