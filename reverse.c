#include<stdio.h>
#include<stdlib.h>
int * reversearr(int *ptr,int n){
    int i=0;
    int j=n-1;
    while(i<j){
        int temp=*(ptr+i);
        *(ptr+i)=*(ptr+j);
        *(ptr+j)=temp;
        i++;
        j--;
    }   
    return ptr;
}

int main(){
    int n;
    printf("Enter size of array 1: ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*(sizeof(int)));
    printf("Enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    int *ptr2=reversearr(ptr,n);
    for(int j=0;j<n;j++){
        printf("%d ",*(ptr2+j));
    }
    free(ptr);
    return 0;
}