#include<stdio.h>
#include<stdlib.h>
int maximfreq(int *ptr,int n){
    int ans=*ptr,c=1;
    for(int i=1;i<n;i++){
        if(*(ptr+i)>ans){
            ans=(*(ptr+i));
            c=1;
        }else if(*(ptr+i)==ans){
            c++;
        }

    }
    printf("Largest number is: %d\n",ans);
    return c;
}
void main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int *ptr= (int *)malloc(n*(sizeof(int)));
    printf("Enter array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    int freq=maximfreq(ptr,n);
    printf("Frequency of Largest number is: %d",freq);
    free(ptr);
}