#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void search(struct node*head,int key){
    int flag=0;
    struct node *ptr=head;
    while(ptr!=NULL){
        if(key==ptr->data){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
struct node* create(struct node* head){
    struct node *t=NULL;
    struct node *new=NULL;
    char c;
    do{
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter node");
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
        printf("Do you want to add another node y/n\n");
        scanf(" %c",&c);
    }while(c=='y');
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
int main(){
    struct node*head;
    head=NULL;
    head=create(head);
    int key;
    printf("Enter no to be check present or not\n");
    scanf("%d",&key);
    search(head,key);
    display(head);
}