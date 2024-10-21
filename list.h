#include "tree.h"
#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
typedef struct s_node_tree{
    t_node_n_aire* node;
    struct s_node_tree* next;
} t_node_tree;


typedef struct s_list{
    t_node_tree* head;
}t_list_tree;

t_node_tree* create_node(int val, char* action);

#endif //UNTITLED1_LIST_H
