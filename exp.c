#include<stdio.h>
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
void poly_add(int arr1[],int arr2[],int n,int m){
    int size;
    size=(n>m)?n:m;
    int arr3[size];
    if(n>m){
        for(int i=0;i<=size;i++){
            arr3[i]=arr1[i];
        }
        for(int i=0;i<=m;i++){
            arr3[i]+=arr2[i];
        }
    }
    else{
        for(int i=0;i<=size;i++){
            arr3[i]=arr2[i];
        }
        for(int i=0;i<=n;i++){
            arr3[i]+=arr1[i];
        }
    }
    printf("Polynomial 1: ");
    printpoly(arr1, n);
    printf("Polynomial 2: ");
    printpoly(arr2, m);
    printf("Sum: ");
    printpoly(arr3, size);
}
int main(){
    int n,m;
    printf("Enter the max deg of both polynomial\n");
    scanf("%d %d",&n,&m);
    int arr1[n+1];
    int arr2[m+1];
    printf("1st polynomail coeff\n");
    for(int i=0;i<=n;i++){
        printf("Coeff of x^%d\n",i);
        scanf("%d",&arr1[i]);
    }
    printf("2nd polynomial coeff\n");
    for(int i=0;i<=m;i++){
        printf("Coeff of x^%d\n",i);
        scanf("%d",&arr2[i]);
    }
    poly_add(arr1,arr2,n,m);
}