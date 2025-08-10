#include<stdio.h>
#include<stdlib.h>
void bubblesort(int a[],int n){
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1] ) {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }  for(int j=0;j<n;j++){
        printf("%d ",a[j]);
    }
}

int main(){
    int n;
    printf("ENter size of array 1: ");
    scanf("%d",&n);
   int a[n];
    printf("ENter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
  
   
    return 0;
}