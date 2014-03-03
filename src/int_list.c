#include <stdlib.h>

#include "int_list.h"

int_list_p new_int_list() {
    int_list_p list = (int_list_p) malloc(sizeof(int_list_t));
    list->size = 0;
    list->head = NULL;
    return list;
}

void int_list_insert(int_list_p list, int val) {
    int_list_push(list, val);
}

void int_list_push(int_list_p list, int val) {
    int_list_node_p node = (int_list_node_p) malloc(sizeof(int_list_node_t));
    node->val = val;
    node->next = list->head;
    list->head = node;
    list->size++;
}

int int_list_pop(int_list_p list) {
    int_list_node_p head = list->head;
    int value = head->val;
    list->head = head->next;
    free(head);
    list->size--;
    return value;
}

int int_list_size(int_list_p list) {
    return list->size;
}

void int_list_destroy(int_list_p list) {
    int_list_node_p current = list->head;
    int_list_node_p next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int_list_node_p int_list_search(int_list_p list, int val) {
    int_list_node_p node = list->head;
    while (node != NULL) {
        if (node->val == val) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
