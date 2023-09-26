/**
  PROJECT 	: stack project
  FILENAME	: stack.c
  VERSION 	: 1.0
  DATE 		: 2023-09-26
*/
//=========================================================================//
// MODULES USED
//=========================================================================//
#include "stack_arr.h"
//=========================================================================//
// LOCAL FUNCTION PROTOTYPE
//=========================================================================//
int sa_isEmpty_impl();
int sa_isFull_impl();
void sa_push_impl(element item);
element sa_pop_impl();
element sa_peek_impl();
void sa_printStack_impl();

element stack[STACK_SIZE]; 
int sa_top; 

//=========================================================================//
// EXTERN FUNTION
//=========================================================================//
int sa_isEmpty() 
{
  return sa_isEmpty_impl();
}

int sa_isFull()
{
    return sa_isFull_impl();
}

void sa_push(element item)
{
    return sa_push_impl(item);
}

element sa_pop()
{
    return sa_pop_impl();
}

element sa_peek()
{
    return sa_peek_impl();
}

void sa_printStack()
{
    return sa_printStack_impl();
}

//=========================================================================//
// LOCAL FUNTION
//=========================================================================//

int sa_isEmpty_impl()
{
    if (sa_top == -1) return 1;
    else return 0;
}

int sa_isFull_impl()
{
    if (sa_top == STACK_SIZE - 1) return 1;
    else return 0;
}

void sa_push_impl(element item)
{
    if (sa_isFull())
    {
        printf("\n스택이 꽉 찼습니다.\n");
        return;
    }
    else stack[++sa_top] = item;
}

element sa_pop_impl()
{
    if (sa_isEmpty())
    {
        printf("\n스택이 텅 비었습니다.\n");
        
    }
    else return stack[sa_top--];
}

element sa_peek_impl()
{
    if (sa_isEmpty())
    {
        printf("\n스택이 텅 비었습니다.\n");
        
    }
    else return stack[sa_top];
}

void sa_printStack_impl()
{
    printf("\"앞으로\" 스택(top <--- bottom) = [ ");
    for (int i = sa_top; i >= 0; i--)
    {
        printf("%s ", stack[i]);
    }
    printf("]\n");
}