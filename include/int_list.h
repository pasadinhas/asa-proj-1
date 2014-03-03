#ifndef __int_list_h__
#define __int_list_h__

typedef struct int_list int_list_t, *int_list_p;
typedef struct int_list_node int_list_node_t, *int_list_node_p;

struct int_list {
    int size;
    int_list_node_p head;
};

struct int_list_node {
    int val;
    int_list_node_p next;
};

int_list_p new_int_list();
void int_list_insert(int_list_p list, int val);
void int_list_push(int_list_p list, int val);
int int_list_pop(int_list_p list);
int int_list_size(int_list_p list);
void int_list_destroy(int_list_p list);
int_list_node_p int_list_search(int_list_p list, int val);

#endif
