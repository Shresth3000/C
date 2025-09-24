#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *p = head;
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(head)\n");
}

void search(struct node *head, int key)
{
    if (head == NULL)
    {
        printf("NO\n");
        return;
    }
    struct node *ptr = head;
    do
    {
        if (key == ptr->data)
        {
            printf("YES\n");
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    printf("NO\n");
}

struct node *create(struct node *head)
{
    struct node *t = NULL, *newNode = NULL;
    char c;
    do
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter node: ");
        scanf("%d", &newNode->data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            t = newNode;
        }
        else
        {
            newNode->next = head;
            t->next = newNode;
            t = newNode;
        }
        printf("Do you want to add another node (y/n)? ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    return head;
}

struct node *atbegin(struct node *head, int key)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        return head;
    p->data = key;
    if (head == NULL)
    {
        p->next = p;
        return p;
    }
    struct node *t = head;
    while (t->next != head)
        t = t->next;
    p->next = head;
    t->next = p;
    head = p;
    return head;
}

struct node *atend(struct node *head, int key)
{
    if (head == NULL)
        return atbegin(head, key);
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        return head;
    p->data = key;
    struct node *t = head;
    while (t->next != head)
        t = t->next;
    t->next = p;
    p->next = head;
    return head;
}

struct node *insertpos(struct node *head, int key, int pos)
{
    if (pos < 1)
        return head;
    if (pos == 1)
        return atbegin(head, key);
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        return head;
    p->data = key;
    struct node *t = head;
    int cnt = 1;
    while (cnt < pos - 1 && t->next != head)
    {
        t = t->next;
        cnt++;
    }
    if (cnt != pos - 1)
    {
        free(p);
        return head;
    }
    p->next = t->next;
    t->next = p;
    return head;
}

struct node *deletefront(struct node *head)
{
    if (head == NULL)
        return head;
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct node *t = head;
    while (t->next != head)
        t = t->next;
    struct node *temp = head;
    head = head->next;
    t->next = head;
    free(temp);
    return head;
}

struct node *deleteend(struct node *head)
{
    if (head == NULL)
        return head;
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    while (ptr->next->next != head)
        ptr = ptr->next;
    free(ptr->next);
    ptr->next = head;
    return head;
}

struct node *deletepos(struct node *head, int pos)
{
    if (pos < 1 || head == NULL)
        return head;
    if (pos == 1)
        return deletefront(head);
    struct node *ptr = head;
    int cnt = 1;
    while (cnt < pos - 1 && ptr->next != head)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (cnt != pos - 1 || ptr->next == head)
        return head;
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;
}

struct node *deletekey(struct node *head, int key)
{
    if (head == NULL)
        return head;
    if (head->data == key)
        return deletefront(head);
    struct node *ptr = head;
    while (ptr->next != head && ptr->next->data != key)
        ptr = ptr->next;
    if (ptr->next == head)
        return head;
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;
}

int count(struct node *head)
{
    if (head == NULL)
        return 0;
    int c = 0;
    struct node *p = head;
    do
    {
        c++;
        p = p->next;
    } while (p != head);
    return c;
}

void check(struct node *head)
{
    if (head == NULL)
        printf("List is empty\n");
    else
        printf("Not empty\n");
}

int main()
{
    struct node *head = NULL;
    int ch, key, pos;
    do
    {
        printf("\n1. Create LL\n2. Traverse LL\n3. Insert at beginning\n4. Insert at position\n5. Insert at end\n6. Delete from start\n7. Delete from position\n8. Delete from end\n9. Delete by Key\n10. Count Nodes\n11. Search element\n12. Check empty\n13. Exit\n");
        printf("Enter operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            traverse(head);
            break;
        case 3:
            printf("Enter element: ");
            scanf("%d", &key);
            head = atbegin(head, key);
            break;
        case 4:
            printf("Enter element: ");
            scanf("%d", &key);
            printf("Enter position: ");
            scanf("%d", &pos);
            head = insertpos(head, key, pos);
            break;
        case 5:
            printf("Enter element: ");
            scanf("%d", &key);
            head = atend(head, key);
            break;
        case 6:
            head = deletefront(head);
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = deletepos(head, pos);
            break;
        case 8:
            head = deleteend(head);
            break;
        case 9:
            printf("Enter element to delete: ");
            scanf("%d", &key);
            head = deletekey(head, key);
            break;
        case 10:
            printf("No. of nodes: %d\n", count(head));
            break;
        case 11:
            printf("Enter element to search: ");
            scanf("%d", &key);
            search(head, key);
            break;
        case 12:
            check(head);
            break;
        case 13:
            printf("Stopped\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 13);
    return 0;
}
