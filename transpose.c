#include <stdio.h>
void transpose(int r,int c,int a[r][c]){
    int b[c][r];
for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
           b[i][j]=a[j][i]; 
        }
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
          printf("%d ",b[i][j]);
        }printf("\n");
    }
}
void main()
{
    int r, c;
    printf("Enter no. of rows and columns: ");
    scanf("%d %d",&r,&c);
    int a[r][c];
    printf("Enter Matrix : \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            
            scanf("%d", &a[i][j]);
        }
    }
      transpose(r,c,a);
}