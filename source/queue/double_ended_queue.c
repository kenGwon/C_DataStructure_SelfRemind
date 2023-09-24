/*
 - 자료구조: double ended queue(DEque)
 - 코드내용: 이중연결리스트(double linked list)를 이용한 데큐 자료구조 구현
*/

#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct double_ended_queue_node
{
    element data;
    struct double_ended_queue_node* head;
    struct double_ended_queue_node* tail;
} DEQnode;

typedef struct double_ended_queue
{
    DEQnode* front;
    DEQnode* rear;
} DEQ;

DEQ* creatdDEQ();
int isEmpty(DEQ* deq);
void insertFront(DEQ* deq, element data);
void insertRear(DEQ* deq, element data);
element deleteFront(DEQ* deq);
element deleteRear(DEQ* deq);
element peekFront(DEQ* deq);
element peekRear(DEQ* deq);
void printDEQ(DEQ* deq);

int main(void)
{
    DEQ* myDEQ = creatdDEQ();
    element data;

    printf("---데큐 연산 테스트---\n");
    insertFront(myDEQ, 'a'); printDEQ(myDEQ);
    insertFront(myDEQ, 'b'); printDEQ(myDEQ);
    insertFront(myDEQ, 'c'); printDEQ(myDEQ);
    deleteRear(myDEQ); printDEQ(myDEQ);
    insertRear(myDEQ, 'd'); printDEQ(myDEQ);
    insertRear(myDEQ, 'e'); printDEQ(myDEQ);
    insertRear(myDEQ, 'f'); printDEQ(myDEQ);
    deleteFront(myDEQ); printDEQ(myDEQ);

    data = peekFront(myDEQ);
    printf("peekFront의 값은 %c\n", data);
    data = peekRear(myDEQ);
    printf("peekRear의 값은 %c\n", data);

    return 0;
}



DEQ* creatdDEQ()
{
    DEQ* temp;
    temp = (DEQ*)malloc(sizeof(DEQ));
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

int isEmpty(DEQ* deq)
{
    if (deq->front == NULL) 
    {
        printf("데큐가 비었음.\n");
        return 1;
    }
    else return 0;
}

void insertFront(DEQ* deq, element data)
{
    DEQnode* new_node = (DEQnode*)malloc(sizeof(DEQnode));
    new_node->data = data;
    
    if (isEmpty(deq))
    {
        deq->front = new_node;
        deq->rear = new_node;
        new_node->head = NULL;
        new_node->tail = NULL;
    }
    else
    {
       deq->front->head = new_node;
       new_node->tail = deq->front;
       new_node->head = NULL;
       deq->front = new_node;
    }
}

void insertRear(DEQ* deq, element data)
{
    DEQnode* new_node = (DEQnode*)malloc(sizeof(DEQnode));
    new_node->data = data;

    if (isEmpty(deq))
    {
        deq->rear = new_node;
        deq->front = new_node;
        new_node->head = NULL;
        new_node->tail = NULL;
    }
    else
    {
        deq->rear->tail = new_node;
        new_node->head = deq->rear;
        new_node->tail = NULL;
        deq->rear = new_node;
    }
}

element deleteFront(DEQ* deq)
{
    DEQnode* old = deq->front;
    element data;

    if (isEmpty(deq)) return 0;
    else
    {
        data = old->data;

        if (deq->front->tail == NULL) // 큐에 요소가 하나밖에 안남은 경우
        {
            deq->front = NULL;
            deq->rear = NULL;
        }
        else
        {
            deq->front = deq->front->tail;
            deq->front->head = NULL;
        }

        free(old);
        return data;
    }
}

element deleteRear(DEQ* deq)
{
    DEQnode* old = deq->rear;
    element data;

    if (isEmpty(deq)) return 0;
    else
    {
        data = old->data;

        if (deq->rear->head == NULL) // 큐에 요소가 하나밖에 안남은 경우
        {
            deq->front = NULL;
            deq->rear = NULL;    
        }
        else
        {
            deq->rear = deq->rear->head;
            deq->rear->tail = NULL;
        }
        
        free(old);
        return data;
    }
}

element peekFront(DEQ* deq)
{
    element data;
    if (isEmpty(deq)) return 0;
    else
    {
        data = deq->front->data;
        return data;
    }
}

element peekRear(DEQ* deq)
{
    element data;
    if (isEmpty(deq)) return 0;
    else
    {
        data = deq->rear->data;
        return data;
    }
}

void printDEQ(DEQ* deq)
{
    DEQnode* temp = deq->front;
    
    printf("DEQ: [ ");
    while (temp)
    {
        printf("%3c", temp->data);
        temp = temp->tail;
    }
    printf(" ]\n");
}


