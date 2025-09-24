#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void search(struct node *head, int key)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (key == ptr->data)
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
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            t = newNode;
        }
        else
        {
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
    {
        printf("Memory allocation failed\n");
        return head;
    }
    p->data = key;
    p->next = head;
    head = p;
    return head;
}

struct node *atend(struct node *head, int key)
{
    if (head == NULL)
    {
        return atbegin(head, key);
    }

    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    p->data = key;
    p->next = NULL;

    struct node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = p;
    return head;
}

struct node *insertpos(struct node *head, int key, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 1)
    {
        return atbegin(head, key);
    }
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    struct node *t = head;
    int cnt = 1;
    while (cnt < pos - 1 && t != NULL)
    {
        t = t->next;
        cnt++;
    }

    if (t == NULL)
    {
        printf("Position out of bound\n");
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
    {
        printf("Underflow\n");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *deleteend(struct node *head)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

struct node *deletepos(struct node *head, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1)
    {
        return deletefront(head);
    }

    struct node *ptr = head;
    int cnt = 1;
    while (cnt < pos - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        printf("Position out of bound\n");
        return head;
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;
}

struct node *deletekey(struct node *head, int key)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return head;
    }

    if (head->data == key)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *ptr = head;
    while (ptr->next != NULL && ptr->next->data != key)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        printf("Key not found\n");
        return head;
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
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
