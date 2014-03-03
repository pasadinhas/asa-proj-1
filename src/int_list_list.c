#include <stdlib.h>

#include "int_list.h"
#include "int_list_list.h"

int_list_list_p new_int_list_list() {
    int_list_list_p list = (int_list_list_p) malloc(sizeof(int_list_list_t));
    list->size = 0;
    list->head = NULL;
    return list;
}

void int_list_list_insert(int_list_list_p list, int_list_p val) {
    int_list_list_node_p node = (int_list_list_node_p) malloc(sizeof(int_list_list_node_t));
    node->list = val;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void int_list_list_destroy(int_list_list_p list) {
    int_list_list_node_p current = list->head;
    int_list_list_node_p next;
    while(current != NULL) {
        next = current->next;
        int_list_destroy(current->list);
        free(current);
        current = next;
    }
    free(list);
}
