#include<stdio.h>
struct node{
    int data;
    struct node* next;
};
int main(){
    struct node* head=NULL;
    struct node ptr1,ptr2,ptr3;
    printf("Enter 1st node data: ");
    scanf("%d",&ptr1.data);
    printf("Enter 2nd node data: ");
    scanf("%d",&ptr2.data);
    printf("Enter 3rd node data: ");
    scanf("%d",&ptr3.data);
    ptr1.next=&ptr2;
    ptr2.next=&ptr3;
    ptr3.next=NULL;
    printf("%d->",ptr1.data);
    printf("%d->",ptr2.data);
    printf("%d",ptr3.data);
    return 0;
}