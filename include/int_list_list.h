#ifndef __int_list_list_h__
#define __int_list_list_h__

#include "int_list.h"

typedef struct int_list_list int_list_list_t, *int_list_list_p;
typedef struct int_list_list_node int_list_list_node_t, *int_list_list_node_p;

struct int_list_list {
    int size;
    int_list_list_node_p head;
};

struct int_list_list_node {
    int_list_p list;
    int_list_list_node_p next;
};

int_list_list_p new_int_list_list();
void int_list_list_insert(int_list_list_p list, int_list_p val);
void int_list_list_destroy(int_list_list_p list);

#endif
