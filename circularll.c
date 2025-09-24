#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
void display(struct node*);
struct node* create(struct node*);

struct node* create(struct node* head) {
    struct node *t = NULL, *new = NULL;
    char c;
    do {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &new->data);
        new->next = NULL;
        if (head == NULL) {
            head = new;
            t = new;
        } else {
            t->next = new;
            t = new;
        }
        printf("Do you want to add another node y/n\n");
        scanf(" %c", &c);
    } while (c == 'y');
    if (t != NULL){        
        t->next = head;
    }
    return head;
}
void display(struct node* head) {
    struct node* ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
     do{
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr!= head);
    printf("HEAD\n");
}


int main() {
    struct node* head = NULL;
    head = create(head);
    display(head);

    return 0;
}
