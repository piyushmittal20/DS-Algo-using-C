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
    printf("\n");
}

struct Node *insertionAtFront(struct Node *head, int data) {
        struct Node *ptr =  (struct Node *)malloc(sizeof(struct Node));

        ptr->data = data;
        ptr->next = head;

        head = ptr;

        return head;
}

struct Node *insertionAtIndex(struct Node *head, int data, int index) {
    struct Node *ptr =  (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertionAtEnd(struct Node *head, int data) {
    struct Node *ptr =  (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node *insertionAfterNode(struct Node *head, int data, struct Node *prevNode) {
    struct Node *ptr =  (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

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

    third->data = 2;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = NULL;

    traversal(head);
    // head = insertionAtFront(head, 1);
    // head = insertionAtIndex(head, 1, 1);
    // head = insertionAtEnd(head, 1);
    head = insertionAfterNode(head, 1, second);
    traversal(head);

    return 0;
}