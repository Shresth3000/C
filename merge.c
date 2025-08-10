#include<stdio.h>
#include<stdlib.h>
void merge(int *ptr1,int *ptr2,int n,int m){
    int i=0,j=0,k=0;
    int *ptr3=(int *)malloc((n+m)*(sizeof(int)));
    while(i<n && j<m){
        if(*(ptr1+i)<*(ptr2+j)){
           *(ptr3+k)=*(ptr1+i);
           i++;
           k++;
        }
        else{
            *(ptr3+k)=*(ptr2+j);
            k++;
            j++;
        }
    }
    while(i<n){
        *(ptr3+k)=*(ptr1+i);
           i++;
           k++;

    }
    while(j<m){
        *(ptr3+k)=*(ptr2+j);
            k++;
            j++;

    }
    for(int x=0;x<m+n;x++){
        printf("%d ",*(ptr3+x));
    }
    free(ptr3);


}
int main(){
    int n,m;
    printf("ENter size of array 1: ");
    scanf("%d",&n);
    int *ptr1=(int *)malloc(n*(sizeof(int)));
    printf("ENter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr1+i));
    }
    printf("ENter size of array 2: ");
    scanf("%d",&m);
     int *ptr2=(int *)malloc(m*(sizeof(int)));
    printf("ENter array: ");
    for(int i=0;i<m;i++){
        scanf("%d",(ptr2+i));
    }
    merge(ptr1,ptr2,n,m);
    free(ptr1);
    free(ptr2);
    return 0;
}