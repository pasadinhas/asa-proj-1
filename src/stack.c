#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"

stack_t *new_stack() {
    stack_t *stack = (stack_t *) malloc(sizeof(stack_t));
    if (stack == NULL) return NULL;
    stack->size = 0;
    stack->list = NULL;
    return stack;
}

void stack_push(stack_t *stack, int val) {
    stack->size++;
    stack->list = list_insert_beggin(stack->list, val);
}

int stack_pop(stack_t *stack) {
    int val;
    stack->size--;
    stack->list = list_pop_beggin(stack->list, &val);
    return val;
}

void stack_destroy(stack_t *stack) {
    list_destroy(stack->list);
    free(stack);
}
