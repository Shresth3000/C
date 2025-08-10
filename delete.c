#include<stdio.h>
#include<stdlib.h>
void delete(int *ptr,int n,int pos){
    
for(int i=pos;i<n-1;i++){
int temp=*(ptr+i);
*(ptr+i)=*(ptr+i+1);
*(ptr+i+1)=temp;
}
ptr=(int*)realloc(ptr,(n-1)*sizeof(int));
 for(int i=0;i<n-1;i++){
        printf("%d ",*(ptr+i));
    }
}
int main(){
    int n,pos;
    printf("ENter size of array 1: ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*(sizeof(int)));
    printf("ENter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
   
    printf("Enter position(index) to delete: ");
    scanf("%d",&pos);
    delete(ptr,n,pos);
    free(ptr);
 return 0;

}