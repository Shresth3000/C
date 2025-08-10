#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *ptr, int n) {
    for(int i = 0; i < n - 1; i++) {
        
        int swapped = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(*(ptr+j) > *(ptr+j+1) ) {
                int temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
                swapped = 1;
            }
        }
        if(!swapped) break; 
    }
}
int mini(int *ptr,int n){
   for (int i=1;i<n;i++){
    if(*(ptr+i)!=*ptr) return *(ptr+i);
}
    return -1;
}
int maxi(int *ptr,int n){
   for (int i=n-2;i>=0;i--){
    if(*(ptr+n-1)!=*(ptr+i)) return *(ptr+i);
}
    return -1;
}
void main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int *ptr= (int *)malloc(n*(sizeof(int)));
     if(n==0) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    bubbleSort(ptr,n);
    int smax = maxi(ptr, n);
    int smin = mini(ptr, n);
    printf("Second max is %d and second min in %d\n",smax,smin);
    free(ptr);  
}