#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void traverseforward(struct node *head)
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d ->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
void traverseback(struct node *head)
{
    struct node *p;
    p = head;
    while (p ->next!= NULL)
    {
       
        p = p->next;
    }
    while (p != NULL) {
    printf("%d ->", p->data);
    p = p->prev;
}


    printf("NULL\n");
}
void search(struct node *head, int key)
{
    int flag = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
struct node *create(struct node *head)
{
    struct node *t = NULL;
    struct node *new = NULL;
    char c;
    do
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter node");
        scanf("%d", &new->data);
        new->next = NULL;
        new->prev=NULL;
        if (head == NULL)
        {
            head = new;
            t = new;
        }
        else
        {    new->prev=t;
            t->next = new;
            t = new;
        }
        printf("Do you want to add another node y/n\n");
        scanf(" %c", &c);
    } while (c == 'y');
    return head;
}
void display(struct node *head)
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d ->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
struct node *atbegin(struct node *head, int key)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    head->prev=p;
    p->prev=NULL;
    p->next = NULL;
    p->next = head;
    head = p;
    return head;
}
 struct node *atend(struct node *head, int key)
{
    struct node *p, *t;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->next = NULL;
    p->prev = NULL;
    t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    p->prev=t;
    t->next = p;
    return head;
}

struct node * insertpos(struct node *head, int key, int pos)
{
    struct node *p, *t;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->next = NULL;
    int cnt = 1;
    t = head;
    while (cnt < pos - 1 && t != NULL)
    {
        t = t->next;
        cnt++;
    }
    if (t == NULL)
    {
        printf("Position out of bound");
    }
    p->prev=t;
    t->next->prev=p;
    p->next = t->next;
    t->next = p;
    return head;
}

struct node *deletefront(struct node *head)
{
    if (head == NULL)
    {
        printf("Underflow");
        return head;
    }
    else if (head->next == NULL)
    {
        struct node *temp;
        temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    else
    {
        struct node *temp;
        temp = head;
        head->next->prev=NULL;
        head = head->next;
        free(temp);
    }
    return head;
}
struct node *deleteend(struct node *head)
{
    if (head == NULL)
    {
        printf("Underflow");
        return head;
    }
    else if (head->next == NULL)
    {
        struct node *temp;
        temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    else
    {
        struct node *temp, *ptr;
        ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    }
    return head;
}
// delete at position
struct node *deletepos(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("Underflow");
        return head;
    }
    else if (head->next == NULL)
    {
        struct node *temp;
        temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        struct node *temp, *ptr;
        int cnt = 1;
        ptr = head;
        while (cnt < pos - 1 && ptr != NULL)
        {
            ptr = ptr->next;
            cnt++;
        }
        if (ptr == NULL)
        {
            printf("Position out of bound");
            return head;
        }
        temp = ptr->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->next = NULL;
        free(temp);
    }
    return head;
}
struct node *deletekey(struct node *head, int key)
{
    if (head == NULL)
    {
        printf("Underflow");
        return head;
    }
    else if (head->next == NULL && head->data == key)
    {
        struct node *temp;
        temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    else
    {
        struct node *temp, *ptr, *ptr2;
        ptr = head;
        ptr2 = head;
        while (ptr->next != NULL)
        {
           if (ptr->next->data == key) {
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev=ptr; 
    free(temp);
    return head;
}

            ptr2 = ptr;
            ptr = ptr->next;
        }
        if (ptr->data == key)
        {
            ptr2->next = NULL;
            free(ptr);
            return head;
        }
        return head;
    }
}
int count(struct node *head)
{
    struct node *p;
    p = head;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
void check(struct node *head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Not empty\n");
}
int main()
{
    struct node *head;
    head = NULL;
    int ch;
    int key;
    int pos;

    do
    {
        printf("1. Create LL\n2. Traverse LL\n3. Insert element at beginning\n4. Insert element at position\n5. Insert element at end\n6. Delete from start\n7. Delete from position\n8. Delete from end\n9. Delete Key\n10. Count Nodes\n11. Search element\n12. Check empty\n13. Exit\n");
        printf("Enter operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = create(head);
            break;
        case 2:
        traverseback(head);
           case 14:
            traverseforward(head);
            break;
            
            break;
        case 3:
            printf("Enter element to insert: ");
            scanf("%d", &key);
           head= atbegin(head, key);
            break;

        case 4:

            printf("Enter element to insert: ");
            scanf("%d", &key);
            printf("Enter position: ");
            scanf("%d", &pos);
          head= insertpos(head, key, pos);
            break;
        case 5:
            printf("Enter element to insert: ");
            scanf("%d", &key);
            head=atend(head, key);
            break;
        case 6:
            head=deletefront(head);
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &pos);
            head=deletepos(head, pos);
            break;
        case 8:
            head=deleteend(head);
            break;
        case 9:
            printf("Enter element to delete: ");
            scanf("%d", &key);
           head= deletekey(head, key);
            break;
        case 10:
            printf("No. of nodes is: %d\n", count(head));
            break;
        case 11:
            printf("Enter no to be check present or not\n");
            scanf("%d", &key);
            search(head, key);
            break;
        case 12:
            check(head);
            break;
        }

    } while (ch != 13);
    return 0;
}
