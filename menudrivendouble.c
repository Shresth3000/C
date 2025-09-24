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
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
void traverseback(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->prev;
    }
    printf("NULL\n");
}
void search(struct node *head, int key)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("YES\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("NO\n");
}
struct node *create(struct node *head)
{
    struct node *t = NULL, *newNode = NULL;
    char c;
    do
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            t = newNode;
        }
        else
        {
            t->next = newNode;
            newNode->prev = t;
            t = newNode;
        }
        printf("Do you want to add another node y/n: ");
        scanf(" %c", &c);
    } while (c == 'y');
    return head;
}
struct node *atbegin(struct node *head, int key)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->prev = NULL;
    p->next = head;
    if (head != NULL)
    {
        head->prev = p;
    }
    head = p;
    return head;
}
struct node *atend(struct node *head, int key)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->next = NULL;
    if (head == NULL)
    {
        p->prev = NULL;
        return p;
    }
    struct node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = p;
    p->prev = t;
    return head;
}
struct node *insertpos(struct node *head, int key, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        return atbegin(head, key);
    }
    struct node *t = head;
    int cnt = 1;
    while (cnt < pos - 1 && t->next != NULL)
    {
        t = t->next;
        cnt++;
    }
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->next = t->next;
    p->prev = t;
    if (t->next != NULL)
    {
        t->next->prev = p;
    }
    t->next = p;
    return head;
}
struct node *deletefront(struct node *head)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}
struct node *deleteend(struct node *head)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return head;
}
struct node *deletepos(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    if (pos <= 1)
    {
        return deletefront(head);
    }
    struct node *ptr = head;
    int cnt = 1;
    while (cnt < pos && ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (ptr == NULL)
    {
        printf("Position out of bound\n");
        return head;
    }
    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    if (ptr->prev != NULL)
    {
        ptr->prev->next = ptr->next;
    }
    free(ptr);
    return head;
}
struct node *deletekey(struct node *head, int key)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    struct node *ptr = head;
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Key not found\n");
        return head;
    }
    if (ptr->prev != NULL)
    {
        ptr->prev->next = ptr->next;
    }
    else
    {
        head = ptr->next;
    }
    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    return head;
}
int count(struct node *head)
{
    int c = 0;
    struct node *p = head;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
void check(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Not empty\n");
    }
}
int main()
{
    struct node *head = NULL;
    int ch, key, pos;

    do
    {
        printf("1. Create LL\n2. Traverse forward\n 3. Traverse backward\n 4. Insert element at beginning\n 5. Insert element at position\n 6. Insert element at end\n 7. Delete from start\n 8. Delete from position\n 9. Delete from end\n 10. Delete Key\n 11. Count Nodes\n 12. Search element\n 13. Check empty\n 14. Exit\nEnter operation : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            traverseforward(head);
            break;
        case 3:
            traverseback(head);
            break;
        case 4:
            printf("Enter element to insert: ");
            scanf("%d", &key);
            head = atbegin(head, key);
            break;
        case 5:
            printf("Enter element to insert: ");
            scanf("%d", &key);
            printf("Enter position: ");
            scanf("%d", &pos);
            head = insertpos(head, key, pos);
            break;
        case 6:
            printf("Enter element to insert: ");
            scanf("%d", &key);
            head = atend(head, key);
            break;
        case 7:
            head = deletefront(head);
            break;
        case 8:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = deletepos(head, pos);
            break;
        case 9:
            head = deleteend(head);
            break;
        case 10:
            printf("Enter element to delete: ");
            scanf("%d", &key);
            head = deletekey(head, key);
            break;
        case 11:
            printf("No. of nodes is: %d\n", count(head));
            break;
        case 12:
            printf("Enter no to check: ");
            scanf("%d", &key);
            search(head, key);
            break;
        case 13:
            check(head);
            break;
        case 14:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (ch != 14);

    return 0;
}
