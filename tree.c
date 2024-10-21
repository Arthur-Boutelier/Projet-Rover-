#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


t_node_n_aire* create_node_n_aire(int value, char *action){
    t_node_n_aire* node = (t_node_n_aire*)malloc(sizeof(t_node_n_aire));
    node->value = value;
    node->action = action;
    node->list_son = NULL;
    return node;
}