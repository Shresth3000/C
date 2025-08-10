#include <stdio.h>
void printpoly(int a[],int n){
    for(int i=n;i>=0;i--){
        if(a[i]==0){
            continue;
        }
        if(i!=n && a[i]>0){
            printf("+");
        }
        if(i==0){
            printf("%d",a[i]);
        }
        else if(i==1){
            printf("%dx",a[i]);
        }
        else{
            printf("%dx^%d",a[i],i);
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the highest power: ");
    scanf("%d", &n);
    int coeff[n + 1];
    for (int i = n; i >= 0; i--) {
        printf("Enter coefficient of term with power %d (if no term then enter 0): ", i);
        scanf("%d", &coeff[i]);
    }
    printpoly(coeff,n);
    return 0;
}
