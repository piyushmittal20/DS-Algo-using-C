#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr) {
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf(" \n");
}

struct Node *deletionAtFront(struct Node *head) {
    struct Node *p = head;
    head = head->next;
    free(p);

    return head;
}

struct Node *deletionAtIndex(struct Node *head, int index) {
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i = 0; i < index-1; i++) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

struct Node *deletionAtEnd(struct Node *head) {
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = NULL;

    traversal(head);
    // head = deletionAtFront(head);
    // head = deletionAtIndex(head, 2);
    head = deletionAtEnd(head);
    traversal(head);

    return 0;
}


