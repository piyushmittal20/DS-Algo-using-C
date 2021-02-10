#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int val) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL) {
        printf("The queue is full\n");
    }
        n->data = val;
        n->next = NULL;
        if(f== NULL) {
            r = f = n;
        } else {
            r->next = n;
            r = n;
        }
}

int dequeue() {
    int val = -1;
    struct Node *ptr = f;
    if(f == NULL) {
        printf("Queue is empty\n");
    } else {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    linkedListTraversal(f);
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}
