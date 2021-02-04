#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    head->prev = ptr;
    ptr->prev = NULL;
    ptr->next = head;
    head = ptr;

    return head;
}

struct Node *deletionAtfront(struct Node *head) {
    struct Node *ptr = head;

    head = head->next;
    head->prev = NULL;
    free(ptr);

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

    head->data = 2;
    head->next = second;
    head->prev = NULL;

    second->data = 5;
    second->next = third;
    second->prev = head;

    third->data = 1;
    third->next = fourth;
    third->prev = second;

    fourth->data = 6;
    fourth->next = NULL;
    fourth->prev = third;

    traversal(head);
    // head = insertionAtFront(head, 4);
    head = deletionAtfront(head);
    traversal(head);

    return 0;
}
