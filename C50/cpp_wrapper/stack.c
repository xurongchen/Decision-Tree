//
// Created by new on 2018/2/1.
//

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


#define FALSE 0

typedef struct STACK_NODE{
    STACK_TYPE value;
    struct STACK_NODE *next;
} StackNode;

static StackNode *stack; // root ptr
static size_t _stack_size;

void create_stack(size_t size){
}

void destroy_stack(void){
    while(!is_empty()){
        pop();
    }

}

void push(STACK_TYPE value){
    assert(!is_full());
    StackNode *new_node;
    new_node = malloc(sizeof(StackNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = stack;
    stack = new_node;
    ++_stack_size;
}

void pop(void){
    StackNode *firstNode;
    assert(!is_empty());

    firstNode = stack;
    stack = stack->next;
    free(firstNode);
    --_stack_size;
}

STACK_TYPE top(void){
    assert(!is_empty());
    return stack->value;
}

int is_empty(){
    return stack == NULL;
}

int is_full(){
    return FALSE;
}

size_t stack_size(){
    return _stack_size;
}