/*
 - 자료구조: circular queue
 - 코드내용: 배열(sequential list)를 이용한 원형큐 자료구조 구현
*/

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

typedef char element;
typedef struct 
{
    element queue[QUEUE_SIZE];
    int front, rear;
} Queue_t;

Queue_t* createQueue();
int isEmpty(Queue_t* cq);
int isFull(Queue_t* cq);
void enQueue(Queue_t* cq, element item);
element deQueue(Queue_t* cq);
element peek(Queue_t* cq);
void printQueue(Queue_t* cq);

int main(void)
{
    Queue_t* myQueue;
    myQueue = createQueue();
    element data;

    printf("<원형 큐 연산>\n");
    enQueue(myQueue, 'a'); printQueue(myQueue);
    enQueue(myQueue, 'b'); printQueue(myQueue);
    enQueue(myQueue, 'c'); printQueue(myQueue);
    printf("현재 peek은 %c\n", peek(myQueue));
    data = deQueue(myQueue); printQueue(myQueue);
    data = deQueue(myQueue); printQueue(myQueue);
    printf("현재 peek은 %c\n", peek(myQueue));
    enQueue(myQueue, 'd'); printQueue(myQueue);
    enQueue(myQueue, 'e'); printQueue(myQueue);

    return 0;
}


Queue_t* createQueue()
{
    Queue_t* cQ;
    cQ = (Queue_t*)malloc(sizeof(Queue_t));
    cQ->front = 0;
    cQ->rear = 0;
    return cQ;
}

int isEmpty(Queue_t* cq)
{
    if (cq->front == cq->rear)
    {
        printf("원형큐가 비었음.\n");
        return 1;
    }
    else return 0;
}

int isFull(Queue_t* cq)
{
    if ((cq->rear + 1) % QUEUE_SIZE == cq->front)
    {
        printf("원형큐가 꽉찼음.\n");
        return 1;
    }
    return 0;
}

void enQueue(Queue_t* cq, element item)
{
    if (isFull(cq)) return;
    else
    {
        cq->rear = (cq->rear + 1) % QUEUE_SIZE;
        cq->queue[cq->rear] = item;
    }
}

element deQueue(Queue_t* cq)
{
    if (isEmpty(cq)) exit(1);
    else
    {
        cq->front = (cq->front + 1) % QUEUE_SIZE;
        return cq->queue[cq->front];
    }
}

element peek(Queue_t* cq)
{
    if (isEmpty(cq)) exit(1);
    else return cq->queue[(cq->front + 1) % QUEUE_SIZE];
}

void printQueue(Queue_t* cq)
{
    int i, first, last;
    first = (cq->front + 1) % QUEUE_SIZE;
    last = (cq->rear + 1) % QUEUE_SIZE;
    
    printf("원형큐: [ ");
    i = first;
    while (i != last)
    {
        printf("%3c", cq->queue[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("] \n");
}