#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void display(struct node *);
struct node *create(struct node *);
struct node *insert_start(struct node *, int);
struct node *insert_end(struct node *, int);
struct node *insert_pos(struct node *, int, int);
struct node *delete_start(struct node *);
struct node *delete_end(struct node *);
struct node *delete_pos(struct node *,int);
struct node *create(struct node *head)
{
    struct node *t = NULL, *new = NULL;
    char c;
    do
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &new->data);
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            t = new;
        }
        else
        {
            t->next = new;
            t = new;
        }
        printf("Do you want to add another node y/n\n");
        scanf(" %c", &c);
    } while (c == 'y');
    if (t != NULL)
    {
        t->next = head;
    }
    return head;
}
void display(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("HEAD\n");
}

struct node *insert_start(struct node *head, int key)
{
    struct node *t, *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = key;
    new->next = NULL;
    if (head == NULL)
    {

        head = new;
        new->next = head;
        return head;
    }
    else
    {
        t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        new->next = head;
        head = new;

        t->next = head;
    }
    return head;
}

struct node *insert_end(struct node *head, int key)
{
    struct node *t, *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = key;
    new->next = NULL;
    if (head == NULL)
    {

        head = new;
        new->next = head;
        return head;
    }
    else
    {
        t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        t->next = new;

        new->next = head;
    }
    return head;
}
struct node *insert_pos(struct node *head, int key, int pos)
{
    if (pos==1){
        return insert_start(head,key);
    }
    else{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = key;
    new->next = NULL;
    struct node *ptr;
    ptr = head;
    int c = 1;
    if (head == NULL)
    {

        head = new;
        new->next = head;
        return head;
    }
    else
    {
        while (c < pos - 1)
        {
            ptr = ptr->next;
            c++;
        }

        new->next = ptr->next;

        ptr->next = new;
    }
}

    return head;
}
struct node *delete_start(struct node *head)
{
    struct node *ptr, *temp;
    temp = head;
    ptr = head;
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    else if(head->next == head) { 
        free(head);
        return NULL;
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        head = head->next;
        free(temp);
    }

    return head;
}
struct node *delete_end(struct node *head)
{
    struct node *ptr, *temp;
    temp = head;
    ptr = head;
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
       else if(head->next == head) { 
        free(head);
        return NULL;
    }
    else
    {
        while (ptr->next->next != head)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = head;

        free(temp);
    }

    return head;
}
struct node *delete_pos(struct node *head,int pos)
{
    struct node *ptr, *temp;
    temp = head;
    ptr = head;
    int c=1;
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
       else if(head->next == head) { 
        free(head);
        return NULL;
    }
   else
    {
        while (c < pos - 1)
        {
            ptr = ptr->next;
            c++;
        }

        temp=ptr->next;
        ptr->next=temp->next;
        free(temp);
        
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    int choice, key, pos;

    head = create(head);

    do
    {
        printf("\nChoose operation:\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from start\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key to insert at start: ");
            scanf("%d", &key);
            head = insert_start(head, key);

            break;
        case 2:
            printf("Enter key to insert at end: ");
            scanf("%d", &key);
            head = insert_end(head, key);

            break;
        case 3:
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            printf("Enter key to insert: ");
            scanf("%d", &key);
            head = insert_pos(head, key, pos);

            break;
        case 4:
            head = delete_start(head);

            break;
        case 5:
            head = delete_end(head);

            break; 
         case 6:
             printf("Enter position to delete: ");
             scanf("%d", &pos);
             head = delete_pos(head, pos);
             break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);
    return 0;
}