/*
 - 자료구조: stack
 - 코드내용: 배열(sequential list)를 이용한 스택 자료구조 구현
*/

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element; // 스택에 들어갈 자료형을 int로 가정하고 그걸 element로 alias

element stack[STACK_SIZE]; // C에서 제공하는 배열로 스택 선언
int top = -1; // 스택 위치를 나타내는 top을 -1로 초기화

int isEmpty();
int isFull();
void push(element item);
element pop();
element peek();
void printStack();

int main(void)
{
    element item;
    printf("<순차 스택 연산>\n");

    printStack();
    push(1); printStack();
    push(2); printStack();
    push(3); printStack();

    item = peek();
    printf("현재 peek 원소의 값은 %d\n", item);

    pop(); printStack();
    item = peek();
    printf("현재 peek 원소의 값은 %d\n", item);
    pop(); printStack();
    item = peek();
    printf("현재 peek 원소의 값은 %d\n", item);
    pop(); printStack();
    item = peek();
    printf("현재 peek 원소의 값은 %d\n", item);

    return 0;
}



int isEmpty()
{
    if (top == -1) return 1;
    else return 0;
}

int isFull()
{
    if (top == STACK_SIZE - 1) return 1;
    else return 0;
}

void push(element item)
{
    if (isFull())
    {
        printf("\n스택이 꽉 찼습니다.\n");
        return;
    }
    else stack[++top] = item;
}

element pop()
{
    if (isEmpty())
    {
        printf("\n스택이 텅 비었습니다.\n");
        return 0;
    }
    else return stack[top--];
}

element peek()
{
    if (isEmpty())
    {
        printf("\n스택이 텅 비었습니다.\n");
        exit(1);
    }
    else return stack[top];
}

void printStack()
{
    printf("STACK [ ");
    for (int i = 0; i < top+1; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("]\n");
}



