#include <stdio.h>
void insert(int a[], int n, int pos, int key)
{
    int last=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            last++;
        }
    }if(last==n-1){
        printf("Overflow\n");
        return;
    }
    a[n + 1];
    for (int i = last+1; i > pos; i--)
    {
        a[i]=a[i-1];
    }
    a[pos] = key;
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int n, key, pos;
    printf("Enter number of elements to enter: ");
    scanf("%d", &n);
    int a[100];
    printf("Enter array: ");
    for (int i = 0; i < n+1; i++)
    {
        a[i]=0;
        }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter position(index): ");
    scanf("%d", &pos);
    printf("Enter Value: ");
    scanf("%d", &key);
    insert(a, n, pos, key);
    return 0;
}