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
struct node* deletepos(struct node* head, int pos){
    if(head == NULL){
        printf("Underflow\n");
        return head;
    }

    struct node* ptr = head;

    
    if(pos == 1){
        head = head->next;
        if(head != NULL)  
            head->prev = NULL;
        free(ptr);
        return head;
    }

    // Traverse to the node at position `pos`
    int c = 1;
    while(c < pos && ptr != NULL){
        ptr = ptr->next;
        c++;
    }

    // If pos is out of range
    if(ptr == NULL){
        printf("Position out of range!\n");
        return head;
    }

    // Case 2: delete last node
    if(ptr->next == NULL){
        ptr->prev->next = NULL;
        free(ptr);
        return head;
    }

    // Case 3: delete middle node
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);

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
            case 3: printf("Enter position which you want to delete");
                    scanf("%d",&pos);
                    head=deletepos(head,pos);
            break;
        }
        printf("Do you want to continue operation-> y/n \n");
        scanf(" %c",&c);
    }while(c=='y');
}