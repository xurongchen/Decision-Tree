//
// Created by chomimi101 on 2018/2/1.
//

#ifndef C50_STACK_H
#define C50_STACK_H

//#include "../defns.i"

#include <stddef.h>

#define  STACK_TYPE void*

//void create_stack(size_t size);
void destroy_stack(void);
void push(STACK_TYPE value);
void pop(void);
STACK_TYPE top(void);
int is_empty();
int is_full();
size_t stack_size();
#endif //C50_STACK_H
