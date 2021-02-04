#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty(struct Node *top) {
    if(top==NULL) {
        return 1;
    } else
    {
        return 0;
    }
}

int isFull(struct Node *top) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL) {
        return 1;
    } else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int data) {
    if(isFull(top)) {
        printf("Stack Overflow \n");
    } else {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = top;
        top = p;

        return top;
    }
}

int pop(struct Node *tp) {
    if(isEmpty(tp)) {
        printf("Stack UnderFlow");
    } else
    {
        struct Node *n = tp;
        top = tp->next;
        int data = n->data;
        free(n);

        return data;
    }
}

int main()
{
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 5);

    int element = pop(top);
    printf("%d \n", element);

    // if(isEmpty(top)) {
    //     printf("Stack is Empty");
    // } else
    // {
    //     printf("Stack is not Empty");
    // }

    return 0;
}
