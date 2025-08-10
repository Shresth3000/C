#include<stdio.h>
#include<stdlib.h>
int * bubblesort(int *ptr,int n){
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(*(ptr+j) > *(ptr+j+1) ) {
                int temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
            }
        }
    }return ptr;
}

int main(){
    int n;
    printf("ENter size of array 1: ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*(sizeof(int)));
    printf("ENter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    int *ptr2=bubblesort(ptr,n);
    for(int j=0;j<n;j++){
        printf("%d ",*(ptr2+j));
    }
    free(ptr);
    return 0;
}