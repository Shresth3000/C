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
int find(int *ptr,int t,int n){
    for(int i=0;i<n;i++){
        if(*(ptr+i)==t){
            return i;
        }
    }return -1;
}
int even(int *ptr,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(*(ptr+i)%2==0){
            c++;
        }
    }return c;
}
int odd(int *ptr,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(*(ptr+i)%2!=0){
            c++;
        }
    }return c;
}

void main(){
    int n,ch,target;
    printf("Enter array size: ");
    scanf("%d",&n);
    int *ptr= (int *)malloc(n*(sizeof(int)));
    printf("Enter array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }
    printf("1. Find min and max\n2. Find index of target\n3. Find number of even and odd in array\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
       switch (ch) {
        case 1:
            printf("Minimum is %d and maximum is %d\n", mini(ptr, n), maxim(ptr, n));
            break;
        case 2:
            printf("Enter target: ");
            scanf("%d", &target);
            printf("Index = %d\n", find(ptr, target, n));
            break;
        case 3:
            printf("Number of Even is %d and No. of odd is %d\n", even(ptr, n), odd(ptr, n));
            break;
        default:
            printf("Invalid choice\n");
    }
    free(ptr);
}

