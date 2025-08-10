#include <stdio.h>
void matrixmulti(int r1,int c1,int r2,int c2,int a[r1][c1],int b[r2][c2]){
    int c[r1][c2];
    for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                c[i][j] = 0;
            }
        }
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < c1; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
void main()
{
    int r1, c1, r2, c2;
    printf("Enter no. of rows and columns for matrix 1: ");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    printf("Enter matrix: \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {

            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter no. of rows and columns for matrix 2: ");
    scanf("%d %d", &r2, &c2);
    int b[r2][c2];
    if (c1 != r2)
    {
        printf("Not possible\n");
    }
    else
    {
        printf("Enter matrix: \n");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
         matrixmulti(r1,c1,r2,c2,a,b);
    }
}