#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void display(struct node*head){
    struct node*p;
    p=head;
    while(p!=NULL){
        printf("%d ->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
struct node* create(struct node*head){
    struct node *new,*t;
    new=NULL;
    t=NULL;
    char c;
    do{
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data->");
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
        printf("Do you want to link another node -> y/n\n");
        scanf(" %c",&c);
    }while(c=='y');
    return head;
}
// insert at begining
struct node* atbegin(struct node*head,int key){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=key;
    p->next=NULL;
    p->next=head;
    head=p;
    return head;
}
//insert at end
void atend(struct node*head,int key){
    struct node*p,*t;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=key;
    p->next=NULL;
    t=head;
    while(t->next != NULL){
        t=t->next;
    }
    t->next=p;
}
//insert at pos
void insertpos(struct node*head,int key,int pos){
    struct node*p,*t;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=key;
    p->next=NULL;
    int cnt=1;
    t=head;
    while(cnt<pos-1 && t!=NULL){
        t=t->next;
        cnt++;
    }
    if(t==NULL){
        printf("Posn out of bound");
    }
    p->next=t->next;
    t->next=p;
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
        temp=ptr->next;
        ptr->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
    return head;
}
int main(){
    struct node*head;
    head=NULL;
    char ch;
    int key,pos;
    do{
        int n;
        printf("Enter operation which you want to perform\n");
        scanf("%d",&n);
        switch(n){
            case 1: head=create(head);
                    break;
            case 2: display(head);
                    break;
            case 3: printf("Enter value which you want to insert\n");
                    scanf("%d",&key);
                    head=atbegin(head,key);
                    break;
            case 4: printf("Enter value which you want to insert\n");
                    scanf("%d",&key);
                    atend(head,key);
                    break;
            case 5: printf("Enter value and position which you want to insert\n");
                    scanf("%d %d",&key,&pos);
                    insertpos(head,key,pos);
                    break;
            case 6: head=deletefront(head);
                    break;
            case 7: head=deleteend(head);
                    break;
            case 8: printf("Enter position which you want to delete");
                    scanf("%d",&pos);
                    head=deletepos(head,pos);
        }
        printf("Enter do you want to continue operations -> y/n\n");
        scanf(" %c",&ch);
    }while(ch=='y');
}