#include<stdio.h>
void delete(int a[],int n,int pos){
    int last=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            last++;
        }
    }
    if(last==0){
        printf("Underflow\n");
    }    
for(int i=pos;i<last;i++){
a[i]=a[i+1];
}
a[last-1];
 for(int i=0;i<last-1;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n,pos;
    printf("ENter size of array 1: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=0;
    }
    printf("ENter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }   
    printf("Enter position(index) to delete: ");
    scanf("%d",&pos);
    delete(a,n,pos);   
 return 0;
}