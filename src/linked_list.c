#include <stdlib.h>

#include "linked_list.h"

list_node_t *new_list(int val) {
    list_node_t *node = (list_node_t *) malloc(1 * sizeof(list_node_t));
    node->val = val;
    node->next = NULL;
    return node;
}

list_node_t *list_insert_beggin(list_node_t *head, int val) {
    list_node_t *new = new_list(val);
    new->next = head;
    return new;
}

list_node_t *list_search(list_node_t *head, int val) {
    list_node_t *current = head;
    while (current != NULL) {
        if (current->val == val) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

list_node_t *list_delete(list_node_t *head, int val) {
    list_node_t *previous, *delete;
    if (head->val == val) {
        return head->next;
    }
    previous = head;
    while (previous->next != NULL) {
        if (previous->next->val == val) {
            delete = previous->next;
            previous->next = delete->next;
            free(delete);
            break;
        }
    }
    return head;
}

void list_destroy(list_node_t *head) {
    list_node_t *delete = head;
    while(head != NULL) {
        delete = head;
        head = head->next;
        free(delete);
    }
}
