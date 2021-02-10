#include <stdlib.h>
#include <stdio.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
        return 0;
}

void push(struct stack *ptr, int data) {
    if(isFull(ptr)) {
        printf("Stack overflow\n");
    } else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct stack *ptr) {
    if(isEmpty(ptr)) {
        printf("Stack Underflow \n");
        return -1;
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *s, int i) {
    int arrIndex = s->top-i+1;
    if(arrIndex < 0) {
        printf("The invalid value entered \n");
        return -1;
    } else
    {
        return s->arr[arrIndex];
    }
    
}

int main()
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 2);
    push(s, 4);
    push(s, 5);
    push(s, 6);

    // printf("The pop out element is %d \n", pop(s));
    // printf("The pop out element is %d \n", pop(s));
    // printf("The pop out element is %d \n", pop(s));

    // if(isEmpty(s)) {
    //     printf("Stack is Empty");
    // } else
    // {
    //     printf("stack is not Empty");
    // }

    for(int j = 1; j <= s->top+1; j++) {
        printf("%d \n", peek(s, j));
    }

    return 0;
}
