#include<stdio.h>
void reversearr(int a[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    } 
    for(int j=0;j<n;j++){
        printf("%d ",a[j]);
    }
}
int main(){
    int n;
    printf("Enter size of array 1: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    reversearr(a,n);
    return 0;
}