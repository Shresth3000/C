#include<stdio.h>
struct distance {
    int kilometer;
    int meter;
};
int main(){
    struct distance d1,d2,d3;
    struct distance *ptr1=&d1;
    struct distance *ptr2=&d2;
    struct distance *ptr3=&d3;
    printf("Enter distance 1: ");
    scanf("%d %d",&ptr1->kilometer,&ptr1->meter);
    printf("Enter distance 2: ");
    scanf("%d %d",&ptr2->kilometer,&ptr2->meter);
    ptr3->kilometer= (ptr1->kilometer)+(ptr2->kilometer)+(ptr1->meter+ptr2->meter)/1000;
    ptr3->meter=(ptr1->meter+ptr2->meter)%1000;
    printf("%d Km %d m\n",ptr3->kilometer,ptr3->meter);
    return 0;
    
}