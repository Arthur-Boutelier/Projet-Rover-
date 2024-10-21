#include "list.h"
#include <stdlib.h>

t_node_tree* create_node_list(int val, char* action){
    t_node_tree * new_node = (t_node_tree*) malloc(sizeof(t_node_tree));
    new_node->next = NULL;
    new_node->value = create_node_n_aire(val, action)
    return new_node;
}


