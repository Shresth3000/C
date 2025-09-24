#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
};

void display(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->Next;
    }
    printf("NULL\n");
}
struct Node * reverse(struct Node *head){
    struct Node *prev=NULL,*curr=head,*ptr=NULL;
    while(curr!=NULL){
        ptr=curr->Next;
        curr->Next=prev;
        prev=curr;
        curr=ptr;
       }
       head=prev;
       return head;

}
void insert_start(struct Node *head, int key)
{
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = key;
    new->Next = NULL;
    new->Next = head;
    head = new;
    display(head);
}
void insert_end(struct Node *head, int key)
{
    struct Node *new;
    struct Node *ptr = head;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = key;
    new->Next = NULL;

    while (ptr->Next != NULL)
    {
        ptr = ptr->Next;
    }
    ptr->Next = new;
    display(head);
}
void insert_pos(struct Node *head, int key, int pos)
{
    struct Node *new;
    struct Node *temp;
    struct Node *ptr = head;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = key;
    new->Next = NULL;
    int c = 1;
    while (c < pos - 1)
    {
        ptr = ptr->Next;
        c++;
    }

    new->Next = ptr->Next;

    ptr->Next = new;
    display(head);
}
void del_start(struct Node *head)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else if (head->Next == NULL)
    {
        struct Node *ptr = head;
        head = NULL;
        free(ptr);
        display(head);
    }
    else
    {
        struct Node *ptr;
        ptr = head;
        head = head->Next;
        free(ptr);
        display(head);
    }
}
void del_end(struct Node *head)
{
     if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else if (head->Next == NULL)
    {
        struct Node *ptr = head;
        head = NULL;
        free(ptr);
        display(head);
    }else{
    struct Node *ptr;
    struct Node *ptr2;
    ptr = head;
    while (ptr->Next->Next != NULL)
    {
        ptr = ptr->Next;
    }
    ptr2 = ptr->Next;
    ptr->Next = NULL;

    free(ptr2);
    display(head);
}
}
void del_pos(struct Node *head, int pos)
{
     if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else if (head->Next == NULL)
    {
        struct Node *ptr = head;
        head = NULL;
        free(ptr);
        display(head);
    }
    else{
    struct Node *ptr;
    struct Node *ptr2;
    int c = 1;
    ptr = head;
    while (c < pos - 1)
    {
        ptr = ptr->Next;
        c++;
    }
    ptr2 = ptr->Next;
    ptr->Next = ptr2->Next;

    free(ptr2);
    display(head);
}
}
int main()
{
    struct Node *head, *new, *temp;
    head = NULL;
    new = (struct Node *)malloc(sizeof(struct Node));
    char ch;

    printf("Enter a number: ");
    scanf("%d", &new->data);
    new->Next = NULL;
    head = new;
    printf("More data?(y/n): ");
    scanf(" %c", &ch);
    while (ch == 'y')
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter a number: ");
        scanf("%d", &temp->data);
        temp->Next = NULL;
        new->Next = temp;
        new = temp;
        printf("More data?(y/n): ");
        scanf(" %c", &ch);
    }
    int op;
    printf("1. Insert in start\n2. Insert in position\n3. Insert in end\n4. Delete from start\n5. Delete from position\n6. Delete from end\n");
    printf("Enter your choice: ");
    scanf("%d", &op);
    int key, pos;

    switch (op)
    {
    case 1:
        printf("Enter element to insert: ");
        scanf("%d", &key);
        insert_start(head, key);
        break;
    case 2:
        printf("Enter element to insert: ");
        scanf("%d", &key);
        printf("Enter position: ");
        scanf("%d", &pos);
        insert_pos(head, key, pos);
        break;
    case 3:
        printf("Enter element to insert: ");
        scanf("%d", &key);
        insert_end(head, key);
        break;
    case 4:

        del_start(head);
        break;
    case 5:
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        del_pos(head, pos);
        break;
    case 6:
        del_end(head);
        break;
    case 7:
        head=reverse(head);
        display(head);
        break;
    default:
        break;
    }

    printf("\n");

    return 0;
}
