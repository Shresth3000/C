#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};

struct node* create(struct node*head){

    struct node*new,*t;
    new=NULL;
    t=NULL;
    char ch;
    do{
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter a node data->");
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL){
            head=new;
            new->prev=NULL;
            t=new;
        }
        else{
            t->next=new;
            new->prev=t;
            t=new;
        }
        printf("Do you want to add another node");
        scanf(" %c",&ch);
    }while(ch=='y');
    return head;
}
void display(struct node*head){
    struct node*p;
    p=head;
    printf("NULL");
    while(p!=NULL){
        printf("<-%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
struct node* insertatpos(struct node*head,int m,int pos){
 int c=1;
 struct node*p,*t,*ptr=head;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=m;
    while(c<pos-1){
        ptr=ptr->next;
        c++;
    }
    p->prev=ptr;
    p->next=ptr->next;
    ptr->next->prev=p;
    ptr->next=p;

return head;
}
int main(){
    struct node*head;
    head=NULL;
    char c;
    int m,pos;
    do{ 
        int n;
        printf("Enter which operation you want to perform->");
        scanf("%d",&n);
        switch(n){
            case 1:head=create(head);
            break;
            /*case 2:display(head);
            break;
            case 3:printf("Enter data which you want to insert at front");
                   scanf("%d",&m);
                   head=atbegin(head,m);
            break;
            case 4:printf("Enter data which you want to insert at end");
                   scanf("%d",&m);
                   atend(head,m);
            break;*/
            case 5:printf("Enter data and postion which you want to insert");
                   scanf("%d %d",&m,&pos);
                   head=insertatpos(head,m,pos);
                   display(head);
            break;/*            case 6: head=deletefront(head);
            break;
            case 7: head=deleteend(head);
            break;
            case 8: printf("Enter position which you want to delete");
                    scanf("%d",&pos);
                    head=deletepos(head,pos);
            break;*/
        }
        printf("Do you want to continue operation-> y/n \n");
        scanf(" %c",&c);
    }while(c=='y');
}