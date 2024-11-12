#ifndef UNTITLED1_LOC_H
#define UNTITLED1_LOC_H
#include "list.h"

typedef struct s_node{
    int value;
    t_move move;
    t_list_move available_move;
    t_list_son son;
} t_node;

typedef struct s_tree
{
    t_node* racine;
} t_tree;

#endif //UNTITLED1_LOC_H
