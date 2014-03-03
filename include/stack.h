#ifndef __stack_h__
#define __stack_h__

#include "linked_list.h"

typedef struct stack {
    int size;
    struct linked_list_node *list;
} stack_t;

stack_t *new_stack();
void stack_push(stack_t *stack, int val);
int stack_pop(stack_t *stack);
void stack_destroy(stack_t *stack);

#endif
