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
void polyadd(int p1[],int p2[],int n,int m){
int size;
size=n>m?n:m;
int p3[size+1];
for(int i=0;i<size+1;i++){
    p3[i]=0;
}
for (int i = 0; i <= size; i++) {
    int val1 = (i <= n) ? p1[i] : 0;
    int val2 = (i <= m) ? p2[i] : 0;
    p3[i] = val1 + val2;
}
printf("Polynomial 1: ");
printpoly(p1,n);
printf("Polynomial 2: ");
printpoly(p2,m);
printf("Polynomial 3: ");
printpoly(p3,size);
}
int main() {
    int n,m;
    printf("Enter the highest power of poly 1: ");
    scanf("%d", &n);
    int coeff1[n + 1];
    for (int i = n; i >= 0; i--) {
        printf("Enter coefficient of term with power %d (if no term then enter 0): ", i);
        scanf("%d", &coeff1[i]);
    }
    printf("Enter the highest power of poly 2: ");
    scanf("%d", &m);
    int coeff2[m + 1];
    for (int i = m; i >= 0; i--) {
        printf("Enter coefficient of term with power %d (if no term then enter 0): ", i);
        scanf("%d", &coeff2[i]);
    }
    polyadd(coeff1,coeff2,n,m); 
    return 0;
}
