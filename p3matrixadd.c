#include <stdio.h>
void matrixadd(int row,int col,int a[row][col],int b[row][col]){
    int c[row][col];
    for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                c[i][j] = 0;
            }
        }
        for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Matrix result: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int row, col;
    printf("Enter no. of rows: ");
    scanf("%d", &row);
    printf("Enter no. of columns: ");
    scanf("%d", &col);
    int a[row][col], b[row][col];
    printf("Matrix 1: \n");
   for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            scanf("%d", &a[i][j]);
        }
    }
    printf("Matrix 2: \n");
     for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        
    matrixadd(row,col,a,b);
    
}