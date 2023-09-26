/**
  PROJECT 	: stack project
  FILENAME	: stack.h
  VERSION 	: 1.0
  DATE 		: 2023-09-26
*/
#ifndef _STACK__LIST_H_ // 헤더파일 중복 포함 문제 해결 

#define _STACK__LIST_H_

//=========================================================================//
// MODULES USED
//=========================================================================//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//=========================================================================//
// DEFINITIONS AND MACROS
//=========================================================================//
#define MAX_BLA_BLA_NUM				(10)

//=========================================================================//
// TYPEDEFS AND STRUCTURES
//=========================================================================//
typedef char* element; 

typedef struct stack_node
{
    element data;
    struct stack_node* link;
} StackNode;

//=========================================================================//
//
// EXTERN FUNCTIONS
//
//=========================================================================//
int sl_isEmpty();
void sl_push(element item);
element sl_pop();
element sl_peek();
void sl_printStack();

#endif/*_STACK__LIST_H_*/
