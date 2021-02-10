#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val) {
    if(isFull(q)) {
        printf("The queue is full\n");
    }
        q->r = (q->r +1) % q->size;
        q->arr[q->r] = val;
}

int dequeue(struct queue *q) {
    int a = -1;
    if(isEmpty(q)) {
        printf("The queue is empty\n");
    }
        q->f = (q->f +1)% q->size;
        a = q->arr[q->f];
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    return 0;
}
