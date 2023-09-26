/**
  PROJECT 	: stack project
  FILENAME	: stack.c
  VERSION 	: 1.0
  DATE 		: 2023-09-26
*/
//=========================================================================//
// MODULES USED
//=========================================================================//
#include "stack_list.h"
//=========================================================================//
// LOCAL FUNCTION PROTOTYPE
//=========================================================================//
int sl_isEmpty_impl();
void sl_push_impl(element item);
element sl_pop_impl();
element sl_peek_impl();
void sl_printStack_impl();

StackNode* sl_top;

//=========================================================================//
// EXTERN FUNTION
//=========================================================================//
int sl_isEmpty() 
{
  return sl_isEmpty_impl();
}

void sl_push(element item)
{
    return sl_push_impl(item);
}

element sl_pop()
{
    return sl_pop_impl();
}

element sl_peek()
{
    return sl_peek_impl();
}

void sl_printStack()
{
    return sl_printStack_impl();
}

//=========================================================================//
// LOCAL FUNTION
//=========================================================================//

/**
  desc : 스택이 비었는지 확인
  return
  : 비었으면, 1(true) 반환
  : 비어있지 않으면, 0(fals)
*/ 
int sl_isEmpty_impl()
{
    if(sl_top == NULL) return 1;
    else return 0;
}

void sl_push_impl(char *item)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = sl_top;
    sl_top = temp;
}

element sl_pop_impl()
{
    if (sl_isEmpty())
    {
        printf("스택이 텅 비어있습니다.\n");
        
    }
    else
    {
        element result;
        StackNode* temp = sl_top;
        result = temp->data;
        sl_top = temp->link;
        free(temp);
        return result;
    }
}

element sl_peek_impl()
{
    if (sl_isEmpty())
    {
        printf("스택이 텅 비어있습니다.\n");
        
    }
    else
    {
        return sl_top->data;
    }
}

void sl_printStack_impl()
{
    printf("뒤로가기 스택 = [ ");
    StackNode* p = sl_top;
    while(p)
    {
        printf("%s ", p->data);
        p = p->link;
    }
    printf("]\n");
}