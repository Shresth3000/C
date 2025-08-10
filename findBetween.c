#include<stdio.h>
#include<stdlib.h> 
void printbetween(int *ptr,int n,int low,int high){
    int c=0;
for(int i=0;i<n;i++){
    if(*(ptr+i)>=low && *(ptr+i)<=high){
        printf("%d,",*(ptr+i));
        c++;
    }
}printf("number of elements are %d",c);
}
void main(){
    int n,low,high;
    printf("Enter array size: ");
    scanf("%d",&n);
    int *ptr= (int *)malloc(n*(sizeof(int)));
    printf("Enter array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    printf("Enter lower bound and upper bound: ");
    scanf("%d %d",&low,&high);
    printbetween(ptr,n,low,high);
    free(ptr);
}