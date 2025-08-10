#include<stdio.h>
#include<stdlib.h>
void insert(int *ptr,int n,int pos,int key){
    ptr=(int *)realloc(ptr,(n+1)*(sizeof(int)));
for(int i=n;i>pos;i--){
int temp=*(ptr+i);
*(ptr+i)=*(ptr+i-1);
*(ptr+i-1)=temp;
}
*(ptr+pos)=key;
 for(int i=0;i<=n;i++){
        printf("%d ",*(ptr+i));
    }
}
int main(){
    int n,pos,key;
    printf("ENter size of array 1: ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*(sizeof(int)));
    printf("ENter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
   
    printf("Enter position(index): ");
    scanf("%d",&pos);
    printf("Enter Value: ");
    scanf("%d",&key);
    insert(ptr,n,pos,key);
    free(ptr);
 return 0;

}