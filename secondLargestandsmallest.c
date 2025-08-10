#include<stdio.h>
#include<stdlib.h>
int mini(int *ptr,int n){
    int ans=*ptr;
    for(int i=1;i<n;i++){
        if(*(ptr+i)<ans){
            ans=(*(ptr+i));
        }
    }return ans;
}
int maxim(int *ptr,int n){
    int ans=*ptr;
    for(int i=1;i<n;i++){
        if(*(ptr+i)>ans){
            ans=(*(ptr+i));
        }
    }return ans;
}
int secondMax(int *ptr,int n,int max1){
    int smax=*(ptr+1);
    for(int i=0;i<n;i++){
        if(*(ptr+i)!=max1 && smax<*(ptr+i)){
            smax=*(ptr+i);
        }
    }return smax;
}
int secondMin(int *ptr,int n,int min1){
    int smin=*(ptr+1);
    for(int i=0;i<n;i++){
        if(*(ptr+i)!=min1 && smin>*(ptr+i)){
            smin=*(ptr+i);
        }
    }return smin;
}
void main(){
    int n,max1,smax,min1,smin;
    printf("Enter array size: ");
    scanf("%d",&n);
    int *ptr= (int *)malloc(n*(sizeof(int)));
    printf("Enter array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
   
    max1=maxim(ptr,n);
    min1=mini(ptr,n);
    smin=secondMin(ptr,n,min1);
     smax=secondMax(ptr,n,max1);
printf("Second max is: %d and Second min is %d \n",smax,smin);
}