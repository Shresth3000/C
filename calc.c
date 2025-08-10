#include<stdio.h>
int sum(int a,int b){
    return a+b;
}
int diff(int a,int b){
    return a-b;
}
int multi(int a,int b){
    return a*b;
}
int divi(int a,int b){
    return a/b;
}
void main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    int n;
    printf("Choose one Operation:\n 1. Sum\n 2. Difference \n 3. Product \n 4. Division\n");
    scanf("%d",&n);
    int res=0;
    if(n==1){
        res=sum(a,b);
        printf("Sum is %d",res);
    }
    else if(n==2){
        res=diff(a,b);
        printf("Difference is %d",res);
    }
     else if(n==3){
        res=multi(a,b);
        printf("Product is %d",res);
    }
     else if(n==4){
        res=divi(a,b);
        printf("Division is %d",res);
    }
    else{
        printf("Invalid choice");
    }
}