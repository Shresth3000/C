#include <stdio.h>
void merge(int a[], int b[], int n, int m)
{
    int i = 0, j = 0, k = 0;
    int c[n + m];
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        k++;
        j++;
    }
    for (int x = 0; x < m + n; x++)
    {
        printf("%d ", c[x]);
    }
}
int main()
{
    int n, m;
    printf("ENter size of array 1: ");
    scanf("%d", &n);
    int a[n];
    printf("ENter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("ENter size of array 2: ");
    scanf("%d", &m);
    int b[m];
    printf("ENter array: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    merge(a, b, n, m);
    return 0;
}