/**
  PROJECT 	: stack project
  FILENAME	: stack_arr.h
  VERSION 	: 1.0
  DATE 		: 2023-09-26
*/
#ifndef _STACK__ARR_H_ // 헤더파일 중복 포함 문제 해결 

#define _STACK__ARR_H_

//=========================================================================//
// MODULES USED
//=========================================================================//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//=========================================================================//
// DEFINITIONS AND MACROS
//=========================================================================//
#define STACK_SIZE 100

//=========================================================================//
// TYPEDEFS AND STRUCTURES
//=========================================================================//
typedef char* element; 

//=========================================================================//
//
// EXTERN FUNCTIONS
//
//=========================================================================//
int sa_isEmpty();
int sa_isFull();
void sa_push(element item);
element sa_pop();
element sa_peek();
void sa_printStack();

#endif/*_STACK__ARR_H_*/
