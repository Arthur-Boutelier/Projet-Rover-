#ifndef UNTITLED1_LOC_H
#define UNTITLED1_LOC_H
#include "list.h"
typedef struct s_node_n_aire{
    int value;
    char* action;
    t_list_tree* list_son;
} t_node_n_aire;

t_node_n_aire* create_node_n_aire(int value, char *action);





#endif //UNTITLED1_LOC_H
