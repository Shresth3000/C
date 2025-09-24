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
// insert at begin
struct node* atbegin(struct node*head,int m){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=m;
    temp->next=NULL;
    temp->prev=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
// insert at end
void atend(struct node*head,int m){
    struct node*temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=m;
    temp->next=NULL;
    temp->prev=NULL;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
}
// insert at pos
struct node* insertatpos(struct node*head,int m,int pos){
    struct node*p,*t,*ptr;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=m;
    p->next=NULL;
    p->prev=NULL;
    int cnt=1;
    t=head;
    ptr=t->next;
    while(cnt<pos-1 && t!=NULL){
        t=t->next;
        ptr=ptr->next;
        cnt++;
    }
    if(t==NULL){
        printf("Posn out of bound");
        return head;
    }
    ptr->prev=p;
    p->next=t->next;
    p->prev=t;
    t->next=p;
    return head;
}
// delete at front
struct node* deletefront(struct node*head){
    if(head==NULL){
       printf("Underflow");
       return head;
    }
    else if(head->next==NULL){
        struct node*temp;
        temp=head;
        head=NULL;
        free(temp);
        return head;
    }
    else{
        struct node*temp;
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    return head;
}
// delete at end
struct node* deleteend(struct node*head){
    if(head==NULL){
       printf("Underflow");
       return head;
    }
    else if(head->next==NULL){
        struct node*temp;
        temp=head;
        head=NULL;
        free(temp);
        return head;
    }
    else{
        struct node*temp,*ptr;
        ptr=head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        temp=ptr->next;
        temp->prev=NULL;
        ptr->next=NULL;
        free(temp);
    }
    return head;
}
// delete at position
struct node * deletepos(struct node*head,int pos){
    if(head==NULL){
       printf("Underflow");
       return head;
    }
    else if(head->next==NULL){
        struct node*temp;
        temp=head;
        head=NULL;
        free(temp);
    }
    else{
        struct node*temp,*ptr;
        int cnt=1;
        ptr=head;
        while(cnt<pos-1 && ptr!=NULL){
            ptr=ptr->next;
            cnt++;
        }
        if(ptr==NULL){
            printf("Position out of bound");
            return head;
        }
        struct node*ptr2;
        temp=ptr->next;
        ptr2=temp->next;
        ptr->next=ptr2;
        ptr2->prev=ptr;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
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
            case 2:display(head);
            break;
            case 3:printf("Enter data which you want to insert at front");
                   scanf("%d",&m);
                   head=atbegin(head,m);
            break;
            case 4:printf("Enter data which you want to insert at end");
                   scanf("%d",&m);
                   atend(head,m);
            break;
            case 5:printf("Enter data and postion which you want to insert");
                   scanf("%d %d",&m,&pos);
                   head=insertatpos(head,m,pos);
            break;
            case 6: head=deletefront(head);
            break;
            case 7: head=deleteend(head);
            break;
            case 8: printf("Enter position which you want to delete");
                    scanf("%d",&pos);
                    head=deletepos(head,pos);
            break;
        }
        printf("Do you want to continue operation-> y/n \n");
        scanf(" %c",&c);
    }while(c=='y');
}