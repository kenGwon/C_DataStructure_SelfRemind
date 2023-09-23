/**
  PROJECT 	: Sample project
  FILENAME	: header_template.h
  VERSION 	: 1.0
  DATE 		: 2020-05-XX
*/
#ifndef _HEADER_TEMPLATE_H_
#define _HEADER_TEMPLATE_H_

#ifdef __cplusplus
extern "C" {
#endif
//=========================================================================//
// MODULES USED
//=========================================================================//
#include <stdio.h>
#include <string.h>
//=========================================================================//
// DEFINITIONS AND MACROS
//=========================================================================//
#define MAX_BLA_BLA_NUM				(10)
//=========================================================================//
// TYPEDEFS AND STRUCTURES
//=========================================================================//
typedef struct _ST_TIME {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
} ST_TIME;
//=========================================================================//
//
// EXTERN FUNCTIONS
//
//=========================================================================//
int ups_plus		(int a, int b);
int ups_minus		(int a, int b);
int ups_multiply	(int a, int b);
int ups_divide		(int a, int b);


#ifdef __cplusplus
}
#endif

#endif/*_HEADER_TEMPLATE_H_*/
