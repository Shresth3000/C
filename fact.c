#include<stdio.h>
long long fact(int n){
if(n==1) return 1;
else return n*fact(n-1);
}
void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    long long f=fact(n);
    printf("Factorial is : %ld",f);
}