#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * Next;
};
void display(struct Node * head){
    struct Node * ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->Next;
    }
}

int main(){
    struct Node *head,*new,*temp;
    head=NULL;
    new=(struct Node *)malloc(sizeof(struct Node));
    char ch;
   
        printf("Enter a number: ");
        scanf("%d",&new->data);
        new->Next=NULL;
        head=new;
        printf("More data?(y/n): ");
        scanf(" %c",&ch);
    while(ch=='y'){
  temp=(struct Node *)malloc(sizeof(struct Node));
  printf("Enter a number: ");
        scanf("%d",&temp->data);
        temp->Next=NULL;
        new->Next=temp;
        new=temp;
         printf("More data?(y/n): ");
        scanf(" %c",&ch);

    }
    display(head);
    
    return 0;
}
