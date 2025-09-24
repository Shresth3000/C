#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(struct node*head){
    struct node *new,*t;
    new=NULL;
    t=NULL;
    char ch;
    do{
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data");
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL){
            head=new;
            t=new;
        }
        else{
            t->next=new;
            t=new;
        }
        printf("Do you want to add new node ->y/n\n");
        scanf(" %c",&ch);
    }while(ch=='y');
    return head;
}
void display(struct node*head){
    struct node*p;
    p=head;
    while(p!=NULL){
        printf("%d ->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
struct node* sortll(struct node*head){
    struct node*ptr1,*ptr2,*tail;
    ptr1=head;
    ptr2=head;
    int temp;
    tail=NULL;
    while(tail!=head){
        ptr1=head;
        ptr2=ptr1->next;
        while(ptr2!=tail){
            if(ptr1->data>ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        tail=ptr1;
    }
    return head;
}
struct node* merge(struct node*head1,struct node*head2){
    struct node *head=NULL;
    struct node*new,*temp,*ptr1,*ptr2;
    int value;
    ptr1=head1;
    temp=head;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        new=(struct node*)malloc(sizeof(struct node));
        new->next=NULL;
        if(ptr1->data<ptr2->data){
            value=ptr1->data;
            ptr1=ptr1->next;
        }
        else{
            value=ptr2->data;
            ptr2=ptr2->next;
        }
        new->data=value;
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
    }
    while(ptr1!=NULL){
        new=(struct node*)malloc(sizeof(struct node));
        new->data=ptr1->data;
        new->next=NULL;
        temp->next=new;
        temp=new;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        new=(struct node*)malloc(sizeof(struct node));
        new->data=ptr2->data;
        new->next=NULL;
        temp->next=new;
        temp=new;
        ptr2=ptr2->next;
    }
    return head;
}
int main(){
    struct node*head=NULL;
    struct node*head1,*head2;
    head1=NULL;
    head2=NULL;
    char c;
    do{
        int n;
        printf("Enter operation ->");
        scanf("%d",&n);
        switch(n){
            case 1: head=create(head);
            break;
            case 2: display(head);
            break;
            case 3: head=sortll(head);
            break;
            case 4:printf("Enter 1st sorted LL");
                   head1=create(head1);
                   printf("Enter 2nd sorted LL");
                   head2=create(head2);
                   head=merge(head1,head2);
        }
        printf("Do you want to continue operations->y/n\n");
        scanf(" %c",&c);
    }while(c=='y');
}