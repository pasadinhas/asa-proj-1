#ifndef __linked_list_h__
#define __linked_list_h__

typedef struct linked_list_node {
    int val;
    struct linked_list_node *next;
} list_node_t;

list_node_t *new_list(int val);
list_node_t *list_insert_beggin(list_node_t *head, int val);
list_node_t *list_search(list_node_t *head, int val);
list_node_t *list_delete(list_node_t *head, int val);

#endif
