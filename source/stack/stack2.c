/*
 - 자료구조: stack
 - 코드내용: 연결리스트(linked list)를 이용한 스택 자료구조 구현
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stack_node
{
    element data;
    struct stack_node* link;
} StackNode;

StackNode* top;

int isEmpty();
void push(element item);
element pop();
element peek();
void printStack();

int main(void)
{
    element item;
    top = NULL;
    printf("Linked List로 구현한 Stack\n");
    printStack();

    push(1); printStack();
    push(2); printStack();
    push(3); printStack();

    item = peek();
    printf("현재 peek: %d\n", item);
    
    pop(); printStack();
    pop(); printStack();
    pop(); printStack();
    pop(); printStack();

    return 0;
}


int isEmpty()
{
    if(top == NULL) return 1;
    else return 0;
}

void push(element item)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

element pop()
{
    if (top == NULL)
    {
        printf("스택이 텅 비어있습니다.\n");
        exit(1);
    }
    else
    {
        element result;
        StackNode* temp = top;
        result = temp->data;
        top = temp->link;
        free(temp);
        return result;
    }
}

element peek()
{
    if (top == NULL)
    {
        printf("스택이 텅 비어있습니다.\n");
        exit(1);
    }
    else
    {
        return top->data;
    }
}

void printStack()
{
    printf("STACK = [ ");
    StackNode* p = top;
    while(p)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("]\n");
}

