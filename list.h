#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
#include "tree.h"

typedef struct s_cell_son{
    t_node* curr_node;
    struct s_cell_son * next;
}t_cell_son;

typedef struct s_list_son
{
    t_cell_son* head;
}t_list_son;

#endif //UNTITLED1_LIST_H
